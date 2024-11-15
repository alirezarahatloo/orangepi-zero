SUMMARY = "UDP Packet Receiver"
DESCRIPTION = "A program to receive UDP packets on a specific port"
LICENSE = "CLOSED"
SRC_URI = "file://udp_receiver.c"

# Dependencies
#DEPENDS = "glibc"
S = "${WORKDIR}"

# Compilation steps
do_compile() {
    ${CC} ${CFLAGS} ${LDFLAGS} udp_receiver.c -o udp_receiver 
}

# Installation steps
do_install_append() {
    install -d ${D}${bindir}
    install -m 0755 udp_receiver ${D}${bindir}
}

FILES_${PN} += "${bindir}/udp_receiver"
