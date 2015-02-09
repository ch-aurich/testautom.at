#include "vitrek.h"

#include <stdio.h>


Vitrek::Vitrek(QWidget *parent)
{
    serial = new QSerialPort();

    serial->setPortName("/dev/ttyUSB0");


    if (serial->open(QIODevice::ReadWrite)) {
        printf("ok\n");
    } else {
        printf("not ok\n");
      //TODO: error handling!
    }

    serial->setBaudRate(115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);


    printf("name\n");
    serial->write("NAME,test\n");

    if (!serial->waitForBytesWritten(1000)) {
        /* timeout handling */
       }

    printf("close\n");
    serial->close();
}

void Vitrek::sequence_clear()
{
    serial->write("NOSEQ");
}

void Vitrek::sequence_set_name(QString name)
{
//    printf("name");
//    serial->write("NAME,test\n");
//    serial->close();
}
