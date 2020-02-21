#
# Makefile for the cbuffer.c
#

obj-m := cbuffer.o
CURRENT_PATH := $(shell pwd)
KERNEL_SRC :=/images/chrism/linux

KVERSION = $(shell uname -r)
obj-m = cbuffer.o

all:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) clean
	-sudo rmmod cbuffer
	-sudo dmesg -CT

run:
	-sudo insmod ./cbuffer.ko
	-sudo dmesg -T
