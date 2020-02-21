#
# Makefile for the kcalloc_node.c
#

obj-m := kcalloc_node.o
CURRENT_PATH := $(shell pwd)
KERNEL_SRC :=/home1/chrism/linux

KVERSION = $(shell uname -r)
obj-m = kcalloc_node.o

all:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) clean
	-sudo rmmod kcalloc_node
	-sudo dmesg -C

run:
	-sudo insmod ./kcalloc_node.ko
	-sudo dmesg
