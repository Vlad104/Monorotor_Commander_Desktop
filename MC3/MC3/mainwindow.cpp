#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    interface_init();
}

MainWindow::~MainWindow()
{
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

    QStringList list;
    list.append("aaa");
    list.append("bbb");
    QStringListModel* model = new QStringListModel(this);
    model->setStringList(list);
    ui->listView_order->setModel(model);
}
