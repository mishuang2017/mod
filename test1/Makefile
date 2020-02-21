#
# Makefile for the test1.c
#

obj-m := test1.o
CURRENT_PATH := $(shell pwd)
KERNEL_SRC :=/home1/chrism/linux

KVERSION = $(shell uname -r)
obj-m = test1.o

all:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD)
clean:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) clean
	-sudo rmmod test1
	-sudo dmesg -C

run:
	-sudo insmod ./test1.ko
	-sudo dmesg
