#pragma once

#include "descriptions.h"
#include "transport_router.h"
#include "json.h"
#include "svg.h"

#include "map_renderer.pb.h"

#include <map>
#include <string>
#include <unordered_map>
#include <vector>


struct RenderSettings {
  double max_width;
  double max_height;
  double padding;
  double outer_margin;
  std::vector<Svg::Color> palette;
  double line_width;
  double company_line_width;
  Svg::Color underlayer_color;
  double underlayer_width;
  double stop_radius;
  double company_radius;
  Svg::Point bus_label_offset;
  int bus_label_font_size;
  Svg::Point stop_label_offset;
  int stop_label_font_size;
  std::vector<std::string> layers;

  void Serialize(TCProto::RenderSettings& proto) const;
  static RenderSettings Deserialize(const TCProto::RenderSettings& proto);
};

struct PointsMaps {
  std::map<std::string, Svg::Point> stops;
  std::vector<Svg::Point> companies;
};

class TransportCatalog;

class MapRenderer {
public:
  MapRenderer(const Descriptions::StopsDict& stops_dict,
              const Descriptions::BusesDict& buses_dict,
              const Json::Dict& render_settings_json,
              const TransportCatalog& catalog);

  void Serialize(TCProto::MapRenderer& proto);
  static std::unique_ptr<MapRenderer> Deserialize(const TCProto::MapRenderer& proto, const TransportCatalog& catalog);

  Svg::Document Render() const;
  Svg::Document RenderRoute(Svg::Document whole_map, const TransportRouter::RouteInfo& route) const;

private:
  MapRenderer(const TransportCatalog& catalog);

  const TransportCatalog& catalog_;
  RenderSettings render_settings_;
  PointsMaps points_maps_;

  std::unordered_map<std::string, Svg::Color> bus_colors_;
  // TODO: move instead of copy
  std::map<std::string, Descriptions::Bus> buses_dict_;

  void RenderBusLabel(Svg::Document& svg, const std::string& bus_name, const std::string& stop_name) const;
  void RenderStopPoint(Svg::Document& svg, Svg::Point point) const;
  void RenderLabel(Svg::Document& svg, Svg::Point point, const std::string& name) const;

  void RenderBusLines(Svg::Document& svg) const;
  void RenderBusLabels(Svg::Document& svg) const;
  void RenderStopPoints(Svg::Document& svg) const;
  void RenderStopLabels(Svg::Document& svg) const;
  void RenderCompanies(Svg::Document& svg) const;

  void RenderRouteBusLines(Svg::Document& svg, const TransportRouter::RouteInfo& route) const;
  void RenderRouteBusLabels(Svg::Document& svg, const TransportRouter::RouteInfo& route) const;
  void RenderRouteStopPoints(Svg::Document& svg, const TransportRouter::RouteInfo& route) const;
  void RenderRouteStopLabels(Svg::Document& svg, const TransportRouter::RouteInfo& route) const;
  void RenderRouteCompanyLabels(Svg::Document& svg, const TransportRouter::RouteInfo& route) const;
  void RenderRouteCompanyPoints(Svg::Document& svg, const TransportRouter::RouteInfo& route) const;
  void RenderRouteCompanyLines(Svg::Document& svg, const TransportRouter::RouteInfo& route) const;

  static const std::unordered_map<
      std::string,
      void (MapRenderer::*)(Svg::Document&) const
  > MAP_LAYER_ACTIONS;

  static const std::unordered_map<
      std::string,
      void (MapRenderer::*)(Svg::Document&, const TransportRouter::RouteInfo&) const
  > ROUTE_LAYER_ACTIONS;
};
