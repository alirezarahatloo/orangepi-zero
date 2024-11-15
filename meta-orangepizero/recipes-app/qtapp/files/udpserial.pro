QT = core
QT += serialport
QT += network
TARGET = udpserial

CONFIG += c++17 cmdline

SOURCES += \
        main.cpp \
        udp.cpp

HEADERS += \
    udp.h
