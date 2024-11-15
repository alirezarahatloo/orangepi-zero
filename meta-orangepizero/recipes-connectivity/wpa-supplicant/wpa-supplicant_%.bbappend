FILESEXTRAPATHS_prepend := "${THISDIR}/files:"


# Install custom wpa_supplicant.conf
do_install_append() {
    install -D ${WORKDIR}/wpa_supplicant.conf ${D}/etc/wpa_supplicant.conf
}
