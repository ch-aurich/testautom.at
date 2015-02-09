#include "mainwindow.h"
#include <QApplication>
#include <QtSql>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


//    QString settings_filename = QApplication::applicationDirPath() + "/setup.ini";
//    QSettings settings(settings_filename, QSettings::IniFormat);

//    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
//    db.setHostName(settings.value("database/host", "127.0.0.1").toString());
//    db.setDatabaseName(settings.value("database/database", "testautomat").toString());
//    db.setUserName(settings.value("database/username", "root").toString());
//    db.setPassword(settings.value("database/password", "").toString());

//    if (!db.open())
//    {
//      /*QMessageBox::critical(0, QObject::tr("Database Error"),
//                db.lastError().text());*/
//    }



//    MainWindow w(0, &db);
    MainWindow w(0);
    w.show();

    return a.exec();
}
