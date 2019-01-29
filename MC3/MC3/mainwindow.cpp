#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model_ = new QStringListModel(this);

    interface_init();

}

MainWindow::~MainWindow()
{
    delete model_;
    delete ui;
}


void MainWindow::interface_init() {
    ui->lineEdit_volume->setValidator(new QIntValidator);
    ui->lineEdit_feedrate->setValidator(new QIntValidator);
    ui->lineEdit_reverse->setValidator(new QIntValidator);
    ui->lineEdit_ratioA->setValidator(new QDoubleValidator);
    ui->lineEdit_ratioA->setValidator(new QDoubleValidator);
    ui->lineEdit_accel->setValidator(new QIntValidator);
    ui->lineEdit_gearA->setValidator(new QDoubleValidator);
    ui->lineEdit_gearB->setValidator(new QDoubleValidator);
    ui->comboBox_dozators->addItem("Два дозатора");
    ui->comboBox_dozators->addItem("Дозатор А");
    ui->comboBox_dozators->addItem("Дозатор B");

    serial_init();
    update_list();
}

void MainWindow::serial_init() {
    serial_connected_ = false;
    serial_.setParity(QSerialPort::NoParity);
    serial_.setBaudRate(QSerialPort::Baud19200);
    serial_.setDataBits(QSerialPort::Data8);
    serial_.setStopBits(QSerialPort::OneStop);

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        ui->comboBox_com->addItem(info.portName());
    }
}

void MainWindow::serial_connect(const QSerialPortInfo &info) {

    serial_.setPort(info);
    if (serial_.open(QIODevice::ReadWrite)) {
        //
        //serial.close();
    }
}

void MainWindow::serial_disconnect() {
    serial_.close();
}

void MainWindow::transmit(const OrderModel& order) {
    TransmitController ctrl(order);
    while (!ctrl.is_empty()) {
        std::string command = ctrl.get_command();
        serial_.write(command.data(), command.size());
    }
}

void MainWindow::update_list() {

    order_model_.emplace_back(DataModel('0', 111000, 222000, 33000, 99, 44.44, 5555, 1, 1, false));
    order_model_.emplace_back(DataModel('1', 123456, 999999, 1000, 50, 444.4, 5555, 1, 2, true));
    order_model_.emplace_back(DataModel('2', 999999, 1000, 123456, 1, 4.444, 5555, 2, 1, false));
    order_model_.emplace_back(DataModel('2', 2000, 22000, 2010, 75, 4.444, 5555, 100, 1, true));
    order_model_.emplace_back(DataModel('2', 2000, 22000, 2010, 75, 4.444, 5555, 100, 1, true));
    order_model_.emplace_back(DataModel('2', 2000, 22000, 2010, 75, 444.4, 5555, 100, 1, false));

    QStringList list;

    for (auto model : order_model_) {
        std::string str = model.to_print();
        list.append(QString::fromUtf8(str.data(), str.size()));
    }

    model_->setStringList(list);
    ui->listView_order->setModel(model_);

    //delete model;
}

void MainWindow::on_pushButton_com_clicked()
{
    if (serial_connected_) {
        ui->pushButton_com->setText("Подключить");
        serial_disconnect();
        serial_connected_ = false;
    }
    else {
        ui->pushButton_com->setText("Отключить");
        if (ui->comboBox_com->count() > 0) {
            QString port = ui->comboBox_com->currentText();
            foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
                if (info.portName() == port) {
                    serial_connect(info);
                    serial_connected_ = true;
                    break;
                }
            }
        }
    }
}
