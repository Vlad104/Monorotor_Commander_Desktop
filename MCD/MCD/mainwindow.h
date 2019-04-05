#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>

#include "mcdserial.h"

#include "../../src/DataModel.h"
#include "../../src/Protocol.h"
#include "../../src/TransmitController.h"

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
    void on_pushButton_com_clicked();

    void on_pushButton_start_clicked();

private:
    Ui::MainWindow *ui;
    MCDSerial serial_;

    void init_fields();
    DataModel make_data_model();
    DataModel make_data_model_reverse();
};

#endif // MAINWINDOW_H
