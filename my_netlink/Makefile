#
# Makefile for the my_netlink.c
#

obj-m := my_netlink.o
CURRENT_PATH := $(shell pwd)
KERNEL_SRC :=/images/chrism/linux

KVERSION = $(shell uname -r)
obj-m = my_netlink.o

all:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) clean
	-sudo rmmod my_netlink
	-sudo dmesg -CT

run:
	-sudo insmod ./my_netlink.ko
	-sudo dmesg -T
