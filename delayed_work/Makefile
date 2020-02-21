#
# Makefile for the delayed_work.c
#

obj-m := delayed_work.o
CURRENT_PATH := $(shell pwd)
KERNEL_SRC :=/home1/chrism/linux

KVERSION = $(shell uname -r)
obj-m = delayed_work.o

all:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) clean
	-sudo rmmod delayed_work
	-sudo dmesg -CT

run:
	-sudo insmod ./delayed_work.ko
	-sudo dmesg -T
