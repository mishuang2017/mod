#
# Makefile for the hash.c
#

obj-m := hash.o
CURRENT_PATH := $(shell pwd)
KERNEL_SRC :=/home1/chrism/linux

KVERSION = $(shell uname -r)
obj-m = hash.o

all:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) clean
	-sudo rmmod hash
	-sudo dmesg -C

run:
	-sudo insmod ./hash.ko
	-sudo dmesg
