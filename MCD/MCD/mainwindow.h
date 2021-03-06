#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QSettings>
#include <QMessageBox>
#include <QMouseEvent>

#include "mcdserial.h"
#include "mcdlineedit.h"
#include "mcdpushbutton.h"

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

    void on_pushButton_continues_clicked();

    void on_pushButton_hold_pressed();

    void on_pushButton_hold_released();

    void on_pushButton_stop_clicked();

    void on_comboBox_dozators_currentIndexChanged(int index);

    void line_edit_focus(MCDLineEdit* edit);

    void on_pushButton_nc_clicked();

protected:
     void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;
    MCDSerial serial_;

    void init_fields();
    DataModel make_data_model();
    DataModel make_data_model_reverse();
    TransmitController transmit_data_;
    MCDLineEdit* active_edit_;
    void start_command(DataModel& model_data);
    void continues_command();
    void stop_command();

    void save_fields();
    void load_fields();

    void set_ratio_enabled(int index);
    void add_text(const QString& symbol);
    void logger(const QString& text);
};

#endif // MAINWINDOW_H
