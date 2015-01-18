#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "globalobjectes.h"
#include <QDebug>
#include <QByteArray>
#include <QThread>
#include <QShortcut>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QShortcut *shortcut = new QShortcut(QKeySequence("Ctrl+s"), this);
    QObject::connect(shortcut, SIGNAL(activated()),ui->pushButton_send,SLOT(click()));

            gSerial.setPortName("COM8");
            gSerial.open(QIODevice::ReadWrite);
            gSerial.setBaudRate(QSerialPort::Baud115200);
            gSerial.setDataBits(QSerialPort::Data8);
            gSerial.setParity(QSerialPort::NoParity);
            gSerial.setStopBits(QSerialPort::OneStop);
            gSerial.setFlowControl(QSerialPort::NoFlowControl);

}

MainWindow::~MainWindow()
{
    gSerial.close();
    delete ui;
}

void MainWindow::on_pushButton_send_clicked()
{

    if (gSerial.isOpen() && gSerial.isWritable())
    {

        QString message_out = ui->plainTextEdit_Message->toPlainText();

        QByteArray mByteAr = message_out.toUtf8();

        qDebug()<<mByteAr;

        gSerial.write(mByteAr);
        gSerial.waitForBytesWritten(1000);
        gSerial.flush();

        ui->plainTextEdit_History->appendPlainText(mByteAr);


    }
}

void MainWindow::on_pushButton_read_clicked()
{
    gSerial.waitForReadyRead(10);
    QByteArray answer = gSerial.read(1000);
    if(answer.length())
    {
        ui->plainTextEdit_Answer->appendPlainText(answer);
    }
}
