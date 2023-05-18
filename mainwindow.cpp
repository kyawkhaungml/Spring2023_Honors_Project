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
#include <QDesktopServices>
#include <QUrl>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_register_2_clicked()
{
    //goes to another page when register button is clicked
    ui->stackedWidget->setCurrentIndex(1);

}


void MainWindow::on_next_button_clicked()
{
    //stores username and password
    QString username = ui->Username->text();
    QString password_confirm = ui->password_confirm->text();
    QString password = ui->password1->text();

    //if the two passwords are incorrect, the user will be asked again
    if (password != password_confirm)
    {
        QMessageBox::warning(this, "Password Incorrect", "Password doesn't match");

    }
    //else, the txt file with username will be created as well as 5 files to store data form 5 days(Mon - Fri)
    else
    {
        //gives string values for files' name
        QString folderPath = "/Users/kyawkhaungmyolwin/QT/Schedule_Builder";
        QString fileExtension = ".txt";
        QString filePath = folderPath + "/" + username + fileExtension;
        QString monday = folderPath +"/" + username + "_monday" + fileExtension;
        QString tuesday = folderPath +"/" + username + "_tuesday" + fileExtension;
        QString wednesday = folderPath +"/" + username + "_wednesday" + fileExtension;
        QString thursday = folderPath +"/" + username + "_thursday" + fileExtension;
        QString friday = folderPath +"/" + username + "_friday" + fileExtension;

        QFile file(filePath);
        QFile Monday(monday);
        QFile Tuesday(tuesday);
        QFile Wednesday(wednesday);
        QFile Thursday(thursday);
        QFile Friday(friday);

        //try-catch to validate file opening
        try
        {
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream stream(&file);
                stream << username << Qt::endl;
                stream << password_confirm << Qt::endl;
                file.close();

                qDebug() << "File created successfully";
                //if the file with username and password was created, 5 files for 5 days will also be created
                Monday.open(QIODevice::WriteOnly|QIODevice::Text);
                Tuesday.open(QIODevice::WriteOnly|QIODevice::Text);
                Wednesday.open(QIODevice::WriteOnly|QIODevice::Text);
                Thursday.open(QIODevice::WriteOnly|QIODevice::Text);
                Friday.open(QIODevice::WriteOnly|QIODevice::Text);
                //close all the files since we only want to create
                Monday.close();
                Tuesday.close();
                Wednesday.close();
                Thursday.close();
                Friday.close();
            } else {
                qDebug() << "Failed to create file";
            }
        } catch (const std:: exception& e)
        {
            qDebug() << "An exception occured: " << e.what();
        }

        ui->stackedWidget->setCurrentIndex(2);
    }
}


void MainWindow::on_pushButton_clicked()
{
    //    QTextBrowser* tbrowser = this->findChild<QTextBrowser*>("mon_9am");
    //    tbrowser->setStyleSheet("background-color: red");
    //    ui->mon_10am->setStyleSheet("background-color: lightblue");
    this->set_schedule();
    this->set_monday();
    this->set_tuesday();
    this->set_wednesday();
    this->set_thursday();
    this->set_friday();
    ui->stackedWidget->setCurrentIndex(3);

}


void MainWindow::on_monday_add_clicked()
{
    QString schedule_name = ui->monday_name->text();
    if (schedule_name.isEmpty())
    {
        QMessageBox::warning(nullptr, "Warning", "Please provide the name of the schedule");
    }
    else
    {
        QString username = ui->Username->text();
        QString folderPath = "/Users/kyawkhaungmyolwin/QT/Schedule_Builder";
        QString fileExtension = ".txt";
        QString monday = folderPath +"/" + username + "_monday" + fileExtension;
        QFile Monday(monday);
        try {
            if(Monday.open(QIODevice::Append | QIODevice::Text))
            {
                //storing values from starting time
                QTime from_time = ui->monday_from->time();
                int from_hour = from_time.hour();
                int from_minute = from_time.minute();
                QString start_ampm = (from_time.hour() < 12) ? "AM":"PM";
                if (start_ampm == "PM" && from_hour > 12)
                {
                    from_hour = from_hour % 12;
                }
                //storing values from ending time
                QTime end_time = ui->monday_to->time();
                int end_hour = end_time.hour();
                int end_minute = end_time.minute();
                QString end_ampm = (end_time.hour() < 12) ? "AM":"PM";
                if (end_ampm == "PM" && end_hour > 12)
                {
                    end_hour = end_hour % 12;
                }
                //stores the values into the monday txt file
                QTextStream stream(&Monday);
                //append the added schedule to the txt file
                stream << schedule_name << "\n" << from_hour << " " << from_minute << " " << start_ampm << " "
                       << end_hour << " "<< end_minute << " " << end_ampm << "\n";
                //stores the string of the schedule to a variable to display on text_browser
                QString line = "Monday\t" + schedule_name + "\t" + QString::number(from_hour) + ":" + QString::number(from_minute) + start_ampm + "--"
                               + QString::number(end_hour) + ":" + QString::number(end_minute) + end_ampm + "\n";
                ui-> schedule_display->append(line);
            }
            else
            {
                qDebug() << "Failed to create file ";
            }
        } catch (const std:: exception& e) {
            qDebug() << "An exception occured: " << e.what();
        }
        Monday.close();
    }
}


