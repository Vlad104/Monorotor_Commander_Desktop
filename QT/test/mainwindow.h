#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_com_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort serial;

    void serial_init();
    void serial_connect(const QSerialPortInfo &info);
    void serial_disconnect();
};

#endif // MAINWINDOW_H
