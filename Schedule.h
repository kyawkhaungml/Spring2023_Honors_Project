#ifndef SCHEDULE_H
#define SCHEDULE_H
#include "Time.h"
#include "Day.h"
#include <vector>
class Schedule
{
protected:
    Day counseling_schedule[5];
public:
    Day day[5];
    Schedule();
    void set_mon_available();
    void set_tue_available();
    void set_wed_available();
    void set_thu_available();
    void set_fri_available();
    void set_counseling();
};

#endif // SCHEDULE_H
