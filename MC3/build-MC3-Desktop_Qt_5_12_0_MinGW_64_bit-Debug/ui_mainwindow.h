/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *frame_model;
    QPushButton *pushButton_add;
    QTabWidget *tabWidget_model;
    QWidget *tab_params;
    QFrame *frame_params;
    QLabel *label_ratioAB;
    QLabel *label_volume;
    QLineEdit *lineEdit_ratioA;
    QLabel *label_reverse;
    QLabel *label_feedrate;
    QComboBox *comboBox_dozators;
    QLineEdit *lineEdit_feedrate;
    QLineEdit *lineEdit_ratioB;
    QLineEdit *lineEdit_reverse;
    QLineEdit *lineEdit_volume;
    QWidget *tab_details;
    QFrame *frame_details;
    QLineEdit *lineEdit_accel;
    QLabel *label_accel;
    QLabel *label_gearA;
    QLineEdit *lineEdit_gearA;
    QLineEdit *lineEdit_gearB;
    QLabel *label_gearB;
    QCheckBox *checkBox_dir;
    QPushButton *pushButton_change;
    QFrame *frame_order;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_reset;
    QTableView *tableView_order;
    QFrame *frame_com;
    QComboBox *comboBox_com;
    QPushButton *pushButton_com;
    QLabel *label_com;
    QFrame *frame_transmit;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_continues;
    QPushButton *pushButton_singleStart;
    QPushButton *pushButton_start;
    QPushButton *pushButton_continues_pressed;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1024, 600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1024, 600));
        MainWindow->setMaximumSize(QSize(1024, 600));
        QFont font;
        font.setPointSize(14);
        MainWindow->setFont(font);
        MainWindow->setInputMethodHints(Qt::ImhNone);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame_model = new QFrame(centralWidget);
        frame_model->setObjectName(QString::fromUtf8("frame_model"));
        frame_model->setGeometry(QRect(10, 110, 431, 341));
        frame_model->setFont(font);
        frame_model->setFrameShape(QFrame::StyledPanel);
        frame_model->setFrameShadow(QFrame::Plain);
        pushButton_add = new QPushButton(frame_model);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));
        pushButton_add->setGeometry(QRect(10, 290, 120, 30));
        pushButton_add->setFont(font);
        tabWidget_model = new QTabWidget(frame_model);
        tabWidget_model->setObjectName(QString::fromUtf8("tabWidget_model"));
        tabWidget_model->setGeometry(QRect(10, 20, 411, 261));
        tabWidget_model->setFont(font);
        tabWidget_model->setAutoFillBackground(true);
        tabWidget_model->setTabShape(QTabWidget::Rounded);
        tabWidget_model->setElideMode(Qt::ElideNone);
        tab_params = new QWidget();
        tab_params->setObjectName(QString::fromUtf8("tab_params"));
        frame_params = new QFrame(tab_params);
        frame_params->setObjectName(QString::fromUtf8("frame_params"));
        frame_params->setGeometry(QRect(0, 0, 401, 271));
        frame_params->setFont(font);
        frame_params->setFrameShape(QFrame::StyledPanel);
        frame_params->setFrameShadow(QFrame::Raised);
        label_ratioAB = new QLabel(frame_params);
        label_ratioAB->setObjectName(QString::fromUtf8("label_ratioAB"));
        label_ratioAB->setGeometry(QRect(200, 130, 160, 30));
        label_ratioAB->setFont(font);
        label_volume = new QLabel(frame_params);
        label_volume->setObjectName(QString::fromUtf8("label_volume"));
        label_volume->setGeometry(QRect(200, 10, 160, 30));
        label_volume->setFont(font);
        lineEdit_ratioA = new QLineEdit(frame_params);
        lineEdit_ratioA->setObjectName(QString::fromUtf8("lineEdit_ratioA"));
        lineEdit_ratioA->setGeometry(QRect(10, 130, 80, 30));
        lineEdit_ratioA->setFont(font);
        lineEdit_ratioA->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_ratioA->setMaxLength(4);
        label_reverse = new QLabel(frame_params);
        label_reverse->setObjectName(QString::fromUtf8("label_reverse"));
        label_reverse->setGeometry(QRect(200, 90, 160, 30));
        label_reverse->setFont(font);
        label_feedrate = new QLabel(frame_params);
        label_feedrate->setObjectName(QString::fromUtf8("label_feedrate"));
        label_feedrate->setGeometry(QRect(200, 50, 160, 30));
        label_feedrate->setFont(font);
        comboBox_dozators = new QComboBox(frame_params);
        comboBox_dozators->setObjectName(QString::fromUtf8("comboBox_dozators"));
        comboBox_dozators->setGeometry(QRect(10, 180, 180, 30));
        comboBox_dozators->setFont(font);
        lineEdit_feedrate = new QLineEdit(frame_params);
        lineEdit_feedrate->setObjectName(QString::fromUtf8("lineEdit_feedrate"));
        lineEdit_feedrate->setGeometry(QRect(10, 50, 180, 30));
        lineEdit_feedrate->setFont(font);
        lineEdit_feedrate->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_feedrate->setMaxLength(6);
        lineEdit_ratioB = new QLineEdit(frame_params);
        lineEdit_ratioB->setObjectName(QString::fromUtf8("lineEdit_ratioB"));
        lineEdit_ratioB->setGeometry(QRect(110, 130, 80, 30));
        lineEdit_ratioB->setFont(font);
        lineEdit_ratioB->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_ratioB->setMaxLength(4);
        lineEdit_reverse = new QLineEdit(frame_params);
        lineEdit_reverse->setObjectName(QString::fromUtf8("lineEdit_reverse"));
        lineEdit_reverse->setGeometry(QRect(10, 90, 180, 30));
        lineEdit_reverse->setFont(font);
        lineEdit_reverse->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_reverse->setMaxLength(6);
        lineEdit_volume = new QLineEdit(frame_params);
        lineEdit_volume->setObjectName(QString::fromUtf8("lineEdit_volume"));
        lineEdit_volume->setGeometry(QRect(10, 10, 180, 30));
        lineEdit_volume->setFont(font);
        lineEdit_volume->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_volume->setMaxLength(7);
        tabWidget_model->addTab(tab_params, QString());
        tab_details = new QWidget();
        tab_details->setObjectName(QString::fromUtf8("tab_details"));
        frame_details = new QFrame(tab_details);
        frame_details->setObjectName(QString::fromUtf8("frame_details"));
        frame_details->setGeometry(QRect(0, 0, 411, 221));
        frame_details->setFrameShape(QFrame::StyledPanel);
        frame_details->setFrameShadow(QFrame::Raised);
        lineEdit_accel = new QLineEdit(frame_details);
        lineEdit_accel->setObjectName(QString::fromUtf8("lineEdit_accel"));
        lineEdit_accel->setGeometry(QRect(10, 10, 180, 30));
        lineEdit_accel->setMinimumSize(QSize(180, 30));
        lineEdit_accel->setFont(font);
        lineEdit_accel->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_accel->setMaxLength(6);
        label_accel = new QLabel(frame_details);
        label_accel->setObjectName(QString::fromUtf8("label_accel"));
        label_accel->setGeometry(QRect(200, 10, 221, 30));
        label_accel->setMinimumSize(QSize(180, 30));
        label_accel->setFont(font);
        label_gearA = new QLabel(frame_details);
        label_gearA->setObjectName(QString::fromUtf8("label_gearA"));
        label_gearA->setGeometry(QRect(200, 50, 180, 30));
        label_gearA->setMinimumSize(QSize(180, 30));
        label_gearA->setFont(font);
        lineEdit_gearA = new QLineEdit(frame_details);
        lineEdit_gearA->setObjectName(QString::fromUtf8("lineEdit_gearA"));
        lineEdit_gearA->setGeometry(QRect(10, 50, 180, 30));
        lineEdit_gearA->setMinimumSize(QSize(180, 30));
        lineEdit_gearA->setFont(font);
        lineEdit_gearA->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_gearA->setMaxLength(8);
        lineEdit_gearB = new QLineEdit(frame_details);
        lineEdit_gearB->setObjectName(QString::fromUtf8("lineEdit_gearB"));
        lineEdit_gearB->setGeometry(QRect(10, 90, 180, 30));
        lineEdit_gearB->setMinimumSize(QSize(180, 30));
        lineEdit_gearB->setFont(font);
        lineEdit_gearB->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_gearB->setMaxLength(8);
        label_gearB = new QLabel(frame_details);
        label_gearB->setObjectName(QString::fromUtf8("label_gearB"));
        label_gearB->setGeometry(QRect(200, 90, 180, 30));
        label_gearB->setMinimumSize(QSize(180, 30));
        label_gearB->setFont(font);
        checkBox_dir = new QCheckBox(frame_details);
        checkBox_dir->setObjectName(QString::fromUtf8("checkBox_dir"));
        checkBox_dir->setGeometry(QRect(10, 130, 211, 30));
        checkBox_dir->setMinimumSize(QSize(180, 30));
        tabWidget_model->addTab(tab_details, QString());
        pushButton_change = new QPushButton(frame_model);
        pushButton_change->setObjectName(QString::fromUtf8("pushButton_change"));
        pushButton_change->setGeometry(QRect(140, 290, 120, 30));
        pushButton_change->setFont(font);
        frame_order = new QFrame(centralWidget);
        frame_order->setObjectName(QString::fromUtf8("frame_order"));
        frame_order->setGeometry(QRect(450, 110, 461, 341));
        frame_order->setFont(font);
        frame_order->setFrameShape(QFrame::StyledPanel);
        frame_order->setFrameShadow(QFrame::Plain);
        pushButton_delete = new QPushButton(frame_order);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));
        pushButton_delete->setGeometry(QRect(140, 300, 120, 30));
        pushButton_delete->setFont(font);
        pushButton_reset = new QPushButton(frame_order);
        pushButton_reset->setObjectName(QString::fromUtf8("pushButton_reset"));
        pushButton_reset->setGeometry(QRect(10, 300, 120, 30));
        pushButton_reset->setFont(font);
        tableView_order = new QTableView(frame_order);
        tableView_order->setObjectName(QString::fromUtf8("tableView_order"));
        tableView_order->setGeometry(QRect(10, 10, 400, 281));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableView_order->sizePolicy().hasHeightForWidth());
        tableView_order->setSizePolicy(sizePolicy1);
        tableView_order->setFont(font);
        tableView_order->setFrameShape(QFrame::StyledPanel);
        tableView_order->setFrameShadow(QFrame::Sunken);
        tableView_order->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableView_order->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView_order->setAlternatingRowColors(false);
        tableView_order->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView_order->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_order->setGridStyle(Qt::SolidLine);
        tableView_order->horizontalHeader()->setCascadingSectionResizes(true);
        tableView_order->horizontalHeader()->setDefaultSectionSize(100);
        tableView_order->horizontalHeader()->setMinimumSectionSize(100);
        tableView_order->verticalHeader()->setVisible(false);
        tableView_order->verticalHeader()->setDefaultSectionSize(30);
        tableView_order->verticalHeader()->setMinimumSectionSize(30);
        frame_com = new QFrame(centralWidget);
        frame_com->setObjectName(QString::fromUtf8("frame_com"));
        frame_com->setGeometry(QRect(10, 10, 431, 91));
        frame_com->setFont(font);
        frame_com->setFrameShape(QFrame::StyledPanel);
        frame_com->setFrameShadow(QFrame::Plain);
        comboBox_com = new QComboBox(frame_com);
        comboBox_com->setObjectName(QString::fromUtf8("comboBox_com"));
        comboBox_com->setGeometry(QRect(10, 50, 180, 30));
        comboBox_com->setFont(font);
        pushButton_com = new QPushButton(frame_com);
        pushButton_com->setObjectName(QString::fromUtf8("pushButton_com"));
        pushButton_com->setGeometry(QRect(210, 50, 180, 30));
        pushButton_com->setFont(font);
        label_com = new QLabel(frame_com);
        label_com->setObjectName(QString::fromUtf8("label_com"));
        label_com->setGeometry(QRect(10, 10, 211, 31));
        label_com->setFont(font);
        frame_transmit = new QFrame(centralWidget);
        frame_transmit->setObjectName(QString::fromUtf8("frame_transmit"));
        frame_transmit->setEnabled(false);
        frame_transmit->setGeometry(QRect(10, 460, 1001, 61));
        frame_transmit->setFont(font);
        frame_transmit->setFrameShape(QFrame::StyledPanel);
        frame_transmit->setFrameShadow(QFrame::Plain);
        pushButton_stop = new QPushButton(frame_transmit);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(410, 10, 180, 30));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setWeight(50);
        pushButton_stop->setFont(font1);
        pushButton_continues = new QPushButton(frame_transmit);
        pushButton_continues->setObjectName(QString::fromUtf8("pushButton_continues"));
        pushButton_continues->setGeometry(QRect(210, 10, 180, 30));
        pushButton_continues->setFont(font1);
        pushButton_singleStart = new QPushButton(frame_transmit);
        pushButton_singleStart->setObjectName(QString::fromUtf8("pushButton_singleStart"));
        pushButton_singleStart->setEnabled(false);
        pushButton_singleStart->setGeometry(QRect(610, 10, 180, 30));
        pushButton_singleStart->setFont(font);
        pushButton_start = new QPushButton(frame_transmit);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setEnabled(false);
        pushButton_start->setGeometry(QRect(810, 10, 180, 30));
        pushButton_start->setFont(font);
        pushButton_continues_pressed = new QPushButton(frame_transmit);
        pushButton_continues_pressed->setObjectName(QString::fromUtf8("pushButton_continues_pressed"));
        pushButton_continues_pressed->setGeometry(QRect(10, 10, 180, 30));
        pushButton_continues_pressed->setFont(font1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 31));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget_model->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Monorotor Commander 3", nullptr));
        pushButton_add->setText(QApplication::translate("MainWindow", "\320\222 \320\276\321\207\320\265\321\200\320\265\320\264\321\214", nullptr));
        label_ratioAB->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\276\321\202\320\275\320\276\321\210\320\265\320\275\320\270\320\265 A:B", nullptr));
        label_volume->setText(QApplication::translate("MainWindow", "\320\236\320\261\321\212\321\221\320\274, \320\274\320\272\320\273", nullptr));
        label_reverse->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\262\320\265\321\200\321\201, \320\274\320\272\320\273", nullptr));
        label_feedrate->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\264\320\260\321\207\320\260, \320\274\320\272\320\273/\320\274\320\270\320\275", nullptr));
        tabWidget_model->setTabText(tabWidget_model->indexOf(tab_params), QApplication::translate("MainWindow", "\320\236\321\201\320\275\320\276\320\262\320\275\321\213\320\265", nullptr));
        label_accel->setText(QApplication::translate("MainWindow", "\320\243\321\201\320\272\320\276\321\200\320\265\320\275\320\270\320\265, \320\274\320\272\320\273/\320\274\320\270\320\275\321\201\320\265\320\272", nullptr));
        label_gearA->setText(QApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 \320\220", nullptr));
        label_gearB->setText(QApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 B", nullptr));
        checkBox_dir->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\262\320\265\321\200\321\201 \320\275\320\260\320\277\320\260\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\217", nullptr));
        tabWidget_model->setTabText(tabWidget_model->indexOf(tab_details), QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\210\320\270\321\200\320\265\320\275\320\275\321\213\320\265", nullptr));
        pushButton_change->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        pushButton_delete->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        pushButton_reset->setText(QApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201", nullptr));
        pushButton_com->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214", nullptr));
        label_com->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 COM-\320\277\320\276\321\200\321\202", nullptr));
        pushButton_stop->setText(QApplication::translate("MainWindow", "\320\241\320\242\320\236\320\237", nullptr));
        pushButton_continues->setText(QApplication::translate("MainWindow", "\320\235\320\265\320\277\321\200\320\265\321\200\321\213\320\262\320\275\320\276", nullptr));
        pushButton_singleStart->setText(QApplication::translate("MainWindow", "\320\237\321\203\321\201\320\272", nullptr));
        pushButton_start->setText(QApplication::translate("MainWindow", "\320\237\321\203\321\201\320\272 \320\276\321\207\320\265\321\200\320\265\320\264\320\270", nullptr));
        pushButton_continues_pressed->setText(QApplication::translate("MainWindow", "\320\237\320\276 \321\203\320\264\320\265\321\200\320\266\320\260\320\275\320\270\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
