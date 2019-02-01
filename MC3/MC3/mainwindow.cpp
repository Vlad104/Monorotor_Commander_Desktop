#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //model_ = new QStringListModel(this);
    spec_model_ = nullptr;

    interface_init();

}

MainWindow::~MainWindow()
{
    write_settings();
    Keeper::save(order_model_);
    //delete model_;
    delete spec_model_;
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

    read_settings();

    Keeper::load(order_model_);

    serial_init();
    update_list();

    QObject::connect(this, SIGNAL(com_conneted_signal()), this, SLOT(com_conneted()));
    QObject::connect(this, SIGNAL(com_disconneted_signal()), this, SLOT(com_disconneted()));
}

void MainWindow::serial_init() {
    serial_connected_ = false;
    emit com_disconneted_signal(); // ?
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
        qDebug() << "connected";
        //
        //serial.close();
    }
}

void MainWindow::serial_disconnect() {
    serial_.close();
    qDebug() << "disconnected";
}

void MainWindow::transmit(const OrderModel& order) {
    TransmitController ctrl(order);
    while (!ctrl.is_empty()) {
        std::string command = ctrl.get_command();
        serial_.write(command.c_str());
        qDebug() << QString::fromUtf8(command.data(), command.size());
    }
}

void MainWindow::update_list() {

    /*
    QStringList list;
    for (auto& model : order_model_) {
        std::string str = model.to_print();
        list.append(QString::fromUtf8(str.data(), str.size()));
    }
    model_->setStringList(list);
    ui->listView_order->setModel(model_);
    */

    delete spec_model_;
    spec_model_ = new SpecOrderModel(order_model_);
    ui->tableView_order->setModel(spec_model_);

}

void MainWindow::com_conneted() {
    ui->pushButton_com->setText("Отключить");
    ui->pushButton_start->setEnabled(true);
    ui->pushButton_singleStart->setEnabled(true);
}

void MainWindow::com_disconneted() {
    ui->pushButton_com->setText("Подключить");
    ui->pushButton_start->setEnabled(false);
    ui->pushButton_singleStart->setEnabled(false);
}

void MainWindow::on_pushButton_com_clicked()
{
    if (serial_connected_) {
        serial_disconnect();
        serial_connected_ = false;
        emit com_disconneted();
    }
    else {
        if (ui->comboBox_com->count() > 0) {
            QString port = ui->comboBox_com->currentText();
            foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
                if (info.portName() == port) {
                    serial_connect(info);
                    serial_connected_ = true;
                    emit com_conneted();
                    break;
                }
            }
        }
    }
}

void MainWindow::on_pushButton_reset_clicked()
{
    order_model_.clear();
    update_list();
}

void MainWindow::on_pushButton_delete_clicked()
{
    int index = ui->tableView_order->currentIndex().row();
    auto it = order_model_.begin();
    for (int i = 0; i < index; i++) {
        ++it;
    }
    order_model_.erase(it);
    update_list();
}

DataModel MainWindow::make_data_model() {
    int iD = ui->comboBox_dozators->currentIndex();
    uint32_t V = ui->lineEdit_volume->text().toUInt();
    uint32_t F = ui->lineEdit_feedrate->text().toUInt();
    uint32_t A = ui->lineEdit_accel->text().toUInt();
    uint32_t R = ui->lineEdit_reverse->text().toUInt();
    double Wa = ui->lineEdit_gearA->text().toDouble();
    double Wb = ui->lineEdit_gearB->text().toDouble();
    double Ra = ui->lineEdit_ratioA->text().toDouble();
    double Rb = ui->lineEdit_ratioB->text().toDouble();
    bool dir = ui->checkBox_dir->isChecked();

    char D;
    switch (iD) {
    case 0:
        D = '2';
        break;
    case 1:
        D = '1';
        break;
    case 2:
        D = '0';
        break;
    default:
        D = '2';
        break;
    }

    return DataModel(D, V, F, A, R, Wa, Wb, Ra, Rb, dir);
}

void MainWindow::on_pushButton_add_clicked()
{
    order_model_.emplace_back(make_data_model());
    update_list();
}

