#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractButton>
#include <QPlainTextEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void update();

private slots:

    void on_pushButton_dig2_clicked(bool checked);

    void readFromArduinoAndUpdatePlainText();

    void on_pushButton_dig3_clicked(bool checked);

    void on_pushButton_dig4_clicked(bool checked);

    void on_pushButton_dig5_clicked(bool checked);

    void on_comboBox_pulseHighLow_dig2_currentIndexChanged(const QString &arg1);

    void on_pushButton_dig2_clicked();


private:
    Ui::MainWindow *ui;

    QPlainTextEdit * arduinoConsole;
};

#endif // MAINWINDOW_H
