QT = core
QT += network
QT += serialport
CONFIG += c++17 cmdline

SOURCES += \
        main.cpp \
        udp.cpp

HEADERS += \
    udp.h
