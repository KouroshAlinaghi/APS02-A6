#include <iostream>

#include "general.hpp"

using namespace std;

string trim(string str) {
    size_t first = str.find_first_not_of(' ');
    if (first == string::npos)
        return str;
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

vector<string> split(string str, char delim) {
    if (str.back() == 13) str.pop_back();
    vector<string> res;
    string cur = "";
    for (char c : str) 
        if (cur.size() and (c == delim or c == '\n'))
            res.push_back(trim(cur)), cur = "";
        else
            cur += c;

    if (cur.size()) res.push_back(trim(cur));

    return res;
}

MISSION_TYPES get_mission_type(std::string cmd) {
    if (cmd == "add_time_mission")
        return MISSION_TYPES::TIME_MISSION;
    if (cmd == "add_distance_mission")
        return MISSION_TYPES::DISTANCE_MISSION;
        
    return MISSION_TYPES::COUNT_MISSION;
}
