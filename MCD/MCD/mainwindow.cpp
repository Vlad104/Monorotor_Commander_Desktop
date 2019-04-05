#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init_fields();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::init_fields() {
    ui->lineEdit_volume->setValidator(new QDoubleValidator);
    ui->lineEdit_feedrate->setValidator(new QDoubleValidator);
    ui->lineEdit_reverse->setValidator(new QDoubleValidator);
    ui->lineEdit_ratioA->setValidator(new QDoubleValidator);
    ui->lineEdit_ratioA->setValidator(new QDoubleValidator);
    ui->lineEdit_accel->setValidator(new QDoubleValidator);
    ui->lineEdit_gearA->setValidator(new QDoubleValidator);
    ui->lineEdit_gearB->setValidator(new QDoubleValidator);
    ui->comboBox_dozators->addItem("Два дозатора");
    ui->comboBox_dozators->addItem("Дозатор А");
    ui->comboBox_dozators->addItem("Дозатор B");

    QStringList ports_list = serial_.get_ports();
    ui->comboBox_com->addItems(ports_list);
}


void MainWindow::on_pushButton_com_clicked()
{
    if (serial_.get_status()) {
        ui->pushButton_com->setText("Подключить");
        ui->frame_transmit->setEnabled(false);
        serial_.disconnect();
    } else if (ui->comboBox_com->count() > 0) {
        ui->pushButton_com->setText("Отключить");
        ui->frame_transmit->setEnabled(true);
        QString port_name = ui->comboBox_com->currentText();
        serial_.connect(port_name);
    }
}

DataModel MainWindow::make_data_model() {
    int iD = ui->comboBox_dozators->currentIndex();
    double V = ui->lineEdit_volume->text().toDouble();
    double F = ui->lineEdit_feedrate->text().toDouble();
    double A = ui->lineEdit_accel->text().toDouble();
    //uint32_t R = ui->lineEdit_reverse->text().toUInt();
    double Wa = ui->lineEdit_gearA->text().toDouble();
    double Wb = ui->lineEdit_gearB->text().toDouble();
    double Ra = ui->lineEdit_ratioA->text().toDouble();
    double Rb = ui->lineEdit_ratioB->text().toDouble();
    //bool dir = ui->checkBox_dir->isChecked();

    char temp[3] = {'2', '0', '1'};
    char D = temp[iD];

    return DataModel(D, V, F, A, Wa, Wb, Ra, Rb);
}

// надо избавлять от этого
DataModel MainWindow::make_data_model_reverse() {
    int iD = ui->comboBox_dozators->currentIndex();
    double R = ui->lineEdit_reverse->text().toDouble();
    R *= -1;
    double F = ui->lineEdit_feedrate->text().toDouble();
    double A = ui->lineEdit_accel->text().toDouble();
    double Wa = ui->lineEdit_gearA->text().toDouble();
    double Wb = ui->lineEdit_gearB->text().toDouble();
    double Ra = ui->lineEdit_ratioA->text().toDouble();
    double Rb = ui->lineEdit_ratioB->text().toDouble();
    char temp[3] = {'2', '0', '1'};
    char D = temp[iD];

    return DataModel(D, R, F, A, Wa, Wb, Ra, Rb);
}

void MainWindow::on_pushButton_start_clicked()
{
    DataModel model_data = make_data_model() ;
    TransmitController transmit_data;
    transmit_data.get_start(model_data);
    serial_.transmit(transmit_data);

    // для реверса
    DataModel model_data_rev = make_data_model() ;
    TransmitController transmit_data_rev;
    transmit_data.get_start(model_data_rev);
    serial_.transmit(transmit_data_rev);
}
