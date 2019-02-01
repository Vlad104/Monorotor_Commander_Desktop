/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
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
    QPushButton *pushButton_singleStart;
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
    QPushButton *pushButton_specChange;
    QPushButton *pushButton_change;
    QFrame *frame_order;
    QPushButton *pushButton_start;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_reset;
    QTableView *tableView_order;
    QFrame *frame_com;
    QComboBox *comboBox_com;
    QPushButton *pushButton_com;
    QLabel *label_com;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(690, 442);
        QFont font;
        font.setPointSize(10);
        MainWindow->setFont(font);
        MainWindow->setInputMethodHints(Qt::ImhNone);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame_model = new QFrame(centralWidget);
        frame_model->setObjectName(QString::fromUtf8("frame_model"));
        frame_model->setGeometry(QRect(10, 80, 341, 301));
        frame_model->setFrameShape(QFrame::StyledPanel);
        frame_model->setFrameShadow(QFrame::Plain);
        pushButton_add = new QPushButton(frame_model);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));
        pushButton_add->setGeometry(QRect(10, 270, 91, 23));
        pushButton_singleStart = new QPushButton(frame_model);
        pushButton_singleStart->setObjectName(QString::fromUtf8("pushButton_singleStart"));
        pushButton_singleStart->setEnabled(false);
        pushButton_singleStart->setGeometry(QRect(210, 270, 121, 23));
        tabWidget_model = new QTabWidget(frame_model);
        tabWidget_model->setObjectName(QString::fromUtf8("tabWidget_model"));
        tabWidget_model->setGeometry(QRect(10, 20, 321, 241));
        tabWidget_model->setAutoFillBackground(true);
        tabWidget_model->setTabShape(QTabWidget::Rounded);
        tabWidget_model->setElideMode(Qt::ElideNone);
        tab_params = new QWidget();
        tab_params->setObjectName(QString::fromUtf8("tab_params"));
        frame_params = new QFrame(tab_params);
        frame_params->setObjectName(QString::fromUtf8("frame_params"));
        frame_params->setGeometry(QRect(0, 0, 311, 201));
        frame_params->setFrameShape(QFrame::StyledPanel);
        frame_params->setFrameShadow(QFrame::Raised);
        label_ratioAB = new QLabel(frame_params);
        label_ratioAB->setObjectName(QString::fromUtf8("label_ratioAB"));
        label_ratioAB->setGeometry(QRect(140, 130, 131, 16));
        QFont font1;
        font1.setPointSize(11);
        label_ratioAB->setFont(font1);
        label_volume = new QLabel(frame_params);
        label_volume->setObjectName(QString::fromUtf8("label_volume"));
        label_volume->setGeometry(QRect(140, 10, 91, 16));
        label_volume->setFont(font1);
        lineEdit_ratioA = new QLineEdit(frame_params);
        lineEdit_ratioA->setObjectName(QString::fromUtf8("lineEdit_ratioA"));
        lineEdit_ratioA->setGeometry(QRect(10, 130, 51, 20));
        QFont font2;
        font2.setPointSize(12);
        lineEdit_ratioA->setFont(font2);
        lineEdit_ratioA->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_ratioA->setMaxLength(4);
        label_reverse = new QLabel(frame_params);
        label_reverse->setObjectName(QString::fromUtf8("label_reverse"));
        label_reverse->setGeometry(QRect(140, 90, 131, 16));
        label_reverse->setFont(font1);
        label_feedrate = new QLabel(frame_params);
        label_feedrate->setObjectName(QString::fromUtf8("label_feedrate"));
        label_feedrate->setGeometry(QRect(140, 50, 131, 16));
        label_feedrate->setFont(font1);
        comboBox_dozators = new QComboBox(frame_params);
        comboBox_dozators->setObjectName(QString::fromUtf8("comboBox_dozators"));
        comboBox_dozators->setGeometry(QRect(10, 170, 161, 22));
        lineEdit_feedrate = new QLineEdit(frame_params);
        lineEdit_feedrate->setObjectName(QString::fromUtf8("lineEdit_feedrate"));
        lineEdit_feedrate->setGeometry(QRect(10, 50, 113, 20));
        lineEdit_feedrate->setFont(font2);
        lineEdit_feedrate->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_feedrate->setMaxLength(6);
        lineEdit_ratioB = new QLineEdit(frame_params);
        lineEdit_ratioB->setObjectName(QString::fromUtf8("lineEdit_ratioB"));
        lineEdit_ratioB->setGeometry(QRect(70, 130, 51, 20));
        lineEdit_ratioB->setFont(font2);
        lineEdit_ratioB->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_ratioB->setMaxLength(4);
        lineEdit_reverse = new QLineEdit(frame_params);
        lineEdit_reverse->setObjectName(QString::fromUtf8("lineEdit_reverse"));
        lineEdit_reverse->setGeometry(QRect(10, 90, 113, 20));
        lineEdit_reverse->setFont(font2);
        lineEdit_reverse->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_reverse->setMaxLength(6);
        lineEdit_volume = new QLineEdit(frame_params);
        lineEdit_volume->setObjectName(QString::fromUtf8("lineEdit_volume"));
        lineEdit_volume->setGeometry(QRect(10, 10, 113, 20));
        lineEdit_volume->setFont(font2);
        lineEdit_volume->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_volume->setMaxLength(7);
        tabWidget_model->addTab(tab_params, QString());
        tab_details = new QWidget();
        tab_details->setObjectName(QString::fromUtf8("tab_details"));
        frame_details = new QFrame(tab_details);
        frame_details->setObjectName(QString::fromUtf8("frame_details"));
        frame_details->setGeometry(QRect(0, 0, 311, 161));
        frame_details->setFrameShape(QFrame::StyledPanel);
        frame_details->setFrameShadow(QFrame::Raised);
        lineEdit_accel = new QLineEdit(frame_details);
        lineEdit_accel->setObjectName(QString::fromUtf8("lineEdit_accel"));
        lineEdit_accel->setGeometry(QRect(10, 10, 113, 20));
        lineEdit_accel->setFont(font2);
        lineEdit_accel->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_accel->setMaxLength(6);
        label_accel = new QLabel(frame_details);
        label_accel->setObjectName(QString::fromUtf8("label_accel"));
        label_accel->setGeometry(QRect(140, 10, 171, 16));
        label_accel->setFont(font1);
        label_gearA = new QLabel(frame_details);
        label_gearA->setObjectName(QString::fromUtf8("label_gearA"));
        label_gearA->setGeometry(QRect(140, 40, 131, 16));
        label_gearA->setFont(font1);
        lineEdit_gearA = new QLineEdit(frame_details);
        lineEdit_gearA->setObjectName(QString::fromUtf8("lineEdit_gearA"));
        lineEdit_gearA->setGeometry(QRect(10, 40, 113, 20));
        lineEdit_gearA->setFont(font2);
        lineEdit_gearA->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_gearA->setMaxLength(8);
        lineEdit_gearB = new QLineEdit(frame_details);
        lineEdit_gearB->setObjectName(QString::fromUtf8("lineEdit_gearB"));
        lineEdit_gearB->setGeometry(QRect(10, 70, 113, 20));
        lineEdit_gearB->setFont(font2);
        lineEdit_gearB->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_gearB->setMaxLength(8);
        label_gearB = new QLabel(frame_details);
        label_gearB->setObjectName(QString::fromUtf8("label_gearB"));
        label_gearB->setGeometry(QRect(140, 70, 131, 16));
        label_gearB->setFont(font1);
        checkBox_dir = new QCheckBox(frame_details);
        checkBox_dir->setObjectName(QString::fromUtf8("checkBox_dir"));
        checkBox_dir->setGeometry(QRect(10, 100, 211, 17));
        pushButton_specChange = new QPushButton(frame_details);
        pushButton_specChange->setObjectName(QString::fromUtf8("pushButton_specChange"));
        pushButton_specChange->setGeometry(QRect(10, 130, 101, 23));
        tabWidget_model->addTab(tab_details, QString());
        pushButton_change = new QPushButton(frame_model);
        pushButton_change->setObjectName(QString::fromUtf8("pushButton_change"));
        pushButton_change->setGeometry(QRect(110, 270, 91, 23));
        frame_order = new QFrame(centralWidget);
        frame_order->setObjectName(QString::fromUtf8("frame_order"));
        frame_order->setGeometry(QRect(360, 80, 321, 301));
        frame_order->setFrameShape(QFrame::StyledPanel);
        frame_order->setFrameShadow(QFrame::Plain);
        pushButton_start = new QPushButton(frame_order);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setEnabled(false);
        pushButton_start->setGeometry(QRect(190, 270, 121, 23));
        pushButton_delete = new QPushButton(frame_order);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));
        pushButton_delete->setGeometry(QRect(100, 270, 81, 23));
        pushButton_reset = new QPushButton(frame_order);
        pushButton_reset->setObjectName(QString::fromUtf8("pushButton_reset"));
        pushButton_reset->setGeometry(QRect(10, 270, 81, 23));
        tableView_order = new QTableView(frame_order);
        tableView_order->setObjectName(QString::fromUtf8("tableView_order"));
        tableView_order->setGeometry(QRect(10, 10, 300, 251));
        QFont font3;
        font3.setPointSize(8);
        tableView_order->setFont(font3);
        tableView_order->setFrameShape(QFrame::StyledPanel);
        tableView_order->setFrameShadow(QFrame::Sunken);
        tableView_order->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableView_order->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView_order->setAlternatingRowColors(false);
        tableView_order->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView_order->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_order->setGridStyle(Qt::SolidLine);
        tableView_order->horizontalHeader()->setCascadingSectionResizes(true);
        tableView_order->horizontalHeader()->setDefaultSectionSize(60);
        tableView_order->horizontalHeader()->setMinimumSectionSize(60);
        tableView_order->verticalHeader()->setVisible(false);
        tableView_order->verticalHeader()->setDefaultSectionSize(21);
        tableView_order->verticalHeader()->setMinimumSectionSize(20);
        frame_com = new QFrame(centralWidget);
        frame_com->setObjectName(QString::fromUtf8("frame_com"));
        frame_com->setGeometry(QRect(10, 10, 271, 61));
        frame_com->setFrameShape(QFrame::StyledPanel);
        frame_com->setFrameShadow(QFrame::Plain);
        comboBox_com = new QComboBox(frame_com);
        comboBox_com->setObjectName(QString::fromUtf8("comboBox_com"));
        comboBox_com->setGeometry(QRect(10, 30, 131, 22));
        pushButton_com = new QPushButton(frame_com);
        pushButton_com->setObjectName(QString::fromUtf8("pushButton_com"));
        pushButton_com->setGeometry(QRect(150, 30, 111, 23));
        label_com = new QLabel(frame_com);
        label_com->setObjectName(QString::fromUtf8("label_com"));
        label_com->setGeometry(QRect(10, 10, 171, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 690, 21));
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
        pushButton_singleStart->setText(QApplication::translate("MainWindow", "\320\237\321\203\321\201\320\272", nullptr));
        label_ratioAB->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\276\321\202\320\275\320\276\321\210\320\265\320\275\320\270\320\265 A:B", nullptr));
        label_volume->setText(QApplication::translate("MainWindow", "\320\236\320\261\321\212\321\221\320\274, \320\274\320\272\320\273", nullptr));
        label_reverse->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\262\320\265\321\200\321\201, \320\274\320\272\320\273", nullptr));
        label_feedrate->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\264\320\260\321\207\320\260, \320\274\320\272\320\273/\320\274\320\270\320\275", nullptr));
        tabWidget_model->setTabText(tabWidget_model->indexOf(tab_params), QApplication::translate("MainWindow", "\320\236\321\201\320\275\320\276\320\262\320\275\321\213\320\265", nullptr));
        label_accel->setText(QApplication::translate("MainWindow", "\320\243\321\201\320\272\320\276\321\200\320\265\320\275\320\270\320\265, \320\274\320\272\320\273/\320\274\320\270\320\275\321\201\320\265\320\272", nullptr));
        label_gearA->setText(QApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 \320\220", nullptr));
        label_gearB->setText(QApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 B", nullptr));
        checkBox_dir->setText(QApplication::translate("MainWindow", "\320\236\320\261\321\200\320\260\321\202\320\275\320\276\320\265 \320\275\320\260\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        pushButton_specChange->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        tabWidget_model->setTabText(tabWidget_model->indexOf(tab_details), QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\210\320\270\321\200\320\265\320\275\320\275\321\213\320\265", nullptr));
        pushButton_change->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        pushButton_start->setText(QApplication::translate("MainWindow", "\320\237\321\203\321\201\320\272", nullptr));
        pushButton_delete->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        pushButton_reset->setText(QApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201", nullptr));
        pushButton_com->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214", nullptr));
        label_com->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 COM-\320\277\320\276\321\200\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
