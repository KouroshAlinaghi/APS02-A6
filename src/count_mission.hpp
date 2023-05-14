#ifndef COUNT_MISSION_HEADERFILE
#define COUNT_MISSION_HEADERFILE

#include "mission.hpp"

class CountMission : public Mission {
private:
    int target_number;
public:
    CountMission(int id_, Timestamp start_, Timestamp end_, int target_number_, int reward_)
    : Mission(id_, start_, end_, reward_) {
        target_number = target_number_;
    }
    bool is_completed(DriverMission* dm);
};

#endif