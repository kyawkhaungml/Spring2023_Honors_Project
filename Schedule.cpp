#include "Schedule.h"
#include <QString>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QTimeEdit"
#include <QMessageBox>
#include <QDir>
#include <QTimeEdit>
#include <QFile>
#include "Time.h"
#include "Day.h"
#include <QPalette>
#include <QPainter>
#include <QStringList>
#include <QT>
#include <string>

Schedule::Schedule()
{

}

void Schedule::set_counseling()
{
    //monday counseling schedule
    counseling_schedule[0].set_time("morning", 9, 0, "am", 12, 0, "pm");
    counseling_schedule[0].set_Time();
    counseling_schedule[0].set_time("mid_day", 12, 0, "pm", 3, 0, "pm");
    counseling_schedule[0].set_Time();
    counseling_schedule[0].set_time("afternoon", 3, 0, "pm", 5, 0, "pm");
    counseling_schedule[0].set_Time();
    //tuesday counseling schedule
    counseling_schedule[1].set_time("morning", 9, 0, "am", 12, 0, "pm");
    counseling_schedule[1].set_Time();
    counseling_schedule[1].set_time("mid_day", 12, 0, "pm", 3, 0, "pm");
    counseling_schedule[1].set_Time();
    counseling_schedule[1].set_time("afternoon", 3, 0, "pm", 5, 0, "pm");
    counseling_schedule[1].set_Time();
    //wednesday counseling schedule
    counseling_schedule[2].set_time("morning", 9, 0, "am", 12, 0, "pm");
    counseling_schedule[2].set_Time();
    counseling_schedule[2].set_time("mid_day", 12, 0, "pm", 3, 0, "pm");
    counseling_schedule[2].set_Time();
    counseling_schedule[2].set_time("afternoon", 3, 0, "pm", 5, 0, "pm");
    counseling_schedule[2].set_Time();
    //thursday counseling schedule
    counseling_schedule[3].set_time("morning", 9, 0, "am", 12, 0, "pm");
    counseling_schedule[3].set_Time();
    counseling_schedule[3].set_time("mid_day", 12, 0, "pm", 3, 0, "pm");
    counseling_schedule[3].set_Time();
    counseling_schedule[3].set_time("afternoon", 3, 0, "pm", 5, 0, "pm");
    counseling_schedule[3].set_Time();
    //friday counseling schedule
    counseling_schedule[4].set_time("morning", 9, 0, "am", 12, 0, "pm");
    counseling_schedule[4].set_Time();
    counseling_schedule[4].set_time("mid_day", 12, 0, "pm", 3, 0, "pm");
    counseling_schedule[4].set_Time();
    counseling_schedule[4].set_time("afternoon", 3, 0, "pm", 5, 0, "pm");
    counseling_schedule[4].set_Time();
}

void Schedule::set_mon_available()
{
//    day[0].availablity();
//    int length = counseling_schedule[0].taken_time.size();
//    bool check = false;

//        for (int j = 0; j < length; j++)
//        {

//            for (int i = 0; i < day[0].available_time.size(); i++)
//            {
//                int counseling_start = counseling_schedule[0].taken_time[j].get_start_hour();
//                int counseling_end = counseling_schedule[0].taken_time[j].get_end_hour();
//                int monday_start = day[0].available_time[i].get_start_hour();
//                int monday_end = day[0].available_time[i].get_start_hour();
//                QString counseling_startampm = counseling_schedule[0].taken_time[j].get_startampm();
//                QString monday_startampm = day[0].available_time[i].get_startampm();
//                QString counseling_endampm = counseling_schedule[0].taken_time[j].get_endampm();
//                QString monday_endampm = day[0].available_time[i].get_endampm();
//            }

//        }
//    QString start_hour = "fri_" + QString::number(i) + startampm.toLower();
//    QTextBrowser* startbrowser = this->findChild<QTextBrowser*>(start_hour);
//    startbrowser->setStyleSheet("background-color: orange")


}
