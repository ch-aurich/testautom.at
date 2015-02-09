#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>
#include <QSettings>

class settings_reader
{
public:
    settings_reader();
    settings_reader(QString name);
    QSettings *settings;
private:
    QString settings_filename;
    void load_settings();
};

#endif // SETTINGS_H
