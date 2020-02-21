#
# Makefile for the rcu_work.c
#

obj-m := rcu_work.o
CURRENT_PATH := $(shell pwd)
KERNEL_SRC :=/home1/chrism/linux

KVERSION = $(shell uname -r)
obj-m = rcu_work.o

all:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) clean
	-sudo rmmod rcu_work
	-sudo dmesg -CT

run:
	-sudo insmod ./rcu_work.ko
	-sudo dmesg -T
