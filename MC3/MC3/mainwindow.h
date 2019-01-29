#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QIntValidator>
#include <QDoubleValidator>
#include <QStringListModel>

#include <QSerialPort>
#include <QSerialPortInfo>

#include "../../DataModel.h"
#include "../../OrderModel.h"
#include "../../Protocol.h"
#include "../../ActionProtocol.h"
#include "../../ParametersProtocol.h"
#include "../../TransmitController.h"
#include "../../Keeper.h"

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
    void on_pushButton_com_clicked();

private:
    Ui::MainWindow *ui;
    QStringListModel* model_;
    QSerialPort serial_;
    OrderModel order_model_;

    bool serial_connected_;

    void serial_init();
    void serial_connect(const QSerialPortInfo &info);
    void serial_disconnect();
    void transmit(const OrderModel& order);

    void interface_init();
    void update_list();

};

#endif // MAINWINDOW_H
