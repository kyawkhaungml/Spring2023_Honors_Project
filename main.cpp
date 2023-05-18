#include "mainwindow.h"
#include <QtWidgets/QApplication>
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    //set the app stylesheet
    QApplication app(argc, argv);
    QFile stylesheetfile("/Users/kyawkhaungmyolwin/QT/Schedule_Builder/Obit.qss");
    stylesheetfile.open(QFile::ReadOnly);
    QString stylesheet = QLatin1String(stylesheetfile.readAll());
    app.setStyleSheet(stylesheet);

    MainWindow w;
    w.show();
    return app.exec();
}
