VERSION		:= 1.2-pre11

ETCDIR		:= /etc
SHELL		:= /bin/bash
EXTDIR		:= ${DESTDIR}${ETCDIR}
MODE		:= 754
DIRMODE		:= 755
CONFMODE	:= 644

all:
	@grep "^install" Makefile | cut -d ":" -f 1
	@echo "dist"
	@echo "Select an appropriate install target from the above list" ; exit 1

.PHONY: dist
dist:
	rm -rf "dist/bootscripts-cross-lfs-$(VERSION)"
	mkdir -p "dist/bootscripts-cross-lfs-$(VERSION)"
	tar --exclude dist -c * | tar -x -C "dist/bootscripts-cross-lfs-$(VERSION)"
	(cd dist; tar -cjf "bootscripts-cross-lfs-$(VERSION).tar.bz2" "bootscripts-cross-lfs-$(VERSION)")
	rm -rf "dist/bootscripts-cross-lfs-$(VERSION)"

create-dirs:
	install -d -m ${DIRMODE} ${EXTDIR}/rc.d/rc{0,1,2,3,4,5,6,sysinit}.d
	install -d -m ${DIRMODE} ${EXTDIR}/rc.d/init.d
	install -d -m ${DIRMODE} ${EXTDIR}/sysconfig

create-service-dir:
	install -d -m ${DIRMODE} ${EXTDIR}/sysconfig/network-devices/services

udev_device_dirs:
	install -d -m ${DIRMODE} ${DESTDIR}/lib/udev/devices/{pts,shm,net}

udev_device_links: udev_device_dirs
	ln -snf /proc/self/fd ${DESTDIR}/lib/udev/devices/fd
	ln -snf /proc/self/fd/0 ${DESTDIR}/lib/udev/devices/stdin
	ln -snf /proc/self/fd/1 ${DESTDIR}/lib/udev/devices/stdout
	ln -snf /proc/self/fd/2 ${DESTDIR}/lib/udev/devices/stderr
	ln -snf /proc/kcore ${DESTDIR}/lib/udev/devices/core

mknod_devices: udev_device_dirs
	@if [ "$$UID" = "0" ]; then \
		if ! [ -e ${DESTDIR}/lib/udev/devices/null ]; then \
			mknod -m 0666 ${DESTDIR}/lib/udev/devices/null c 1 3 ;\
		fi \
	fi
	@if [ "$$UID" = "0" ]; then \
		if ! [ -e ${DESTDIR}/lib/udev/devices/console ]; then \
			mknod -m 0600 ${DESTDIR}/lib/udev/devices/console c 5 1 ;\
		fi \
	fi
	@if [ "$$UID" != "0" ]; then \
		if ! [ -e ${DESTDIR}/lib/udev/devices/null ]; then \
			echo "You will need to issue the following command as the root user" ;\
			echo "" ;\
			echo "mknod -m 0666 ${DESTDIR}/lib/udev/devices/null c 1 3" ;\
		fi \
	fi
	@if [ "$$UID" != "0" ]; then \
		if ! [ -e ${DESTDIR}/lib/udev/devices/console ]; then \
			echo "mknod -m 0600 ${DESTDIR}/lib/udev/devices/console c 5 1" ;\
			echo "" ;\
		fi \
	fi

install-bootscripts: create-dirs create-service-dir udev_device_dirs udev_device_links

	install -m ${MODE} clfs/init.d/checkfs       ${EXTDIR}/rc.d/init.d/
	install -m ${MODE} clfs/init.d/cleanfs       ${EXTDIR}/rc.d/init.d/
	install -m ${CONFMODE} clfs/init.d/functions ${EXTDIR}/rc.d/init.d/
	install -m ${MODE} clfs/init.d/halt          ${EXTDIR}/rc.d/init.d/
	install -m ${MODE} clfs/init.d/consolelog    ${EXTDIR}/rc.d/init.d/
	install -m ${MODE} clfs/init.d/i18n          ${EXTDIR}/rc.d/init.d/
	install -m ${MODE} clfs/init.d/localnet      ${EXTDIR}/rc.d/init.d/
	install -m ${MODE} clfs/init.d/modules       ${EXTDIR}/rc.d/init.d/
	install -m ${MODE} clfs/init.d/mountfs       ${EXTDIR}/rc.d/init.d/
	install -m ${MODE} clfs/init.d/mountkernfs   ${EXTDIR}/rc.d/init.d/
	install -m ${MODE} clfs/init.d/rc            ${EXTDIR}/rc.d/init.d/
	install -m ${MODE} clfs/init.d/reboot        ${EXTDIR}/rc.d/init.d/
	install -m ${MODE} clfs/init.d/sendsignals   ${EXTDIR}/rc.d/init.d/
	install -m ${MODE} clfs/init.d/setclock	     ${EXTDIR}/rc.d/init.d/
	install -m ${MODE} clfs/init.d/rsyslog       ${EXTDIR}/rc.d/init.d/
	install -m ${MODE} clfs/init.d/swap          ${EXTDIR}/rc.d/init.d/
	install -m ${MODE} clfs/init.d/sysctl        ${EXTDIR}/rc.d/init.d/
	install -m ${MODE} clfs/init.d/template      ${EXTDIR}/rc.d/init.d/
	install -m ${MODE} clfs/init.d/udev          ${EXTDIR}/rc.d/init.d/
	ln -sf ../init.d/rsyslog     ${EXTDIR}/rc.d/rc0.d/K90rsyslog
	ln -sf ../init.d/sendsignals ${EXTDIR}/rc.d/rc0.d/S60sendsignals
	ln -sf ../init.d/mountfs     ${EXTDIR}/rc.d/rc0.d/S70mountfs
	ln -sf ../init.d/swap        ${EXTDIR}/rc.d/rc0.d/S80swap
	ln -sf ../init.d/localnet    ${EXTDIR}/rc.d/rc0.d/S90localnet
	ln -sf ../init.d/halt        ${EXTDIR}/rc.d/rc0.d/S99halt
	ln -sf ../init.d/rsyslog     ${EXTDIR}/rc.d/rc1.d/S10rsyslog
	ln -sf ../init.d/rsyslog     ${EXTDIR}/rc.d/rc2.d/S10rsyslog
	ln -sf ../init.d/rsyslog     ${EXTDIR}/rc.d/rc3.d/S10rsyslog
	ln -sf ../init.d/rsyslog     ${EXTDIR}/rc.d/rc4.d/S10rsyslog
	ln -sf ../init.d/rsyslog     ${EXTDIR}/rc.d/rc5.d/S10rsyslog
	ln -sf ../init.d/rsyslog     ${EXTDIR}/rc.d/rc6.d/K90rsyslog
	ln -sf ../init.d/sendsignals ${EXTDIR}/rc.d/rc6.d/S60sendsignals
	ln -sf ../init.d/mountfs     ${EXTDIR}/rc.d/rc6.d/S70mountfs
	ln -sf ../init.d/swap        ${EXTDIR}/rc.d/rc6.d/S80swap
	ln -sf ../init.d/localnet    ${EXTDIR}/rc.d/rc6.d/S90localnet
	ln -sf ../init.d/reboot      ${EXTDIR}/rc.d/rc6.d/S99reboot
	ln -sf ../init.d/mountkernfs ${EXTDIR}/rc.d/rcsysinit.d/S00mountkernfs
	ln -sf ../init.d/consolelog  ${EXTDIR}/rc.d/rcsysinit.d/S02consolelog
	ln -sf ../init.d/modules     ${EXTDIR}/rc.d/rcsysinit.d/S05modules
	ln -sf ../init.d/udev        ${EXTDIR}/rc.d/rcsysinit.d/S10udev
	ln -sf ../init.d/setclock    ${EXTDIR}/rc.d/rcsysinit.d/S15setclock
	ln -sf ../init.d/checkfs     ${EXTDIR}/rc.d/rcsysinit.d/S20checkfs
	ln -sf ../init.d/mountfs     ${EXTDIR}/rc.d/rcsysinit.d/S30mountfs
	ln -sf ../init.d/swap        ${EXTDIR}/rc.d/rcsysinit.d/S40swap
	ln -sf ../init.d/cleanfs     ${EXTDIR}/rc.d/rcsysinit.d/S50cleanfs
	ln -sf ../init.d/i18n        ${EXTDIR}/rc.d/rcsysinit.d/S70i18n
	ln -sf ../init.d/localnet    ${EXTDIR}/rc.d/rcsysinit.d/S80localnet
	ln -sf ../init.d/sysctl      ${EXTDIR}/rc.d/rcsysinit.d/S90sysctl
	if [ ! -f ${EXTDIR}/sysconfig/bootscripts ]; then install -m ${CONFMODE} clfs/sysconfig/bootscripts ${EXTDIR}/sysconfig/bootscripts; fi
	if [ ! -f ${EXTDIR}/sysconfig/createfiles ]; then install -m ${CONFMODE} clfs/sysconfig/createfiles ${EXTDIR}/sysconfig/; fi
	if [ ! -f ${EXTDIR}/sysconfig/i18n        ]; then install -m ${CONFMODE} clfs/sysconfig/i18n        ${EXTDIR}/sysconfig/; fi
	if [ ! -f ${EXTDIR}/sysconfig/modules     ]; then install -m ${CONFMODE} clfs/sysconfig/modules     ${EXTDIR}/sysconfig/; fi
	if [ ! -f ${EXTDIR}/sysconfig/rc          ]; then install -m ${CONFMODE} clfs/sysconfig/rc          ${EXTDIR}/sysconfig/; fi
	@$(MAKE) mknod_devices

install-network: create-dirs create-service-dir

	install -m ${MODE} clfs/init.d/network       ${EXTDIR}/rc.d/init.d/
	ln -sf ../init.d/network     ${EXTDIR}/rc.d/rc0.d/K80network
	ln -sf ../init.d/network     ${EXTDIR}/rc.d/rc1.d/K80network
	ln -sf ../init.d/network     ${EXTDIR}/rc.d/rc2.d/S20network
	ln -sf ../init.d/network     ${EXTDIR}/rc.d/rc3.d/S20network
	ln -sf ../init.d/network     ${EXTDIR}/rc.d/rc4.d/S20network
	ln -sf ../init.d/network     ${EXTDIR}/rc.d/rc5.d/S20network
	ln -sf ../init.d/network     ${EXTDIR}/rc.d/rc6.d/K80network
	install                   -m ${MODE} clfs/sysconfig/network-devices/ifup   ${EXTDIR}/sysconfig/network-devices/
	install                   -m ${MODE} clfs/sysconfig/network-devices/ifdown ${EXTDIR}/sysconfig/network-devices/
	install                   -m ${MODE} clfs/sysconfig/network-devices/services/ipv4-static       ${EXTDIR}/sysconfig/network-devices/services/
	install                   -m ${MODE} clfs/sysconfig/network-devices/services/ipv4-static-route ${EXTDIR}/sysconfig/network-devices/services/

install-service-mtu: create-service-dir
	install -m ${MODE} contrib/sysconfig/network-devices/services/mtu ${EXTDIR}/sysconfig/network-devices/services

