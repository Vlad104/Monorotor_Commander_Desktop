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
    write_settings();
    Keeper::save(order_model_);
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

    read_settings();

    Keeper::load(order_model_);

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

    /*
    order_model_.emplace_back(DataModel('0', 111000, 222000, 33000, 99, 44.44, 5555, 1, 1, false));
    order_model_.emplace_back(DataModel('1', 123456, 999999, 1000, 50, 444.4, 5555, 1, 2, true));
    order_model_.emplace_back(DataModel('2', 999999, 1000, 123456, 1, 4.444, 5555, 2, 1, false));
    order_model_.emplace_back(DataModel('2', 2000, 22000, 2010, 75, 4.444, 5555, 100, 1, true));
    order_model_.emplace_back(DataModel('2', 2000, 22000, 2010, 75, 4.444, 5555, 100, 1, true));
    order_model_.emplace_back(DataModel('2', 2000, 22000, 2010, 75, 444.4, 5555, 100, 1, false));
    */

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

void MainWindow::on_pushButton_reset_clicked()
{
    order_model_.clear();
    update_list();
}

void MainWindow::on_pushButton_delete_clicked()
{
    int index = ui->listView_order->currentIndex().row();
    auto it = order_model_.begin();
    for (int i = 0; i < index; i++) {
        ++it;
    }
    order_model_.erase(it);
    update_list();
}

void MainWindow::on_pushButton_add_clicked()
{
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

    order_model_.emplace_back(DataModel(D, V, F, A, R, Wa, Wb, Ra, Rb, dir));
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
