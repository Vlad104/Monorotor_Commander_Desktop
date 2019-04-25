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

void MainWindow::closeEvent(QCloseEvent *event) {
    save_fields();
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
    ui->frame_transmit->setEnabled(false);

    QStringList ports_list = serial_.get_ports();
    ui->comboBox_com->addItems(ports_list);

    load_fields();
    set_ratio_enabled(ui->comboBox_dozators->currentIndex());

    active_edit_ = ui->lineEdit_volume;
    QObject::connect(ui->lineEdit_volume, &MCDLineEdit::focussed, this, &MainWindow::line_edit_focus);
    QObject::connect(ui->lineEdit_feedrate, &MCDLineEdit::focussed, this, &MainWindow::line_edit_focus);
    QObject::connect(ui->lineEdit_accel, &MCDLineEdit::focussed, this, &MainWindow::line_edit_focus);
    QObject::connect(ui->lineEdit_reverse, &MCDLineEdit::focussed, this, &MainWindow::line_edit_focus);
    QObject::connect(ui->lineEdit_ratioA, &MCDLineEdit::focussed, this, &MainWindow::line_edit_focus);
    QObject::connect(ui->lineEdit_ratioB, &MCDLineEdit::focussed, this, &MainWindow::line_edit_focus);
    QObject::connect(ui->lineEdit_gearA, &MCDLineEdit::focussed, this, &MainWindow::line_edit_focus);
    QObject::connect(ui->lineEdit_gearB, &MCDLineEdit::focussed, this, &MainWindow::line_edit_focus);
    QObject::connect(ui->pushButton_n0, &MCDPushButton::was_clicked, this, &MainWindow::add_text);
    QObject::connect(ui->pushButton_n1, &MCDPushButton::was_clicked, this, &MainWindow::add_text);
    QObject::connect(ui->pushButton_n2, &MCDPushButton::was_clicked, this, &MainWindow::add_text);
    QObject::connect(ui->pushButton_n3, &MCDPushButton::was_clicked, this, &MainWindow::add_text);
    QObject::connect(ui->pushButton_n4, &MCDPushButton::was_clicked, this, &MainWindow::add_text);
    QObject::connect(ui->pushButton_n5, &MCDPushButton::was_clicked, this, &MainWindow::add_text);
    QObject::connect(ui->pushButton_n6, &MCDPushButton::was_clicked, this, &MainWindow::add_text);
    QObject::connect(ui->pushButton_n7, &MCDPushButton::was_clicked, this, &MainWindow::add_text);
    QObject::connect(ui->pushButton_n8, &MCDPushButton::was_clicked, this, &MainWindow::add_text);
    QObject::connect(ui->pushButton_n9, &MCDPushButton::was_clicked, this, &MainWindow::add_text);
    QObject::connect(ui->pushButton_nd, &MCDPushButton::was_clicked, this, &MainWindow::add_text);

    // ui->pushButton_stop->setStyleSheet("background-color: red");

}

void MainWindow::logger(const QString& text) {
    ui->textEdit_log->append(text);
}

void MainWindow::line_edit_focus(MCDLineEdit* edit) {
    active_edit_ = edit;
    qDebug() << edit->objectName();
    logger(edit->objectName());
}

void MainWindow::add_text(const QString& symbol) {
    active_edit_->setText(active_edit_->text() + symbol);
}

void MainWindow::on_pushButton_com_clicked()
{
    if (serial_.get_status()) {
        serial_.disconnect();
        ui->pushButton_com->setText("Подключить");
        ui->frame_transmit->setEnabled(false);
        transmit_data_.clear_story();
    } else if (ui->comboBox_com->count() > 0) {
        ui->pushButton_com->setText("Отключить");
        ui->frame_transmit->setEnabled(true);
        QString port_name = ui->comboBox_com->currentText();
        if (!serial_.connect(port_name)) {
            QMessageBox::critical(this, "MONOROTOR COMMANDER DESKTOP",
                                  "Ошибка при подключении по COM-порту. Перезарузите Блок управления и MONOROTOR COMMANDER DESKTOP");
            ui->pushButton_com->setText("Подключить");
            ui->frame_transmit->setEnabled(false);
        }
    }
}

void MainWindow::save_fields() {
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

void MainWindow::load_fields() {
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
    if (D == '0') {
        Ra = 1.0;
        Rb = 0.0;
    } else if (D == '1') {
        Ra = 0.0;
        Rb = 1.0;
    }

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
    if (D == '0') {
        Ra = 1.0;
        Rb = 0.0;
    } else if (D == '1') {
        Ra = 0.0;
        Rb = 1.0;
    }

    return DataModel(D, R, F, A, Wa, Wb, Ra, Rb);
}

void MainWindow::on_pushButton_start_clicked()
{
    DataModel model_data = make_data_model() ;
    DataModel model_data_rev = make_data_model_reverse() ;

    start_command(model_data);
    qDebug() << "Reverse";
    logger("Reverse");
    start_command(model_data_rev);
}

void MainWindow::start_command(DataModel& model_data) {
    transmit_data_.get_start(model_data);
    serial_.transmit(transmit_data_);
}

void MainWindow::continues_command() {
    DataModel model_data = make_data_model() ;
    transmit_data_.get_continues(model_data);
    serial_.transmit(transmit_data_);
}


void MainWindow::stop_command() {
    transmit_data_.get_stop();
    serial_.transmit(transmit_data_);
}

void MainWindow::on_pushButton_continues_clicked()
{
    continues_command();
}

void MainWindow::on_pushButton_hold_pressed()
{
    continues_command();
}

void MainWindow::on_pushButton_hold_released()
{
    stop_command();
}

void MainWindow::on_pushButton_stop_clicked()
{
    stop_command();
}

void MainWindow::set_ratio_enabled(int index) {
    if (index == 0) {
        ui->frame_ratio->setEnabled(true);
    } else {
        ui->frame_ratio->setEnabled(false);
    }
}

void MainWindow::on_comboBox_dozators_currentIndexChanged(int index)
{
    set_ratio_enabled(index);
}

void MainWindow::on_pushButton_nc_clicked()
{
    QString temp = active_edit_->text();
    if (temp.size() > 0) {
        temp.resize(temp.size() - 1);
    }
    active_edit_->setText(temp);
}
