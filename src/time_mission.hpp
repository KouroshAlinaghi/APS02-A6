#ifndef TIME_MISSION_HEADERFILE
#define TIME_MISSION_HEADERFILE

#include "mission.hpp"

class TimeMission : public Mission {
private:
    int target_time_in_minutes;
public:
    TimeMission(int id_, Timestamp start_, Timestamp end_, int target_time_in_minutes_, int reward_)
    : Mission(id_, start_, end_, reward_) {
        target_time_in_minutes = target_time_in_minutes_;
    }
    bool is_completed(DriverMission* dm);
};

#endif
