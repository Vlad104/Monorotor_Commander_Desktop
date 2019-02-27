#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//#include <QIntValidator>
#include <QDoubleValidator>
#include <QStringListModel>

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>
#include <QEventLoop>
#include <QSettings>
#include <QLineEdit>

#include "../../src/DataModel.h"
#include "../../src/OrderModel.h"
#include "../../src/Protocol.h"
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

    void on_pushButton_continues_clicked();

    void on_pushButton_continues_pressed_pressed();

    void on_pushButton_continues_pressed_released();

    void on_lineEdit_volume_selectionChanged();

    void on_pushButton_n1_clicked();

    void on_lineEdit_feedrate_selectionChanged();


    void on_lineEdit_ratioB_selectionChanged();

    void on_lineEdit_accel_selectionChanged();


    void on_lineEdit_gearB_selectionChanged();

    void on_pushButton_n2_clicked();

    void on_pushButton_n3_clicked();

    void on_pushButton_n4_clicked();

    void on_pushButton_n5_clicked();

    void on_pushButton_n6_clicked();

    void on_pushButton_n7_clicked();

    void on_pushButton_n8_clicked();

    void on_pushButton_n9_clicked();

    void on_pushButton_n11_clicked();

    void on_pushButton_n0_clicked();

    void on_pushButton_n12_clicked();

    void on_lineEdit_ratioA_selectionChanged();

    void on_lineEdit_gearA_selectionChanged();

private:
    Ui::MainWindow *ui;
    QStandardItemModel* spec_model_;
    QSerialPort serial_;
    OrderModel order_model_;
    TransmitController transmit_order_;

    bool serial_connected_;
    QString serial_receive_data_;

    QTimer* timer_;
    bool timeout_;

    QLineEdit* active_edit_;

    void serial_init();
    void serial_connect(const QSerialPortInfo &info);
    void serial_disconnect();
    void transmit();
    void interface_init();
    void update_list();

    DataModel make_data_model();

    void write_settings();
    void read_settings();

    void keyPressEvent(QKeyEvent *event);

};

#endif // MAINWINDOW_H
