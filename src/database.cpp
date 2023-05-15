#include <iostream>

#include "database.hpp"
#include "custom_exception.hpp"
#include "time_mission.hpp"
#include "distance_mission.hpp"
#include "count_mission.hpp"

using namespace std;

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

void Database::assign_mission(int driver_id, int mission_id) {
    Driver* driver = get_or_create_driver(driver_id);
    Mission* mission = get_mission(mission_id);
    if (!mission)
        throw CustomException("MISSION_NOT_FOUND");

    for (DriverMission* dm : driver_missions)
        if (dm->get_driver() == driver and dm->get_mission() == mission)
            throw CustomException("DUPLICATE_DRIVER_MISSION");

    DriverMission* driver_mission = new DriverMission(driver, mission);

    for (Ride* ride : rides)
        if (ride->get_driver() == driver and mission->includes_ride(*ride))
            driver_mission->update_stats(*ride);

    driver_missions.push_back(driver_mission);
    cout << "OK" << endl;
}

void Database::record_ride(Timestamp start, Timestamp end, int driver_id, int distance) {
    if (end < start) 
        throw CustomException("INVALID_ARGUMENTS");

    Driver* driver = get_driver(driver_id);
    if (!driver)
        throw CustomException("DRIVER_NOT_FOUND");

    Ride* ride = new Ride(start, end, driver, distance);
    bool found_mission = false;

    cout << "completed missions for driver " << driver_id << ":" << endl;

    for (DriverMission* dm : driver_missions) {
        if (dm->is_done()) continue;
        if (dm->get_driver() != driver) continue;
        found_mission = true;
        if (dm->is_done())
            dm->get_mission()->print(end);
    }

    if (found_mission)
        rides.push_back(ride);
}

void Database::print_driver_missions(int driver_id) {
    bool found_mission = false;
    for (DriverMission* dm : driver_missions)
        if (dm->get_driver()->get_id() == driver_id)
            found_mission = true;

    if (!found_mission)
        throw CustomException("DRIVER_MISSION_NOT_FOUND");

    cout << "missions status for driver " << driver_id << ":" << endl;

    for (DriverMission* dm : driver_missions) {
        if (dm->get_driver()->get_id() != driver_id) continue;
        found_mission = true;
        dm->get_mission()->print_with_details(dm->is_done());
    }
}

void Database::add_mission(MISSION_TYPES type, int mission_id, Timestamp start, Timestamp end, int component, int reward_amount) {
    if (start > end or component < 0 or reward_amount < 0) throw CustomException("INVALID_ARGUMENTS");
    if (get_mission(mission_id)) throw CustomException("DUPLICATE_MISSION_ID");
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
