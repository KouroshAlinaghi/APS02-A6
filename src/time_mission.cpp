#include "time_mission.hpp"

bool TimeMission::is_completed(DriverMission* dm) {
    return dm->get_minutes_spent() >= target_time_in_minutes;
}