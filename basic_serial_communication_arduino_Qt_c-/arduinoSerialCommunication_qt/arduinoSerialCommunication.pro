#-------------------------------------------------
#
# Project created by QtCreator 2015-01-03T13:13:15
#
#-------------------------------------------------

QT       += core gui\
            serialport


CONFIG  += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = arduinoSerialCommunication
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    globalobjectes.cpp

HEADERS  += mainwindow.h \
    globalobjectes.h

FORMS    += mainwindow.ui
