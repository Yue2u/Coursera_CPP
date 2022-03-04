#include "map_renderer.h"
#include "sphere.h"
#include "utils.h"
#include <algorithm>
#include <cassert>

using namespace std;


static Svg::Point ParsePoint(const Json::Node& json) {
  const auto& array = json.AsArray();
  return {
      array[0].AsDouble(),
      array[1].AsDouble()
  };
}

static Svg::Color ParseColor(const Json::Node& json) {
  if (json.IsString()) {
    return json.AsString();
  }
  const auto& array = json.AsArray();
  assert(array.size() == 3 || array.size() == 4);
  Svg::Rgb rgb{
      static_cast<uint8_t>(array[0].AsInt()),
      static_cast<uint8_t>(array[1].AsInt()),
      static_cast<uint8_t>(array[2].AsInt())
  };
  if (array.size() == 3) {
    return rgb;
  } else {
    return Svg::Rgba{rgb, array[3].AsDouble()};
  }
}

static vector<Svg::Color> ParseColors(const Json::Node& json) {
  const auto& array = json.AsArray();
  vector<Svg::Color> colors;
  colors.reserve(array.size());
  transform(begin(array), end(array), back_inserter(colors), ParseColor);
  return colors;
}

RenderSettings ParseRenderSettings(const Json::Dict& json) {
  RenderSettings result;
  result.max_width = json.at("width").AsDouble();
  result.max_height = json.at("height").AsDouble();
  result.padding = json.at("padding").AsDouble();
  result.palette = ParseColors(json.at("color_palette"));
  result.line_width = json.at("line_width").AsDouble();
  result.underlayer_color = ParseColor(json.at("underlayer_color"));
  result.underlayer_width = json.at("underlayer_width").AsDouble();
  result.stop_radius = json.at("stop_radius").AsDouble();
  result.bus_label_offset = ParsePoint(json.at("bus_label_offset"));
  result.bus_label_font_size = json.at("bus_label_font_size").AsInt();
  result.stop_label_offset = ParsePoint(json.at("stop_label_offset"));
  result.stop_label_font_size = json.at("stop_label_font_size").AsInt();

  const auto& layers_array = json.at("layers").AsArray();
  result.layers.reserve(layers_array.size());
  for (const auto& layer_node : layers_array) {
    result.layers.push_back(layer_node.AsString());
  }

  return result;
}

class CoordsCompressor {
public:
  CoordsCompressor(const Descriptions::StopsDict& stops_dict) {
    for (const auto& [_, stop_ptr] : stops_dict) {
      lats_.push_back({stop_ptr->position.latitude});
      lons_.push_back({stop_ptr->position.longitude});
    }

    sort(begin(lats_), end(lats_));
    sort(begin(lons_), end(lons_));
  }

  void FillTargets(double max_width, double max_height, double padding) {
    if (lats_.empty() || lons_.empty()) {
      return;
    }

    const size_t max_lat_idx = lats_.size() - 1;
    const double y_step = max_lat_idx ? (max_height - 2 * padding) / max_lat_idx : 0;

    const size_t max_lon_idx = lons_.size() - 1;
    const double x_step = max_lon_idx ? (max_width - 2 * padding) / max_lon_idx : 0;

    {
      size_t idx = 0;
      for (auto& [_, value] : lats_) {
        value = max_height - padding - idx++ * y_step;
      }
    }
    {
      size_t idx = 0;
      for (auto& [_, value] : lons_) {
        value = idx++ * x_step + padding;
      }
    }
  }

  double MapLat(double value) const {
    return Find(lats_, value).target;
  }
  double MapLon(double value) const {
    return Find(lons_, value).target;
  }

private:
  struct CoordInfo {
    double source;
    double target = 0;

    bool operator<(const CoordInfo& other) const {
      return source < other.source;
    }
  };

  vector<CoordInfo> lats_;
  vector<CoordInfo> lons_;

  static const CoordInfo& Find(const vector<CoordInfo>& sorted_values, double value) {
    return *lower_bound(begin(sorted_values), end(sorted_values), CoordInfo{value});
  }
};

static map<string, Svg::Point> ComputeStopsCoordsByGrid(const Descriptions::StopsDict& stops_dict,
                                                        const RenderSettings& render_settings) {
  CoordsCompressor compressor(stops_dict);
  compressor.FillTargets(render_settings.max_width, render_settings.max_height, render_settings.padding);

  map<string, Svg::Point> new_stops_coords;
  for (const auto& [stop_name, stop_ptr] : stops_dict) {
    new_stops_coords[stop_name] = {compressor.MapLon(stop_ptr->position.longitude), compressor.MapLat(stop_ptr->position.latitude)};
  }

  return new_stops_coords;
}

