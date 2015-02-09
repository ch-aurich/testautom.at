#ifndef VITREK_H
#define VITREK_H

#include <QString>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class Vitrek
{
public:
    Vitrek(QWidget *parent=0);

    //modify sequences
    void sequence_clear();
    //TODO:
    //void sequence_add(TODO);
    void sequence_recall(unsigned int step_number);
    void sequence_set_name(QString name);
    void sequence_save(unsigned int sequence_number);

    //control the device function
    void set_active_sequence(unsigned int sequence_number);
    void run_active_sequence();
    void abort_running_sequence();
    void continue_hold_sequence();

    //query status of the device
    bool is_running();
    unsigned int active_sequence();
    unsigned int active_step();
    unsigned int get_result();

    //error handling of the device
    void reset_error();
    unsigned int get_error();


private:
    //void connect();
    void disconnect();

    QSerialPort *serial;

};

#endif // VITREK_H
