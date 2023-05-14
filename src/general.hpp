#ifndef GENERAL_HEADERFILE
#define GENERAL_HEADERFILE

#include <vector>
#include <string>

#include "mission.hpp"

std::string trim(std::string str);
std::vector<std::string> split(std::string str, char delim);
MISSION_TYPES get_mission_type(std::string cmd);

#endif