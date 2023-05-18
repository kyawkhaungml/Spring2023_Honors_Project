#include "Time.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <iostream>
using namespace std;

//constructor
Time::Time()
{
    schedule_name = "Schedule";
    start_hour = 0;
    end_hour = 0;
    start_ampm = "AMPM";
    start_minute = 0;
    end_minute = 0;
    end_ampm = "AMPM";
}

//setters
void Time::set_time(QString name, int start_h, int start_m, QString start_name,
                    int end_h, int end_m, QString end_name)
{
    schedule_name = name;
    start_hour = start_h;
    start_minute = start_m;
    start_ampm = start_name;
    end_hour = end_h;
    end_minute = end_m;
    end_ampm = end_name;

}

void Time::set_start_hour(int start_h)
{
    start_hour = start_h;
}

void Time::set_start_minute(int start_m)
{
    start_minute = start_m;
}

void Time::set_end_hour(int end_h)
{
    end_hour = end_h;
}

void Time::set_end_minute(int end_m)
{
    end_minute = end_m;
}

//display output
void Time::display_time()
{
    cout << "\t" << schedule_name.toStdString() << ":\n";
    cout << start_hour << ":" << start_minute << " -- " << end_hour << ":" << end_minute << endl;
}

//getters
int Time::get_start_hour()
{
    return start_hour;
}

int Time::get_end_hour()
{
    return end_hour;
}

int Time::get_start_minute()
{
    return start_minute;
}

int Time::get_end_minute()
{
    return end_minute;
}

QString Time::get_startampm()
{
    return start_ampm;
}

QString Time::get_endampm()
{
    return end_ampm;
}
