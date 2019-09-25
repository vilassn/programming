obj-m :=mycache.o
obj-m +=cache.o
obj-m  +=cachepool.o
obj-m +=dma_test.o
obj-m +=dma_pci_test.o

KDIR = /lib/modules/$(shell uname -r)/build
all:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

clean:
	rm -rf $(wildcard *.o *.ko *.mod.* .c* .t* test Module.symvers *.order *.markers a.out)
