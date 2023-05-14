#include "distance_mission.hpp"

bool DistanceMission::is_completed(DriverMission* dm) {
    return dm->get_distance_covered() >= target_distance_in_meters;
}