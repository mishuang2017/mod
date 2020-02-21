#
# Makefile for the test_printk.c
#

obj-m := test_printk.o
CURRENT_PATH := $(shell pwd)
KERNEL_SRC :=/home1/chrism/linux

KVERSION = $(shell uname -r)
obj-m = test_printk.o

CFLAGS_test_printk.o := -DDEBUG

all:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) clean
	-sudo rmmod test_printk
	-sudo dmesg -CT

run:
	-sudo insmod ./test_printk.ko
	-sudo dmesg -T
