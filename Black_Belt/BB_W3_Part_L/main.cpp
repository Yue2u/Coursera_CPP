#include "descriptions.h"
#include "json.h"
#include "requests.h"
#include "sphere.h"
#include "transport_catalog.h"
#include "utils.h"

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream is("inp.json");
    ofstream os("out.json");

    const auto input_doc = Json::Load(is);
    const auto& input_map = input_doc.GetRoot().AsMap();

    const TransportCatalog db(
        Descriptions::ReadDescriptions(input_map.at("base_requests").AsArray()),
        input_map.at("routing_settings").AsMap(),
        input_map.at("render_settings").AsMap()
    );

    Json::PrintValue(
    Requests::ProcessAll(db, input_map.at("stat_requests").AsArray()),
    os
    );
    cout << endl;

    system("python change_svg_out.py");

  return 0;
}
