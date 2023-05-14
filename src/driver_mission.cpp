#include "driver_mission.hpp"

Driver* DriverMission::get_driver() {
    return driver;
}

Mission* DriverMission::get_mission() {
    return mission;
}

bool DriverMission::is_done() {
    if (done) return done;
    done = mission->is_completed(this);
    return done;
}

void DriverMission::update_stats(Ride ride) {
    distance_covered += ride.get_distance();
    minutes_spent += ride.get_minutes();
    total_rides_count++;
}

int DriverMission::get_distance_covered() {
    return distance_covered;
}

int DriverMission::get_minutes_spent() {
    return minutes_spent;
}

int DriverMission::get_total_rides_count() {
    return total_rides_count;
}