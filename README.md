# orangepi-zero
core image minimal for orange pi zero with initialize wifi


add these sentences to /etc/network/interface
auto wlan0
iface wlan0 inet dhcp
        pre-up wpa_supplicant -B -Dnl80211 -iwlan0 -c/etc/wpa_supplicant.conf
        post-down killall -q wpa_supplicant
