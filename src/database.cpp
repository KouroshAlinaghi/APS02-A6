#include <iostream>
#include <algorithm>

#include "database.hpp"
#include "custom_exception.hpp"
#include "time_mission.hpp"
#include "distance_mission.hpp"
#include "count_mission.hpp"

using namespace std;

#define p(x) cout << x << endl

Driver* Database::get_driver(int driver_id) {
    for (Driver* driver : drivers)
            if (driver->get_id() == driver_id)
                return driver;

    return nullptr;    
}

Driver* Database::get_or_create_driver(int driver_id) {
    if (get_driver(driver_id))
        return get_driver(driver_id);
    
    Driver* new_driver = new Driver(driver_id);
    drivers.push_back(new_driver);
    return new_driver;
}

Mission* Database::get_mission(int mission_id) {
    for (Mission* mission : missions)
        if (mission->get_id() == mission_id)
            return mission;

    return nullptr;
}

void Database::assign_mission(int mission_id, int driver_id) {
    Mission* mission = get_mission(mission_id);
    if (!mission)
        throw CustomException("MISSION_NOT_FOUND");

    Driver* driver = get_or_create_driver(driver_id);
    for (DriverMission* dm : driver_missions)
        if (dm->get_driver() == driver and dm->get_mission() == mission)
            throw CustomException("DUPLICATE_DRIVER_MISSION");

    DriverMission* driver_mission = new DriverMission(driver, mission);

    driver_missions.push_back(driver_mission);
    sort(driver_missions.begin(), driver_missions.end(), [](DriverMission* m1, DriverMission* m2) { return m1->get_mission()->get_start_time() < m2->get_mission()->get_start_time(); });
    cout << "OK" << endl;
}

void Database::record_ride(Timestamp start, Timestamp end, int driver_id, int distance) {
    Driver* driver = get_driver(driver_id);
    if (!driver) return;
    if (end < start) throw CustomException("INVALID_ARGUMENTS");

    Ride* ride = new Ride(start, end, driver, distance);
    rides.push_back(ride);
    cout << "completed missions for driver " << driver_id << ":" << endl;
    int stupid_counter = 0;
    for (DriverMission* dm : driver_missions) {
        if (dm->is_done()) continue;
        if (!dm->get_mission()->includes_ride(*ride)) continue;
        if (dm->get_driver() == driver) dm->update_stats(*ride);
        if (dm->get_driver() == driver && dm->is_done()) {
            if (stupid_counter) cout << endl;
            stupid_counter++;
            dm->get_mission()->print(end);
        }
    }
}

void Database::print_driver_missions(int driver_id) {
    if (!get_driver(driver_id))
        throw CustomException("DRIVER_MISSION_NOT_FOUND");

    cout << "missions status for driver " << driver_id << ":" << endl;
    int stupid_counter = 0;
    for (DriverMission* dm : driver_missions)
        if (dm->get_driver()->get_id() == driver_id) {
            if (stupid_counter) cout << endl;
            stupid_counter++;
            dm->get_mission()->print_with_details(dm->is_done(), dm->get_finisher_timestamp());
        }
}

void Database::add_mission(MISSION_TYPES type, int mission_id, Timestamp start, Timestamp end, int component, int reward_amount) {
    if (get_mission(mission_id)) throw CustomException("DUPLICATE_MISSION_ID");
    if (start > end or component < 0 or reward_amount < 0) throw CustomException("INVALID_ARGUMENTS");
    Mission* new_mission;
    switch (type) {
        case TIME_MISSION:
            new_mission = new TimeMission(mission_id, start, end, component, reward_amount);
            break;
        case DISTANCE_MISSION:
            new_mission = new DistanceMission(mission_id, start, end, component, reward_amount);
            break;
        case COUNT_MISSION:
            new_mission = new CountMission(mission_id, start, end, component, reward_amount);
            break;
    }
    missions.push_back(new_mission);
    cout << "OK" << endl;
}
