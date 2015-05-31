#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/TobyOS.kernel isodir/boot/TobyOS.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "TobyOS" {
	multiboot /boot/TobyOS.kernel
}
EOF
grub-mkrescue -o TobyOS.iso isodir
