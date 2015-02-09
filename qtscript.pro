#-------------------------------------------------
#
# Project created by QtCreator 2015-01-10T18:51:20
#
#-------------------------------------------------

QT       += core gui script sql serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtscript
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    childwindow.cpp \
    settings_reader.cpp \
    vitrek.cpp

HEADERS  += mainwindow.h \
    childwindow.h \
    settings_reader.h \
    vitrek.h

FORMS    += mainwindow.ui \
    childwindow.ui