void MainWindow::on_tuesday_add_clicked()
{
    QString schedule_name = ui->tuesday_name->text();
    if (schedule_name.isEmpty())
    {
        QMessageBox::warning(nullptr, "Warning", "Please provide the name of the schedule");
    }
    else
    {
        QString username = ui->Username->text();
        QString folderPath = "/Users/kyawkhaungmyolwin/QT/Schedule_Builder";
        QString fileExtension = ".txt";
        QString tuesday = folderPath +"/" + username + "_tuesday" + fileExtension;
        QFile Tuesday(tuesday);
        try {
            if(Tuesday.open(QIODevice::Append | QIODevice::Text))
            {
                //storing values from starting time
                QTime from_time = ui->tuesday_from->time();
                int from_hour = from_time.hour();
                int from_minute = from_time.minute();
                QString start_ampm = (from_time.hour() < 12) ? "AM":"PM";
                if (start_ampm == "PM" && from_hour > 12)
                {
                    from_hour = from_hour % 12;
                }
                //storing values from ending time
                QTime end_time = ui->tuesday_to->time();
                int end_hour = end_time.hour();
                int end_minute = end_time.minute();
                QString end_ampm = (end_time.hour() < 12) ? "AM":"PM";
                if (end_ampm == "PM" && end_hour > 12)
                {
                    end_hour = end_hour % 12;
                }
                //stores the values into the monday txt file
                QTextStream stream(&Tuesday);
                //append the added schedule to the txt file
                stream << schedule_name << "\n" << from_hour << " " << from_minute << " " << start_ampm << " "
                       << end_hour << " " << end_minute << " " << end_ampm << "\n";
                //stores the string of the schedule to a variable to display on text_browser
                QString line = "Tuesday\t" + schedule_name + "\t" + QString::number(from_hour) + ":" + QString::number(from_minute) + start_ampm + "--"
                               + QString::number(end_hour) + ":" + QString::number(end_minute) + end_ampm + "\n";
                ui-> schedule_display->append(line);
            }
            else
            {
                qDebug() << "Failed to create file ";
            }
        } catch (const std:: exception& e) {
            qDebug() << "An exception occured: " << e.what();
        }
        Tuesday.close();
    }
}




void MainWindow::on_wednesday_add_clicked()
{
    QString schedule_name = ui->wednesday_name->text();
    if (schedule_name.isEmpty())
    {
        QMessageBox::warning(nullptr, "Warning", "Please provide the name of the schedule");
    }
    else
    {
        QString username = ui->Username->text();
        QString folderPath = "/Users/kyawkhaungmyolwin/QT/Schedule_Builder";
        QString fileExtension = ".txt";
        QString wednesday = folderPath +"/" + username + "_wednesday" + fileExtension;
        QFile Wednesday(wednesday);
        try {
            if(Wednesday.open(QIODevice::Append | QIODevice::Text))
            {
                //storing values from starting time
                QTime from_time = ui->wednesday_from->time();
                int from_hour = from_time.hour();
                int from_minute = from_time.minute();
                QString start_ampm = (from_time.hour() < 12) ? "AM":"PM";
                if (start_ampm == "PM" && from_hour > 12)
                {
                    from_hour = from_hour % 12;
                }
                //storing values from ending time
                QTime end_time = ui->wednesday_to->time();
                int end_hour = end_time.hour();
                int end_minute = end_time.minute();
                QString end_ampm = (end_time.hour() < 12) ? "AM":"PM";
                if (end_ampm == "PM" && end_hour > 12)
                {
                    end_hour = end_hour % 12;
                }
                //stores the values into the monday txt file
                QTextStream stream(&Wednesday);
                //append the added schedule to the txt file
                stream << schedule_name << "\n" << from_hour << " " << from_minute << " "
                       << start_ampm << " "
                       << end_hour << " " << end_minute << " " << end_ampm << "\n";
                //stores the string of the schedule to a variable to display on text_browser
                QString line = "Wednesday\t" + schedule_name + "\t" + QString::number(from_hour) + ":" + QString::number(from_minute) + start_ampm + "--"
                               + QString::number(end_hour) + ":" + QString::number(end_minute) + end_ampm + "\n";
                ui-> schedule_display->append(line);
            }
            else
            {
                qDebug() << "Failed to create file ";
            }
        } catch (const std:: exception& e) {
            qDebug() << "An exception occured: " << e.what();
        }
        Wednesday.close();
    }
}


