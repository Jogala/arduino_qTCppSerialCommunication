#ifndef ARDUINO_H
#define ARDUINO_H

#include <QObject>
#include <QString>
#include <QSerialPort>

class Arduino: public QObject
{
    Q_OBJECT

protected:
    QSerialPort itsPort;

public:
    Arduino();

    bool connect(QString comPort);
    void disconnect();



    QString read();

public slots:
    void HighLow(int pin, int level);
};

#endif // ARDUINO_H





