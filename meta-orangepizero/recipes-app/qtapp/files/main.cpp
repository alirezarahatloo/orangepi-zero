#include <QCoreApplication>
#include "udp.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    udp Udpins;
    return a.exec();
}
