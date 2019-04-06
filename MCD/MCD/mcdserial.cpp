#include "mcdserial.h"

MCDSerial::MCDSerial()
{
    connected_ = false;
    receive_data_ = "";
    setParity(NoParity);
    setBaudRate(Baud19200);
    setDataBits(Data8);
    setStopBits(OneStop);

    QObject::connect(this, &QSerialPort::readyRead, this, &MCDSerial::receive);
}

QStringList MCDSerial::get_ports() {
    QStringList list;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        list << info.portName();
    }
    return list;
}

bool MCDSerial::connect(const QString& port_name) {
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        if (info.portName() == port_name) {
            internal_connect(info);
            if (!check_protocol()) {
                connected_ = false;
                return false;
            }
            connected_ = true;
            return true;
        }
    }
}

bool MCDSerial::check_protocol() {
    bool result = false;
    write("=0");
    QEventLoop evloop;
    for (int i = 0; i < wait_answer_times; i++) {
        QThread::msleep(1);
        evloop.processEvents();
    }
    if (receive_data_ == "!") {
        qDebug() << "Protocol OK";
        result = true;
    } else {
        qDebug() << "Protocol NOT OK";
        result = false;
    }
    receive_data_ = "";
    return result;

}

bool MCDSerial::get_status() {
    return connected_;
}

void MCDSerial::internal_connect(const QSerialPortInfo& info) {
    setPort(info);
    if (open(QIODevice::ReadWrite)) {
        qDebug() << "connected";
    }
}

void MCDSerial::disconnect() {
    close();
    connected_ = false;
    qDebug() << "disconnected";
}


void MCDSerial::transmit(TransmitController& data) {
    while (!data.is_empty()) {
        std::string command = data.get_command();
        write(command.c_str());
        qDebug() << QString::fromUtf8(command.data(), command.size());

        QEventLoop evloop;
        while(receive_data_ == "") { // Добавить таймаут
            evloop.processEvents();
        }
        qDebug() << receive_data_;
        if (receive_data_ == "!") {
            qDebug() << "Transmit complete!";
            receive_data_ = "";
        } else {
            qDebug() << "Transmit prodlem(";
            receive_data_ = "";
        }
    }
    qDebug() << "Command complete!";
    return;
}

void MCDSerial::receive() {
    const QByteArray data = readAll();
    receive_data_ = data;
    qDebug() << "RXed";
}

