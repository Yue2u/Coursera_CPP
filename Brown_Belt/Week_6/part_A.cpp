#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>
#include <string>
#include <cmath>
#include <string_view>
using namespace std;


string_view RemoveSpaces(string_view line){

while (!line.empty() && line[0] == ' '){
line.remove_prefix(1);
}

while (!line.empty() && line.back() == ' '){
line.remove_suffix(1);
}

return line;
}

enum class BusType{
Reversive,
Circular
};

struct TypeHolder{
string_view name;
vector<string_view> stops = vector<string_view>(0);
BusType type = BusType::Reversive;
};


TypeHolder SplitStops(string_view line){
vector<string_view> result;

string_view name = line.substr(0, line.find_first_of(':'));
line.remove_prefix(line.find_first_of(':') + 1);

size_t pos = 0;
size_t delim_pos;
char ch = (line.find_first_of('-') == line.npos ? '>' : '-');

while(line.find_first_of(ch, pos) != line.npos){
delim_pos = line.find_first_of(ch, pos);
result.push_back(RemoveSpaces(line.substr(pos, delim_pos - pos)));
pos = delim_pos + 2;
}

result.push_back(RemoveSpaces(line.substr(pos, line.size() - pos)));

BusType bt;
bt = (ch == '-' ? BusType::Reversive : BusType::Circular);

return {name, result, bt};
}

struct Coordinates{

    Coordinates(double lattitude, double longtitude) : lat(lattitude), lon(longtitude){}

    Coordinates() = default;

double lat; // Широта
double lon;// Долгота
};

double ComputeRoute(Coordinates lhs, Coordinates rhs){
return acos(sin(lhs.lat) * sin(rhs.lat) +
 cos(lhs.lat) * cos(rhs.lat) *
 cos(abs(lhs.lon - rhs.lon))) * 6371000;
}

struct Stop{
string_view name;
Coordinates coordinates;
unordered_map<string_view, double> distance_to_stops;
};

double DegreeToRadian(double degree){
return degree * 3.1415926535 / 180.0;
}

unordered_map<string_view, double> SplitStopsDistance(string_view line){

    unordered_map<string_view, double> result;
while(!line.empty() && line.find_first_of(',') != line.npos){
    string_view distance = line.substr(0, line.find_first_of('m'));
    line.remove_prefix(line.find_first_of('m') + 3);
    string_view name = line.substr(line.find_first_of(' ') + 1, line.find_first_of(',') - line.find_first_of(' ') - 1);
    result[name] = stod(string(distance));
    line.remove_prefix(line.find_first_of(',') + 2);
}
    string_view distance = line.substr(0, line.find_first_of('m'));
    line.remove_prefix(line.find_first_of('m') + 3);
    string_view name = line.substr(line.find_first_of(' ') + 1, line.size() - line.find_first_of(' ') - 1);
    result[name] = stod(string(distance));
return result;
}

Stop SplitStopInfo(string_view line){

string_view name_s = line.substr(0, line.find_first_of(':'));
line.remove_prefix(line.find_first_of(':') + 1);
string_view lat = RemoveSpaces(line.substr(line.find_first_of(' '), line.find_first_of(',')));
line.remove_prefix(line.find_first_of(',') + 1);
if(line.find_first_of(',') != line.npos){
string_view lon = RemoveSpaces(line.substr(line.find_first_of(' '), line.find_first_of(',')));
line.remove_prefix(line.find_first_of(',') + 1);
auto d_t_s = SplitStopsDistance(RemoveSpaces(line));
return {name_s, {DegreeToRadian(stod(string(lat))) , DegreeToRadian(stod(string(lon)))}, d_t_s};
}
string_view lon = RemoveSpaces(line.substr(line.find_first_of(' '), line.size() - line.find_first_of(' ')));
return {name_s, {DegreeToRadian(stod(string(lat))) , DegreeToRadian(stod(string(lon)))}, {}};
}


