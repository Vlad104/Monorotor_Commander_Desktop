/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MC3/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[472];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 20), // "com_connected_signal"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 22), // "com_disconneted_signal"
QT_MOC_LITERAL(4, 56, 25), // "on_pushButton_com_clicked"
QT_MOC_LITERAL(5, 82, 27), // "on_pushButton_reset_clicked"
QT_MOC_LITERAL(6, 110, 28), // "on_pushButton_delete_clicked"
QT_MOC_LITERAL(7, 139, 25), // "on_pushButton_add_clicked"
QT_MOC_LITERAL(8, 165, 27), // "on_pushButton_start_clicked"
QT_MOC_LITERAL(9, 193, 33), // "on_pushButton_singleStart_cli..."
QT_MOC_LITERAL(10, 227, 12), // "com_conneted"
QT_MOC_LITERAL(11, 240, 15), // "com_disconneted"
QT_MOC_LITERAL(12, 256, 7), // "receive"
QT_MOC_LITERAL(13, 264, 16), // "transmit_timeout"
QT_MOC_LITERAL(14, 281, 32), // "on_tableView_order_doubleClicked"
QT_MOC_LITERAL(15, 314, 11), // "QModelIndex"
QT_MOC_LITERAL(16, 326, 5), // "index"
QT_MOC_LITERAL(17, 332, 26), // "on_pushButton_stop_clicked"
QT_MOC_LITERAL(18, 359, 31), // "on_pushButton_continues_clicked"
QT_MOC_LITERAL(19, 391, 39), // "on_pushButton_continues_press..."
QT_MOC_LITERAL(20, 431, 40) // "on_pushButton_continues_press..."

    },
    "MainWindow\0com_connected_signal\0\0"
    "com_disconneted_signal\0on_pushButton_com_clicked\0"
    "on_pushButton_reset_clicked\0"
    "on_pushButton_delete_clicked\0"
    "on_pushButton_add_clicked\0"
    "on_pushButton_start_clicked\0"
    "on_pushButton_singleStart_clicked\0"
    "com_conneted\0com_disconneted\0receive\0"
    "transmit_timeout\0on_tableView_order_doubleClicked\0"
    "QModelIndex\0index\0on_pushButton_stop_clicked\0"
    "on_pushButton_continues_clicked\0"
    "on_pushButton_continues_pressed_pressed\0"
    "on_pushButton_continues_pressed_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06 /* Public */,
       3,    0,  100,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x08 /* Private */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    0,  105,    2, 0x08 /* Private */,
       9,    0,  106,    2, 0x08 /* Private */,
      10,    0,  107,    2, 0x08 /* Private */,
      11,    0,  108,    2, 0x08 /* Private */,
      12,    0,  109,    2, 0x08 /* Private */,
      13,    0,  110,    2, 0x08 /* Private */,
      14,    1,  111,    2, 0x08 /* Private */,
      17,    0,  114,    2, 0x08 /* Private */,
      18,    0,  115,    2, 0x08 /* Private */,
      19,    0,  116,    2, 0x08 /* Private */,
      20,    0,  117,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->com_connected_signal(); break;
        case 1: _t->com_disconneted_signal(); break;
        case 2: _t->on_pushButton_com_clicked(); break;
        case 3: _t->on_pushButton_reset_clicked(); break;
        case 4: _t->on_pushButton_delete_clicked(); break;
        case 5: _t->on_pushButton_add_clicked(); break;
        case 6: _t->on_pushButton_start_clicked(); break;
        case 7: _t->on_pushButton_singleStart_clicked(); break;
        case 8: _t->com_conneted(); break;
        case 9: _t->com_disconneted(); break;
        case 10: _t->receive(); break;
        case 11: _t->transmit_timeout(); break;
        case 12: _t->on_tableView_order_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 13: _t->on_pushButton_stop_clicked(); break;
        case 14: _t->on_pushButton_continues_clicked(); break;
        case 15: _t->on_pushButton_continues_pressed_pressed(); break;
        case 16: _t->on_pushButton_continues_pressed_released(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::com_connected_signal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::com_disconneted_signal)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::com_connected_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::com_disconneted_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE