#
# Makefile for the slab.c
#

obj-m := slab.o
CURRENT_PATH := $(shell pwd)
KERNEL_SRC :=/home1/chrism/linux

KVERSION = $(shell uname -r)
obj-m = slab.o

all:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) clean
	-sudo rmmod slab
	-sudo dmesg -CT

run:
	-sudo insmod ./slab.ko
	-sudo dmesg -T
