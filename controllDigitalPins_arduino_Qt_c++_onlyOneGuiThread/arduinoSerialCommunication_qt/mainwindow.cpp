#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "globalobjectes.h"
#include <QDebug>
#include <QByteArray>
#include <QShortcut>
#include <QTimer>
#include <QtTest/QTest>
#include <QSignalMapper>
#include <QThread>
#include <math.h>
#include <QIODevice>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    arduinoConsole = ui->plainTextEdit_fromArduino;

    ui->pushButton_dig2->setText("1    --   Ext. Trig  --    2  ::  LOW");
    ui->pushButton_dig2->setStyleSheet("background-color: green");
    ui->spinBox_pulseDuration_dig2->setMaximum(10000);
    ui->spinBox_pulseDuration_dig2->setMinimum(100);
    ui->spinBox_pulseDuration_dig2->setValue(1000);


    ui->pushButton_dig3->setCheckable(true);
    ui->pushButton_dig3->setText("3 :: LOW");
    ui->pushButton_dig3->setStyleSheet("background-color: green");

    ui->pushButton_dig4->setCheckable(true);
    ui->pushButton_dig4->setText("4 :: LOW");
    ui->pushButton_dig4->setStyleSheet("background-color: green");

    ui->pushButton_dig5->setCheckable(true);
    ui->pushButton_dig5->setText("5 :: LOW");
    ui->pushButton_dig5->setStyleSheet("background-color: green");

    gArduino.connect("COM8");

    QShortcut *shortcut = new QShortcut(QKeySequence("Ctrl+2"), this);
    QObject::connect(shortcut, SIGNAL(activated()),ui->pushButton_dig2,SLOT(toggle()));

    //s.t. plainText edit gets updated as well
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this,SLOT(readFromArduinoAndUpdatePlainText()));
    timer->start(100);


}

MainWindow::~MainWindow()
{
    gArduino.disconnect();
    delete ui;
}


void MainWindow::update(){

    ui->plainTextEdit_fromArduino->appendPlainText(gArduino.read());

}

void MainWindow::on_pushButton_dig2_clicked(bool checked)
{

    if(ui->comboBox_pulseHighLow_dig2->currentText().operator ==("High/Low"))
    {
            if(checked)
            {
                ui->pushButton_dig2->setText("1    --   Ext. Trig  --    2  ::  HIGH");
                ui->pushButton_dig2->setStyleSheet("background-color: red");
            }
            else
            {
                ui->pushButton_dig2->setText("1    --   Ext. Trig  --    2  ::  LOW");
                ui->pushButton_dig2->setStyleSheet("background-color: green");
            }

            gArduino.HighLow(2,checked);
    }
}



void MainWindow::on_pushButton_dig3_clicked(bool checked)
{
    if(checked)
    {
        ui->pushButton_dig3->setText("3  ::  HIGH");
        ui->pushButton_dig3->setStyleSheet("background-color: red");
    }
    else
    {
        ui->pushButton_dig3->setText("3  ::  LOW");
        ui->pushButton_dig3->setStyleSheet("background-color: green");
    }

    int pin = 3;

    gArduino.HighLow(pin,checked);
}

void MainWindow::on_pushButton_dig4_clicked(bool checked)
{
    if(checked)
    {
        ui->pushButton_dig4->setText("4  ::  LOW");
        ui->pushButton_dig4->setStyleSheet("background-color: red");
    }
    else
    {
        ui->pushButton_dig4->setText("4  ::  LOW");
        ui->pushButton_dig4->setStyleSheet("background-color: green");
    }

    int pin = 4;

    gArduino.HighLow(pin,checked);
}

void MainWindow::on_pushButton_dig5_clicked(bool checked)
{
    if(checked)
    {
        ui->pushButton_dig5->setText("5  ::  LOW");
        ui->pushButton_dig5->setStyleSheet("background-color: red");
    }
    else
    {
        ui->pushButton_dig5->setText("5  ::  LOW");
        ui->pushButton_dig5->setStyleSheet("background-color: green");
    }

    int pin = 5;

    gArduino.HighLow(pin,checked);
}

void MainWindow::readFromArduinoAndUpdatePlainText()
{
    QString message = gArduino.read();
    if(message.length())arduinoConsole->appendPlainText(message);
}

void MainWindow::on_comboBox_pulseHighLow_dig2_currentIndexChanged(const QString &digitalOutPutMode)
{
    if(digitalOutPutMode.operator ==("Pulse"))
    {
        ui->spinBox_pulseDuration_dig2->setEnabled(1);
        ui->label_spinBox_pulsDuration_dig2->setEnabled(1);
        ui->pushButton_dig2->setCheckable(false);
    }

    if(digitalOutPutMode.operator ==( "High/Low"))
    {
        ui->spinBox_pulseDuration_dig2->setEnabled(0);
        ui->label_spinBox_pulsDuration_dig2->setEnabled(0);
        ui->pushButton_dig2->setCheckable(true);
    }
}

void MainWindow::on_pushButton_dig2_clicked()
{
    qDebug()<<"on_pushButton_dig2_clicked";
    if(ui->comboBox_pulseHighLow_dig2->currentText().operator ==("Pulse"))
    {

        gArduino.HighLow(2,1);
        QThread::msleep(ui->spinBox_pulseDuration_dig2->value());
        gArduino.HighLow(2,0);

    }

}

