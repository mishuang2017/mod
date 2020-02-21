#
# Makefile for the semaphore_mutex.c
#

obj-m := semaphore_mutex.o
CURRENT_PATH := $(shell pwd)
KERNEL_SRC :=/images/chrism/linux

KVERSION = $(shell uname -r)
obj-m = semaphore_mutex.o

all:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) clean
	-sudo rmmod semaphore_mutex
	-sudo dmesg -CT

run:
	-sudo insmod ./semaphore_mutex.ko
	-sudo dmesg -T
