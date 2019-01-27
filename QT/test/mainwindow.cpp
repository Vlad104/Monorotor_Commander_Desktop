#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QStandardItem>

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_com, SIGNAL (released()),this, SLOT (on_pushButton_com_clicked()));

    serial_init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::serial_init() {
    serial.setParity(QSerialPort::NoParity);
    serial.setBaudRate(QSerialPort::Baud19200);
    serial.setDataBits(QSerialPort::Data8);
    serial.setStopBits(QSerialPort::OneStop);

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        ui->comboBox->addItem(info.portName());
    }
}

void MainWindow::serial_connect(const QSerialPortInfo &info) {

    serial.setPort(info);
    if (serial.open(QIODevice::ReadWrite)) {
        //
        //serial.close();
    }
}

void MainWindow::serial_disconnect() {
    serial.close();
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this, "fddddd", "fddddd");
}

void MainWindow::on_pushButton_com_clicked()
{
    ui->pushButton_com->setText("Отключить");
    if (ui->comboBox->count() > 0) {
        QString port = ui->comboBox->currentText();
        foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
            if (info.portName() == port) {
                serial_connect(info);
                break;
            }
        }
    }

}

void MainWindow::on_pushButton_add_clicked()
{
    //ui->tableView->setModel();
}

void MainWindow::on_pushButton_transmit_clicked()
{
    QString qV = ui->lineEdit->text();
    QString qF = ui->lineEdit_2->text();
    QString qRa = ui->lineEdit_3->text();
    QString qRb = ui->lineEdit_5->text();
    QString qRev = ui->lineEdit_4->text();

    //std::string V = qV.toUtf8().constData();
    //std::string F = qF.toUtf8().constData();
    //std::string R = qR.toUtf8().constData();
    //std::string Rev = qRev.toUtf8().constData();

    uint32_t iV = qV.toUInt();
    uint32_t iF = qF.toUInt();
    double iRa = qRa.toDouble();
    double iRb = qVRb.toDouble();
    uint32_t iRev = qRev.toUInt();

    char dozators = '2';
    uint32_t iA = 20000;
    double Wa = 2000;
    double Wb = 2000;
    bool dir = true;


    OrderModel order;
    order.emplace_back(DataModel(dozators, iV, iF, iA, iRev, Wa, Wb, iRa, iRb, dir));
    transmit(order);
}

void MainWindow::transmit(const OrderModel& order) {
    TransmitController ctrl(order);
    while (!ctrl.is_empty()) {
        std::string command = ctrl.get_command();
        std::cout << command << std::endl;
        serial.write(command.data(), command.size());
    }
}
