#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QIntValidator>
#include <QDoubleValidator>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QStandardItem>

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QThread>

#include <QSettings>

#include "../../DataModel.h"
#include "../../OrderModel.h"
#include "../../Protocol.h"
#include "../../ActionProtocol.h"
#include "../../ParametersProtocol.h"
#include "../../TransmitController.h"
#include "../../Keeper.h"

#include "specordermodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
     void com_connected_signal();
     void com_disconneted_signal();

private slots:
    void on_pushButton_com_clicked();

    void on_pushButton_reset_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_start_clicked();

    void on_pushButton_singleStart_clicked();

    void com_conneted();

    void com_disconneted();

    void on_tableView_order_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    //QStringListModel* model_;
    QStandardItemModel* spec_model_;
    QSerialPort serial_;
    OrderModel order_model_;

    bool serial_connected_;
    QString serial_receive_data_;

    void serial_init();
    void serial_connect(const QSerialPortInfo &info);
    void serial_disconnect();
    void transmit(const OrderModel& order);
    void receive();

    void interface_init();
    void update_list();

    DataModel make_data_model();

    void write_settings();
    void read_settings();

};

#endif // MAINWINDOW_H
