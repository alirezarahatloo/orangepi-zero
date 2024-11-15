#include "udp.h"
#include <qdebug.h>


udp::udp(QObject *parent) : QObject(parent) {
    qDebug() << "Initializing UDP and Serial...";
    //udp
    const int udpPort = 8866; // Change to your desired UDP port
    socket_udp = new QUdpSocket(this);
    if (socket_udp->bind(QHostAddress::Any, udpPort)) 
    {
        qDebug() << "Successfully bound to UDP port" << udpPort;
    } else 
    {
        qDebug() << "Failed to bind UDP socket:" << socket_udp->errorString();
    }
    connect(socket_udp, SIGNAL(readyRead()), this, SLOT(Read_Udp()));
    // Serial Port Initialization
    serial = new QSerialPort(this);
    serial->setPortName("/dev/ttyS1");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    if (!serial->open(QIODevice::ReadWrite)) 
    {
        qDebug() << "Failed to open serial port:" << serial->errorString();
    } 
    else 
    {
        qDebug() << "Serial port opened successfully.";
        connect(serial, SIGNAL(readyRead()), this, SLOT(Read_Serial()));  // Trigger Read_Serial() when data is available from the serial port
    }
}

void udp::Read_Serial()
{
    QByteArray data = serial->readAll();
    if (!data.isEmpty()) {
        qDebug() << "Received from Serial:" << data;
        socket_udp->writeDatagram(data, QHostAddress("192.168.1.4"), 8867);
    }
}

void udp::Read_Udp() 
{
    qDebug() << "UDP receive triggered";
    QByteArray buffer;
    buffer.resize(socket_udp->pendingDatagramSize());

    // Read the incoming UDP datagram
    socket_udp->readDatagram(buffer.data(), buffer.size());
    qDebug() << "Received UDP packet:" << buffer;

    if (serial->isOpen()) 
    {
        serial->write(buffer);
    } 
    else 
    {
        qDebug() << "Serial port is not open.";
    }
}
