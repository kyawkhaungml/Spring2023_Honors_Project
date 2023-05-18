#include "Day.h"
#include "Time.h"
#include <iostream>
using namespace std;

Day::Day()
{
    day_name = "Any Day";
}

//put all the schedules user put in into a class vector
void Day::set_Time()
{
    t.set_time(schedule_name, start_hour, start_minute, start_ampm, end_hour, end_minute, end_ampm);
//    for (int i = 0; i < time_vector.size(); i++)
//    {
//        taken_time.push_back(time_vector[i]);
//        taken_time[i].display_time();
//    }
    taken_time.push_back(t);
}

void Day::availablity()
{
    //copy the values in taken_time to available_time before sorting
    available_time = taken_time;

    int end_hour = available_time[0].get_start_hour();
    int end_minute = available_time[0].get_start_minute();

    for (int i = 0; i < available_time.size(); i++)
    {
        //if i reaches the available_time last index the function leads back to the starting time of the first schedule
        if (i == available_time.size() - 1)
        {
            int start_hour = available_time[i].get_end_hour();
            int start_minute = available_time[i].get_end_minute();
            available_time[i].set_start_hour(start_hour);
            available_time[i].set_start_minute(start_minute);
            available_time[i].set_end_hour(end_hour);
            available_time[i].set_end_minute(end_minute);
        }
        else
        {
            //set s_hour and s_minute to the ending time of the current schedule and set e_hour and e_minute to the starting time of the next schedule
            int s_hour = available_time[i].get_end_hour();
            int s_minute = available_time[i].get_end_minute();
            available_time[i].set_start_hour(s_hour);
            available_time[i].set_start_minute(s_minute);
            int e_hour = available_time[i+1].get_start_hour();
            int e_minute = available_time[i+1].get_start_minute();
            available_time[i].set_end_hour(e_hour);
            available_time[i].set_end_minute(e_minute);
        }
    }
}

void Day::available_display()
{
    cout << "\tAvailable Time:\n";
    for (int i = 0; i < available_time.size(); i++)
    {
        cout << available_time[i].get_start_hour() << ":" << available_time[i].get_start_minute() << "--" << available_time[i].get_end_hour() << ":" << available_time[i].get_end_minute() << endl;
    }
    cout << endl;
}


