#
# Makefile for the helloworld.c
#

obj-m := hello.o
CURRENT_PATH := $(shell pwd)
KERNEL_SRC :=/images/chrism/linux
# KERNEL_SRC :=/lib/modules/3.10.0-862.11.6.el7.x86_64/build

MY_CFLAGS += -g -DDEBUG -D__KERNEL__
ccflags-y += ${MY_CFLAGS}
CC += ${MY_CFLAGS}

all:
	$(MAKE) -C $(KERNEL_SRC) M=$(CURRENT_PATH)
	EXTRA_CFLAGS="$(MY_CFLAGS)"

run:
	sudo insmod ./hello.ko
	dmesg | grep hello

clean:
	rm *.ko
	rm *.o
	rm *.mod.c
	rm *.order
	rm *symvers
	sudo rmmod hello
	sudo dmesg -C