install-minimal: create-dirs create-service-dir udev_device_dirs udev_device_links
	sed -e 's|/bin:/usr/bin:/sbin:/usr/sbin|/tools/bin:/tools/sbin:/bin:/sbin|g' clfs/init.d/functions > clfs/init.d/functions.minimal
	install -m ${MODE} clfs/init.d/checkfs       		${EXTDIR}/rc.d/init.d/
	install -m ${MODE} clfs/init.d/cleanfs       		${EXTDIR}/rc.d/init.d/
	install -m ${CONFMODE} clfs/init.d/functions.minimal	${EXTDIR}/rc.d/init.d/functions
	install -m ${MODE} clfs/init.d/halt          		${EXTDIR}/rc.d/init.d/
	install -m ${MODE} clfs/init.d/localnet      		${EXTDIR}/rc.d/init.d/
	install -m ${MODE} clfs/init.d/mountfs       		${EXTDIR}/rc.d/init.d/
	install -m ${MODE} clfs/init.d/mountkernfs   		${EXTDIR}/rc.d/init.d/
	install -m ${MODE} clfs/init.d/rc            		${EXTDIR}/rc.d/init.d/
	install -m ${MODE} clfs/init.d/reboot        		${EXTDIR}/rc.d/init.d/
	install -m ${MODE} clfs/init.d/sendsignals   		${EXTDIR}/rc.d/init.d/
	install -m ${MODE} clfs/init.d/setclock      		${EXTDIR}/rc.d/init.d/
	install -m ${MODE} clfs/init.d/swap          		${EXTDIR}/rc.d/init.d/
	install -m ${MODE} clfs/init.d/udev          		${EXTDIR}/rc.d/init.d/
	ln -sf ../init.d/sendsignals ${EXTDIR}/rc.d/rc0.d/S60sendsignals
	ln -sf ../init.d/mountfs     ${EXTDIR}/rc.d/rc0.d/S70mountfs
	ln -sf ../init.d/swap        ${EXTDIR}/rc.d/rc0.d/S80swap
	ln -sf ../init.d/halt        ${EXTDIR}/rc.d/rc0.d/S99halt
	ln -sf ../init.d/sendsignals ${EXTDIR}/rc.d/rc6.d/S60sendsignals
	ln -sf ../init.d/mountfs     ${EXTDIR}/rc.d/rc6.d/S70mountfs
	ln -sf ../init.d/swap        ${EXTDIR}/rc.d/rc6.d/S80swap
	ln -sf ../init.d/reboot      ${EXTDIR}/rc.d/rc6.d/S99reboot
	ln -sf ../init.d/mountkernfs ${EXTDIR}/rc.d/rcsysinit.d/S00mountkernfs
	ln -sf ../init.d/udev        ${EXTDIR}/rc.d/rcsysinit.d/S10udev
	ln -sf ../init.d/checkfs     ${EXTDIR}/rc.d/rcsysinit.d/S20checkfs
	ln -sf ../init.d/mountfs     ${EXTDIR}/rc.d/rcsysinit.d/S30mountfs
	ln -sf ../init.d/swap        ${EXTDIR}/rc.d/rcsysinit.d/S40swap
	ln -sf ../init.d/cleanfs     ${EXTDIR}/rc.d/rcsysinit.d/S50cleanfs
	ln -sf ../init.d/setclock    ${EXTDIR}/rc.d/rcsysinit.d/S60setclock
	if [ ! -f ${EXTDIR}/sysconfig/rc          ]; then install -m ${CONFMODE} clfs/sysconfig/rc          ${EXTDIR}/sysconfig/; fi
	if [ ! -f ${EXTDIR}/sysconfig/createfiles ]; then install -m ${CONFMODE} clfs/sysconfig/createfiles ${EXTDIR}/sysconfig/; fi
	@$(MAKE) mknod_devices

install-raq2: create-dirs
	install -m ${MODE} clfs/init.d/paneld        ${EXTDIR}/rc.d/init.d/
	ln -sf ../init.d/paneld      ${EXTDIR}/rc.d/rc0.d/K01paneld
	ln -sf ../init.d/paneld      ${EXTDIR}/rc.d/rc1.d/S99paneld
	ln -sf ../init.d/paneld      ${EXTDIR}/rc.d/rc2.d/S99paneld
	ln -sf ../init.d/paneld      ${EXTDIR}/rc.d/rc3.d/S99paneld
	ln -sf ../init.d/paneld      ${EXTDIR}/rc.d/rc4.d/S99paneld
	ln -sf ../init.d/paneld      ${EXTDIR}/rc.d/rc5.d/S99paneld
	ln -sf ../init.d/paneld      ${EXTDIR}/rc.d/rc6.d/K01paneld
	if [ ! -f ${EXTDIR}/sysconfig/lcd          ]; then install -m ${CONFMODE} clfs/sysconfig/lcd-raq2   ${EXTDIR}/sysconfig/lcd; fi

install-raq3: create-dirs
	install -m ${MODE} clfs/init.d/setlcd        ${EXTDIR}/rc.d/init.d/
	ln -sf ../init.d/setlcd      ${EXTDIR}/rc.d/rc0.d/K01setlcd
	ln -sf ../init.d/setlcd      ${EXTDIR}/rc.d/rc1.d/S99setlcd
	ln -sf ../init.d/setlcd      ${EXTDIR}/rc.d/rc2.d/S99setlcd
	ln -sf ../init.d/setlcd      ${EXTDIR}/rc.d/rc3.d/S99setlcd
	ln -sf ../init.d/setlcd      ${EXTDIR}/rc.d/rc4.d/S99setlcd
	ln -sf ../init.d/setlcd      ${EXTDIR}/rc.d/rc5.d/S99setlcd
	ln -sf ../init.d/setlcd      ${EXTDIR}/rc.d/rc6.d/K01setlcd
	if [ ! -f ${EXTDIR}/sysconfig/lcd          ]; then install -m ${CONFMODE} clfs/sysconfig/lcd-raq3   ${EXTDIR}/sysconfig/lcd; fi

install-lcd: create-dirs
	if [ ! -f ${EXTDIR}/sysconfig/lcd          ]; then install -m ${CONFMODE} clfs/sysconfig/lcd        ${EXTDIR}/sysconfig/lcd; fi

install-service-dhclient: create-service-dir
	install -m ${MODE} cblfs/sysconfig/network-devices/services/dhclient ${EXTDIR}/sysconfig/network-devices/services

install-service-dhcpcd: create-service-dir
	install -m ${MODE} cblfs/sysconfig/network-devices/services/dhcpcd   ${EXTDIR}/sysconfig/network-devices/services

install-service-ipx: create-service-dir
	install -m ${MODE} cblfs/sysconfig/network-devices/services/ipx      ${EXTDIR}/sysconfig/network-devices/services

install-service-pppoe: create-service-dir
	install -m ${MODE} cblfs/sysconfig/network-devices/services/pppoe    ${EXTDIR}/sysconfig/network-devices/services

install-netboot: create-dirs create-service-dir udev_device_dirs udev_device_links
	rm -rf ${EXTDIR}/rc.d
	install -d -m ${DIRMODE} ${EXTDIR}/rc.d
	install -m ${MODE} netboot/rc.0         ${EXTDIR}/rc.d/
	install -m ${MODE} netboot/rc.1         ${EXTDIR}/rc.d/
	install -m ${MODE} netboot/rc.sysinit ${EXTDIR}/rc.d/
	if [ ! -f ${EXTDIR}/inittab ]; then install -m ${CONFMODE} netboot/inittab ${EXTDIR}/inittab; fi
	ln -sf ../rc.d/rc.0 ${EXTDIR}/rc.d/rc.6
	ln -sf ../rc.d/rc.1 ${EXTDIR}/rc.d/rc.2
	ln -sf ../rc.d/rc.1 ${EXTDIR}/rc.d/rc.3
	ln -sf ../rc.d/rc.1 ${EXTDIR}/rc.d/rc.4
	ln -sf ../rc.d/rc.1 ${EXTDIR}/rc.d/rc.5

install-alsa: create-dirs
	install -m ${MODE} cblfs/init.d/alsa       ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/alsa ${EXTDIR}/rc.d/rc0.d/K35alsa
	ln -sf  ../init.d/alsa ${EXTDIR}/rc.d/rc1.d/K35alsa
	ln -sf  ../init.d/alsa ${EXTDIR}/rc.d/rc6.d/K35alsa

install-apache: create-dirs
	install -m ${MODE} cblfs/init.d/apache     ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/apache ${EXTDIR}/rc.d/rc0.d/K28apache
	ln -sf  ../init.d/apache ${EXTDIR}/rc.d/rc1.d/K28apache
	ln -sf  ../init.d/apache ${EXTDIR}/rc.d/rc2.d/K28apache
	ln -sf  ../init.d/apache ${EXTDIR}/rc.d/rc3.d/S32apache
	ln -sf  ../init.d/apache ${EXTDIR}/rc.d/rc4.d/S32apache
	ln -sf  ../init.d/apache ${EXTDIR}/rc.d/rc5.d/S32apache
	ln -sf  ../init.d/apache ${EXTDIR}/rc.d/rc6.d/K28apache

install-autofs: create-dirs
	install -m $(MODE) cblfs/init.d/autofs    $(EXTDIR)/rc.d/init.d/
	install -m $(CONFMODE) cblfs/sysconfig/autofs.conf $(EXTDIR)/sysconfig/
	ln -sf  ../init.d/autofs $(EXTDIR)/rc.d/rcsysinit.d/S52autofs

install-bind: create-dirs
	install -m ${MODE} cblfs/init.d/bind       ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/bind ${EXTDIR}/rc.d/rc0.d/K49bind
	ln -sf  ../init.d/bind ${EXTDIR}/rc.d/rc1.d/K49bind
	ln -sf  ../init.d/bind ${EXTDIR}/rc.d/rc2.d/K49bind
	ln -sf  ../init.d/bind ${EXTDIR}/rc.d/rc3.d/S22bind
	ln -sf  ../init.d/bind ${EXTDIR}/rc.d/rc4.d/S22bind
	ln -sf  ../init.d/bind ${EXTDIR}/rc.d/rc5.d/S22bind
	ln -sf  ../init.d/bind ${EXTDIR}/rc.d/rc6.d/K49bind

