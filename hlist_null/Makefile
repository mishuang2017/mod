#
# Makefile for the hlist_null.c
#

obj-m := hlist_null.o
CURRENT_PATH := $(shell pwd)
KERNEL_SRC :=/home1/chrism/linux

KVERSION = $(shell uname -r)
obj-m = hlist_null.o

all:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) clean
	-sudo rmmod hlist_null
	-sudo dmesg -CT

run:
	-sudo insmod ./hlist_null.ko
	-sudo dmesg -T
