#pragma once

#include "transport_catalog.h"
#include "datetime.h"
#include "json.h"
#include "companies_index.h"

#include <string>
#include <variant>


namespace Requests {
  struct Stop {
    std::string name;

    Json::Dict Process(const TransportCatalog& db) const;
  };

  struct Bus {
    std::string name;

    Json::Dict Process(const TransportCatalog& db) const;
  };

  struct Route {
    std::string stop_from;
    std::string stop_to;

    Json::Dict Process(const TransportCatalog& db) const;
  };

  struct Map {
    Json::Dict Process(const TransportCatalog& db) const;
  };

  struct FindCompanies {
    YellowPages::CompanyQuery query;

    Json::Dict Process(const TransportCatalog& db) const;
  };

  struct RouteToCompany {
    WeekDayTime datetime;
    std::string stop_from;
    YellowPages::CompanyQuery company_query;

    Json::Dict Process(const TransportCatalog& db) const;
  };

  std::variant<Stop, Bus, Route, Map, FindCompanies, RouteToCompany> Read(const Json::Dict& attrs);

  Json::Array ProcessAll(const TransportCatalog& db, const Json::Array& requests);
}
