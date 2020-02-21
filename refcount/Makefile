#
# Makefile for the refcount.c
#

obj-m := refcount.o
CURRENT_PATH := $(shell pwd)
KERNEL_SRC :=/home1/chrism/linux

KVERSION = $(shell uname -r)
obj-m = refcount.o

all:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) clean
	-sudo rmmod refcount
	-sudo dmesg -C

run:
	-sudo insmod ./refcount.ko
	-sudo dmesg