static unordered_map<string, Svg::Color> ChooseBusColors(const Descriptions::BusesDict& buses_dict,
                                                         const RenderSettings& render_settings) {
  const auto& palette = render_settings.palette;
  unordered_map<string, Svg::Color> bus_colors;
  int idx = 0;
  for (const auto& [bus_name, bus_ptr] : buses_dict) {
    bus_colors[bus_name] = palette[idx++ % palette.size()];
  }
  return bus_colors;
}

MapRenderer::MapRenderer(const Descriptions::StopsDict& stops_dict,
                         const Descriptions::BusesDict& buses_dict,
                         const Json::Dict& render_settings_json)
    : render_settings_(ParseRenderSettings(render_settings_json)),
      buses_dict_(buses_dict),
      stops_coords_(ComputeStopsCoordsByGrid(stops_dict, render_settings_)),
      bus_colors_(ChooseBusColors(buses_dict, render_settings_))
{
}

void MapRenderer::RenderBusLines(Svg::Document& svg) const {
  for (const auto& [bus_name, bus_ptr] : buses_dict_) {
    const auto& stops = bus_ptr->stops;
    if (stops.empty()) {
      continue;
    }
    Svg::Polyline line;
    line.SetStrokeColor(bus_colors_.at(bus_name))
        .SetStrokeWidth(render_settings_.line_width)
        .SetStrokeLineCap("round").SetStrokeLineJoin("round");
    for (const auto& stop_name : stops) {
      line.AddPoint(stops_coords_.at(stop_name));
    }
    svg.Add(line);
  }
}

void MapRenderer::RenderBusLabels(Svg::Document& svg) const {
  for (const auto& [bus_name, bus_ptr] : buses_dict_) {
    const auto& stops = bus_ptr->stops;
    if (!stops.empty()) {
      const auto& color = bus_colors_.at(bus_name);
      for (const string& endpoint : bus_ptr->endpoints) {
        const auto point = stops_coords_.at(endpoint);
        const auto base_text =
            Svg::Text{}
            .SetPoint(point)
            .SetOffset(render_settings_.bus_label_offset)
            .SetFontSize(render_settings_.bus_label_font_size)
            .SetFontFamily("Verdana")
            .SetFontWeight("bold")
            .SetData(bus_name);
        svg.Add(
            Svg::Text(base_text)
            .SetFillColor(render_settings_.underlayer_color)
            .SetStrokeColor(render_settings_.underlayer_color)
            .SetStrokeWidth(render_settings_.underlayer_width)
            .SetStrokeLineCap("round").SetStrokeLineJoin("round")
        );
        svg.Add(
            Svg::Text(base_text)
            .SetFillColor(color)
        );
      }
    }
  }
}

void MapRenderer::RenderStopPoints(Svg::Document& svg) const {
  for (const auto& [stop_name, stop_point] : stops_coords_) {
    svg.Add(Svg::Circle{}
            .SetCenter(stop_point)
            .SetRadius(render_settings_.stop_radius)
            .SetFillColor("white"));
  }
}

void MapRenderer::RenderStopLabels(Svg::Document& svg) const {
  for (const auto& [stop_name, stop_point] : stops_coords_) {
    const auto base_text =
        Svg::Text{}
        .SetPoint(stop_point)
        .SetOffset(render_settings_.stop_label_offset)
        .SetFontSize(render_settings_.stop_label_font_size)
        .SetFontFamily("Verdana")
        .SetData(stop_name);
    svg.Add(
        Svg::Text(base_text)
        .SetFillColor(render_settings_.underlayer_color)
        .SetStrokeColor(render_settings_.underlayer_color)
        .SetStrokeWidth(render_settings_.underlayer_width)
        .SetStrokeLineCap("round").SetStrokeLineJoin("round")
    );
    svg.Add(
        Svg::Text(base_text)
        .SetFillColor("black")
    );
  }
}

const unordered_map<string, void (MapRenderer::*)(Svg::Document&) const> MapRenderer::LAYER_ACTIONS = {
    {"bus_lines",   &MapRenderer::RenderBusLines},
    {"bus_labels",  &MapRenderer::RenderBusLabels},
    {"stop_points", &MapRenderer::RenderStopPoints},
    {"stop_labels", &MapRenderer::RenderStopLabels},
};

Svg::Document MapRenderer::Render() const {
  Svg::Document svg;

  for (const auto& layer : render_settings_.layers) {
    (this->*LAYER_ACTIONS.at(layer))(svg);
  }

  return svg;
}