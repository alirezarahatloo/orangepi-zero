#ifndef UDP_H
#define UDP_H

#include <QObject>
#include <QUdpSocket>
#include <QtSerialPort/QSerialPort>

class udp : public QObject
{
    Q_OBJECT
public:
    explicit udp(QObject *parent = 0);
    QSerialPort* serial;
    QUdpSocket   *socket_udp;
    QByteArray Data_Serial;
private slots:
    void Read_Serial();
    void Read_Udp();

};

#endif // UDP_H
