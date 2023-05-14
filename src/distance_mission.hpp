#ifndef DISTANCE_MISSION_HEADERFILE
#define DISTANCE_MISSION_HEADERFILE

#include "mission.hpp"

class DistanceMission : public Mission {
private:
    int target_distance_in_meters;
public:
    DistanceMission(int id_, Timestamp start_, Timestamp end_, int target_distance_in_meters_, int reward_)
    : Mission(id_, start_, end_, reward_) {
        target_distance_in_meters = target_distance_in_meters_;
    }
    bool is_completed(DriverMission* dm);
};

#endif
