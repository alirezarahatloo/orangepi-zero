#
# Build QT xyz application
#

SUMMARY = "..."
LICENSE = "CLOSED"

#Add whatever you need here
DEPENDS += " qtbase qtserialport"

SRC_URI = "file://udpserial.pro \
	   file://main.cpp \
	   file://udp.h \
	   file://udp.cpp \
	   "
S = "${WORKDIR}"

do_install_append () {
    install -d ${D}${bindir}
    install -m 0755 udpserial ${D}${bindir}/
}

FILES_${PN} += "${bindir}/udpserial"

inherit qmake5
#inherit update-rc.d
#INITSCRIPT_NAME="udpserial"
#INITSCRIPT_PARAMS= "defaults 10"
