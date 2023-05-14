#ifndef RIDE_HEADERFILE
#define RIDE_HEADERFILE

#include "timestamp.hpp"
#include "driver.hpp"

class Ride {
private:
    Driver* driver;
    int distance;
    Timestamp start_time, end_time;
public:
    Ride(Timestamp start_time_, Timestamp end_time_, Driver* driver_, int distance_) {
        driver = driver_;
        distance = distance_;
        start_time = start_time_;
        end_time = end_time_;
    }
    int get_distance();
    int get_minutes();
    Timestamp get_start_time();
    Timestamp get_end_time();
    Driver* get_driver();
};

#endif