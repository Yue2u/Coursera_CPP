#include "transport_router.h"
#include "working_time.h"
#include "numeric.h"

using namespace std;


TransportRouter::TransportRouter(const Descriptions::StopsDict& stops_dict,
                                 const Descriptions::BusesDict& buses_dict,
                                 const YellowPages::CompaniesProto& companies,
                                 const Json::Dict& routing_settings_json)
    : routing_settings_(MakeRoutingSettings(routing_settings_json))
{
  const size_t company_count = companies.size();
  const size_t vertex_count = stops_dict.size() * 2 + company_count;
  companies_vertex_id_.resize(company_count);
  vertices_info_.reserve(vertex_count);
  graph_ = BusGraph(vertex_count);

  FillGraphWithStops(stops_dict);
  FillGraphWithCompanies(companies);
  FillGraphWithBuses(stops_dict, buses_dict);

  router_ = std::make_unique<Router>(graph_);
}

TransportRouter::RoutingSettings TransportRouter::MakeRoutingSettings(const Json::Dict& json) {
  return {
      json.at("bus_wait_time").AsInt(),
      json.at("bus_velocity").AsDouble(),
      json.at("pedestrian_velocity").AsDouble(),
  };
}

void TransportRouter::FillGraphWithStops(const Descriptions::StopsDict& stops_dict) {
  Graph::VertexId vertex_id = 0;

  for (const auto& [stop_name, _] : stops_dict) {
    auto& vertex_ids = stops_vertex_ids_[stop_name];
    vertex_ids.in = vertex_id++;
    vertex_ids.out = vertex_id++;
    vertices_info_.push_back(StopVertexInfo{stop_name});
    vertices_info_.push_back(StopVertexInfo{stop_name});

    edges_info_.push_back(WaitEdgeInfo{});
    const Graph::EdgeId edge_id = graph_.AddEdge({
        vertex_ids.out,
        vertex_ids.in,
        static_cast<double>(routing_settings_.bus_wait_time)
    });
    assert(edge_id == edges_info_.size() - 1);
  }
  assert(vertex_id == vertices_info_.size());
}

static double ComputeTime(double meters, double km_per_hour) {
  return meters * 1.0 / (km_per_hour * 1000.0 / 60);  // m / (km/h * 1000 / 60) = min
}

void TransportRouter::FillGraphWithCompanies(const YellowPages::CompaniesProto& companies) {
  Graph::VertexId vertex_id = vertices_info_.size();
  for (const YellowPages::Company& company : companies) {
    companies_vertex_id_[company.id()] = vertex_id;
    vertices_info_.push_back(CompanyVertexInfo{company.id()});

    for (const auto& nearby_stop : company.nearby_stops()) {
      const Graph::VertexId start_vertex = stops_vertex_ids_.at(nearby_stop.name()).out;
      const Graph::VertexId finish_vertex = vertex_id;
      const double time = ComputeTime(nearby_stop.meters(), routing_settings_.pedestrian_velocity);
      edges_info_.push_back(CompanyEdgeInfo{
          .stop_name = nearby_stop.name(),
          .company_id = company.id(),
      });
      const Graph::EdgeId edge_id = graph_.AddEdge({start_vertex, finish_vertex, time});
      assert(edge_id == edges_info_.size() - 1);
    }

    ++vertex_id;
  }
  assert(vertex_id == vertices_info_.size());
}

void TransportRouter::FillGraphWithBuses(const Descriptions::StopsDict& stops_dict,
                                         const Descriptions::BusesDict& buses_dict) {
  for (const auto& [_, bus_item] : buses_dict) {
    const auto& bus = *bus_item;
    const size_t stop_count = bus.stops.size();
    if (stop_count <= 1) {
      continue;
    }
    auto compute_distance_from = [&stops_dict, &bus](size_t lhs_idx) {
      return Descriptions::ComputeStopsDistance(*stops_dict.at(bus.stops[lhs_idx]), *stops_dict.at(bus.stops[lhs_idx + 1]));
    };
    for (size_t start_stop_idx = 0; start_stop_idx + 1 < stop_count; ++start_stop_idx) {
      const Graph::VertexId start_vertex = stops_vertex_ids_[bus.stops[start_stop_idx]].in;
      int total_distance = 0;
      for (size_t finish_stop_idx = start_stop_idx + 1; finish_stop_idx < stop_count; ++finish_stop_idx) {
        total_distance += compute_distance_from(finish_stop_idx - 1);
        edges_info_.push_back(BusEdgeInfo{
            .bus_name = bus.name,
            .start_stop_idx = start_stop_idx,
            .finish_stop_idx = finish_stop_idx,
        });
        const Graph::EdgeId edge_id = graph_.AddEdge({
            start_vertex,
            stops_vertex_ids_[bus.stops[finish_stop_idx]].out,
            ComputeTime(total_distance, routing_settings_.bus_velocity)
        });
        assert(edge_id == edges_info_.size() - 1);
      }
    }
  }
}

