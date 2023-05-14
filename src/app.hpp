#ifndef APP_HEADERFILE
#define APP_HEADERFILE

#include <vector>
#include <map>

#include "database.hpp"
#include "command.hpp"

class App {
private:
    Database db;
    std::map<std::string, Command*> commands;
    void initialize_commands();
    void execute_command(std::string command, std::vector<std::string> arguments);
public:
    App() {
        initialize_commands();
    }
    void start();
};

#endif