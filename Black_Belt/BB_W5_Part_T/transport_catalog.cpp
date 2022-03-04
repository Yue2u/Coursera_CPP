#include "transport_catalog.h"
#include "working_time.h"
#include "algorithm.h"
#include "map.h"
#include "range.h"

#include "transport_catalog.pb.h"

#include <algorithm>
#include <iterator>
#include <map>
#include <optional>
#include <sstream>
#include <unordered_map>

using namespace std;

static void FillCompanyIds(YellowPages::Database& yellow_pages_db) {
  YellowPages::CompanyId company_id = 0;
  for (auto& company : *yellow_pages_db.mutable_companies()) {
    company.set_id(company_id++);
  }
}

static void ValidateWorkingTimes(const YellowPages::Database& yellow_pages_db) {
  for (const auto& company : yellow_pages_db.companies()) {
    YellowPages::ValidateWorkingTime(company.working_time());
  }
}

TransportCatalog::TransportCatalog(
    vector<Descriptions::InputQuery> data,
    YellowPages::Database yellow_pages_db,
    const Json::Dict& routing_settings_json,
    const Json::Dict& render_settings_json
)
    : yellow_pages_db_(move(yellow_pages_db))
{
  auto stops_end = partition(begin(data), end(data), [](const auto& item) {
    return holds_alternative<Descriptions::Stop>(item);
  });

  Descriptions::StopsDict stops_dict;
  for (const auto& item : Range{begin(data), stops_end}) {
    const auto& stop = get<Descriptions::Stop>(item);
    stops_dict[stop.name] = &stop;
    stops_.insert({stop.name, {}});
  }

  Descriptions::BusesDict buses_dict;
  for (const auto& item : Range{stops_end, end(data)}) {
    const auto& bus = get<Descriptions::Bus>(item);

    buses_dict[bus.name] = &bus;
    buses_[bus.name] = Bus{
      bus.stops.size(),
      ComputeUniqueItemsCount(AsRange(bus.stops)),
      ComputeRoadRouteLength(bus.stops, stops_dict),
      ComputeGeoRouteDistance(bus.stops, stops_dict)
    };

    for (const string& stop_name : bus.stops) {
      stops_.at(stop_name).bus_names.insert(bus.name);
    }
  }

  ValidateWorkingTimes(yellow_pages_db_);
  FillCompanyIds(yellow_pages_db_);

  router_ = make_unique<TransportRouter>(stops_dict, buses_dict, yellow_pages_db_.companies(), routing_settings_json);

  map_renderer_ = make_unique<MapRenderer>(stops_dict, buses_dict, render_settings_json, *this);
  map_ = map_renderer_->Render();
}

const TransportCatalog::Stop* TransportCatalog::GetStop(const string& name) const {
  return GetValuePointer(stops_, name);
}

const TransportCatalog::Bus* TransportCatalog::GetBus(const string& name) const {
  return GetValuePointer(buses_, name);
}

optional<TransportRouter::RouteInfo> TransportCatalog::FindRoute(const string& stop_from, const string& stop_to) const {
  return router_->FindRoute(stop_from, stop_to);
}

optional<TransportRouter::RouteInfo> TransportCatalog::FindRouteToCompany(
    const WeekDayTime& datetime,
    const string& stop_from,
    const YellowPages::CompanyQuery& company_query
) const {
  const auto companies = FindCompanies(company_query);
  return router_->FindRouteToCompany(datetime, stop_from, companies);
}

string TransportCatalog::RenderMap() const {
  ostringstream out;
  map_.Render(out);
  return out.str();
}

string TransportCatalog::RenderRoute(const TransportRouter::RouteInfo& route) const {
  ostringstream out;
  BuildRouteMap(route).Render(out);
  return out.str();
}

size_t TransportCatalog::ComputeRoadRouteLength(
    const vector<string>& stops,
    const Descriptions::StopsDict& stops_dict
) {
  size_t result = 0;
  for (size_t i = 1; i < stops.size(); ++i) {
    result += Descriptions::ComputeStopsDistance(*stops_dict.at(stops[i - 1]), *stops_dict.at(stops[i]));
  }
  return result;
}

