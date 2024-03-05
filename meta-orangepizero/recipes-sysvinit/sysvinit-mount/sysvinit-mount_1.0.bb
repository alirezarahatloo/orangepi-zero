DESCRIPTION = "Initscripts for mounting filesystems"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"

SRC_URI = "file://alireza.sh"
INITSCRIPT_NAME = "alireza.sh"
INITSCRIPT_PARAMS = "defaults 10"
inherit update-rc.d
S = "${WORKDIR}"
do_install () {
install -d ${D}${sysconfdir}/init.d/
install -c -m 755 ${WORKDIR}/${INITSCRIPT_NAME} ${D}${sysconfdir}/init.d/${INITSCRIPT_NAME}
}
