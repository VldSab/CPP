#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

void  NEW_BUS (const string& bus_name, const vector<string>& new_stops, map<string,vector<string>>& buses,
               vector<string>& bus_queue ){
    buses[bus_name] = new_stops;
    if (count(bus_queue.begin(), bus_queue.end(), bus_name) == 0){
        bus_queue.push_back(bus_name);
    }
}

void BUSES_FOR_STOP (const map<string,vector<string>>& buses, const string& stop_name, const vector<string>& bus_queue){
    vector<string> uniq_buses;
    for (const auto& [bus, stops_list] : buses){
        if (count(stops_list.begin(), stops_list.end(), stop_name) > 0){
            uniq_buses.push_back(bus);
            continue;
        }
    }
    if (uniq_buses.size() == 0){
        cout << "No stop " << endl;
    } else {
        for (const auto& queue : bus_queue){
            if (count(uniq_buses.begin(), uniq_buses.end(), queue) != 0){
                cout << queue << ' ';
            }
        }
    }
    cout << endl;
}

void STOPS_FOR_BUS (map<string,vector<string>>& buses, const string& bus_name, const vector<string>& bus_queue){
    vector<string> buses_on_station;
    int counter = 0;
    for (const auto& [k, v] : buses){
        if (bus_name == k){
            ++counter;
        }
    }
    if(counter > 0){
        for (const auto& station : buses[bus_name]){
            cout << "Stop " << station << ": ";
            for (const auto& [bus_from_list, station_from_list] : buses){
                if ((count(station_from_list.begin(), station_from_list.end(), station) != 0) &&
                (bus_from_list != bus_name)){
                    buses_on_station.push_back(bus_from_list);
                }
            }
            if (buses_on_station.size() == 0){
                cout << "no interchange";
            } else {
                for (const auto & queue : bus_queue){
                    if (count(buses_on_station.begin(), buses_on_station.end(), queue) != 0){
                        cout << queue << " ";
                    }
                }
                buses_on_station.clear();
            }
            cout << endl;
        }
    } else {
        cout << " No bus" << endl;
    }
}

void ALL_BUSES (const map<string,vector<string>>& buses){
    if (buses.size() != 0){
        for (const auto& [bus, stops] : buses){
            cout << "Bus " << bus << ": ";
            for (const auto& s : stops){
                cout << s << " ";
            }
            cout << endl;
        }
        cout << endl;
    } else {
        cout << " No buses" << endl;
    }
}


int main() {
    int stop_count = 0, n = 0, position = 0;
    string key, bus_name, stop_name;
    vector<string> stops, bus_queue;
    map<string,vector<string>> buses;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> key;
        if (key == "NEW_BUS"){
            cin >> bus_name;
            cin >> stop_count;
            stops.resize(stop_count);
            for (int j = 0; j < stop_count; ++j){
                cin >> stops[j];
                NEW_BUS(bus_name, stops, buses, bus_queue);
            }
            stops.clear();
        } else {
            if (key == "BUSES_FOR_STOP"){
                cin >> stop_name;
                BUSES_FOR_STOP(buses, stop_name, bus_queue);
            } else {
                if (key == "STOPS_FOR_BUS"){
                    cin >> bus_name;
                    STOPS_FOR_BUS(buses, bus_name, bus_queue);
                } else {
                    if (key == "ALL_BUSES"){
                        ALL_BUSES(buses);
                    }
                }
            }
        }
    }

    return 0;
}

