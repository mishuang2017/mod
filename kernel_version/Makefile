#
# Makefile for the kernel_version.c
#

obj-m := kernel_version.o
CURRENT_PATH := $(shell pwd)
KERNEL_SRC :=/home1/chrism/linux

KVERSION = $(shell uname -r)
obj-m = kernel_version.o

all:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) clean
	-sudo rmmod kernel_version
	-sudo dmesg -CT

run:
	-sudo insmod ./kernel_version.ko
	-sudo dmesg -T