void TransportRouter::Serialize(TCProto::TransportRouter& proto) const {
  auto& routing_settings_proto = *proto.mutable_routing_settings();
  routing_settings_proto.set_bus_wait_time(routing_settings_.bus_wait_time);
  routing_settings_proto.set_bus_velocity(routing_settings_.bus_velocity);

  graph_.Serialize(*proto.mutable_graph());
  router_->Serialize(*proto.mutable_router());

  for (const auto& [name, vertex_ids] : stops_vertex_ids_) {
    auto& vertex_ids_proto = *proto.add_stops_vertex_ids();
    vertex_ids_proto.set_name(name);
    vertex_ids_proto.set_in(vertex_ids.in);
    vertex_ids_proto.set_out(vertex_ids.out);
  }

  for (const Graph::VertexId vertex_id : companies_vertex_id_) {
    proto.add_companies_vertex_id(vertex_id);
  }

  for (const auto& vertex_info : vertices_info_) {
    auto& vertex_info_proto = *proto.add_vertices_info();
    if (holds_alternative<StopVertexInfo>(vertex_info)) {
      const auto& stop_name = get<StopVertexInfo>(vertex_info).stop_name;
      vertex_info_proto.mutable_stop_data()->set_stop_name(stop_name);
    } else {
      vertex_info_proto.mutable_company_data()->set_company_id(get<CompanyVertexInfo>(vertex_info).company_id);
    }
  }

  for (const auto& edge_info : edges_info_) {
    auto& edge_info_proto = *proto.add_edges_info();
    if (holds_alternative<BusEdgeInfo>(edge_info)) {
      const auto& bus_edge_info = get<BusEdgeInfo>(edge_info);
      auto& bus_edge_info_proto = *edge_info_proto.mutable_bus_data();
      bus_edge_info_proto.set_bus_name(bus_edge_info.bus_name);
      bus_edge_info_proto.set_start_stop_idx(bus_edge_info.start_stop_idx);
      bus_edge_info_proto.set_finish_stop_idx(bus_edge_info.finish_stop_idx);
    } else if (holds_alternative<CompanyEdgeInfo>(edge_info)) {
      const auto& company_edge_info = get<CompanyEdgeInfo>(edge_info);
      auto& company_edge_info_proto = *edge_info_proto.mutable_company_data();
      company_edge_info_proto.set_stop_name(company_edge_info.stop_name);
      company_edge_info_proto.set_company_id(company_edge_info.company_id);
    } else {
      edge_info_proto.mutable_wait_data();
    }
  }
}

unique_ptr<TransportRouter> TransportRouter::Deserialize(const TCProto::TransportRouter& proto) {
  unique_ptr<TransportRouter> router_holder(new TransportRouter);  // ctor is private, so can't use make_unique
  TransportRouter& router = *router_holder;

  auto& routing_settings = router.routing_settings_;
  routing_settings.bus_wait_time = proto.routing_settings().bus_wait_time();
  routing_settings.bus_velocity = proto.routing_settings().bus_velocity();

  router.graph_ = BusGraph::Deserialize(proto.graph());
  router.router_ = Router::Deserialize(proto.router(), router.graph_);

  for (const auto& stop_vertex_ids_proto : proto.stops_vertex_ids()) {
    router.stops_vertex_ids_[stop_vertex_ids_proto.name()] = {
        stop_vertex_ids_proto.in(),
        stop_vertex_ids_proto.out(),
    };
  }

  router.companies_vertex_id_.reserve(proto.companies_vertex_id_size());
  for (const Graph::VertexId vertex_id : proto.companies_vertex_id()) {
    router.companies_vertex_id_.push_back(vertex_id);
  }

  router.vertices_info_.reserve(proto.vertices_info_size());
  for (const auto& vertex_info_proto : proto.vertices_info()) {
    if (vertex_info_proto.has_company_data()) {
      router.vertices_info_.push_back(CompanyVertexInfo{vertex_info_proto.company_data().company_id()});
    } else {
      router.vertices_info_.push_back(StopVertexInfo{vertex_info_proto.stop_data().stop_name()});
    }
  }

  router.edges_info_.reserve(proto.edges_info_size());
  for (const auto& edge_info_proto : proto.edges_info()) {
    auto& edge_info = router.edges_info_.emplace_back();
    if (edge_info_proto.has_bus_data()) {
      const auto& bus_info_proto = edge_info_proto.bus_data();
      edge_info = BusEdgeInfo{
          bus_info_proto.bus_name(),
          bus_info_proto.start_stop_idx(),
          bus_info_proto.finish_stop_idx(),
      };
    } else if (edge_info_proto.has_company_data()) {
      const auto& company_info_proto = edge_info_proto.company_data();
      edge_info = CompanyEdgeInfo{
          company_info_proto.stop_name(),
          company_info_proto.company_id(),
      };
    } else {
      edge_info = WaitEdgeInfo{};
    }
  }

  return router_holder;
}