void MainWindow::write_settings() {
    QSettings settings("Monorotor Commander", "MONOROTOR");

    settings.beginGroup("ui");
    settings.setValue("comboBox_dozators", ui->comboBox_dozators->currentIndex());
    settings.setValue("lineEdit_volume", ui->lineEdit_volume->text());
    settings.setValue("lineEdit_feedrate", ui->lineEdit_feedrate->text());
    settings.setValue("lineEdit_accel", ui->lineEdit_accel->text());
    settings.setValue("lineEdit_reverse", ui->lineEdit_reverse->text());
    settings.setValue("lineEdit_gearA", ui->lineEdit_gearA->text());
    settings.setValue("lineEdit_gearB", ui->lineEdit_gearB->text());
    settings.setValue("lineEdit_ratioA", ui->lineEdit_ratioA->text());
    settings.setValue("lineEdit_ratioB", ui->lineEdit_ratioB->text());
    settings.setValue("checkBox_dir", ui->checkBox_dir->isChecked());
    settings.endGroup();
}

void MainWindow::read_settings() {
    QSettings settings("Monorotor Commander", "MONOROTOR");

    settings.beginGroup("ui");
    ui->comboBox_dozators->setCurrentIndex(settings.value("comboBox_dozators", "0").toInt());
    ui->lineEdit_volume->setText(settings.value("lineEdit_volume", "0").toString());
    ui->lineEdit_feedrate->setText(settings.value("lineEdit_feedrate", "0").toString());
    ui->lineEdit_accel->setText(settings.value("lineEdit_accel", "0").toString());
    ui->lineEdit_reverse->setText(settings.value("lineEdit_reverse", "0").toString());
    ui->lineEdit_gearA->setText(settings.value("lineEdit_gearA", "0").toString());
    ui->lineEdit_gearB->setText(settings.value("lineEdit_gearB", "0").toString());
    ui->lineEdit_ratioA->setText(settings.value("lineEdit_ratioA", "0").toString());
    ui->lineEdit_ratioB->setText(settings.value("lineEdit_ratioB", "0").toString());
    ui->checkBox_dir->setChecked(settings.value("checkBox_dir", "0").toBool());
    settings.endGroup();
}

void MainWindow::on_pushButton_start_clicked()
{
    transmit(order_model_);
}

void MainWindow::on_pushButton_singleStart_clicked()
{
    OrderModel order;
    order.emplace_back(make_data_model());
    transmit(order);
}

void MainWindow::on_tableView_order_doubleClicked(const QModelIndex &index)
{
    int int_index = index.row();
    auto it = order_model_.begin();
    for (int i = 0; i < int_index; i++) {
        ++it;
    }
    char iD = it->get_dozators();
    uint32_t V = it->get_volume();
    uint32_t F = it->get_feedrate();
    uint32_t A = it->get_accel();
    uint32_t R = it->get_reverse();
    double Wa = it->get_gear_A();
    double Wb = it->get_gear_B();
    double Ra = it->get_ratio_A();
    double Rb = it->get_ratio_B();
    bool dir = it->get_direction();

    switch (iD) {
    case '2':
        ui->comboBox_dozators->setCurrentIndex(0);
        break;
    case '1':
        ui->comboBox_dozators->setCurrentIndex(1);
        break;
    case '0':
        ui->comboBox_dozators->setCurrentIndex(2);
        break;
    default:
        ui->comboBox_dozators->setCurrentIndex(0);
        break;
    }

    ui->lineEdit_volume->setText(QString::number(V));
    ui->lineEdit_feedrate->setText(QString::number(F));
    ui->lineEdit_accel->setText(QString::number(A));
    ui->lineEdit_reverse->setText(QString::number(R));
    ui->lineEdit_gearA->setText(QString::number(Wa));
    ui->lineEdit_gearB->setText(QString::number(Wb));
    ui->lineEdit_ratioA->setText(QString::number(Ra));
    ui->lineEdit_ratioB->setText(QString::number(Rb));
    ui->checkBox_dir->setChecked(dir);
}
