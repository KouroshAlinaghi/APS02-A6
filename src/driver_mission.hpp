#ifndef DRIVER_MISSION_HEADERFILE
#define DRIVER_MISSION_HEADERFILE

#include "timestamp.hpp"
class Mission;

#include "driver.hpp"
#include "mission.hpp"
#include "ride.hpp"

class DriverMission {
private:
    Driver* driver;
    Mission* mission;
    bool done;
    Timestamp finisher_timestamp;
    int distance_covered, minutes_spent, total_rides_count;
public:
    DriverMission(Driver* driver_, Mission* mission_) {
        driver = driver_;
        mission = mission_;
        done = false;
        distance_covered = 0;
        minutes_spent = 0;
        total_rides_count = 0;
    }
    Driver* get_driver();
    Mission* get_mission();
    bool is_done();
    void update_stats(Ride ride);
    int get_distance_covered();
    int get_minutes_spent();
    int get_total_rides_count();
    Timestamp get_finisher_timestamp();
};

#endif
