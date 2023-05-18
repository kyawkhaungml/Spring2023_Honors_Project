#ifndef TIME_H
#define TIME_H
#include <QString>
#include <iostream>
using namespace std;
#include <string>

class Time
{
protected:
    int start_hour, start_minute;
    int end_hour, end_minute;
    QString schedule_name, start_ampm, end_ampm;
public:
    Time();
    int get_start_hour();
    int get_start_minute();
    int get_end_hour();
    int get_end_minute();
    QString get_startampm();
    QString get_endampm();
    void set_time(QString,int, int, QString, int, int, QString);
    void set_start_hour(int);
    void set_start_minute(int);
    void set_end_hour(int);
    void set_end_minute(int);
    void display_time();
};
#endif // TIME_H
