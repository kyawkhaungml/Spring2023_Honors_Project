#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Time.h"
#include "Day.h"
#include <QMainWindow>
#include <QTimeEdit>
#include "Schedule.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Day day;
    Schedule schedule;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_register_2_clicked();

    void on_next_button_clicked();

    void on_pushButton_clicked();

    void on_monday_add_clicked();

    void on_tuesday_add_clicked();

    void on_wednesday_add_clicked();

    void on_thursday_add_clicked();

    void on_friday_add_clicked();

    void set_schedule();

    void set_monday();

    void set_tuesday();

    void set_wednesday();

    void set_thursday();

    void set_friday();


    void on_get_appointment_clicked();

    void on_login_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
