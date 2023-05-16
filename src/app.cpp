#include <iostream>
#include <string>
#include <vector>

#include "app.hpp"
#include "custom_exception.hpp"
#include "general.hpp"

using namespace std;

void App::initialize_commands() {
    commands.empty();
    commands["add_count_mission"] = new AddMissionCommand(COUNT_MISSION);
    commands["add_time_mission"] = new AddMissionCommand(TIME_MISSION);
    commands["add_distance_mission"] = new AddMissionCommand(DISTANCE_MISSION);
    commands["assign_mission"] = new AssignMissionCommand();
    commands["record_ride"] = new RecordRideCommand();
    commands["show_missions_status"] = new ShowMissionsStatusCommand();
}

void App::execute_command(string command, vector<string> arguments) {
    if (commands.find(command) == commands.end()) return;
    commands[command]->execute(db, arguments);
}

void App::start() {
    string new_line;
    while (getline(cin, new_line)) {
        vector<string> words = split(new_line, ' ');
        if (words.empty()) continue;
        try {
            execute_command(words.front(), words);
        } catch (CustomException& e) {
            cout << e.what() << endl;
        }
    }
}
