#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QStandardItem>

#include <iostream>
#include "../../ParamCom.h"
#include "../../ActCom.h"

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
    QString qV = ui->lineEdit->text();
    QString qF = ui->lineEdit_2->text();
    QString qR = ui->lineEdit_3->text();
    QString qRev = ui->lineEdit_4->text();

    std::string V = qV.toUtf8().constData();
    std::string F = qF.toUtf8().constData();
    std::string R = qR.toUtf8().constData();
    std::string Rev = qRev.toUtf8().constData();

    Command* command = new ParamCom('2', V, F, R, Rev);
    std::string result;
    if (command->get_command(result)) {
        std::cout << result << std::endl;
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "ERROR 2" << std::endl;
    }
    delete command;
    QMessageBox::information(this, "fddddd", QString::fromUtf8(result.data(), result.size()));

    serial.write(result.data(), result.size());
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
