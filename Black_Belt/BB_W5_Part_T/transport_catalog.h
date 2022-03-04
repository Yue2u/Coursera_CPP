#pragma once

#include "descriptions.h"
#include "map_renderer.h"
#include "transport_router.h"

#include "datetime.h"
#include "json.h"
#include "svg.h"

#include "companies_index.h"
#include "company.h"
#include "rubric.h"
#include "database.pb.h"

#include <memory>
#include <optional>
#include <set>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

namespace Responses {
  struct Stop {
    std::set<std::string> bus_names;
  };

  struct Bus {
    size_t stop_count = 0;
    size_t unique_stop_count = 0;
    size_t road_route_length = 0;
    double geo_route_length = 0.0;
  };
}

class TransportCatalog {
private:
  using Bus = Responses::Bus;
  using Stop = Responses::Stop;

public:
  TransportCatalog(
      std::vector<Descriptions::InputQuery> data,
      YellowPages::Database yellow_pages_db,
      const Json::Dict& routing_settings_json,
      const Json::Dict& render_settings_json
  );

  const Stop* GetStop(const std::string& name) const;
  const Bus* GetBus(const std::string& name) const;

  std::optional<TransportRouter::RouteInfo> FindRoute(const std::string& stop_from, const std::string& stop_to) const;
  std::optional<TransportRouter::RouteInfo> FindRouteToCompany(
      const WeekDayTime& datetime,
      const std::string& stop_from,
      const YellowPages::CompanyQuery& company_query
  ) const;

  std::string RenderMap() const;
  std::string RenderRoute(const TransportRouter::RouteInfo& route) const;

  const YellowPages::CompaniesProto& GetCompanies() const;
  const YellowPages::Company& GetCompanyById(YellowPages::CompanyId id) const;
  const YellowPages::RubricsById& GetRubricsById() const;

  YellowPages::Companies FindCompanies(const YellowPages::CompanyQuery& query) const;

  std::string Serialize() const;
  static std::unique_ptr<TransportCatalog> Deserialize(const std::string& data);

private:
  TransportCatalog() = default;

  static size_t ComputeRoadRouteLength(
      const std::vector<std::string>& stops,
      const Descriptions::StopsDict& stops_dict
  );

  static double ComputeGeoRouteDistance(
      const std::vector<std::string>& stops,
      const Descriptions::StopsDict& stops_dict
  );

  static Svg::Document BuildMap(
      const Descriptions::StopsDict& stops_dict,
      const Descriptions::BusesDict& buses_dict,
      const Json::Dict& render_settings_json
  );
  Svg::Document BuildRouteMap(const TransportRouter::RouteInfo& route) const;

  std::unordered_map<std::string, Stop> stops_;
  std::unordered_map<std::string, Bus> buses_;
  std::unique_ptr<TransportRouter> router_;
  std::unique_ptr<MapRenderer> map_renderer_;
  Svg::Document map_;

  YellowPages::Database yellow_pages_db_;
  YellowPages::RubricsNameToId rubrics_name_to_id_;
  std::unique_ptr<YellowPages::CompaniesIndex> yellow_pages_index_;
};
