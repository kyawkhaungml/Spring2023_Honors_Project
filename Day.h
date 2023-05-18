#ifndef DAY_H
#define DAY_H
#include <QMainWindow>
#include "Time.h"
#include <vector>

class Day : public Time
{
protected:
    QString day_name;
    Time t;
public:
    vector <Time> available_time;
    vector <Time> taken_time;
    Day();
    void set_Time();
    void availablity();
    void available_display();
};

#endif // DAY_H
