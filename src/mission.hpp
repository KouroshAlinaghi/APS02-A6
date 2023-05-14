#ifndef MISSION_HEADERFILE
#define MISSION_HEADERFILE

class DriverMission;

#include "timestamp.hpp"
#include "ride.hpp"
#include "driver_mission.hpp"

enum MISSION_TYPES {
    TIME_MISSION, COUNT_MISSION, DISTANCE_MISSION
};

class Mission {
protected:
    int id;
    int reward_amount;
    Timestamp start_time, end_time;
public:
    Mission(int id_, Timestamp start_, Timestamp end_, int reward_) {
        id = id_;
        start_time = start_;
        end_time = end_;
        reward_amount = reward_;
    }
    int get_id();
    Timestamp get_start_time();
    Timestamp get_end_time();
    void print(Timestamp finisher_end_timestamp);
    void print_with_details(bool completed);
    bool includes_ride(Ride ride);
    virtual bool is_completed(DriverMission* dm) = 0;
};

#endif