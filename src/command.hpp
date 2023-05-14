#ifndef COMMAND_HEADERFILE
#define COMMAND_HEADERFILE

#include <vector>
#include <string>

#include "database.hpp"
#include "mission.hpp"

namespace arguments_count {
    const int ADD_MISSION = 5;
    const int ASSIGN_MISSION = 2;
    const int RECORD_RIDE = 4;
    const int SHOW_MISSIONS_STATUS = 1;
}

class Command {
protected:
    int num_of_args;
    void validate_number_of_arguments(std::vector<std::string>& args);
public:
    Command(int num_of_args_) {
        num_of_args = num_of_args_;
    }
    virtual void execute(Database& db, std::vector<std::string> args) = 0;
};

class AddMissionCommand : public Command {
private:
    MISSION_TYPES mission_type;
public:
    AddMissionCommand(MISSION_TYPES mission_type_) : Command(arguments_count::ADD_MISSION) {
        mission_type = mission_type_;
    }
    void execute(Database& db, std::vector<std::string> args);
};

class AssignMissionCommand : public Command {
public:
    AssignMissionCommand() : Command(arguments_count::ASSIGN_MISSION) {};
    void execute(Database& db, std::vector<std::string> args);
};

class RecordRideCommand : public Command {
public:
    RecordRideCommand() : Command(arguments_count::RECORD_RIDE) {};
    void execute(Database& db, std::vector<std::string> args);
};

class ShowMissionsStatusCommand : public Command {
public:
    ShowMissionsStatusCommand() : Command(arguments_count::SHOW_MISSIONS_STATUS) {};
    void execute(Database& db, std::vector<std::string> args);
};

#endif