double TransportCatalog::ComputeGeoRouteDistance(
    const vector<string>& stops,
    const Descriptions::StopsDict& stops_dict
) {
  double result = 0;
  for (size_t i = 1; i < stops.size(); ++i) {
    result += Sphere::Distance(
      stops_dict.at(stops[i - 1])->position, stops_dict.at(stops[i])->position
    );
  }
  return result;
}

Svg::Document TransportCatalog::BuildRouteMap(const TransportRouter::RouteInfo& route) const {
  return map_renderer_->RenderRoute(map_, route);
}

const YellowPages::CompaniesProto& TransportCatalog::GetCompanies() const {
  return yellow_pages_db_.companies();
}

const YellowPages::Company& TransportCatalog::GetCompanyById(YellowPages::CompanyId id) const {
  const auto& company = yellow_pages_db_.companies()[id];
  assert(company.id() == id);
  return company;
}

const YellowPages::RubricsById& TransportCatalog::GetRubricsById() const {
  return yellow_pages_db_.rubrics();
}

YellowPages::Companies TransportCatalog::FindCompanies(const YellowPages::CompanyQuery& query) const {
  return yellow_pages_index_->Find(query, rubrics_name_to_id_);
}

string TransportCatalog::Serialize() const {
  TCProto::TransportCatalog db_proto;

  for (const auto& [name, stop] : stops_) {
    TCProto::StopResponse& stop_proto = *db_proto.add_stops();
    stop_proto.set_name(name);
    for (const string& bus_name : stop.bus_names) {
      stop_proto.add_bus_names(bus_name);
    }
  }

  for (const auto& [name, bus] : buses_) {
    TCProto::BusResponse& bus_proto = *db_proto.add_buses();
    bus_proto.set_name(name);
    bus_proto.set_stop_count(bus.stop_count);
    bus_proto.set_unique_stop_count(bus.unique_stop_count);
    bus_proto.set_road_route_length(bus.road_route_length);
    bus_proto.set_geo_route_length(bus.geo_route_length);
  }

  router_->Serialize(*db_proto.mutable_router());
  map_renderer_->Serialize(*db_proto.mutable_renderer());

  *db_proto.mutable_yellow_pages() = yellow_pages_db_;

  return db_proto.SerializeAsString();
}

unique_ptr<TransportCatalog> TransportCatalog::Deserialize(const string& data) {
  TCProto::TransportCatalog proto;
  assert(proto.ParseFromString(data));

  unique_ptr<TransportCatalog> catalog_holder(new TransportCatalog);  // ctor is private, so we can't use make_unique here
  auto& catalog = *catalog_holder;

  for (const TCProto::StopResponse& stop_proto : proto.stops()) {
    Stop& stop = catalog.stops_[stop_proto.name()];
    for (const string& bus_name : stop_proto.bus_names()) {
      stop.bus_names.insert(bus_name);
    }
  }

  for (const TCProto::BusResponse& bus_proto : proto.buses()) {
    Bus& bus = catalog.buses_[bus_proto.name()];
    bus.stop_count = bus_proto.stop_count();
    bus.unique_stop_count = bus_proto.unique_stop_count();
    bus.road_route_length = bus_proto.road_route_length();
    bus.geo_route_length = bus_proto.geo_route_length();
  }

  catalog.router_ = TransportRouter::Deserialize(proto.router());
  // A unique_ptr is returned to avoid passing a reference to a local object here
  catalog.map_renderer_ = MapRenderer::Deserialize(proto.renderer(), catalog);
  catalog.map_ = catalog.map_renderer_->Render();

  catalog.yellow_pages_db_ = move(*proto.mutable_yellow_pages());

  catalog.yellow_pages_index_ = make_unique<YellowPages::CompaniesIndex>(
      begin(catalog.yellow_pages_db_.companies()),
      end(catalog.yellow_pages_db_.companies())
  );

  catalog.rubrics_name_to_id_ = YellowPages::MakeRubricsNameToId(catalog.yellow_pages_db_.rubrics());

  return catalog_holder;
}