void MainWindow::on_thursday_add_clicked()
{
    QString schedule_name = ui->thursday_name->text();
    if (schedule_name.isEmpty())
    {
        QMessageBox::warning(nullptr, "Warning", "Please provide the name of the schedule");
    }
    else
    {
        QString username = ui->Username->text();
        QString folderPath = "/Users/kyawkhaungmyolwin/QT/Schedule_Builder";
        QString fileExtension = ".txt";
        QString thursday = folderPath +"/" + username + "_thursday" + fileExtension;
        QFile Thursday(thursday);
        try {
            if(Thursday.open(QIODevice::Append | QIODevice::Text))
            {
                //storing values from starting time
                QTime from_time = ui->thursday_from->time();
                int from_hour = from_time.hour();
                int from_minute = from_time.minute();
                QString start_ampm = (from_time.hour() < 12) ? "AM":"PM";
                if (start_ampm == "PM" && from_hour > 12)
                {
                    from_hour = from_hour % 12;
                }
                //storing values from ending time
                QTime end_time = ui->thursday_to->time();
                int end_hour = end_time.hour();
                int end_minute = end_time.minute();
                QString end_ampm = (end_time.hour() < 12) ? "AM":"PM";
                if (end_ampm == "PM" && end_hour > 12)
                {
                    end_hour = end_hour % 12;
                }
                //stores the values into the monday txt file
                QTextStream stream(&Thursday);
                //append the added schedule to the txt file
                stream << schedule_name << "\n" << from_hour << " " << from_minute << " " << start_ampm
                       << " "
                       << end_hour << " " << end_minute << " " << end_ampm << "\n";
                //stores the string of the schedule to a variable to display on text_browser
                QString line = "Thursday\t" + schedule_name + "\t" + QString::number(from_hour) + ":" + QString::number(from_minute) + start_ampm + "--"
                               + QString::number(end_hour) + ":" + QString::number(end_minute) + end_ampm + "\n";
                ui-> schedule_display->append(line);
            }
            else
            {
                qDebug() << "Failed to create file ";
            }
        } catch (const std:: exception& e) {
            qDebug() << "An exception occured: " << e.what();
        }
        Thursday.close();
    }
}


void MainWindow::on_friday_add_clicked()
{
    QString schedule_name = ui->friday_name->text();
    if (schedule_name.isEmpty())
    {
        QMessageBox::warning(nullptr, "Warning", "Please provide the name of the schedule");
    }
    else
    {
        QString username = ui->Username->text();
        QString folderPath = "/Users/kyawkhaungmyolwin/QT/Schedule_Builder";
        QString fileExtension = ".txt";
        QString friday = folderPath +"/" + username + "_friday" + fileExtension;
        QFile Friday(friday);
        try {
            if(Friday.open(QIODevice::Append | QIODevice::Text))
            {
                //storing values from starting time
                QTime from_time = ui->friday_from->time();
                int from_hour = from_time.hour();
                int from_minute = from_time.minute();
                QString start_ampm = (from_time.hour() < 12) ? "AM":"PM";
                if (start_ampm == "PM" && from_hour > 12)
                {
                    from_hour = from_hour % 12;
                }
                //storing values from ending time
                QTime end_time = ui->friday_to->time();
                int end_hour = end_time.hour();
                int end_minute = end_time.minute();
                QString end_ampm = (end_time.hour() < 12) ? "AM":"PM";
                if (end_ampm == "PM" && end_hour > 12)
                {
                    end_hour = end_hour % 12;
                }
                //stores the values into the monday txt file
                QTextStream stream(&Friday);
                //append the added schedule to the txt file
                stream << schedule_name << "\n" << from_hour << " " << from_minute << " "
                       << start_ampm << " "
                       << end_hour << " " << end_minute << " " << end_ampm << "\n";
                //stores the string of the schedule to a variable to display on text_browser
                QString line = "Friday\t" + schedule_name + "\t" + QString::number(from_hour) + ":" + QString::number(from_minute) + start_ampm + "--"
                               + QString::number(end_hour) + ":" + QString::number(end_minute) + end_ampm + "\n";
                ui-> schedule_display->append(line);
            }
            else
            {
                qDebug() << "Failed to create file ";
            }
        } catch (const std:: exception& e) {
            qDebug() << "An exception occured: " << e.what();
        }
        Friday.close();
    }
}

