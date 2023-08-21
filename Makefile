include efi.mk

all: createDisc

createDisc: posixutils.efi
	truncate -s 16M efi.img
	mkfs.fat efi.img
	mcopy -i efi.img posixutils.efi "::posixutils.efi"

test: createDisc
	qemu-system-x86_64 -pflash ../code.fd -m 256M --enable-kvm -hda efi.img -vga std