class BusManager{
    public:

void Stops_For_Bus(string_view bus) const {

if(!buses.count(bus)){
    cout<<"Bus "<<bus<<": not found\n";
    return;
}

double route = 0;
double short_route = 0;
double curvature;
size_t vec_size = base.at(bus).size();

BusType bt = buses.at(bus);

size_t stops_amount;
size_t unique_stops_amount;

Coordinates prev_coordinates = stops.at(base.at(bus).at(0));
string_view prev_stop_name = base.at(bus).at(0);
if(bt == BusType::Reversive){

for(size_t i = 1;i < vec_size;++i){
    string_view curr_stop_name = base.at(bus).at(i);
    auto curr_coordinates = stops.at(curr_stop_name);
    if(route_between_stops.count(prev_stop_name) && route_between_stops.at(prev_stop_name).count(curr_stop_name)){
       route+= route_between_stops.at(prev_stop_name).at(curr_stop_name);
    }else {
        route+= ComputeRoute(prev_coordinates, curr_coordinates);
        }
     if(route_between_stops.count(curr_stop_name) && route_between_stops.at(curr_stop_name).count(prev_stop_name)){
       route+= route_between_stops.at(curr_stop_name).at(prev_stop_name);
    }else {
        route+= ComputeRoute(prev_coordinates, curr_coordinates);
        }

short_route+= ComputeRoute(prev_coordinates, curr_coordinates);
prev_coordinates = curr_coordinates;
prev_stop_name = curr_stop_name;
}
    short_route*= 2;
    stops_amount = base.at(bus).size() * 2 - 1;
}
else{

for(size_t i = 1;i < vec_size;++i){
string_view curr_stop_name = base.at(bus).at(i);
auto curr_coordinates = stops.at(curr_stop_name);
if(route_between_stops.count(prev_stop_name) && route_between_stops.at(prev_stop_name).count(curr_stop_name)){
       route+= route_between_stops.at(prev_stop_name).at(curr_stop_name);
    }else {
        route+= ComputeRoute(prev_coordinates, curr_coordinates);
        }
short_route+= ComputeRoute(prev_coordinates, curr_coordinates);
prev_coordinates = curr_coordinates;
prev_stop_name = curr_stop_name;
}
    stops_amount = base.at(bus).size();
}

unordered_set<string_view> stops_(base.at(bus).begin(), base.at(bus).end());
unique_stops_amount = stops_.size();

curvature = route / short_route;

cout<<fixed<<"Bus "<<bus<<": "<<stops_amount<<" stops on route, "<<unique_stops_amount
<<" unique stops, "<<route<<" route length, "<<curvature<<" curvature\n";

}

void Buses_For_Stops(string_view stop) const {

if(!stops.count(stop)){
    cout<<"Stop "<<stop<<": not found\n";
    return;
}
if(!buses_for_stop.count(stop)){
  cout<<"Stop "<<stop<<": no buses\n";
  return;
}

const auto& buses =  buses_for_stop.at(stop);
cout<<"Stop "<<stop<<": buses ";
for(auto it = buses.begin();it != buses.end(); ++it){
cout<<*it;
it != prev(buses.end()) ? cout<<' ' : cout<<"\n";
}
}

void Add_New_Bus(TypeHolder&& th){
string_view bus_name = th.name;

base[bus_name].swap(th.stops);
buses[bus_name] = th.type;

const auto& stops = base[th.name];
for(auto stop : stops){
    buses_for_stop[stop].emplace(bus_name);
}
}

void Add_New_Stop(const Stop& stop){
    string_view name = stop.name;
stops[name] = stop.coordinates;
const auto& d_b_s = stop.distance_to_stops;
for(const auto& s : d_b_s){
    string_view stop_name = s.first;
    double distance = s.second;
   route_between_stops[name][stop_name] = distance;
   if(!route_between_stops.count(stop_name) || !route_between_stops.at(stop_name).count(name)){
    route_between_stops[stop_name][name] = distance;
   }
}

}

private:
unordered_map<string_view, vector<string_view>> base;
unordered_map<string_view, Coordinates> stops;
unordered_map<string_view, BusType> buses;
unordered_map<string_view, set<string_view>> buses_for_stop;
unordered_map<string_view, unordered_map<string_view, double>> route_between_stops;
};


void Perform_Modifying_Requests(BusManager& bm, const vector<string>& base){


for(size_t i = 0;i < base.size();++i){
string_view sv(base.at(i));
string_view type = sv.substr(0, sv.find_first_of(' '));

if(type == "Stop"){

sv.remove_prefix(sv.find_first_of(' '));
bm.Add_New_Stop(SplitStopInfo(RemoveSpaces(sv)));
}
else if (type == "Bus"){

sv.remove_prefix(sv.find_first_of(' '));
bm.Add_New_Bus(SplitStops(RemoveSpaces(sv)));
}
}
}

vector<string> Read_Requests(istream& is = cin){

size_t q;
cin>>q;
vector<string> result(q);
string line;
getline(is, line); //Фикс бага с пустой строкой

for(size_t i = 0; i < q;++i){
    getline(is, line);
    result[i] = move(line);
}

return move(result);
}


void Perform_Computing_Requests(const BusManager& bm, const vector<string>& base){

for(size_t i = 0;i < base.size(); ++i){
    string_view sv(base.at(i));
    if(sv.substr(0, sv.find_first_of(' ')) == "Bus"){
    sv.remove_prefix(sv.find_first_of(' '));
    bm.Stops_For_Bus(RemoveSpaces(sv));
    } else if (sv.substr(0, sv.find_first_of(' ')) == "Stop"){
    sv.remove_prefix(sv.find_first_of(' '));
    bm.Buses_For_Stops(RemoveSpaces(sv));
}

}
}

int main()
{

ios_base::sync_with_stdio(false);
cin.tie(nullptr);
cout.precision(6);

BusManager bm;

const auto Modifying_requests = Read_Requests();
Perform_Modifying_Requests(bm, Modifying_requests);


const auto Computing_Requests = Read_Requests();
Perform_Computing_Requests(bm, Computing_Requests);

    return 0;
}
