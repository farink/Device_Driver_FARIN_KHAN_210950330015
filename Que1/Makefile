obj-m := kernel.o

KERNELDIR = /lib/modules/$(shell uname -r)/build

pwd := $(shell pwd)

all:
	make -C $(KERNELDIR) M=$(PWD) modules

clean:
	make -C $(KERNELDIR) M=$(PWD) clean
