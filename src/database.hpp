#ifndef DATABASE_HEADERFILE
#define DATABASE_HEADERFILE

#include <vector>

#include "driver.hpp"
#include "ride.hpp"
#include "mission.hpp"
#include "driver_mission.hpp"

class Database {
private:
    std::vector<Driver*> drivers;
    std::vector<Ride*> rides;
    std::vector<Mission*> missions;
    std::vector<DriverMission*> driver_missions;
    Driver* get_or_create_driver(int driver_id);
    Driver* get_driver(int driver_id);
    Mission* get_mission(int mission_id);
public:
    Database() {
        drivers.empty();
        rides.empty();
        missions.empty();
    }
    void assign_mission(int driver_id, int mission_id);
    void record_ride(Timestamp start, Timestamp end, int driver_id, int distance);
    void print_driver_missions(int driver_id);
    void add_mission(MISSION_TYPES type, int mission_id, Timestamp start, Timestamp end, int component, int reward_amount);
};

#endif
