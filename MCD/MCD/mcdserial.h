#ifndef MCDSERIAL_H
#define MCDSERIAL_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QStringList>
#include <QEventLoop>
#include <QDebug>
#include <QThread>

#include "../../src/TransmitController.h"

const int wait_answer_times = 200;

class MCDSerial : public QSerialPort {
public:
    MCDSerial();
    QStringList get_ports();
    bool connect(const QString& port_name);
    void disconnect();
    bool get_status();
    void transmit(TransmitController& data);

private:
    bool connected_;
    QString receive_data_;
    void internal_connect(const QSerialPortInfo& info);
    bool check_protocol();
    void receive();

};

#endif // MCDSERIAL_H
