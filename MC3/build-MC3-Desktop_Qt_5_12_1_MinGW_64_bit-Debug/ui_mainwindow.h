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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *frame_model;
    QLineEdit *lineEdit_volume;
    QLabel *label_volume;
    QLineEdit *lineEdit_feedrate;
    QLabel *label_feedrate;
    QLabel *label_reverse;
    QLineEdit *lineEdit_reverse;
    QLabel *label_ratioAB;
    QLineEdit *lineEdit_ratioA;
    QLineEdit *lineEdit_ratioB;
    QFrame *frame_details;
    QLineEdit *lineEdit_accel;
    QLabel *label_accel;
    QLabel *label_gearA;
    QLineEdit *lineEdit_gearA;
    QLineEdit *lineEdit_gearB;
    QLabel *label_gearB;
    QCheckBox *checkBox_dir;
    QComboBox *comboBox_dozators;
    QFrame *frame_order;
    QListView *listView_order;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(666, 573);
        QFont font;
        font.setPointSize(12);
        MainWindow->setFont(font);
        MainWindow->setInputMethodHints(Qt::ImhNone);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame_model = new QFrame(centralWidget);
        frame_model->setObjectName(QString::fromUtf8("frame_model"));
        frame_model->setGeometry(QRect(20, 50, 291, 441));
        frame_model->setFrameShape(QFrame::StyledPanel);
        frame_model->setFrameShadow(QFrame::Plain);
        lineEdit_volume = new QLineEdit(frame_model);
        lineEdit_volume->setObjectName(QString::fromUtf8("lineEdit_volume"));
        lineEdit_volume->setGeometry(QRect(20, 20, 113, 20));
        lineEdit_volume->setFont(font);
        lineEdit_volume->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_volume->setMaxLength(7);
        label_volume = new QLabel(frame_model);
        label_volume->setObjectName(QString::fromUtf8("label_volume"));
        label_volume->setGeometry(QRect(150, 20, 91, 16));
        label_volume->setFont(font);
        lineEdit_feedrate = new QLineEdit(frame_model);
        lineEdit_feedrate->setObjectName(QString::fromUtf8("lineEdit_feedrate"));
        lineEdit_feedrate->setGeometry(QRect(20, 60, 113, 20));
        lineEdit_feedrate->setFont(font);
        lineEdit_feedrate->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_feedrate->setMaxLength(6);
        label_feedrate = new QLabel(frame_model);
        label_feedrate->setObjectName(QString::fromUtf8("label_feedrate"));
        label_feedrate->setGeometry(QRect(150, 60, 131, 16));
        label_feedrate->setFont(font);
        label_reverse = new QLabel(frame_model);
        label_reverse->setObjectName(QString::fromUtf8("label_reverse"));
        label_reverse->setGeometry(QRect(150, 100, 131, 16));
        label_reverse->setFont(font);
        lineEdit_reverse = new QLineEdit(frame_model);
        lineEdit_reverse->setObjectName(QString::fromUtf8("lineEdit_reverse"));
        lineEdit_reverse->setGeometry(QRect(20, 100, 113, 20));
        lineEdit_reverse->setFont(font);
        lineEdit_reverse->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_reverse->setMaxLength(6);
        label_ratioAB = new QLabel(frame_model);
        label_ratioAB->setObjectName(QString::fromUtf8("label_ratioAB"));
        label_ratioAB->setGeometry(QRect(150, 140, 131, 16));
        label_ratioAB->setFont(font);
        lineEdit_ratioA = new QLineEdit(frame_model);
        lineEdit_ratioA->setObjectName(QString::fromUtf8("lineEdit_ratioA"));
        lineEdit_ratioA->setGeometry(QRect(20, 140, 51, 20));
        lineEdit_ratioA->setFont(font);
        lineEdit_ratioA->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_ratioA->setMaxLength(4);
        lineEdit_ratioB = new QLineEdit(frame_model);
        lineEdit_ratioB->setObjectName(QString::fromUtf8("lineEdit_ratioB"));
        lineEdit_ratioB->setGeometry(QRect(80, 140, 51, 20));
        lineEdit_ratioB->setFont(font);
        lineEdit_ratioB->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_ratioB->setMaxLength(4);
        frame_details = new QFrame(frame_model);
        frame_details->setObjectName(QString::fromUtf8("frame_details"));
        frame_details->setGeometry(QRect(10, 220, 271, 161));
        frame_details->setFrameShape(QFrame::StyledPanel);
        frame_details->setFrameShadow(QFrame::Raised);
        lineEdit_accel = new QLineEdit(frame_details);
        lineEdit_accel->setObjectName(QString::fromUtf8("lineEdit_accel"));
        lineEdit_accel->setGeometry(QRect(10, 10, 113, 20));
        lineEdit_accel->setFont(font);
        lineEdit_accel->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_accel->setMaxLength(6);
        label_accel = new QLabel(frame_details);
        label_accel->setObjectName(QString::fromUtf8("label_accel"));
        label_accel->setGeometry(QRect(140, 10, 131, 16));
        label_accel->setFont(font);
        label_gearA = new QLabel(frame_details);
        label_gearA->setObjectName(QString::fromUtf8("label_gearA"));
        label_gearA->setGeometry(QRect(140, 40, 131, 16));
        label_gearA->setFont(font);
        lineEdit_gearA = new QLineEdit(frame_details);
        lineEdit_gearA->setObjectName(QString::fromUtf8("lineEdit_gearA"));
        lineEdit_gearA->setGeometry(QRect(10, 40, 113, 20));
        lineEdit_gearA->setFont(font);
        lineEdit_gearA->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_gearA->setMaxLength(8);
        lineEdit_gearB = new QLineEdit(frame_details);
        lineEdit_gearB->setObjectName(QString::fromUtf8("lineEdit_gearB"));
        lineEdit_gearB->setGeometry(QRect(10, 70, 113, 20));
        lineEdit_gearB->setFont(font);
        lineEdit_gearB->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_gearB->setMaxLength(8);
        label_gearB = new QLabel(frame_details);
        label_gearB->setObjectName(QString::fromUtf8("label_gearB"));
        label_gearB->setGeometry(QRect(140, 70, 131, 16));
        label_gearB->setFont(font);
        checkBox_dir = new QCheckBox(frame_details);
        checkBox_dir->setObjectName(QString::fromUtf8("checkBox_dir"));
        checkBox_dir->setGeometry(QRect(10, 100, 211, 17));
        comboBox_dozators = new QComboBox(frame_model);
        comboBox_dozators->setObjectName(QString::fromUtf8("comboBox_dozators"));
        comboBox_dozators->setGeometry(QRect(20, 180, 161, 22));
        frame_order = new QFrame(centralWidget);
        frame_order->setObjectName(QString::fromUtf8("frame_order"));
        frame_order->setGeometry(QRect(330, 50, 311, 441));
        frame_order->setFrameShape(QFrame::StyledPanel);
        frame_order->setFrameShadow(QFrame::Plain);
        listView_order = new QListView(frame_order);
        listView_order->setObjectName(QString::fromUtf8("listView_order"));
        listView_order->setGeometry(QRect(20, 20, 256, 192));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 666, 27));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_volume->setText(QApplication::translate("MainWindow", "\320\236\320\261\321\212\321\221\320\274, \320\274\320\272\320\273", nullptr));
        label_feedrate->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\264\320\260\321\207\320\260, \320\274\320\272\320\273/\320\274\320\270\320\275", nullptr));
        label_reverse->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\262\320\265\321\200\321\201, \320\274\320\272\320\273", nullptr));
        label_ratioAB->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\276\321\202\320\275\320\276\321\210\320\265\320\275\320\270\320\265 A:B", nullptr));
        label_accel->setText(QApplication::translate("MainWindow", "\320\243\321\201\320\272\320\276\321\200\320\265\320\275\320\270\320\265, \320\274\320\272\320\273/\320\274\320\270\320\275\321\201\320\265\320\272", nullptr));
        label_gearA->setText(QApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 \320\220", nullptr));
        label_gearB->setText(QApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 B", nullptr));
        checkBox_dir->setText(QApplication::translate("MainWindow", "\320\236\320\261\321\200\320\260\321\202\320\275\320\276\320\265 \320\275\320\260\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