void MainWindow::set_schedule()
{
    QString username = ui->Username->text();
    //gives string values for files' name
    QString folderPath = "/Users/kyawkhaungmyolwin/QT/Schedule_Builder";
    QString fileExtension = ".txt";
    QString monday = folderPath +"/" + username + "_monday" + fileExtension;
    QString tuesday = folderPath +"/" + username + "_tuesday" + fileExtension;
    QString wednesday = folderPath +"/" + username + "_wednesday" + fileExtension;
    QString thursday = folderPath +"/" + username + "_thursday" + fileExtension;
    QString friday = folderPath +"/" + username + "_friday" + fileExtension;

    QFile Monday(monday);
    QFile Tuesday(tuesday);
    QFile Wednesday(wednesday);
    QFile Thursday(thursday);
    QFile Friday(friday);

    try {
        if(Monday.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream mon(&Monday);
            while (!mon.atEnd())
            {
                QString name = Monday.readLine();
                QString line = Monday.readLine();
                QStringList parts = line.split(' ');
                //remove the empty parts
                parts.removeAll("");

                if (parts.size() == 6)
                {
                    int starth = parts[0].toInt();
                    int startm = parts[1].toInt();
                    QString startampm = parts[2];
                    int endh = parts[3].toInt();
                    int endm = parts[4].toInt();
                    QString endampm = parts[5];
                    //put the schedule in the class and taken_time vector
                    //                day.set_time(name, starth, startm, startampm, endh, endm, endampm);
                    //                day.set_Time();
                    schedule.day[0].set_time(name, starth, startm, startampm, endh, endm, endampm);
                    schedule.day[0].set_Time();
                    //color the selected schedule
                    if (startampm == "am" && endampm == "pm")
                    {
                        int ed = endh + 12;
                        for (int i = starth; i < ed; i++)
                        {
                            if (starth > 12)
                            {
                                QString start_hour = "mon_" + QString::number(i-12) + "pm";
                                QTextBrowser* startbrowser = this->findChild<QTextBrowser*>(start_hour);
                                startbrowser->setStyleSheet("background-color: orange");
                                startbrowser->setText(name);
                            }
                            else
                            {
                                QString start_hour = "mon_" + QString::number(i) + startampm.toLower();
                                QTextBrowser* startbrowser = this->findChild<QTextBrowser*>(start_hour);
                                startbrowser->setStyleSheet("background-color: orange");
                                startbrowser->setText(name);
                            }
                            //                    startbrowser->close();
                        }
                    }
                    else
                    {
                        for (int i = starth; i < endh; i++)
                        {
                            QString start_hour = "mon_" + QString::number(i) + startampm.toLower();
                            QTextBrowser* startbrowser = this->findChild<QTextBrowser*>(start_hour);
                            startbrowser->setStyleSheet("background-color: orange");
                            startbrowser->setText(name);
                            //                    startbrowser->close();
                        }
                    }
                    QString end_hour = "mon_" + QString::number(endh) + endampm.trimmed().toLower();
                    QTextBrowser* endbrowser = this->findChild<QTextBrowser*>(end_hour);
                    endbrowser->setStyleSheet("background-color:orange");
                    endbrowser->setText(name);
                    //                endbrowser->close();
                }
            }
            Monday.close();

        }
        else
        {
            qDebug() << "Failed to open file ";
        }
    } catch (const std:: exception& e) {
        qDebug() << "An exception occured: " << e.what();
    }
    try {
        if(Tuesday.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream tue(&Tuesday);
            while (!tue.atEnd())
            {
                QString name = Tuesday.readLine();
                QString line = Tuesday.readLine();
                QStringList parts = line.split(' ');
                //remove the empty parts
                parts.removeAll("");

                if (parts.size() == 6)
                {
                    int starth = parts[0].toInt();
                    int startm = parts[1].toInt();
                    QString startampm = parts[2];
                    int endh = parts[3].toInt();
                    int endm = parts[4].toInt();
                    QString endampm = parts[5];
                    //put the schedule in the class and taken_time vector
                    //                day.set_time(name, starth, startm, startampm, endh, endm, endampm);
                    //                day.set_Time();
                    schedule.day[1].set_time(name, starth, startm, startampm, endh, endm, endampm);
                    schedule.day[1].set_Time();
                    //color the selected schedule
                    if (startampm == "am" && endampm == "pm")
                    {
                        int ed = endh + 12;
                        for (int i = starth; i < ed; i++)
                        {
                            if (starth > 12)
                            {
                                QString start_hour = "tue_" + QString::number(i-12) + "pm";
                                QTextBrowser* startbrowser = this->findChild<QTextBrowser*>(start_hour);
                                startbrowser->setStyleSheet("background-color: orange");
                                startbrowser->setText(name);
                            }
                            else
                            {
                                QString start_hour = "tue_" + QString::number(i) + startampm.toLower();
                                QTextBrowser* startbrowser = this->findChild<QTextBrowser*>(start_hour);
                                startbrowser->setStyleSheet("background-color: orange");
                                startbrowser->setText(name);
                            }
                            //                    startbrowser->close();
                        }
                    }
                    else
                    {
                        for (int i = starth; i < endh; i++)
                        {
                            QString start_hour = "tue_" + QString::number(i) + startampm.toLower();
                            QTextBrowser* startbrowser = this->findChild<QTextBrowser*>(start_hour);
                            startbrowser->setStyleSheet("background-color: orange");
                            startbrowser->setText(name);
                            //                    startbrowser->close();
                        }
                    }

                    QString end_hour = "tue_" + QString::number(endh) + endampm.trimmed().toLower();
                    QTextBrowser* endbrowser = this->findChild<QTextBrowser*>(end_hour);
                    endbrowser->setStyleSheet("background-color:orange");
                    endbrowser->setText(name);
                    //                endbrowser->close();
                }
            }
            Tuesday.close();
        }
        else
        {
            qDebug() << "Failed to open file ";
        }
    } catch (const std:: exception& e) {
        qDebug() << "An exception occured: " << e.what();
    }
    try {
        if(Wednesday.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream wed(&Wednesday);
            while (!wed.atEnd())
            {
                QString name = Wednesday.readLine();
                QString line = Wednesday.readLine();
                QStringList parts = line.split(' ');
                //remove the empty parts
                parts.removeAll("");

                if (parts.size() == 6)
                {
                    int starth = parts[0].toInt();
                    int startm = parts[1].toInt();
                    QString startampm = parts[2];
                    int endh = parts[3].toInt();
                    int endm = parts[4].toInt();
                    QString endampm = parts[5];
                    //put the schedule in the class and taken_time vector
                    //                day.set_time(name, starth, startm, startampm, endh, endm, endampm);
                    //                day.set_Time();
                    schedule.day[2].set_time(name, starth, startm, startampm, endh, endm, endampm);
                    schedule.day[2].set_Time();
                    //color the selected schedule
                    if (startampm == "am" && endampm == "pm")
                    {
                        int ed = endh + 12;
                        for (int i = starth; i < ed; i++)
                        {
                            if (starth > 12)
                            {
                                QString start_hour = "wed_" + QString::number(i-12) + "pm";
                                QTextBrowser* startbrowser = this->findChild<QTextBrowser*>(start_hour);
                                startbrowser->setStyleSheet("background-color: orange");
                                startbrowser->setText(name);
                            }
                            else
                            {
                                QString start_hour = "wed_" + QString::number(i) + startampm.toLower();
                                QTextBrowser* startbrowser = this->findChild<QTextBrowser*>(start_hour);
                                startbrowser->setStyleSheet("background-color: orange");
                                startbrowser->setText(name);
                            }
                            //                    startbrowser->close();
                        }
                    }
                    else
                    {
                        for (int i = starth; i < endh; i++)
                        {
                            QString start_hour = "wed_" + QString::number(i) + startampm.toLower();
                            QTextBrowser* startbrowser = this->findChild<QTextBrowser*>(start_hour);
                            startbrowser->setStyleSheet("background-color: orange");
                            startbrowser->setText(name);
                            //                    startbrowser->close();
                        }
                    }

                    QString end_hour = "wed_" + QString::number(endh) + endampm.trimmed().toLower();
                    QTextBrowser* endbrowser = this->findChild<QTextBrowser*>(end_hour);
                    endbrowser->setStyleSheet("background-color:orange");
                    endbrowser->setText(name);
                    //                endbrowser->close();
                }
            }
            Wednesday.close();
        }
        else
        {
            qDebug() << "Failed to open file ";
        }
    } catch (const std:: exception& e) {
        qDebug() << "An exception occured: " << e.what();
    }

    try {
        if(Thursday.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream thu(&Thursday);
            while (!thu.atEnd())
            {
                QString name = Thursday.readLine();
                QString line = Thursday.readLine();
                QStringList parts = line.split(' ');
                //remove the empty parts
                parts.removeAll("");

                if (parts.size() == 6)
                {
                    int starth = parts[0].toInt();
                    int startm = parts[1].toInt();
                    QString startampm = parts[2];
                    int endh = parts[3].toInt();
                    int endm = parts[4].toInt();
                    QString endampm = parts[5];
                    //put the schedule in the class and taken_time vector
                    //                day.set_time(name, starth, startm, startampm, endh, endm, endampm);
                    //                day.set_Time();
                    schedule.day[3].set_time(name, starth, startm, startampm, endh, endm, endampm);
                    schedule.day[3].set_Time();
                    //color the selected schedule
                    if (startampm == "am" && endampm == "pm")
                    {
                        int ed = endh + 12;
                        for (int i = starth; i < ed; i++)
                        {
                            if (starth > 12)
                            {
                                QString start_hour = "thu_" + QString::number(i-12) + "pm";
                                QTextBrowser* startbrowser = this->findChild<QTextBrowser*>(start_hour);
                                startbrowser->setStyleSheet("background-color: orange");
                                startbrowser->setText(name);
                            }
                            else
                            {
                                QString start_hour = "thu_" + QString::number(i) + startampm.toLower();
                                QTextBrowser* startbrowser = this->findChild<QTextBrowser*>(start_hour);
                                startbrowser->setStyleSheet("background-color: orange");
                                startbrowser->setText(name);
                            }
                            //                    startbrowser->close();
                        }
                    }
                    else
                    {
                        for (int i = starth; i < endh; i++)
                        {
                            QString start_hour = "thu_" + QString::number(i) + startampm.toLower();
                            QTextBrowser* startbrowser = this->findChild<QTextBrowser*>(start_hour);
                            startbrowser->setStyleSheet("background-color: orange");
                            startbrowser->setText(name);
                            //                    startbrowser->close();
                        }
                    }

                    QString end_hour = "thu_" + QString::number(endh) + endampm.trimmed().toLower();
                    QTextBrowser* endbrowser = this->findChild<QTextBrowser*>(end_hour);
                    endbrowser->setStyleSheet("background-color:orange");
                    endbrowser->setText(name);
                    //                endbrowser->close();
                }
            }
            Thursday.close();
        }
        else
        {
            qDebug() << "Failed to open file ";
        }
    } catch (const std:: exception& e) {
        qDebug() << "An exception occured: " << e.what();
    }
    try {
        if(Friday.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream fri(&Friday);
            while (!fri.atEnd())
            {
                QString name = Friday.readLine();
                QString line = Friday.readLine();
                QStringList parts = line.split(' ');
                //remove the empty parts
                parts.removeAll("");

                if (parts.size() == 6)
                {
                    int starth = parts[0].toInt();
                    int startm = parts[1].toInt();
                    QString startampm = parts[2];
                    int endh = parts[3].toInt();
                    int endm = parts[4].toInt();
                    QString endampm = parts[5];
                    //put the schedule in the class and taken_time vector
                    //                day.set_time(name, starth, startm, startampm, endh, endm, endampm);
                    //                day.set_Time();
                    schedule.day[4].set_time(name, starth, startm, startampm, endh, endm, endampm);
                    schedule.day[4].set_Time();
                    //color the selected schedule
                    if (startampm == "am" && endampm == "pm")
                    {
                        int ed = endh + 12;
                        for (int i = starth; i < ed; i++)
                        {
                            if (starth > 12)
                            {
                                QString start_hour = "fri_" + QString::number(i-12) + "pm";
                                QTextBrowser* startbrowser = this->findChild<QTextBrowser*>(start_hour);
                                startbrowser->setStyleSheet("background-color: orange");
                                startbrowser->setText(name);
                            }
                            else
                            {
                                QString start_hour = "fri_" + QString::number(i) + startampm.toLower();
                                QTextBrowser* startbrowser = this->findChild<QTextBrowser*>(start_hour);
                                startbrowser->setStyleSheet("background-color: orange");
                                startbrowser->setText(name);
                            }
                            //                    startbrowser->close();
                        }
                    }
                    else
                    {
                        for (int i = starth; i < endh; i++)
                        {
                            QString start_hour = "fri_" + QString::number(i) + startampm.toLower();
                            QTextBrowser* startbrowser = this->findChild<QTextBrowser*>(start_hour);
                            startbrowser->setStyleSheet("background-color: orange");
                            startbrowser->setText(name);
                            //                    startbrowser->close();
                        }
                    }

                    QString end_hour = "fri_" + QString::number(endh) + endampm.trimmed().toLower();
                    QTextBrowser* endbrowser = this->findChild<QTextBrowser*>(end_hour);
                    endbrowser->setStyleSheet("background-color:orange");
                    endbrowser->setText(name);
                    //                endbrowser->close();
                }
            }
            Friday.close();
        }
        else
        {
            qDebug() << "Failed to open file ";
        }
    } catch (const std:: exception& e) {
        qDebug() << "An exception occured: " << e.what();
    }


}

