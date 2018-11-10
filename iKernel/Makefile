#Compile the kernel moduel independtly
KVERS = $(shell uname -r)
CURDIR = $(shell pwd)
obj-m := iHelloWorldModule.o
build: kernel_modules
kernel_modules:
	make -C /usr/src/linux-headers-$(KVERS) M=$(CURDIR) modules
clean:
	make -C /usr/src/linux-headers-$(KVERS) M=$(CURDIR) clean
