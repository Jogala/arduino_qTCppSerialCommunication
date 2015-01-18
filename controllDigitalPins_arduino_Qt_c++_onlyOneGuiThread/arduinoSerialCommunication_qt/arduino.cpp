#include "arduino.h"
#include <QDebug>

Arduino::Arduino()
{

}

bool Arduino::connect(QString comPort)
{
    itsPort.setPortName(comPort);
    itsPort.open(QIODevice::ReadWrite);
    itsPort.setBaudRate(QSerialPort::Baud57600 );
    itsPort.setDataBits(QSerialPort::Data8);
    itsPort.setParity(QSerialPort::NoParity);
    itsPort.setStopBits(QSerialPort::OneStop);
    itsPort.setFlowControl(QSerialPort::NoFlowControl);

    return(itsPort.isOpen() && itsPort.isWritable());

    for(int i = 2; i<=13;i++)
    {
        HighLow(i,0);
    }
}

void Arduino::disconnect()
{
    itsPort.close();
}

void Arduino::HighLow(int pin, int level)
{

    qDebug()<<"HighLow LEAVING";

    QString messagePin = QString::number(pin);
    QString messageLevel = QString::number(level);

    QString message = "s"+messagePin+","+messageLevel;

    QByteArray mByteAr = message.toUtf8();

    itsPort.write(mByteAr,24);
    itsPort.waitForBytesWritten(1000);

    qDebug()<<"HighLow LEAVING";

}

QString Arduino::read()
{
    itsPort.waitForReadyRead(10);

    QByteArray answer = itsPort.read(1000);

    return(QString::fromUtf8(answer));
}