void MainWindow::set_monday()
{
    bool morning = false;
    bool afternoon = false;
    bool evening = false;
    if((ui->mon_9am->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
        (ui->mon_10am->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
        (ui->mon_11am->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
        ui->mon_12pm->palette().color(QPalette::Base)!=QColor(255,165,0))
    {
        ui->mon_9am->setStyleSheet("background-color:lightblue");
        ui->mon_10am->setStyleSheet("background-color:lightblue");
        ui->mon_11am->setStyleSheet("background-color:lightblue");
        ui->mon_12pm->setStyleSheet("background-color:lightblue");
        morning = true;
    }


    if (morning)
    {
        if((ui->mon_1pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
            (ui->mon_2pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
            (ui->mon_3pm->palette().color(QPalette::Base)!=QColor(255,165,0)))
        {
            ui->mon_1pm->setStyleSheet("background-color:lightblue");
            ui->mon_2pm->setStyleSheet("background-color:lightblue");
            ui->mon_3pm->setStyleSheet("background-color:lightblue");
            afternoon = true;
        }
    }
        else
        {if ((ui->mon_12pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
                (ui->mon_1pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
                (ui->mon_2pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
                (ui->mon_3pm->palette().color(QPalette::Base)!=QColor(255,165,0))){
                ui->mon_12pm->setStyleSheet("background-color:lightblue");
                ui->mon_1pm->setStyleSheet("background-color:lightblue");
                ui->mon_2pm->setStyleSheet("background-color:lightblue");
                ui->mon_3pm->setStyleSheet("background-color:lightblue");
                afternoon = true;

            }
        }



    if (afternoon)
    {
        if((ui->mon_4pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
            (ui->mon_5pm->palette().color(QPalette::Base)!=QColor(255,165,0)))
        {
            ui->mon_4pm->setStyleSheet("background-color:lightblue");
            ui->mon_5pm->setStyleSheet("background-color:lightblue");
        }
    }
        else
        {if ((ui->mon_3pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
                (ui->mon_4pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
                (ui->mon_5pm->palette().color(QPalette::Base)!=QColor(255,165,0))){
                ui->mon_3pm->setStyleSheet("background-color:lightblue");
                ui->mon_4pm->setStyleSheet("background-color:lightblue");
                ui->mon_5pm->setStyleSheet("background-color:lightblue");
            }
        }

}

void MainWindow:: set_tuesday()
{
    bool morning = false;
    bool afternoon = false;
    bool evening = false;
    if((ui->tue_9am->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
        (ui->tue_10am->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
        (ui->tue_11am->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
        ui->tue_12pm->palette().color(QPalette::Base)!=QColor(255,165,0))
    {
        ui->tue_9am->setStyleSheet("background-color:lightblue");
        ui->tue_10am->setStyleSheet("background-color:lightblue");
        ui->tue_11am->setStyleSheet("background-color:lightblue");
        ui->tue_12pm->setStyleSheet("background-color:lightblue");
        morning = true;
    }


    if (morning)
    {
        if((ui->tue_1pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
            (ui->tue_2pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
            (ui->tue_3pm->palette().color(QPalette::Base)!=QColor(255,165,0)))
        {
            ui->tue_1pm->setStyleSheet("background-color:lightblue");
            ui->tue_2pm->setStyleSheet("background-color:lightblue");
            ui->tue_3pm->setStyleSheet("background-color:lightblue");
            afternoon = true;
        }
    }
        else
        {if ((ui->tue_12pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
                (ui->tue_1pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
                (ui->tue_2pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
                (ui->tue_3pm->palette().color(QPalette::Base)!=QColor(255,165,0))){
                ui->tue_12pm->setStyleSheet("background-color:lightblue");
                ui->tue_1pm->setStyleSheet("background-color:lightblue");
                ui->tue_2pm->setStyleSheet("background-color:lightblue");
                ui->tue_3pm->setStyleSheet("background-color:lightblue");
                afternoon = true;

            }
        }



    if (afternoon)
    {
        if((ui->tue_4pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
            (ui->tue_5pm->palette().color(QPalette::Base)!=QColor(255,165,0)))
        {
            ui->tue_4pm->setStyleSheet("background-color:lightblue");
            ui->tue_5pm->setStyleSheet("background-color:lightblue");
        }
    }
        else
        {if ((ui->tue_3pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
                (ui->tue_4pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
                (ui->tue_5pm->palette().color(QPalette::Base)!=QColor(255,165,0))){
                ui->tue_3pm->setStyleSheet("background-color:lightblue");
                ui->tue_4pm->setStyleSheet("background-color:lightblue");
                ui->tue_5pm->setStyleSheet("background-color:lightblue");
            }
        }

}

void MainWindow::set_wednesday()
{
    bool morning = false;
    bool afternoon = false;
    bool evening = false;
    if((ui->wed_9am->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
        (ui->wed_10am->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
        (ui->wed_11am->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
        ui->wed_12pm->palette().color(QPalette::Base)!=QColor(255,165,0))
    {
        ui->wed_9am->setStyleSheet("background-color:lightblue");
        ui->wed_10am->setStyleSheet("background-color:lightblue");
        ui->wed_11am->setStyleSheet("background-color:lightblue");
        ui->wed_12pm->setStyleSheet("background-color:lightblue");
        morning = true;
    }


    if (morning)
    {
        if((ui->wed_1pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
            (ui->wed_2pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
            (ui->wed_3pm->palette().color(QPalette::Base)!=QColor(255,165,0)))
        {
            ui->wed_1pm->setStyleSheet("background-color:lightblue");
            ui->wed_2pm->setStyleSheet("background-color:lightblue");
            ui->wed_3pm->setStyleSheet("background-color:lightblue");
            afternoon = true;
        }
    }
        else
        {if ((ui->wed_12pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
                (ui->wed_1pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
                (ui->wed_2pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
                (ui->wed_3pm->palette().color(QPalette::Base)!=QColor(255,165,0))){
                ui->wed_12pm->setStyleSheet("background-color:lightblue");
                ui->wed_1pm->setStyleSheet("background-color:lightblue");
                ui->wed_2pm->setStyleSheet("background-color:lightblue");
                ui->wed_3pm->setStyleSheet("background-color:lightblue");
                afternoon = true;

            }
        }



    if (afternoon)
    {
        if((ui->wed_4pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
            (ui->wed_5pm->palette().color(QPalette::Base)!=QColor(255,165,0)))
        {
            ui->wed_4pm->setStyleSheet("background-color:lightblue");
            ui->wed_5pm->setStyleSheet("background-color:lightblue");
        }
    }
        else
        {if ((ui->wed_3pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
                (ui->wed_4pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
                (ui->wed_5pm->palette().color(QPalette::Base)!=QColor(255,165,0))){
                ui->wed_3pm->setStyleSheet("background-color:lightblue");
                ui->wed_4pm->setStyleSheet("background-color:lightblue");
                ui->wed_5pm->setStyleSheet("background-color:lightblue");
            }
        }

}

void MainWindow::set_thursday()
{
    bool morning = false;
    bool afternoon = false;
    bool evening = false;
    if((ui->thu_9am->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
        (ui->thu_10am->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
        (ui->thu_11am->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
        ui->thu_12pm->palette().color(QPalette::Base)!=QColor(255,165,0))
    {
        ui->thu_9am->setStyleSheet("background-color:lightblue");
        ui->thu_10am->setStyleSheet("background-color:lightblue");
        ui->thu_11am->setStyleSheet("background-color:lightblue");
        ui->thu_12pm->setStyleSheet("background-color:lightblue");
        morning = true;
    }


    if (morning)
    {
        if((ui->thu_1pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
            (ui->thu_2pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
            (ui->thu_3pm->palette().color(QPalette::Base)!=QColor(255,165,0)))
        {
            ui->thu_1pm->setStyleSheet("background-color:lightblue");
            ui->thu_2pm->setStyleSheet("background-color:lightblue");
            ui->thu_3pm->setStyleSheet("background-color:lightblue");
            afternoon = true;
        }
    }
        else
        {if ((ui->thu_12pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
                (ui->thu_1pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
                (ui->thu_2pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
            (ui->thu_3pm->palette().color(QPalette::Base)!=QColor(255,165,0))){
                ui->thu_12pm->setStyleSheet("background-color:lightblue");
                ui->thu_1pm->setStyleSheet("background-color:lightblue");
                ui->thu_2pm->setStyleSheet("background-color:lightblue");
                ui->thu_3pm->setStyleSheet("background-color:lightblue");
                afternoon = true;

            }
        }



    if (afternoon)
    {
        if((ui->thu_4pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
                (ui->thu_5pm->palette().color(QPalette::Base)!=QColor(255,165,0)))
        {
            ui->thu_4pm->setStyleSheet("background-color:lightblue");
            ui->thu_5pm->setStyleSheet("background-color:lightblue");
        }
    }
        else
        {if ((ui->thu_3pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
                (ui->thu_4pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
            (ui->thu_5pm->palette().color(QPalette::Base)!=QColor(255,165,0))){
                ui->thu_3pm->setStyleSheet("background-color:lightblue");
                ui->thu_4pm->setStyleSheet("background-color:lightblue");
                ui->thu_5pm->setStyleSheet("background-color:lightblue");
            }
        }

}

void MainWindow::set_friday()
{
    bool morning = false;
    bool afternoon = false;
    bool evening = false;

    if((ui->fri_9am->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
        (ui->fri_10am->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
        (ui->fri_11am->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
        ui->fri_12pm->palette().color(QPalette::Base)!=QColor(255,165,0))
    {
        ui->fri_9am->setStyleSheet("background-color:lightblue");
        ui->fri_10am->setStyleSheet("background-color:lightblue");
        ui->fri_11am->setStyleSheet("background-color:lightblue");
        ui->fri_12pm->setStyleSheet("background-color:lightblue");
        morning = true;
    }


    if (morning)
    {
        if((ui->fri_1pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
            (ui->fri_2pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
            (ui->fri_3pm->palette().color(QPalette::Base)!=QColor(255,165,0)))
        {
            ui->fri_1pm->setStyleSheet("background-color:lightblue");
            ui->fri_2pm->setStyleSheet("background-color:lightblue");
            ui->fri_3pm->setStyleSheet("background-color:lightblue");
            afternoon = true;
        }
    }
        else
        {if ((ui->fri_12pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
                (ui->fri_1pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
                (ui->fri_2pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
                (ui->fri_3pm->palette().color(QPalette::Base)!=QColor(255,165,0))) {
                ui->fri_12pm->setStyleSheet("background-color:lightblue");
                ui->fri_1pm->setStyleSheet("background-color:lightblue");
                ui->fri_2pm->setStyleSheet("background-color:lightblue");
                ui->fri_3pm->setStyleSheet("background-color:lightblue");
                afternoon = true;

            }
        }



    if (afternoon)
    {
        if((ui->fri_4pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
            (ui->fri_5pm->palette().color(QPalette::Base)!=QColor(255,165,0)))
        {
            ui->fri_4pm->setStyleSheet("background-color:lightblue");
            ui->fri_5pm->setStyleSheet("background-color:lightblue");
        }
    }
        else
        {if ((ui->fri_3pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
                (ui->fri_4pm->palette().color(QPalette::Base)!=QColor(255,165,0)) &&
            (ui->fri_5pm->palette().color(QPalette::Base)!=QColor(255,165,0))){
                ui->fri_3pm->setStyleSheet("background-color:lightblue");
                ui->fri_4pm->setStyleSheet("background-color:lightblue");
                ui->fri_5pm->setStyleSheet("background-color:lightblue");
            }
        }

}



void MainWindow::on_get_appointment_clicked()
{
        QUrl url("https://forms.office.com/Pages/ResponsePage.aspx?id=s_BgbwZfCU6XFZiduozH2NNGPlqtzw9HneF5bgW6e19UNDlXSk5QOTBZQkM1Rzk4TUZXOTE0WVcxMi4u");  // Replace with the desired URL
        QDesktopServices::openUrl(url);
}


void MainWindow::on_login_clicked()
{
//        QString uname = ui->username->text();
//        QString folderPath = "/Users/kyawkhaungmyolwin/QT/Schedule_Builder";
//        QString fileExtension = ".txt";
//        QString uu = folderPath +"/" + uname + fileExtension;
//        QFile Username(uu);
//        try {
//            if(Username.open(QIODeviceBase::ReadOnly|QIODeviceBase::Text))
//            {
//                QString name = Username.readLine();
//                QString pass = Username.readLine().trimmed();
//                //remove the empty parts
//                QString p = ui->password_c->text();
//                if (p == pass)
//                {
//                ui->Username->text().trimmed() = name.trimmed();
//               this->on_next_button_clicked();
//                this->set_schedule();
//                this->set_monday();
//                this->set_tuesday();
//                this->set_wednesday();
//                this->set_thursday();
//                this->set_friday();
//                 ui->stackedWidget->setCurrentIndex(3);
//               this->on_pushButton_clicked();
//                }
//                else
//                {
//                qDebug() << "Password Incorrect";
//                qWarning()<<"Password" <<p << "incorrect.";
//                }
//            }
//            else
//            {
//                qDebug() << "Username doesn't exist";
//            }
//        } catch (const std:: exception& e) {
//            qDebug() << "An exception occured: " << e.what();
//        }
//        while (!fri.atEnd())
//        {
//           QString name = Friday.readLine();
//        }
        QString Name = ui->username->text();
        QString folderPath = "/Users/kyawkhaungmyolwin/QT/Schedule_Builder/";
        QString fileExtension = ".txt";
        QString username_file = folderPath + Name + fileExtension;
        QFile User(username_file);
        try {
            if(!User.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                throw QString("Username Not Found").arg(User.errorString());
            }
            QTextStream in(&User);
            while (!in.atEnd())
            {
                QString uname = in.readLine().trimmed();
                QString password = in.readLine().trimmed();
                QString password_match = ui->password_c->text().trimmed();
                // Process the line as needed
                qDebug() << uname;
                qDebug() << password;
                if(password == password_match)
                {
                this->on_pushButton_clicked();
                }
                else
                {
                QMessageBox::warning(this,"Warning", "Password Incorrect");
                }
            }
        } catch (const QString& error) {
            qDebug() << "Error:" << error;
            QMessageBox::warning(this,"Warning", "Password Incorrect");
        }
}

