obj-m += spidev.o

CROSS_COMPILE ?= aarch64-linux-gnu-
ARCH ?= arm64
KDIR ?= $(shell git rev-parse --show-toplevel)/external/kernel

all:
	$(MAKE) -C $(KDIR) M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) clean
