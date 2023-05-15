#include <string>
#include <vector>

#include "custom_exception.hpp"
#include "command.hpp"
#include "general.hpp"

using namespace std;

void Command::validate_number_of_arguments(vector<string>& args) {
    if (num_of_args != (int)args.size() - 1) throw CustomException("INVALID_ARGUMENTS");
}

void AddMissionCommand::execute(Database& db, std::vector<std::string> args) {
    validate_number_of_arguments(args);
    MISSION_TYPES type = get_mission_type(args[0]);
    db.add_mission(type, stoi(args[1]), stoi(args[2]), stoi(args[3]), stoi(args[4]), stoi(args[5]));
}

void AssignMissionCommand::execute(Database& db, std::vector<std::string> args) {
    validate_number_of_arguments(args);
    db.assign_mission(stoi(args[1]), stoi(args[2]));
}

void RecordRideCommand::execute(Database& db, std::vector<std::string> args) {
    validate_number_of_arguments(args);
    db.record_ride(stoi(args[1]), stoi(args[2]), stoi(args[3]), stoi(args[4]));
}

void ShowMissionsStatusCommand::execute(Database& db, std::vector<std::string> args) {
    validate_number_of_arguments(args);
    db.print_driver_missions(stoi(args[1]));
}
