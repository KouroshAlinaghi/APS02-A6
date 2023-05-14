#include "count_mission.hpp"

bool CountMission::is_completed(DriverMission* dm) {
    return dm->get_total_rides_count() >= target_number;
}