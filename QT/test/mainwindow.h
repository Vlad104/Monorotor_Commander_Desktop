#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "../../DataModel.h"
#include "../../OrderModel.h"
#include "../../Protocol.h"
#include "../../ActionProtocol.h"
#include "../../ParametersProtocol.cpp"
#include "../../TransmitController.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_com_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_transmit_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort serial;

    void serial_init();
    void serial_connect(const QSerialPortInfo &info);
    void serial_disconnect();
    void transmit(const OrderModel& order);
};

#endif // MAINWINDOW_H
