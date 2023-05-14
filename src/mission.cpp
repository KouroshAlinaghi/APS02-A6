#include <iostream>

#include "mission.hpp"

using namespace std;

int Mission::get_id() {
    return id;
}

Timestamp Mission::get_start_time() {
    return start_time;
}

Timestamp Mission::get_end_time() {
    return end_time;
}

void Mission::print(Timestamp finisher_end_timestamp) {
    cout << "mission: " << id << endl;
    cout << "start timestamp: " << start_time << endl;
    cout << "end timestamp: " << finisher_end_timestamp << endl;
    cout << "reward: " << reward_amount << endl << endl;
}

void Mission::print_with_details(bool completed) {
    cout << "mission: " << id << endl;
    cout << "start timestamp: " << start_time << endl;
    cout << "reward: " << reward_amount << endl;
    cout << "status: " << (completed ? "completed" : "ongoing") << endl << endl;
}

bool Mission::includes_ride(Ride ride) {
    return (ride.get_start_time() >= start_time and ride.get_end_time() <= end_time);
}