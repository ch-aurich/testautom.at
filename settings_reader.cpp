#include "settings_reader.h"
#include <QSettings>
#include <QApplication>
#include <QFile>

settings_reader::settings_reader()
{
    settings_filename = QApplication::applicationDirPath().left(1) + ":/setup.ini";
    load_settings();
}

settings_reader::settings_reader(QString name)
{
    settings_filename = name;
    QFile file( settings_filename );
    if (file.exists()){
        return;
    }
    else
    {
        settings_reader();
    }
    load_settings();
}


void settings_reader::load_settings()
{
    settings = new QSettings(settings_filename, QSettings::IniFormat);
}
