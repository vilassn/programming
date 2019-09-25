obj-m :=chr_drv_reentrant.o
obj-m +=chr_drv_mutex.o
obj-m +=chr_drv_spinlock.o
KDIR= /lib/modules/$(shell uname -r)/build

all:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
clean:
	rm -rf $(wildcard *.o *.ko mo* Mo* *.mod.c)