optional<TransportRouter::RouteInfo> TransportRouter::MakeRouteInfo(
    Graph::VertexId vertex_from,
    Graph::VertexId vertex_to,
    optional<double> company_wait_time
) const {
  const auto route = router_->BuildRoute(vertex_from, vertex_to);
  if (!route) {
    return nullopt;
  }

  if (company_wait_time && IsZero(*company_wait_time)) {
    company_wait_time = nullopt;
  }

  RouteInfo route_info = {
      .total_time = route->weight + company_wait_time.value_or(0)
  };
  route_info.items.reserve(route->edge_count + company_wait_time.has_value());
  optional<YellowPages::CompanyId> company_id;
  for (size_t edge_idx = 0; edge_idx < route->edge_count; ++edge_idx) {
    const Graph::EdgeId edge_id = router_->GetRouteEdge(route->id, edge_idx);
    const auto& edge = graph_.GetEdge(edge_id);
    const auto& edge_info = edges_info_[edge_id];
    if (holds_alternative<BusEdgeInfo>(edge_info)) {
      const BusEdgeInfo& bus_edge_info = get<BusEdgeInfo>(edge_info);
      RouteInfo::RideBusItem i;
      i.time = edge.weight;
      i.bus_name = bus_edge_info.bus_name;
      i.start_stop_idx = bus_edge_info.start_stop_idx;
      i.finish_stop_idx = bus_edge_info.finish_stop_idx;
      i.span_count = i.finish_stop_idx - i.start_stop_idx;
      route_info.items.push_back(i);
    } else if (holds_alternative<CompanyEdgeInfo>(edge_info)) {
      const CompanyEdgeInfo& company_edge_info = get<CompanyEdgeInfo>(edge_info);
      RouteInfo::WalkToCompanyItem i;
      i.time = edge.weight;
      i.stop_name = company_edge_info.stop_name;
      i.company_id = company_edge_info.company_id;
      route_info.items.push_back(i);
      company_id = company_edge_info.company_id;
    } else if (holds_alternative<WaitEdgeInfo>(edge_info)) {
      const Graph::VertexId vertex_id = edge.from;
      RouteInfo::WaitBusItem i;
      i.time = edge.weight;
      i.stop_name = get<StopVertexInfo>(vertices_info_[vertex_id]).stop_name;
      route_info.items.push_back(i);
    }
  }

  if (company_wait_time) {
    RouteInfo::WaitCompanyItem i;
    i.time = *company_wait_time;
    i.company_id = *company_id;
    route_info.items.push_back(i);
  }

  // Releasing in destructor of some proxy object would be better,
  // but we do not expect exceptions in normal workflow
  router_->ReleaseRoute(route->id);
  return route_info;
}

optional<TransportRouter::RouteInfo> TransportRouter::FindRoute(const string& stop_from, const string& stop_to) const {
  const Graph::VertexId vertex_from = stops_vertex_ids_.at(stop_from).out;
  const Graph::VertexId vertex_to = stops_vertex_ids_.at(stop_to).out;
  return MakeRouteInfo(vertex_from, vertex_to);
}

optional<TransportRouter::RouteInfo> TransportRouter::FindRouteToCompany(
    const WeekDayTime& datetime,
    const string& stop_from,
    const YellowPages::Companies& companies
) const {
  const Graph::VertexId vertex_from = stops_vertex_ids_.at(stop_from).out;

  optional<double> min_route_weight;
  optional<Graph::VertexId> nearest_company_vertex_id;
  double best_company_wait_time = 0;
  for (const auto* company : companies) {
    const Graph::VertexId vertex_to = companies_vertex_id_[company->id()];
    if (auto weight = router_->GetBestRouteWeight(vertex_from, vertex_to)) {
      const double company_wait_time = YellowPages::ComputeMinutesToNearestInterval(
          ToWeekMinutes(datetime) + *weight,
          company->working_time()
      );
      *weight += company_wait_time;
      if (!min_route_weight || *weight < *min_route_weight) {
        min_route_weight = weight;
        nearest_company_vertex_id = vertex_to;
        best_company_wait_time = company_wait_time;
      }
    }
  }

  if (!nearest_company_vertex_id) {
    return nullopt;
  } else {
    return MakeRouteInfo(vertex_from, *nearest_company_vertex_id, best_company_wait_time);
  }
}
