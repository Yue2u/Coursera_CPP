#include "requests.h"
#include "transport_router.h"
#include "company.h"

#include <vector>

using namespace std;

namespace Requests {

  Json::Dict Stop::Process(const TransportCatalog& db) const {
    const auto* stop = db.GetStop(name);
    Json::Dict dict;
    if (!stop) {
      dict["error_message"] = Json::Node("not found"s);
    } else {
      Json::Array bus_nodes;
      bus_nodes.reserve(stop->bus_names.size());
      for (const auto& bus_name : stop->bus_names) {
        bus_nodes.emplace_back(bus_name);
      }
      dict["buses"] = Json::Node(move(bus_nodes));
    }
    return dict;
  }

  Json::Dict Bus::Process(const TransportCatalog& db) const {
    const auto* bus = db.GetBus(name);
    Json::Dict dict;
    if (!bus) {
      dict["error_message"] = Json::Node("not found"s);
    } else {
      dict = {
          {"stop_count", Json::Node(static_cast<int>(bus->stop_count))},
          {"unique_stop_count", Json::Node(static_cast<int>(bus->unique_stop_count))},
          {"route_length", Json::Node(static_cast<int>(bus->road_route_length))},
          {"curvature", Json::Node(bus->road_route_length / bus->geo_route_length)},
      };
    }
    return dict;
  }

  struct RouteItemResponseBuilder {
    const TransportCatalog& db;

    Json::Dict operator()(const TransportRouter::RouteInfo::RideBusItem& bus_item) const {
      return Json::Dict{
          {"type", Json::Node("RideBus"s)},
          {"bus", Json::Node(bus_item.bus_name)},
          {"time", Json::Node(bus_item.time)},
          {"span_count", Json::Node(static_cast<int>(bus_item.span_count))}
      };
    }
    Json::Dict operator()(const TransportRouter::RouteInfo::WaitBusItem& wait_item) const {
      return Json::Dict{
          {"type", Json::Node("WaitBus"s)},
          {"stop_name", Json::Node(wait_item.stop_name)},
          {"time", Json::Node(wait_item.time)},
      };
    }
    Json::Dict operator()(const TransportRouter::RouteInfo::WalkToCompanyItem& company_item) const {
      return Json::Dict{
          {"type", Json::Node("WalkToCompany"s)},
          {"stop_name", Json::Node(company_item.stop_name)},
          {"company", YellowPages::MakeCompanyJson(db.GetCompanyById(company_item.company_id))},
          {"time", Json::Node(company_item.time)},
      };
    }
    Json::Dict operator()(const TransportRouter::RouteInfo::WaitCompanyItem& company_wait_item) const {
      return Json::Dict{
          {"type", Json::Node("WaitCompany"s)},
          {"company", YellowPages::MakeCompanyJson(db.GetCompanyById(company_wait_item.company_id))},
          {"time", Json::Node(company_wait_item.time)},
      };
    }
  };

  static Json::Dict MakeRouteJson(const TransportCatalog& db, const optional<TransportRouter::RouteInfo>& route) {
    Json::Dict dict;
    if (!route) {
      dict["error_message"] = Json::Node("not found"s);
    } else {
      dict["total_time"] = Json::Node(route->total_time);
      RouteItemResponseBuilder builder{db};
      Json::Array items;
      items.reserve(route->items.size());
      for (const auto& item : route->items) {
        items.push_back(visit(builder, item));
      }

      dict["items"] = move(items);

      dict["map"] = Json::Node(db.RenderRoute(*route));
    }
    return dict;
  }

  Json::Dict Route::Process(const TransportCatalog& db) const {
    return MakeRouteJson(db, db.FindRoute(stop_from, stop_to));
  }

  Json::Dict Map::Process(const TransportCatalog& db) const {
    return Json::Dict{
        {"map", Json::Node(db.RenderMap())},
    };
  }

  Json::Dict FindCompanies::Process(const TransportCatalog& db) const {
    Json::Dict result;
    Json::Array companies_json;
    const auto companies = db.FindCompanies(query);
    companies_json.reserve(companies.size());
    for (const YellowPages::Company* company : companies) {
      companies_json.push_back(YellowPages::MakeCompanyJson(*company));
    }
    result["companies"] = move(companies_json);
    return result;
  }

  Json::Dict RouteToCompany::Process(const TransportCatalog& db) const {
    return MakeRouteJson(db, db.FindRouteToCompany(datetime, stop_from, company_query));
  }

  variant<Stop, Bus, Route, Map, FindCompanies, RouteToCompany> Read(const Json::Dict& attrs) {
    const string& type = attrs.at("type").AsString();
    if (type == "Bus") {
      return Bus{attrs.at("name").AsString()};
    } else if (type == "Stop") {
      return Stop{attrs.at("name").AsString()};
    } else if (type == "Route") {
      return Route{attrs.at("from").AsString(), attrs.at("to").AsString()};
    } else if (type == "Map") {
      return Map{};
    } else if (type == "FindCompanies") {
      return FindCompanies{YellowPages::CompanyQuery::FromJson(attrs)};
    } else {
      const auto& datetime_json = attrs.at("datetime").AsArray();
      const WeekDayTime datetime{
          datetime_json[0].AsInt(),
          datetime_json[1].AsInt(),
          datetime_json[2].AsInt(),
      };
      return RouteToCompany{
          datetime,
          attrs.at("from").AsString(),
          YellowPages::CompanyQuery::FromJson(attrs.at("companies").AsMap())
      };
    }
  }

  Json::Array ProcessAll(const TransportCatalog& db, const Json::Array& requests) {
    Json::Array responses;
    responses.reserve(requests.size());
    for (const Json::Node& request_node : requests) {
      Json::Dict dict = visit([&db](const auto& request) {
                                return request.Process(db);
                              },
                              Requests::Read(request_node.AsMap()));
      dict["request_id"] = Json::Node(request_node.AsMap().at("id").AsInt());
      responses.push_back(Json::Node(dict));
    }
    return responses;
  }

}
