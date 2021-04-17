#include <iostream>
#include <map>
using namespace std;

void CHANGE_CAPITAL (const string& country_name, const string& new_capital, map<string, string>& countries){
    if (countries.count(country_name) == 0){
        countries[country_name] = new_capital;
        cout << "Introduce new country " << country_name << " with capital " << new_capital << endl;
    } else {
        if (countries[country_name] == new_capital){
            cout << "Country " <<  country_name << " hasn't changed its capital" << endl;
        } else {
            string old_capital = countries[country_name];
            countries[country_name] = new_capital;
            cout << "Country " << country_name << " has changed its capital from "
            << old_capital<< " to " << new_capital << endl;
        }
    }
}

void RENAME (map<string, string>& countries, const string& new_country_name, const string& country_name){
    if (country_name == new_country_name || countries.count(country_name) == 0 ||
    countries.count(new_country_name) == 1){
        cout << "Incorrect rename, skip" << endl;
    } else {
        countries[new_country_name] = countries[country_name];
        countries.erase(country_name);
        cout << "Country " << country_name << " with capital " << countries[new_country_name] <<
        " has been renamed to " << new_country_name << endl;
    }
}

void ABOUT (map<string, string>& countries, const string country_name){
    if (countries.count(country_name) == 0){
        cout << "Country " << country_name << " doesn't exist" << endl;
    } else {
        cout << "Country " << country_name << " has capital " << countries[country_name] << endl;
    }
}

void DUMP (const map<string, string>& countries){
    if (countries.size() == 0) {
        cout << "There are no countries in the world" << endl;
    } else {
        for (const auto& [key, value] : countries){
            cout << key << "/" << value << endl;
        }

    }
}

int main() {

    int n = 0;
    string request, country_name, new_capital, new_country_name;
    cin >> n;
    map<string, string> countries;
    for (int i = 0; i < n; ++i){
        cin >> request;
        if (request == "CHANGE_CAPITAL"){
            cin >> country_name;
            cin >> new_capital;
            CHANGE_CAPITAL(country_name, new_capital, countries);
        } else {
            if (request == "RENAME"){
                cin >> country_name;
                cin >> new_country_name;
                RENAME(countries, new_country_name, country_name);
            } else {
                if (request == "ABOUT"){
                    cin >> country_name;
                    ABOUT(countries, country_name);
                } else {
                    if (request == "DUMP"){
                        DUMP(countries);
                    }
                }
            }
        }
    }

    return 0;
}

