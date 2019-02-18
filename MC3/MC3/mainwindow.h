#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QIntValidator>
#include <QDoubleValidator>
#include <QStringListModel>

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>
#include <QEventLoop>
#include <QSettings>

#include "../../src/DataModel.h"
#include "../../src/OrderModel.h"
#include "../../src/Protocol.h"
#include "../../src/ActionProtocol.h"
#include "../../src/ParametersProtocol.h"
#include "../../src/TransmitController.h"
#include "../../src/Keeper.h"

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

    void receive();

    void transmit_timeout();

    void on_tableView_order_doubleClicked(const QModelIndex &index);

    void on_pushButton_stop_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel* spec_model_;
    QSerialPort serial_;
    OrderModel order_model_;

    bool serial_connected_;
    QString serial_receive_data_;

    QTimer* timer_;
    bool timeout_;

    void serial_init();
    void serial_connect(const QSerialPortInfo &info);
    void serial_disconnect();
    void transmit(const OrderModel& order);
    void interface_init();
    void update_list();

    DataModel make_data_model();

    void write_settings();
    void read_settings();

};

#endif // MAINWINDOW_H
