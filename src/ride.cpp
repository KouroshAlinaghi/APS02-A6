#include "ride.hpp"

int Ride::get_distance() {
    return distance;
}

int Ride::get_minutes() {
    return (end_time - start_time + 1) / 60;
}

Timestamp Ride::get_start_time() {
    return start_time;
}

Timestamp Ride::get_end_time() {
    return end_time;
}

Driver* Ride::get_driver() {
    return driver;
}