install-cluster-all: create-dirs
	install -m ${MODE} cblfs/init.d/cluster	${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/cluster ${EXTDIR}/rc.d/rc0.d/K15cluster
	ln -sf  ../init.d/cluster ${EXTDIR}/rc.d/rc1.d/K15cluster
	ln -sf  ../init.d/cluster ${EXTDIR}/rc.d/rc2.d/K15cluster
	ln -sf  ../init.d/cluster ${EXTDIR}/rc.d/rc3.d/S99cluster
	ln -sf  ../init.d/cluster ${EXTDIR}/rc.d/rc4.d/S99cluster
	ln -sf  ../init.d/cluster ${EXTDIR}/rc.d/rc5.d/S99cluster
	ln -sf  ../init.d/cluster ${EXTDIR}/rc.d/rc6.d/K15cluster

install-cups: create-dirs
	install -m ${MODE} cblfs/init.d/cups       ${EXTDIR}/rc.d/init.d/
	rm -f ${EXTDIR}/rc.d/rc0.d/K36cups
	rm -f ${EXTDIR}/rc.d/rc2.d/K36cups
	rm -f ${EXTDIR}/rc.d/rc3.d/K36cups
	rm -f ${EXTDIR}/rc.d/rc5.d/K36cups
	rm -f ${EXTDIR}/rc.d/rc2.d/S81cups
	rm -f ${EXTDIR}/rc.d/rc3.d/S81cups
	rm -f ${EXTDIR}/rc.d/rc5.d/S81cups
	ln -sf  ../init.d/cups ${EXTDIR}/rc.d/rc0.d/K00cups
	ln -sf  ../init.d/cups ${EXTDIR}/rc.d/rc1.d/K00cups
	ln -sf  ../init.d/cups ${EXTDIR}/rc.d/rc2.d/S25cups
	ln -sf  ../init.d/cups ${EXTDIR}/rc.d/rc3.d/S25cups
	ln -sf  ../init.d/cups ${EXTDIR}/rc.d/rc4.d/S25cups
	ln -sf  ../init.d/cups ${EXTDIR}/rc.d/rc5.d/S25cups
	ln -sf  ../init.d/cups ${EXTDIR}/rc.d/rc6.d/K00cups

install-cyrus-sasl: create-dirs
	install -m ${MODE} cblfs/init.d/cyrus-sasl ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/cyrus-sasl ${EXTDIR}/rc.d/rc0.d/K49cyrus-sasl
	ln -sf  ../init.d/cyrus-sasl ${EXTDIR}/rc.d/rc1.d/K49cyrus-sasl
	ln -sf  ../init.d/cyrus-sasl ${EXTDIR}/rc.d/rc2.d/S24cyrus-sasl
	ln -sf  ../init.d/cyrus-sasl ${EXTDIR}/rc.d/rc3.d/S24cyrus-sasl
	ln -sf  ../init.d/cyrus-sasl ${EXTDIR}/rc.d/rc4.d/S24cyrus-sasl
	ln -sf  ../init.d/cyrus-sasl ${EXTDIR}/rc.d/rc5.d/S24cyrus-sasl
	ln -sf  ../init.d/cyrus-sasl ${EXTDIR}/rc.d/rc6.d/K49cyrus-sasl

install-dbus: create-dirs
	install -m ${MODE} cblfs/init.d/dbus ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/dbus ${EXTDIR}/rc.d/rc0.d/K30dbus
	ln -sf  ../init.d/dbus ${EXTDIR}/rc.d/rc1.d/K30dbus
	ln -sf  ../init.d/dbus ${EXTDIR}/rc.d/rc2.d/S20dbus
	ln -sf  ../init.d/dbus ${EXTDIR}/rc.d/rc3.d/S20dbus
	ln -sf  ../init.d/dbus ${EXTDIR}/rc.d/rc4.d/S20dbus
	ln -sf  ../init.d/dbus ${EXTDIR}/rc.d/rc5.d/S20dbus
	ln -sf  ../init.d/dbus ${EXTDIR}/rc.d/rc6.d/K30dbus

install-devmapper: create-dirs
	install -m ${MODE} cblfs/init.d/devmapper  ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/devmapper ${EXTDIR}/rc.d/rcsysinit.d/S15devmapper

install-dhcp: create-dirs
	install -m ${MODE} cblfs/init.d/dhcp       ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/dhcp ${EXTDIR}/rc.d/rc0.d/K30dhcp
	ln -sf  ../init.d/dhcp ${EXTDIR}/rc.d/rc1.d/K30dhcp
	ln -sf  ../init.d/dhcp ${EXTDIR}/rc.d/rc2.d/K30dhcp
	ln -sf  ../init.d/dhcp ${EXTDIR}/rc.d/rc3.d/S30dhcp
	ln -sf  ../init.d/dhcp ${EXTDIR}/rc.d/rc4.d/S30dhcp
	ln -sf  ../init.d/dhcp ${EXTDIR}/rc.d/rc5.d/S30dhcp
	ln -sf  ../init.d/dhcp ${EXTDIR}/rc.d/rc6.d/K30dhcp

install-exim: create-dirs
	install -m ${MODE} cblfs/init.d/exim       ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/exim ${EXTDIR}/rc.d/rc0.d/K25exim
	ln -sf  ../init.d/exim ${EXTDIR}/rc.d/rc1.d/K25exim
	ln -sf  ../init.d/exim ${EXTDIR}/rc.d/rc2.d/K25exim
	ln -sf  ../init.d/exim ${EXTDIR}/rc.d/rc3.d/S35exim
	ln -sf  ../init.d/exim ${EXTDIR}/rc.d/rc4.d/S35exim
	ln -sf  ../init.d/exim ${EXTDIR}/rc.d/rc5.d/S35exim
	ln -sf  ../init.d/exim ${EXTDIR}/rc.d/rc6.d/K25exim

install-fam: create-dirs
	install -m ${MODE} cblfs/init.d/fam      ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/fam ${EXTDIR}/rc.d/rc0.d/K37fam
	ln -sf  ../init.d/fam ${EXTDIR}/rc.d/rc1.d/K37fam
	ln -sf  ../init.d/fam ${EXTDIR}/rc.d/rc2.d/S23fam
	ln -sf  ../init.d/fam ${EXTDIR}/rc.d/rc3.d/S23fam
	ln -sf  ../init.d/fam ${EXTDIR}/rc.d/rc4.d/S23fam
	ln -sf  ../init.d/fam ${EXTDIR}/rc.d/rc5.d/S23fam
	ln -sf  ../init.d/fam ${EXTDIR}/rc.d/rc6.d/K39fam

install-fcron: create-dirs
	install -m ${MODE} cblfs/init.d/fcron      ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/fcron ${EXTDIR}/rc.d/rc0.d/K08fcron
	ln -sf  ../init.d/fcron ${EXTDIR}/rc.d/rc1.d/K08fcron
	ln -sf  ../init.d/fcron ${EXTDIR}/rc.d/rc2.d/S40fcron
	ln -sf  ../init.d/fcron ${EXTDIR}/rc.d/rc3.d/S40fcron
	ln -sf  ../init.d/fcron ${EXTDIR}/rc.d/rc4.d/S40fcron
	ln -sf  ../init.d/fcron ${EXTDIR}/rc.d/rc5.d/S40fcron
	ln -sf  ../init.d/fcron ${EXTDIR}/rc.d/rc6.d/K08fcron

install-gdm: create-dirs
	install -m ${MODE} cblfs/init.d/gdm        ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/gdm ${EXTDIR}/rc.d/rc0.d/K05gdm
	ln -sf  ../init.d/gdm ${EXTDIR}/rc.d/rc1.d/K05gdm
	ln -sf  ../init.d/gdm ${EXTDIR}/rc.d/rc2.d/K05gdm
	ln -sf  ../init.d/gdm ${EXTDIR}/rc.d/rc3.d/K05gdm
	ln -sf  ../init.d/gdm ${EXTDIR}/rc.d/rc4.d/K05gdm
	ln -sf  ../init.d/gdm ${EXTDIR}/rc.d/rc5.d/S95gdm
	ln -sf  ../init.d/gdm ${EXTDIR}/rc.d/rc6.d/K05gdm

install-gmetad:
	install -m ${MODE} cblfs/init.d/gmetad	${EXTDIR}/rc.d/init.d
	ln -sf  ../init.d/gmetad ${EXTDIR}/rc.d/rc0.d/K15gmetad
	ln -sf  ../init.d/gmetad ${EXTDIR}/rc.d/rc1.d/K15gmetad
	ln -sf  ../init.d/gmetad ${EXTDIR}/rc.d/rc2.d/K15gmetad
	ln -sf  ../init.d/gmetad ${EXTDIR}/rc.d/rc3.d/S99gmetad
	ln -sf  ../init.d/gmetad ${EXTDIR}/rc.d/rc4.d/S99gmetad
	ln -sf  ../init.d/gmetad ${EXTDIR}/rc.d/rc5.d/S99gmetad
	ln -sf  ../init.d/gmetad ${EXTDIR}/rc.d/rc6.d/K15gmetad

install-gmond:
	install -m ${MODE} cblfs/init.d/gmond       ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/gmond ${EXTDIR}/rc.d/rc0.d/K15gmond
	ln -sf  ../init.d/gmond ${EXTDIR}/rc.d/rc1.d/K15gmond
	ln -sf  ../init.d/gmond ${EXTDIR}/rc.d/rc2.d/K15gmond
	ln -sf  ../init.d/gmond ${EXTDIR}/rc.d/rc3.d/S99gmond
	ln -sf  ../init.d/gmond ${EXTDIR}/rc.d/rc4.d/S99gmond
	ln -sf  ../init.d/gmond ${EXTDIR}/rc.d/rc5.d/S99gmond
	ln -sf  ../init.d/gmond ${EXTDIR}/rc.d/rc6.d/K15gmond

install-gpm: create-dirs
	install -m ${MODE} cblfs/init.d/gpm        ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/gpm ${EXTDIR}/rc.d/rc0.d/K10gpm
	ln -sf  ../init.d/gpm ${EXTDIR}/rc.d/rc1.d/K10gpm
	ln -sf  ../init.d/gpm ${EXTDIR}/rc.d/rc2.d/S70gpm
	ln -sf  ../init.d/gpm ${EXTDIR}/rc.d/rc3.d/S70gpm
	ln -sf  ../init.d/gpm ${EXTDIR}/rc.d/rc4.d/S70gpm
	ln -sf  ../init.d/gpm ${EXTDIR}/rc.d/rc5.d/S70gpm
	ln -sf  ../init.d/gpm ${EXTDIR}/rc.d/rc6.d/K10gpm

install-haldaemon: create-dirs
	install -m ${MODE} cblfs/init.d/haldaemon      ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/haldaemon ${EXTDIR}/rc.d/rc0.d/K29haldaemon
	ln -sf  ../init.d/haldaemon ${EXTDIR}/rc.d/rc1.d/K29haldaemon
	ln -sf  ../init.d/haldaemon ${EXTDIR}/rc.d/rc2.d/S21haldaemon
	ln -sf  ../init.d/haldaemon ${EXTDIR}/rc.d/rc3.d/S21haldaemon
	ln -sf  ../init.d/haldaemon ${EXTDIR}/rc.d/rc4.d/S21haldaemon
	ln -sf  ../init.d/haldaemon ${EXTDIR}/rc.d/rc5.d/S21haldaemon
	ln -sf  ../init.d/haldaemon ${EXTDIR}/rc.d/rc6.d/K29haldaemon

install-heimdal: create-dirs
	install -m ${MODE} cblfs/init.d/heimdal        ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/heimdal ${EXTDIR}/rc.d/rc0.d/K42heimdal
	ln -sf  ../init.d/heimdal ${EXTDIR}/rc.d/rc1.d/K42heimdal
	ln -sf  ../init.d/heimdal ${EXTDIR}/rc.d/rc2.d/K42heimdal
	ln -sf  ../init.d/heimdal ${EXTDIR}/rc.d/rc3.d/S28heimdal
	ln -sf  ../init.d/heimdal ${EXTDIR}/rc.d/rc4.d/S28heimdal
	ln -sf  ../init.d/heimdal ${EXTDIR}/rc.d/rc5.d/S28heimdal
	ln -sf  ../init.d/heimdal ${EXTDIR}/rc.d/rc6.d/K42heimdal

install-iptables: create-dirs
	install -m ${MODE} cblfs/init.d/iptables        ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/iptables ${EXTDIR}/rc.d/rc3.d/S19iptables
	ln -sf  ../init.d/iptables ${EXTDIR}/rc.d/rc4.d/S19iptables
	ln -sf  ../init.d/iptables ${EXTDIR}/rc.d/rc5.d/S19iptables

install-kerberos: create-dirs
	install -m ${MODE} cblfs/init.d/kerberos ${EXTDIR}/rc.d/init.d/
	ln -sf ../init.d/kerberos ${EXTDIR}/rc.d/rc0.d/K42kerberos
	ln -sf ../init.d/kerberos ${EXTDIR}/rc.d/rc1.d/K42kerberos
	ln -sf ../init.d/kerberos ${EXTDIR}/rc.d/rc2.d/K42kerberos
	ln -sf ../init.d/kerberos ${EXTDIR}/rc.d/rc3.d/S28kerberos
	ln -sf ../init.d/kerberos ${EXTDIR}/rc.d/rc4.d/S28kerberos
	ln -sf ../init.d/kerberos ${EXTDIR}/rc.d/rc5.d/S28kerberos
	ln -sf ../init.d/kerberos ${EXTDIR}/rc.d/rc6.d/K42kerberos

install-LCDd: create-dirs
	install -m ${MODE} cblfs/init.d/LCDd ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/LCDd ${EXTDIR}/rc.d/rc0.d/K65LCDd
	ln -sf  ../init.d/LCDd ${EXTDIR}/rc.d/rc1.d/K65LCDd
	ln -sf  ../init.d/LCDd ${EXTDIR}/rc.d/rc2.d/K65LCDd
	ln -sf  ../init.d/LCDd ${EXTDIR}/rc.d/rc3.d/S35LCDd
	ln -sf  ../init.d/LCDd ${EXTDIR}/rc.d/rc4.d/S35LCDd
	ln -sf  ../init.d/LCDd ${EXTDIR}/rc.d/rc5.d/S35LCDd
	ln -sf  ../init.d/LCDd ${EXTDIR}/rc.d/rc6.d/K65LCDd

install-lcdproc: install-LCDd create-dirs
	install -m ${MODE} cblfs/init.d/lcdproc ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/lcdproc ${EXTDIR}/rc.d/rc0.d/K60lcdproc
	ln -sf  ../init.d/lcdproc ${EXTDIR}/rc.d/rc1.d/K60lcdproc
	ln -sf  ../init.d/lcdproc ${EXTDIR}/rc.d/rc2.d/K60lcdproc
	ln -sf  ../init.d/lcdproc ${EXTDIR}/rc.d/rc3.d/S40lcdproc
	ln -sf  ../init.d/lcdproc ${EXTDIR}/rc.d/rc4.d/S40lcdproc
	ln -sf  ../init.d/lcdproc ${EXTDIR}/rc.d/rc5.d/S40lcdproc
	ln -sf  ../init.d/lcdproc ${EXTDIR}/rc.d/rc6.d/K60lcdproc

install-lisa: create-dirs
	install -m ${MODE} cblfs/init.d/lisa       ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/lisa ${EXTDIR}/rc.d/rc0.d/K35lisa
	ln -sf  ../init.d/lisa ${EXTDIR}/rc.d/rc1.d/K35lisa
	ln -sf  ../init.d/lisa ${EXTDIR}/rc.d/rc2.d/K35lisa
	ln -sf  ../init.d/lisa ${EXTDIR}/rc.d/rc3.d/S30lisa
	ln -sf  ../init.d/lisa ${EXTDIR}/rc.d/rc4.d/S30lisa
	ln -sf  ../init.d/lisa ${EXTDIR}/rc.d/rc5.d/S30lisa
	ln -sf  ../init.d/lisa ${EXTDIR}/rc.d/rc6.d/K35lisa

install-lprng: create-dirs
	install -m ${MODE} cblfs/init.d/lprng      ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/lprng ${EXTDIR}/rc.d/rc0.d/K00lprng
	ln -sf  ../init.d/lprng ${EXTDIR}/rc.d/rc1.d/K00lprng
	ln -sf  ../init.d/lprng ${EXTDIR}/rc.d/rc2.d/S99lprng
	ln -sf  ../init.d/lprng ${EXTDIR}/rc.d/rc3.d/S99lprng
	ln -sf  ../init.d/lprng ${EXTDIR}/rc.d/rc4.d/S99lprng
	ln -sf  ../init.d/lprng ${EXTDIR}/rc.d/rc5.d/S99lprng
	ln -sf  ../init.d/lprng ${EXTDIR}/rc.d/rc6.d/K00lprng

install-maui: create-dirs
	install -m ${MODE} cblfs/init.d/maui        ${EXTDIR}/rc.d/init.d/
	ln -sf ../init.d/maui      ${EXTDIR}/rc.d/rc0.d/K15maui
	ln -sf ../init.d/maui      ${EXTDIR}/rc.d/rc1.d/K15maui
	ln -sf ../init.d/maui      ${EXTDIR}/rc.d/rc2.d/K15maui
	ln -sf ../init.d/maui      ${EXTDIR}/rc.d/rc3.d/S50maui
	ln -sf ../init.d/maui      ${EXTDIR}/rc.d/rc4.d/S50maui
	ln -sf ../init.d/maui      ${EXTDIR}/rc.d/rc5.d/S50maui
	ln -sf ../init.d/maui      ${EXTDIR}/rc.d/rc6.d/K15maui

install-momclient: create-dirs
	install -m ${MODE} cblfs/init.d/momclient        ${EXTDIR}/rc.d/init.d/
	ln -sf ../init.d/momclient      ${EXTDIR}/rc.d/rc0.d/K15momclient
	ln -sf ../init.d/momclient      ${EXTDIR}/rc.d/rc1.d/K15momclient
	ln -sf ../init.d/momclient      ${EXTDIR}/rc.d/rc2.d/K15momclient
	ln -sf ../init.d/momclient      ${EXTDIR}/rc.d/rc3.d/S35momclient
	ln -sf ../init.d/momclient      ${EXTDIR}/rc.d/rc4.d/S35momclient
	ln -sf ../init.d/momclient      ${EXTDIR}/rc.d/rc5.d/S35momclient
	ln -sf ../init.d/momclient      ${EXTDIR}/rc.d/rc6.d/K15momclient

install-mpich2: create-dirs
	install -m ${MODE} cblfs/init.d/mpd     ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/mpd ${EXTDIR}/rc.d/rc0.d/K10mpd
	ln -sf  ../init.d/mpd ${EXTDIR}/rc.d/rc1.d/K10mpd
	ln -sf  ../init.d/mpd ${EXTDIR}/rc.d/rc2.d/K10mpd
	ln -sf  ../init.d/mpd ${EXTDIR}/rc.d/rc3.d/S99mpd
	ln -sf  ../init.d/mpd ${EXTDIR}/rc.d/rc4.d/S99mpd
	ln -sf  ../init.d/mpd ${EXTDIR}/rc.d/rc5.d/S99mpd
	ln -sf  ../init.d/mpd ${EXTDIR}/rc.d/rc6.d/K10mpd

install-mysql: create-dirs
	install -m ${MODE} cblfs/init.d/mysql      ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/mysql ${EXTDIR}/rc.d/rc0.d/K26mysql
	ln -sf  ../init.d/mysql ${EXTDIR}/rc.d/rc1.d/K26mysql
	ln -sf  ../init.d/mysql ${EXTDIR}/rc.d/rc2.d/K26mysql
	ln -sf  ../init.d/mysql ${EXTDIR}/rc.d/rc3.d/S34mysql
	ln -sf  ../init.d/mysql ${EXTDIR}/rc.d/rc4.d/S34mysql
	ln -sf  ../init.d/mysql ${EXTDIR}/rc.d/rc5.d/S34mysql
	ln -sf  ../init.d/mysql ${EXTDIR}/rc.d/rc6.d/K26mysql

install-nas: create-dirs
	install -m ${MODE} cblfs/init.d/nas        ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/nas ${EXTDIR}/rc.d/rc0.d/K35nas
	ln -sf  ../init.d/nas ${EXTDIR}/rc.d/rc1.d/K35nas
	ln -sf  ../init.d/nas ${EXTDIR}/rc.d/rc2.d/K35nas
	ln -sf  ../init.d/nas ${EXTDIR}/rc.d/rc3.d/S30nas
	ln -sf  ../init.d/nas ${EXTDIR}/rc.d/rc4.d/S30nas
	ln -sf  ../init.d/nas ${EXTDIR}/rc.d/rc5.d/S30nas
	ln -sf  ../init.d/nas ${EXTDIR}/rc.d/rc6.d/K35nas

install-netfs: create-dirs
	install -m ${MODE} cblfs/init.d/netfs      ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/netfs ${EXTDIR}/rc.d/rc0.d/K47netfs
	ln -sf  ../init.d/netfs ${EXTDIR}/rc.d/rc1.d/K47netfs
	ln -sf  ../init.d/netfs ${EXTDIR}/rc.d/rc2.d/K47netfs
	ln -sf  ../init.d/netfs ${EXTDIR}/rc.d/rc3.d/S28netfs
	ln -sf  ../init.d/netfs ${EXTDIR}/rc.d/rc4.d/S28netfs
	ln -sf  ../init.d/netfs ${EXTDIR}/rc.d/rc5.d/S28netfs
	ln -sf  ../init.d/netfs ${EXTDIR}/rc.d/rc6.d/K47netfs

install-nfs-client: create-dirs
	install -m ${MODE} cblfs/init.d/nfs-client ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/nfs-client ${EXTDIR}/rc.d/rc0.d/K48nfs-client
	ln -sf  ../init.d/nfs-client ${EXTDIR}/rc.d/rc1.d/K48nfs-client
	ln -sf  ../init.d/nfs-client ${EXTDIR}/rc.d/rc2.d/K48nfs-client
	ln -sf  ../init.d/nfs-client ${EXTDIR}/rc.d/rc3.d/S24nfs-client
	ln -sf  ../init.d/nfs-client ${EXTDIR}/rc.d/rc4.d/S24nfs-client
	ln -sf  ../init.d/nfs-client ${EXTDIR}/rc.d/rc5.d/S24nfs-client
	ln -sf  ../init.d/nfs-client ${EXTDIR}/rc.d/rc6.d/K48nfs-client

install-nfs-server: create-dirs
	install -m ${MODE} cblfs/init.d/nfs-server ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/nfs-server ${EXTDIR}/rc.d/rc0.d/K48nfs-server
	ln -sf  ../init.d/nfs-server ${EXTDIR}/rc.d/rc1.d/K48nfs-server
	ln -sf  ../init.d/nfs-server ${EXTDIR}/rc.d/rc2.d/K48nfs-server
	ln -sf  ../init.d/nfs-server ${EXTDIR}/rc.d/rc3.d/S24nfs-server
	ln -sf  ../init.d/nfs-server ${EXTDIR}/rc.d/rc4.d/S24nfs-server
	ln -sf  ../init.d/nfs-server ${EXTDIR}/rc.d/rc5.d/S24nfs-server
	ln -sf  ../init.d/nfs-server ${EXTDIR}/rc.d/rc6.d/K48nfs-server

install-ntp: create-dirs
	install -m ${MODE} cblfs/init.d/ntp        ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/ntp ${EXTDIR}/rc.d/rc0.d/K46ntp
	ln -sf  ../init.d/ntp ${EXTDIR}/rc.d/rc1.d/K46ntp
	ln -sf  ../init.d/ntp ${EXTDIR}/rc.d/rc2.d/K46ntp
	ln -sf  ../init.d/ntp ${EXTDIR}/rc.d/rc3.d/S26ntp
	ln -sf  ../init.d/ntp ${EXTDIR}/rc.d/rc4.d/S26ntp
	ln -sf  ../init.d/ntp ${EXTDIR}/rc.d/rc5.d/S26ntp
	ln -sf  ../init.d/ntp ${EXTDIR}/rc.d/rc6.d/K46ntp

install-openldap1: create-dirs
	install -m ${MODE} cblfs/init.d/openldap1  ${EXTDIR}/rc.d/init.d/openldap
	ln -sf  ../init.d/openldap ${EXTDIR}/rc.d/rc0.d/K46openldap
	ln -sf  ../init.d/openldap ${EXTDIR}/rc.d/rc1.d/K46openldap
	ln -sf  ../init.d/openldap ${EXTDIR}/rc.d/rc2.d/K46openldap
	ln -sf  ../init.d/openldap ${EXTDIR}/rc.d/rc3.d/S25openldap
	ln -sf  ../init.d/openldap ${EXTDIR}/rc.d/rc4.d/S25openldap
	ln -sf  ../init.d/openldap ${EXTDIR}/rc.d/rc5.d/S25openldap
	ln -sf  ../init.d/openldap ${EXTDIR}/rc.d/rc6.d/K46openldap

install-openldap2: create-dirs
	install -m ${MODE} cblfs/init.d/openldap2  ${EXTDIR}/rc.d/init.d/openldap
	ln -sf  ../init.d/openldap ${EXTDIR}/rc.d/rc0.d/K46openldap
	ln -sf  ../init.d/openldap ${EXTDIR}/rc.d/rc1.d/K46openldap
	ln -sf  ../init.d/openldap ${EXTDIR}/rc.d/rc2.d/K46openldap
	ln -sf  ../init.d/openldap ${EXTDIR}/rc.d/rc3.d/S25openldap
	ln -sf  ../init.d/openldap ${EXTDIR}/rc.d/rc4.d/S25openldap
	ln -sf  ../init.d/openldap ${EXTDIR}/rc.d/rc5.d/S25openldap
	ln -sf  ../init.d/openldap ${EXTDIR}/rc.d/rc6.d/K46openldap

install-pbsserver: create-dirs
	install -m ${MODE} cblfs/init.d/pbsserver        ${EXTDIR}/rc.d/init.d/
	ln -sf ../init.d/pbsserver      ${EXTDIR}/rc.d/rc0.d/K15pbsserver
	ln -sf ../init.d/pbsserver      ${EXTDIR}/rc.d/rc1.d/K15pbsserver
	ln -sf ../init.d/pbsserver      ${EXTDIR}/rc.d/rc2.d/K15pbsserver
	ln -sf ../init.d/pbsserver      ${EXTDIR}/rc.d/rc3.d/S25pbsserver
	ln -sf ../init.d/pbsserver      ${EXTDIR}/rc.d/rc4.d/S25pbsserver
	ln -sf ../init.d/pbsserver      ${EXTDIR}/rc.d/rc5.d/S25pbsserver
	ln -sf ../init.d/pbsserver      ${EXTDIR}/rc.d/rc6.d/K15pbsserver

install-portmap: create-dirs
	install -m ${MODE} cblfs/init.d/portmap    ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/portmap ${EXTDIR}/rc.d/rc0.d/K49portmap
	ln -sf  ../init.d/portmap ${EXTDIR}/rc.d/rc1.d/K49portmap
	ln -sf  ../init.d/portmap ${EXTDIR}/rc.d/rc2.d/K49portmap
	ln -sf  ../init.d/portmap ${EXTDIR}/rc.d/rc3.d/S22portmap
	ln -sf  ../init.d/portmap ${EXTDIR}/rc.d/rc4.d/S22portmap
	ln -sf  ../init.d/portmap ${EXTDIR}/rc.d/rc5.d/S22portmap
	ln -sf  ../init.d/portmap ${EXTDIR}/rc.d/rc6.d/K49portmap

install-postfix: create-dirs
	install -m ${MODE} cblfs/init.d/postfix    ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/postfix ${EXTDIR}/rc.d/rc0.d/K25postfix
	ln -sf  ../init.d/postfix ${EXTDIR}/rc.d/rc1.d/K25postfix
	ln -sf  ../init.d/postfix ${EXTDIR}/rc.d/rc2.d/K25postfix
	ln -sf  ../init.d/postfix ${EXTDIR}/rc.d/rc3.d/S35postfix
	ln -sf  ../init.d/postfix ${EXTDIR}/rc.d/rc4.d/S35postfix
	ln -sf  ../init.d/postfix ${EXTDIR}/rc.d/rc5.d/S35postfix
	ln -sf  ../init.d/postfix ${EXTDIR}/rc.d/rc6.d/K25postfix

install-postgresql: create-dirs
	install -m ${MODE} cblfs/init.d/postgresql ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/postgresql ${EXTDIR}/rc.d/rc0.d/K26postgresql
	ln -sf  ../init.d/postgresql ${EXTDIR}/rc.d/rc1.d/K26postgresql
	ln -sf  ../init.d/postgresql ${EXTDIR}/rc.d/rc2.d/K26postgresql
	ln -sf  ../init.d/postgresql ${EXTDIR}/rc.d/rc3.d/S34postgresql
	ln -sf  ../init.d/postgresql ${EXTDIR}/rc.d/rc4.d/S34postgresql
	ln -sf  ../init.d/postgresql ${EXTDIR}/rc.d/rc5.d/S34postgresql
	ln -sf  ../init.d/postgresql ${EXTDIR}/rc.d/rc6.d/K26postgresql

install-proftpd: create-dirs
	install -m ${MODE} cblfs/init.d/proftpd    ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/proftpd ${EXTDIR}/rc.d/rc0.d/K28proftpd
	ln -sf  ../init.d/proftpd ${EXTDIR}/rc.d/rc1.d/K28proftpd
	ln -sf  ../init.d/proftpd ${EXTDIR}/rc.d/rc2.d/K28proftpd
	ln -sf  ../init.d/proftpd ${EXTDIR}/rc.d/rc3.d/S32proftpd
	ln -sf  ../init.d/proftpd ${EXTDIR}/rc.d/rc4.d/S32proftpd
	ln -sf  ../init.d/proftpd ${EXTDIR}/rc.d/rc5.d/S32proftpd
	ln -sf  ../init.d/proftpd ${EXTDIR}/rc.d/rc6.d/K28proftpd

install-random: create-dirs
	install -m ${MODE} cblfs/init.d/random     ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/random ${EXTDIR}/rc.d/rc0.d/K45random
	ln -sf  ../init.d/random ${EXTDIR}/rc.d/rc1.d/S25random
	ln -sf  ../init.d/random ${EXTDIR}/rc.d/rc2.d/S25random
	ln -sf  ../init.d/random ${EXTDIR}/rc.d/rc3.d/S25random
	ln -sf  ../init.d/random ${EXTDIR}/rc.d/rc4.d/S25random
	ln -sf  ../init.d/random ${EXTDIR}/rc.d/rc5.d/S25random
	ln -sf  ../init.d/random ${EXTDIR}/rc.d/rc6.d/K45random

install-rsyncd: create-dirs
	install -m ${MODE} cblfs/init.d/rsyncd     ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/rsyncd ${EXTDIR}/rc.d/rc0.d/K30rsyncd
	ln -sf  ../init.d/rsyncd ${EXTDIR}/rc.d/rc1.d/K30rsyncd
	ln -sf  ../init.d/rsyncd ${EXTDIR}/rc.d/rc2.d/K30rsyncd
	ln -sf  ../init.d/rsyncd ${EXTDIR}/rc.d/rc3.d/S30rsyncd
	ln -sf  ../init.d/rsyncd ${EXTDIR}/rc.d/rc4.d/S30rsyncd
	ln -sf  ../init.d/rsyncd ${EXTDIR}/rc.d/rc5.d/S30rsyncd
	ln -sf  ../init.d/rsyncd ${EXTDIR}/rc.d/rc6.d/K30rsyncd

install-samba: create-dirs
	install -m ${MODE} cblfs/init.d/samba      ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/samba ${EXTDIR}/rc.d/rc0.d/K48samba
	ln -sf  ../init.d/samba ${EXTDIR}/rc.d/rc1.d/K48samba
	ln -sf  ../init.d/samba ${EXTDIR}/rc.d/rc2.d/K48samba
	ln -sf  ../init.d/samba ${EXTDIR}/rc.d/rc3.d/S45samba
	ln -sf  ../init.d/samba ${EXTDIR}/rc.d/rc4.d/S45samba
	ln -sf  ../init.d/samba ${EXTDIR}/rc.d/rc5.d/S45samba
	ln -sf  ../init.d/samba ${EXTDIR}/rc.d/rc6.d/K48samba

install-sendmail: create-dirs
	install -m ${MODE} cblfs/init.d/sendmail   ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/sendmail ${EXTDIR}/rc.d/rc0.d/K25sendmail
	ln -sf  ../init.d/sendmail ${EXTDIR}/rc.d/rc1.d/K25sendmail
	ln -sf  ../init.d/sendmail ${EXTDIR}/rc.d/rc2.d/K25sendmail
	ln -sf  ../init.d/sendmail ${EXTDIR}/rc.d/rc3.d/S35sendmail
	ln -sf  ../init.d/sendmail ${EXTDIR}/rc.d/rc4.d/S35sendmail
	ln -sf  ../init.d/sendmail ${EXTDIR}/rc.d/rc5.d/S35sendmail
	ln -sf  ../init.d/sendmail ${EXTDIR}/rc.d/rc6.d/K25sendmail

install-sysklogd: create-dirs
	install -m ${MODE} cblfs/init.d/sysklogd   ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/sysklogd ${EXTDIR}/rc.d/rc0.d/K90sysklogd
	ln -sf  ../init.d/sysklogd ${EXTDIR}/rc.d/rc1.d/S10sysklogd
	ln -sf  ../init.d/sysklogd ${EXTDIR}/rc.d/rc2.d/S10sysklogd
	ln -sf  ../init.d/sysklogd ${EXTDIR}/rc.d/rc3.d/S10sysklogd
	ln -sf  ../init.d/sysklogd ${EXTDIR}/rc.d/rc4.d/S10sysklogd
	ln -sf  ../init.d/sysklogd ${EXTDIR}/rc.d/rc5.d/S10sysklogd
	ln -sf  ../init.d/sysklogd ${EXTDIR}/rc.d/rc6.d/K90sysklogd

install-qpopper: create-dirs
	install -m ${MODE} cblfs/init.d/qpopper   ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/qpopper ${EXTDIR}/rc.d/rc0.d/K23qpopper
	ln -sf  ../init.d/qpopper ${EXTDIR}/rc.d/rc1.d/K23qpopper
	ln -sf  ../init.d/qpopper ${EXTDIR}/rc.d/rc2.d/K23qpopper
	ln -sf  ../init.d/qpopper ${EXTDIR}/rc.d/rc3.d/S37qpopper
	ln -sf  ../init.d/qpopper ${EXTDIR}/rc.d/rc4.d/S37qpopper
	ln -sf  ../init.d/qpopper ${EXTDIR}/rc.d/rc5.d/S37qpopper
	ln -sf  ../init.d/qpopper ${EXTDIR}/rc.d/rc6.d/K23qpopper

install-sshd: create-dirs
	install -m ${MODE} cblfs/init.d/sshd       ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/sshd ${EXTDIR}/rc.d/rc0.d/K30sshd
	ln -sf  ../init.d/sshd ${EXTDIR}/rc.d/rc1.d/K30sshd
	ln -sf  ../init.d/sshd ${EXTDIR}/rc.d/rc2.d/K30sshd
	ln -sf  ../init.d/sshd ${EXTDIR}/rc.d/rc3.d/S30sshd
	ln -sf  ../init.d/sshd ${EXTDIR}/rc.d/rc4.d/S30sshd
	ln -sf  ../init.d/sshd ${EXTDIR}/rc.d/rc5.d/S30sshd
	ln -sf  ../init.d/sshd ${EXTDIR}/rc.d/rc6.d/K30sshd

install-stunnel: create-dirs
	install -m ${MODE} cblfs/init.d/stunnel    ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/stunnel ${EXTDIR}/rc.d/rc0.d/K47stunnel
	ln -sf  ../init.d/stunnel ${EXTDIR}/rc.d/rc1.d/K47stunnel
	ln -sf  ../init.d/stunnel ${EXTDIR}/rc.d/rc2.d/K47stunnel
	ln -sf  ../init.d/stunnel ${EXTDIR}/rc.d/rc3.d/S55stunnel
	ln -sf  ../init.d/stunnel ${EXTDIR}/rc.d/rc4.d/S55stunnel
	ln -sf  ../init.d/stunnel ${EXTDIR}/rc.d/rc5.d/S55stunnel
	ln -sf  ../init.d/stunnel ${EXTDIR}/rc.d/rc6.d/K47stunnel

install-svn: create-dirs
	install -m ${MODE} cblfs/init.d/svn        ${EXTDIR}/rc.d/init.d/
	ln -sf ../init.d/svn ${EXTDIR}/rc.d/rc0.d/K27svn
	ln -sf ../init.d/svn ${EXTDIR}/rc.d/rc1.d/K27svn
	ln -sf ../init.d/svn ${EXTDIR}/rc.d/rc2.d/K27svn
	ln -sf ../init.d/svn ${EXTDIR}/rc.d/rc3.d/S33svn
	ln -sf ../init.d/svn ${EXTDIR}/rc.d/rc4.d/S33svn
	ln -sf ../init.d/svn ${EXTDIR}/rc.d/rc5.d/S33svn
	ln -sf ../init.d/svn ${EXTDIR}/rc.d/rc6.d/K27svn

install-syslog-ng: create-dirs
	install -m ${MODE} cblfs/init.d/syslog-ng	${EXTDIR}/rc.d/init.d/
	ln -sf ../init.d/syslog-ng ${EXTDIR}/rc.d/rc0.d/K90syslog-ng
	ln -sf ../init.d/syslog-ng ${EXTDIR}/rc.d/rc1.d/S10syslog-ng
	ln -sf ../init.d/syslog-ng ${EXTDIR}/rc.d/rc2.d/S10syslog-ng
	ln -sf ../init.d/syslog-ng ${EXTDIR}/rc.d/rc3.d/S10syslog-ng
	ln -sf ../init.d/syslog-ng ${EXTDIR}/rc.d/rc4.d/S10syslog-ng
	ln -sf ../init.d/syslog-ng ${EXTDIR}/rc.d/rc5.d/S10syslog-ng
	ln -sf ../init.d/syslog-ng ${EXTDIR}/rc.d/rc6.d/K90syslog-ng

install-sysstat: create-dirs
	install -m ${MODE} cblfs/init.d/sysstat    ${EXTDIR}/rc.d/init.d/
	ln -sf ../init.d/sysstat ${EXTDIR}/rc.d/rcsysinit.d/S85sysstat

install-usb: create-dirs
	install -m ${MODE} cblfs/init.d/usb        ${EXTDIR}/rc.d/init.d/
	ln -sf ../init.d/usb ${EXTDIR}/rc.d/rcsysinit.d/S90usb

install-vsftpd: create-dirs
	install -m ${MODE} cblfs/init.d/vsftpd     ${EXTDIR}/rc.d/init.d/
	ln -sf ../init.d/vsftpd ${EXTDIR}/rc.d/rc0.d/K28vsftpd
	ln -sf ../init.d/vsftpd ${EXTDIR}/rc.d/rc1.d/K28vsftpd
	ln -sf ../init.d/vsftpd ${EXTDIR}/rc.d/rc2.d/K28vsftpd
	ln -sf ../init.d/vsftpd ${EXTDIR}/rc.d/rc3.d/S32vsftpd
	ln -sf ../init.d/vsftpd ${EXTDIR}/rc.d/rc4.d/S32vsftpd
	ln -sf ../init.d/vsftpd ${EXTDIR}/rc.d/rc5.d/S32vsftpd
	ln -sf ../init.d/vsftpd ${EXTDIR}/rc.d/rc6.d/K28vsftpd

install-winbind: create-dirs
	install -m ${MODE} cblfs/init.d/winbind    ${EXTDIR}/rc.d/init.d/
	ln -sf ../init.d/winbind ${EXTDIR}/rc.d/rc0.d/K49winbind
	ln -sf ../init.d/winbind ${EXTDIR}/rc.d/rc1.d/K49winbind
	ln -sf ../init.d/winbind ${EXTDIR}/rc.d/rc2.d/K49winbind
	ln -sf ../init.d/winbind ${EXTDIR}/rc.d/rc3.d/S50winbind
	ln -sf ../init.d/winbind ${EXTDIR}/rc.d/rc4.d/S50winbind
	ln -sf ../init.d/winbind ${EXTDIR}/rc.d/rc5.d/S50winbind
	ln -sf ../init.d/winbind ${EXTDIR}/rc.d/rc6.d/K49winbind

install-xinetd: create-dirs
	install -m ${MODE} cblfs/init.d/xinetd     ${EXTDIR}/rc.d/init.d/
	ln -sf  ../init.d/xinetd ${EXTDIR}/rc.d/rc0.d/K49xinetd
	ln -sf  ../init.d/xinetd ${EXTDIR}/rc.d/rc1.d/K49xinetd
	ln -sf  ../init.d/xinetd ${EXTDIR}/rc.d/rc2.d/K49xinetd
	ln -sf  ../init.d/xinetd ${EXTDIR}/rc.d/rc3.d/S23xinetd
	ln -sf  ../init.d/xinetd ${EXTDIR}/rc.d/rc4.d/S23xinetd
	ln -sf  ../init.d/xinetd ${EXTDIR}/rc.d/rc5.d/S23xinetd
	ln -sf  ../init.d/xinetd ${EXTDIR}/rc.d/rc6.d/K49xinetd

uninstall-alsa:
	rm -f ${EXTDIR}/rc.d/init.d/alsa
	rm -f ${EXTDIR}/rc.d/rc0.d/K35alsa
	rm -f ${EXTDIR}/rc.d/rc1.d/K35alsa
	rm -f ${EXTDIR}/rc.d/rc6.d/K35alsa

uninstall-apache:
	rm -f ${EXTDIR}/rc.d/init.d/apache
	rm -f ${EXTDIR}/rc.d/rc0.d/K28apache
	rm -f ${EXTDIR}/rc.d/rc1.d/K28apache
	rm -f ${EXTDIR}/rc.d/rc2.d/K28apache
	rm -f ${EXTDIR}/rc.d/rc3.d/S32apache
	rm -f ${EXTDIR}/rc.d/rc4.d/S32apache
	rm -f ${EXTDIR}/rc.d/rc5.d/S32apache
	rm -f ${EXTDIR}/rc.d/rc6.d/K28apache

uninstall-autofs:
	rm -f $(EXTDIR)/rc.d/init.d/autofs
	rm -f $(EXTDIR)/rc.d/rcsysinit.d/S52autofs

uninstall-bind:
	rm -f ${EXTDIR}/rc.d/init.d/bind
	rm -f ${EXTDIR}/rc.d/rc0.d/K49bind
	rm -f ${EXTDIR}/rc.d/rc1.d/K49bind
	rm -f ${EXTDIR}/rc.d/rc2.d/K49bind
	rm -f ${EXTDIR}/rc.d/rc3.d/S22bind
	rm -f ${EXTDIR}/rc.d/rc4.d/S22bind
	rm -f ${EXTDIR}/rc.d/rc5.d/S22bind
	rm -f ${EXTDIR}/rc.d/rc6.d/K49bind

uninstall-cluster-all:
	rm -f ${EXTDIR}/rc.d/init.d/cluster
	rm -f ${EXTDIR}/rc.d/rc0.d/K15cluster
	rm -f ${EXTDIR}/rc.d/rc1.d/K15cluster
	rm -f ${EXTDIR}/rc.d/rc2.d/K15cluster
	rm -f ${EXTDIR}/rc.d/rc3.d/S99cluster
	rm -f ${EXTDIR}/rc.d/rc4.d/S99cluster
	rm -f ${EXTDIR}/rc.d/rc5.d/S99cluster
	rm -f ${EXTDIR}/rc.d/rc6.d/K15cluster

uninstall-cups:
	rm -f ${EXTDIR}/rc.d/init.d/cups
	rm -f ${EXTDIR}/rc.d/rc0.d/K00cups
	rm -f ${EXTDIR}/rc.d/rc1.d/K00cups
	rm -f ${EXTDIR}/rc.d/rc2.d/S25cups
	rm -f ${EXTDIR}/rc.d/rc3.d/S25cups
	rm -f ${EXTDIR}/rc.d/rc4.d/S25cups
	rm -f ${EXTDIR}/rc.d/rc5.d/S25cups
	rm -f ${EXTDIR}/rc.d/rc6.d/K00cups

uninstall-cyrus-sasl:
	rm -f ${EXTDIR}/rc.d/init.d/cyrus-sasl
	rm -f ${EXTDIR}/rc.d/rc0.d/K49cyrus-sasl
	rm -f ${EXTDIR}/rc.d/rc1.d/K49cyrus-sasl
	rm -f ${EXTDIR}/rc.d/rc2.d/S24cyrus-sasl
	rm -f ${EXTDIR}/rc.d/rc3.d/S24cyrus-sasl
	rm -f ${EXTDIR}/rc.d/rc4.d/S24cyrus-sasl
	rm -f ${EXTDIR}/rc.d/rc5.d/S24cyrus-sasl
	rm -f ${EXTDIR}/rc.d/rc6.d/K49cyrus-sasl

uninstall-devmapper:
	rm -f ${EXTDIR}/etc/rc.d/init.d/devmapper
	rm -f ${EXTDIR}/etc/rc.d/rcsysinit.d/S15devmapper

uninstall-dhcp:
	rm -f ${EXTDIR}/rc.d/init.d/dhcp
	rm -f ${EXTDIR}/rc.d/rc0.d/K30dhcp
	rm -f ${EXTDIR}/rc.d/rc1.d/K30dhcp
	rm -f ${EXTDIR}/rc.d/rc2.d/K30dhcp
	rm -f ${EXTDIR}/rc.d/rc3.d/S30dhcp
	rm -f ${EXTDIR}/rc.d/rc4.d/S30dhcp
	rm -f ${EXTDIR}/rc.d/rc5.d/S30dhcp
	rm -f ${EXTDIR}/rc.d/rc6.d/K30dhcp

uninstall-exim:
	rm -f ${EXTDIR}/rc.d/init.d/exim
	rm -f ${EXTDIR}/rc.d/rc0.d/K25exim
	rm -f ${EXTDIR}/rc.d/rc1.d/K25exim
	rm -f ${EXTDIR}/rc.d/rc2.d/K25exim
	rm -f ${EXTDIR}/rc.d/rc3.d/S35exim
	rm -f ${EXTDIR}/rc.d/rc4.d/S35exim
	rm -f ${EXTDIR}/rc.d/rc5.d/S35exim
	rm -f ${EXTDIR}/rc.d/rc6.d/K25exim

uninstall-fam:
	rm -f ${EXTDIR}/rc.d/init.d/fam
	rm -f ${EXTDIR}/rc.d/rc0.d/K37fam
	rm -f ${EXTDIR}/rc.d/rc1.d/K37fam
	rm -f ${EXTDIR}/rc.d/rc2.d/S23fam
	rm -f ${EXTDIR}/rc.d/rc3.d/S23fam
	rm -f ${EXTDIR}/rc.d/rc4.d/S23fam
	rm -f ${EXTDIR}/rc.d/rc5.d/S23fam
	rm -f ${EXTDIR}/rc.d/rc6.d/K39fam

uninstall-fcron:
	rm -f ${EXTDIR}/rc.d/init.d/fcron
	rm -f ${EXTDIR}/rc.d/rc0.d/K08fcron
	rm -f ${EXTDIR}/rc.d/rc1.d/K08fcron
	rm -f ${EXTDIR}/rc.d/rc2.d/S40fcron
	rm -f ${EXTDIR}/rc.d/rc3.d/S40fcron
	rm -f ${EXTDIR}/rc.d/rc4.d/S40fcron
	rm -f ${EXTDIR}/rc.d/rc5.d/S40fcron
	rm -f ${EXTDIR}/rc.d/rc6.d/K08fcron

uninstall-gdm:
	rm -f ${EXTDIR}/rc.d/init.d/gdm
	rm -f ${EXTDIR}/rc.d/rc0.d/K05gdm
	rm -f ${EXTDIR}/rc.d/rc1.d/K05gdm
	rm -f ${EXTDIR}/rc.d/rc2.d/K05gdm
	rm -f ${EXTDIR}/rc.d/rc3.d/K05gdm
	rm -f ${EXTDIR}/rc.d/rc4.d/K05gdm
	rm -f ${EXTDIR}/rc.d/rc5.d/S95gdm
	rm -f ${EXTDIR}/rc.d/rc6.d/K05gdm

uninstall-gmetad:
	rm -f ${EXTDIR}/rc.d/init.d/gmetad
	rm -f ${EXTDIR}/rc.d/rc0.d/K15gmetad
	rm -f ${EXTDIR}/rc.d/rc1.d/K15gmetad
	rm -f ${EXTDIR}/rc.d/rc2.d/K15gmetad
	rm -f ${EXTDIR}/rc.d/rc3.d/S99gmetad
	rm -f ${EXTDIR}/rc.d/rc4.d/S99gmetad
	rm -f ${EXTDIR}/rc.d/rc5.d/S99gmetad
	rm -f ${EXTDIR}/rc.d/rc6.d/K15gmetad

uninstall-gmond:
	rm -f ${EXTDIR}/rc.d/init.d/gmond
	rm -f ${EXTDIR}/rc.d/rc0.d/K15gmond
	rm -f ${EXTDIR}/rc.d/rc1.d/K15gmond
	rm -f ${EXTDIR}/rc.d/rc2.d/K15gmond
	rm -f ${EXTDIR}/rc.d/rc3.d/S99gmond
	rm -f ${EXTDIR}/rc.d/rc4.d/S99gmond
	rm -f ${EXTDIR}/rc.d/rc5.d/S99gmond
	rm -f ${EXTDIR}/rc.d/rc6.d/K15gmond

uninstall-gpm:
	rm -f ${EXTDIR}/rc.d/init.d/gpm
	rm -f ${EXTDIR}/rc.d/rc0.d/K10gpm
	rm -f ${EXTDIR}/rc.d/rc1.d/K10gpm
	rm -f ${EXTDIR}/rc.d/rc2.d/S70gpm
	rm -f ${EXTDIR}/rc.d/rc3.d/S70gpm
	rm -f ${EXTDIR}/rc.d/rc4.d/S70gpm
	rm -f ${EXTDIR}/rc.d/rc5.d/S70gpm
	rm -f ${EXTDIR}/rc.d/rc6.d/K10gpm

uninstall-heimdal:
	rm -f ${EXTDIR}/rc.d/init.d/heimdal
	rm -f ${EXTDIR}/rc.d/rc0.d/K42heimdal
	rm -f ${EXTDIR}/rc.d/rc1.d/K42heimdal
	rm -f ${EXTDIR}/rc.d/rc2.d/K42heimdal
	rm -f ${EXTDIR}/rc.d/rc3.d/S28heimdal
	rm -f ${EXTDIR}/rc.d/rc4.d/S28heimdal
	rm -f ${EXTDIR}/rc.d/rc5.d/S28heimdal
	rm -f ${EXTDIR}/rc.d/rc6.d/K42heimdal

uninstall-iptables:
	rm -f ${EXTDIR}/rc.d/init.d/iptables
	rm -f ${EXTDIR}/rc.d/rc3.d/S19iptables
	rm -f ${EXTDIR}/rc.d/rc4.d/S19iptables
	rm -f ${EXTDIR}/rc.d/rc5.d/S19iptables

uninstall-kerberos:
	rm -f ${EXTDIR}/rc.d/init.d/kerberos
	rm -f ${EXTDIR}/rc.d/rc0.d/K42kerberos
	rm -f ${EXTDIR}/rc.d/rc1.d/K42kerberos
	rm -f ${EXTDIR}/rc.d/rc2.d/K42kerberos
	rm -f ${EXTDIR}/rc.d/rc3.d/S28kerberos
	rm -f ${EXTDIR}/rc.d/rc4.d/S28kerberos
	rm -f ${EXTDIR}/rc.d/rc5.d/S28kerberos
	rm -f ${EXTDIR}/rc.d/rc6.d/K42kerberos

uninstall-LCDd:
	rm -f ${EXTDIR}/rc.d/init.d/LCDd
	rm -f ${EXTDIR}/rc.d/rc0.d/K65LCDd
	rm -f ${EXTDIR}/rc.d/rc1.d/K65LCDd
	rm -f ${EXTDIR}/rc.d/rc2.d/K65LCDd
	rm -f ${EXTDIR}/rc.d/rc3.d/S35LCDd
	rm -f ${EXTDIR}/rc.d/rc4.d/S35LCDd
	rm -f ${EXTDIR}/rc.d/rc5.d/S35LCDd
	rm -f ${EXTDIR}/rc.d/rc6.d/K65LCDd

uninstall-lcdproc: uninstall-LCDd
	rm -f ${EXTDIR}/rc.d/init.d/lcdproc
	rm -f ${EXTDIR}/rc.d/rc0.d/K60lcdproc
	rm -f ${EXTDIR}/rc.d/rc1.d/K60lcdproc
	rm -f ${EXTDIR}/rc.d/rc2.d/K60lcdproc
	rm -f ${EXTDIR}/rc.d/rc3.d/S40lcdproc
	rm -f ${EXTDIR}/rc.d/rc4.d/S40lcdproc
	rm -f ${EXTDIR}/rc.d/rc5.d/S40lcdproc
	rm -f ${EXTDIR}/rc.d/rc6.d/K60lcdproc

uninstall-lisa:
	rm -f ${EXTDIR}/rc.d/init.d/lisa
	rm -f ${EXTDIR}/rc.d/rc0.d/K35lisa
	rm -f ${EXTDIR}/rc.d/rc1.d/K35lisa
	rm -f ${EXTDIR}/rc.d/rc2.d/K35lisa
	rm -f ${EXTDIR}/rc.d/rc3.d/S30lisa
	rm -f ${EXTDIR}/rc.d/rc4.d/S30lisa
	rm -f ${EXTDIR}/rc.d/rc5.d/S30lisa
	rm -f ${EXTDIR}/rc.d/rc6.d/K35lisa

uninstall-lprng:
	rm -f ${EXTDIR}/rc.d/init.d/lprng
	rm -f ${EXTDIR}/rc.d/rc0.d/K00lprng
	rm -f ${EXTDIR}/rc.d/rc1.d/K00lprng
	rm -f ${EXTDIR}/rc.d/rc2.d/S99lprng
	rm -f ${EXTDIR}/rc.d/rc3.d/S99lprng
	rm -f ${EXTDIR}/rc.d/rc4.d/S99lprng
	rm -f ${EXTDIR}/rc.d/rc5.d/S99lprng
	rm -f ${EXTDIR}/rc.d/rc6.d/K00lprng

uninstall-maui:
	rm -f ${EXTDIR}/rc.d/init.d/maui
	rm -f ${EXTDIR}/rc.d/rc0.d/K15maui
	rm -f ${EXTDIR}/rc.d/rc1.d/K15maui
	rm -f ${EXTDIR}/rc.d/rc2.d/K15maui
	rm -f ${EXTDIR}/rc.d/rc3.d/S50maui
	rm -f ${EXTDIR}/rc.d/rc4.d/S50maui
	rm -f ${EXTDIR}/rc.d/rc5.d/S50maui
	rm -f ${EXTDIR}/rc.d/rc6.d/K15maui

uninstall-momclient:
	rm -f ${EXTDIR}/rc.d/init.d/momclient
	rm -f ${EXTDIR}/rc.d/rc0.d/K15momclient
	rm -f ${EXTDIR}/rc.d/rc1.d/K15momclient
	rm -f ${EXTDIR}/rc.d/rc2.d/K15momclient
	rm -f ${EXTDIR}/rc.d/rc3.d/S35momclient
	rm -f ${EXTDIR}/rc.d/rc4.d/S35momclient
	rm -f ${EXTDIR}/rc.d/rc5.d/S35momclient
	rm -f ${EXTDIR}/rc.d/rc6.d/K15momclient

uninstall-mpich2:
	rm -f ${EXTDIR}/rc.d/init.d/mpd
	rm -f ${EXTDIR}/rc.d/rc0.d/K15mpd
	rm -f ${EXTDIR}/rc.d/rc1.d/K15mpd
	rm -f ${EXTDIR}/rc.d/rc2.d/K15mpd
	rm -f ${EXTDIR}/rc.d/rc3.d/S99mpd
	rm -f ${EXTDIR}/rc.d/rc4.d/S99mpd
	rm -f ${EXTDIR}/rc.d/rc5.d/S99mpd
	rm -f ${EXTDIR}/rc.d/rc6.d/K15mpd

uninstall-mysql:
	rm -f ${EXTDIR}/rc.d/init.d/mysql
	rm -f ${EXTDIR}/rc.d/rc0.d/K26mysql
	rm -f ${EXTDIR}/rc.d/rc1.d/K26mysql
	rm -f ${EXTDIR}/rc.d/rc2.d/K26mysql
	rm -f ${EXTDIR}/rc.d/rc3.d/S34mysql
	rm -f ${EXTDIR}/rc.d/rc4.d/S34mysql
	rm -f ${EXTDIR}/rc.d/rc5.d/S34mysql
	rm -f ${EXTDIR}/rc.d/rc6.d/K26mysql

uninstall-nas:
	rm -f ${EXTDIR}/rc.d/init.d/nas
	rm -f ${EXTDIR}/rc.d/rc0.d/K35nas
	rm -f ${EXTDIR}/rc.d/rc1.d/K35nas
	rm -f ${EXTDIR}/rc.d/rc2.d/K35nas
	rm -f ${EXTDIR}/rc.d/rc3.d/S30nas
	rm -f ${EXTDIR}/rc.d/rc4.d/S30nas
	rm -f ${EXTDIR}/rc.d/rc5.d/S30nas
	rm -f ${EXTDIR}/rc.d/rc6.d/K35nas

uninstall-netfs:
	rm -f ${EXTDIR}/rc.d/init.d/netfs
	rm -f ${EXTDIR}/rc.d/rc0.d/K47netfs
	rm -f ${EXTDIR}/rc.d/rc1.d/K47netfs
	rm -f ${EXTDIR}/rc.d/rc2.d/K47netfs
	rm -f ${EXTDIR}/rc.d/rc3.d/S28netfs
	rm -f ${EXTDIR}/rc.d/rc4.d/S28netfs
	rm -f ${EXTDIR}/rc.d/rc5.d/S28netfs
	rm -f ${EXTDIR}/rc.d/rc6.d/K47netfs

uninstall-nfs-client:
	rm -f ${EXTDIR}/rc.d/init.d/nfs-client
	rm -f ${EXTDIR}/rc.d/rc0.d/K48nfs-client
	rm -f ${EXTDIR}/rc.d/rc1.d/K48nfs-client
	rm -f ${EXTDIR}/rc.d/rc2.d/K48nfs-client
	rm -f ${EXTDIR}/rc.d/rc3.d/S24nfs-client
	rm -f ${EXTDIR}/rc.d/rc4.d/S24nfs-client
	rm -f ${EXTDIR}/rc.d/rc5.d/S24nfs-client
	rm -f ${EXTDIR}/rc.d/rc6.d/K48nfs-client

uninstall-nfs-server:
	rm -f ${EXTDIR}/rc.d/init.d/nfs-server
	rm -f ${EXTDIR}/rc.d/rc0.d/K48nfs-server
	rm -f ${EXTDIR}/rc.d/rc1.d/K48nfs-server
	rm -f ${EXTDIR}/rc.d/rc2.d/K48nfs-server
	rm -f ${EXTDIR}/rc.d/rc3.d/S24nfs-server
	rm -f ${EXTDIR}/rc.d/rc4.d/S24nfs-server
	rm -f ${EXTDIR}/rc.d/rc5.d/S24nfs-server
	rm -f ${EXTDIR}/rc.d/rc6.d/K48nfs-server

uninstall-ntp:
	rm -f ${EXTDIR}/rc.d/init.d/ntp
	rm -f ${EXTDIR}/rc.d/rc0.d/K46ntp
	rm -f ${EXTDIR}/rc.d/rc1.d/K46ntp
	rm -f ${EXTDIR}/rc.d/rc2.d/K46ntp
	rm -f ${EXTDIR}/rc.d/rc3.d/S26ntp
	rm -f ${EXTDIR}/rc.d/rc4.d/S26ntp
	rm -f ${EXTDIR}/rc.d/rc5.d/S26ntp
	rm -f ${EXTDIR}/rc.d/rc6.d/K46ntp

uninstall-openldap1:
	rm -f ${EXTDIR}/rc.d/init.d/openldap
	rm -f ${EXTDIR}/rc.d/rc0.d/K46openldap
	rm -f ${EXTDIR}/rc.d/rc1.d/K46openldap
	rm -f ${EXTDIR}/rc.d/rc2.d/K46openldap
	rm -f ${EXTDIR}/rc.d/rc3.d/S25openldap
	rm -f ${EXTDIR}/rc.d/rc4.d/S25openldap
	rm -f ${EXTDIR}/rc.d/rc5.d/S25openldap
	rm -f ${EXTDIR}/rc.d/rc6.d/K46openldap

uninstall-openldap2:
	rm -f ${EXTDIR}/rc.d/init.d/openldap
	rm -f ${EXTDIR}/rc.d/rc0.d/K46openldap
	rm -f ${EXTDIR}/rc.d/rc1.d/K46openldap
	rm -f ${EXTDIR}/rc.d/rc2.d/K46openldap
	rm -f ${EXTDIR}/rc.d/rc3.d/S25openldap
	rm -f ${EXTDIR}/rc.d/rc4.d/S25openldap
	rm -f ${EXTDIR}/rc.d/rc5.d/S25openldap
	rm -f ${EXTDIR}/rc.d/rc6.d/K46openldap

uninstall-pbsserver:
	rm -f ${EXTDIR}/rc.d/init.d/pbsserver
	rm -f ${EXTDIR}/rc.d/rc0.d/K15pbsserver
	rm -f ${EXTDIR}/rc.d/rc1.d/K15pbsserver
	rm -f ${EXTDIR}/rc.d/rc2.d/K15pbsserver
	rm -f ${EXTDIR}/rc.d/rc3.d/S25pbsserver
	rm -f ${EXTDIR}/rc.d/rc4.d/S25pbsserver
	rm -f ${EXTDIR}/rc.d/rc5.d/S25pbsserver
	rm -f ${EXTDIR}/rc.d/rc6.d/K15pbsserver

uninstall-portmap:
	rm -f ${EXTDIR}/rc.d/init.d/portmap
	rm -f ${EXTDIR}/rc.d/rc0.d/K49portmap
	rm -f ${EXTDIR}/rc.d/rc1.d/K49portmap
	rm -f ${EXTDIR}/rc.d/rc2.d/K49portmap
	rm -f ${EXTDIR}/rc.d/rc3.d/S22portmap
	rm -f ${EXTDIR}/rc.d/rc4.d/S22portmap
	rm -f ${EXTDIR}/rc.d/rc5.d/S22portmap
	rm -f ${EXTDIR}/rc.d/rc6.d/K49portmap

uninstall-postfix:
	rm -f ${EXTDIR}/rc.d/init.d/postfix
	rm -f ${EXTDIR}/rc.d/rc0.d/K25postfix
	rm -f ${EXTDIR}/rc.d/rc1.d/K25postfix
	rm -f ${EXTDIR}/rc.d/rc2.d/K25postfix
	rm -f ${EXTDIR}/rc.d/rc3.d/S35postfix
	rm -f ${EXTDIR}/rc.d/rc4.d/S35postfix
	rm -f ${EXTDIR}/rc.d/rc5.d/S35postfix
	rm -f ${EXTDIR}/rc.d/rc6.d/K25postfix

uninstall-postgresql:
	rm -f ${EXTDIR}/rc.d/init.d/postgresql
	rm -f ${EXTDIR}/rc.d/rc0.d/K26postgresql
	rm -f ${EXTDIR}/rc.d/rc1.d/K26postgresql
	rm -f ${EXTDIR}/rc.d/rc2.d/K26postgresql
	rm -f ${EXTDIR}/rc.d/rc3.d/S34postgresql
	rm -f ${EXTDIR}/rc.d/rc4.d/S34postgresql
	rm -f ${EXTDIR}/rc.d/rc5.d/S34postgresql
	rm -f ${EXTDIR}/rc.d/rc6.d/K26postgresql

uninstall-proftpd:
	rm -f ${EXTDIR}/rc.d/init.d/proftpd
	rm -f ${EXTDIR}/rc.d/rc0.d/K28proftpd
	rm -f ${EXTDIR}/rc.d/rc1.d/K28proftpd
	rm -f ${EXTDIR}/rc.d/rc2.d/K28proftpd
	rm -f ${EXTDIR}/rc.d/rc3.d/S32proftpd
	rm -f ${EXTDIR}/rc.d/rc4.d/S32proftpd
	rm -f ${EXTDIR}/rc.d/rc5.d/S32proftpd
	rm -f ${EXTDIR}/rc.d/rc6.d/K28proftpd

uninstall-random:
	rm -f ${EXTDIR}/rc.d/init.d/random
	rm -f ${EXTDIR}/rc.d/rc0.d/K45random
	rm -f ${EXTDIR}/rc.d/rc1.d/S25random
	rm -f ${EXTDIR}/rc.d/rc2.d/S25random
	rm -f ${EXTDIR}/rc.d/rc3.d/S25random
	rm -f ${EXTDIR}/rc.d/rc4.d/S25random
	rm -f ${EXTDIR}/rc.d/rc5.d/S25random
	rm -f ${EXTDIR}/rc.d/rc6.d/K45random

uninstall-rsyncd:
	rm -f ${EXTDIR}/rc.d/init.d/rsyncd
	rm -f ${EXTDIR}/rc.d/rc0.d/K30rsyncd
	rm -f ${EXTDIR}/rc.d/rc1.d/K30rsyncd
	rm -f ${EXTDIR}/rc.d/rc2.d/K30rsyncd
	rm -f ${EXTDIR}/rc.d/rc3.d/S30rsyncd
	rm -f ${EXTDIR}/rc.d/rc4.d/S30rsyncd
	rm -f ${EXTDIR}/rc.d/rc5.d/S30rsyncd
	rm -f ${EXTDIR}/rc.d/rc6.d/K30rsyncd

uninstall-samba:
	rm -f ${EXTDIR}/rc.d/init.d/samba
	rm -f ${EXTDIR}/rc.d/rc0.d/K48samba
	rm -f ${EXTDIR}/rc.d/rc1.d/K48samba
	rm -f ${EXTDIR}/rc.d/rc2.d/K48samba
	rm -f ${EXTDIR}/rc.d/rc3.d/S45samba
	rm -f ${EXTDIR}/rc.d/rc4.d/S45samba
	rm -f ${EXTDIR}/rc.d/rc5.d/S45samba
	rm -f ${EXTDIR}/rc.d/rc6.d/K48samba

uninstall-sendmail:
	rm -f ${EXTDIR}/rc.d/init.d/sendmail
	rm -f ${EXTDIR}/rc.d/rc0.d/K25sendmail
	rm -f ${EXTDIR}/rc.d/rc1.d/K25sendmail
	rm -f ${EXTDIR}/rc.d/rc2.d/K25sendmail
	rm -f ${EXTDIR}/rc.d/rc3.d/S35sendmail
	rm -f ${EXTDIR}/rc.d/rc4.d/S35sendmail
	rm -f ${EXTDIR}/rc.d/rc5.d/S35sendmail
	rm -f ${EXTDIR}/rc.d/rc6.d/K25sendmail

uninstall-sysklogd:
	rm -f ${EXTDIR}/rc.d/init.d/sysklogd
	rm -f ${EXTDIR}/rc.d/rc0.d/K90sysklogd
	rm -f ${EXTDIR}/rc.d/rc1.d/S10sysklogd
	rm -f ${EXTDIR}/rc.d/rc2.d/S10sysklogd
	rm -f ${EXTDIR}/rc.d/rc3.d/S10sysklogd
	rm -f ${EXTDIR}/rc.d/rc4.d/S10sysklogd
	rm -f ${EXTDIR}/rc.d/rc5.d/S10sysklogd
	rm -f ${EXTDIR}/rc.d/rc6.d/S10sysklogd

uninstall-sshd:
	rm -f ${EXTDIR}/rc.d/init.d/sshd
	rm -f ${EXTDIR}/rc.d/rc0.d/K30sshd
	rm -f ${EXTDIR}/rc.d/rc1.d/K30sshd
	rm -f ${EXTDIR}/rc.d/rc2.d/K30sshd
	rm -f ${EXTDIR}/rc.d/rc3.d/S30sshd
	rm -f ${EXTDIR}/rc.d/rc4.d/S30sshd
	rm -f ${EXTDIR}/rc.d/rc5.d/S30sshd
	rm -f ${EXTDIR}/rc.d/rc6.d/K30sshd

uninstall-stunnel:
	rm -f ${EXTDIR}/rc.d/init.d/stunnel
	rm -f ${EXTDIR}/rc.d/rc0.d/K47stunnel
	rm -f ${EXTDIR}/rc.d/rc1.d/K47stunnel
	rm -f ${EXTDIR}/rc.d/rc2.d/K47stunnel
	rm -f ${EXTDIR}/rc.d/rc3.d/S55stunnel
	rm -f ${EXTDIR}/rc.d/rc4.d/S55stunnel
	rm -f ${EXTDIR}/rc.d/rc5.d/S55stunnel
	rm -f ${EXTDIR}/rc.d/rc6.d/K47stunnel

uninstall-svn:
	rm -f ${EXTDIR}/rc.d/init.d/svn
	rm -f ${EXTDIR}/rc.d/rc0.d/K27svn
	rm -f ${EXTDIR}/rc.d/rc1.d/K27svn
	rm -f ${EXTDIR}/rc.d/rc2.d/K27svn
	rm -f ${EXTDIR}/rc.d/rc3.d/S33svn
	rm -f ${EXTDIR}/rc.d/rc4.d/S33svn
	rm -f ${EXTDIR}/rc.d/rc5.d/S33svn
	rm -f ${EXTDIR}/rc.d/rc6.d/K27svn

uninstall-syslog-ng:
	rm -f ${EXTDIR}/rc.d/init.d/syslog-ng
	rm -f ${EXTDIR}/rc.d/rc0.d/K90syslog-ng
	rm -f ${EXTDIR}/rc.d/rc1.d/S10syslog-ng
	rm -f ${EXTDIR}/rc.d/rc2.d/S10syslog-ng
	rm -f ${EXTDIR}/rc.d/rc3.d/S10syslog-ng
	rm -f ${EXTDIR}/rc.d/rc4.d/S10syslog-ng
	rm -f ${EXTDIR}/rc.d/rc5.d/S10syslog-ng
	rm -f ${EXTDIR}/rc.d/rc6.d/K90syslog-ng

uninstall-sysstat:
	rm -f ${EXTDIR}/rc.d/init.d/sysstat
	rm -f ${EXTDIR}/rc.d/rcsysinit.d/S85sysstat

uninstall-usb:
	rm -f ${EXTDIR}/rc.d/init.d/usb
	rm -f ${EXTDIR}/rc.d/rcsysinit.d/S90usb

uninstall-vsftpd:
	rm -f ${EXTDIR}/rc.d/init.d/vsftpd
	rm -f ${EXTDIR}/rc.d/rc0.d/K28vsftpd
	rm -f ${EXTDIR}/rc.d/rc1.d/K28vsftpd
	rm -f ${EXTDIR}/rc.d/rc2.d/K28vsftpd
	rm -f ${EXTDIR}/rc.d/rc3.d/S32vsftpd
	rm -f ${EXTDIR}/rc.d/rc4.d/S32vsftpd
	rm -f ${EXTDIR}/rc.d/rc5.d/S32vsftpd
	rm -f ${EXTDIR}/rc.d/rc6.d/K28vsftpd

uninstall-winbind:
	rm -f ${EXTDIR}/rc.d/init.d/winbind
	rm -f ${EXTDIR}/rc.d/rc0.d/K49winbind
	rm -f ${EXTDIR}/rc.d/rc1.d/K49winbind
	rm -f ${EXTDIR}/rc.d/rc2.d/K49winbind
	rm -f ${EXTDIR}/rc.d/rc3.d/S50winbind
	rm -f ${EXTDIR}/rc.d/rc4.d/S50winbind
	rm -f ${EXTDIR}/rc.d/rc5.d/S50winbind
	rm -f ${EXTDIR}/rc.d/rc6.d/K49winbind

uninstall-xinetd:
	rm -f ${EXTDIR}/rc.d/init.d/xinetd
	rm -f ${EXTDIR}/rc.d/rc0.d/K49xinetd
	rm -f ${EXTDIR}/rc.d/rc1.d/K49xinetd
	rm -f ${EXTDIR}/rc.d/rc2.d/K49xinetd
	rm -f ${EXTDIR}/rc.d/rc3.d/S23xinetd
	rm -f ${EXTDIR}/rc.d/rc4.d/S23xinetd
	rm -f ${EXTDIR}/rc.d/rc5.d/S23xinetd
	rm -f ${EXTDIR}/rc.d/rc6.d/K49xinetd

.PHONY: all create-dirs create-service-dir \
	install \
	install-bootscripts \
	install-network \
	install-dhcpcd \
	install-service-mtu \
	minimal \
	install-lcd \
	install-raq2 \
	install-raq3 \
	install-service-dhclient \
	install-service-dhcpcd \
	install-service-ipx \
	install-service-pppoe \
	install-alsa \
	install-apache \
	install-bind \
	install-cups \
	install-cyrus-sasl \
	install-devmapper \
	install-dhcp \
	install-exim \
	install-fcron \
	install-gdm \
	install-gpm \
	install-heimdal \
	install-iptables \
	install-kerberos \
	install-LCDd \
	install-lcdproc \
	install-lisa \
	install-lprng \
	install-mysql \
	install-nas \
	install-netfs \
	install-nfs-client \
	install-nfs-server \
	install-ntp \
	install-openldap1 \
	install-openldap2 \
	install-portmap \
	install-postfix \
	install-postgresql \
	install-proftpd \
	install-random \
	install-rsync \
	install-samba \
	install-sendmail \
	install-sshd \
	install-stunnel \
	install-svn \
	install-sysklogd \
	install-syslog-ng \
	install-sysstat \
	install-vsftpd \
	install-usb \
	install-winbind \
	install-xinetd \
	uninstall-alsa \
	uninstall-apache \
	uninstall-bind \
	uninstall-cups \
	uninstall-cyrus-sasl \
	uninstall-devmapper \
	uninstall-dhcp \
	uninstall-exim \
	uninstall-fcron \
	uninstall-gdm \
	uninstall-gpm \
	uninstall-heimdal \
	uninstall-iptables \
	uninstall-kerberos \
	uninstall-LCDd \
	uninstall-lcdproc \
	uninstall-lisa \
	uninstall-lprng \
	uninstall-mysql \
	uninstall-nas \
	uninstall-netfs \
	uninstall-nfs-client \
	uninstall-nfs-server \
	uninstall-ntp \
	uninstall-openldap1 \
	uninstall-openldap2 \
	uninstall-portmap \
	uninstall-postfix \
	uninstall-postgresql \
	uninstall-proftpd \
	uninstall-random \
	uninstall-rsync \
	uninstall-samba \
	uninstall-sendmail \
	uninstall-sshd \
	uninstall-stunnel \
	uninstall-svn \
	uninstall-syslog-ng \
	uninstall-sysstat \
	uninstall-vsftpd \
	uninstall-usb \
	uninstall-winbind \
	uninstall-xinetd
