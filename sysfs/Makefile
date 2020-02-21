#
# Makefile for the sysfs.c
#

obj-m := sysfs.o
CURRENT_PATH := $(shell pwd)
KERNEL_SRC :=/home1/chrism/linux

KVERSION = $(shell uname -r)
obj-m = sysfs.o

all:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) clean
	-sudo rmmod sysfs
	-sudo dmesg -CT

run:
	-sudo insmod ./sysfs.ko
	-sudo dmesg -T
