obj-m :=alloc_page.o
obj-m +=structpage.o
obj-m +=ptdump.o


KDIR= /lib/modules/$(shell uname -r)/build

all:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
clean: 
	 rm -rf $(wildcard *.o *.ko *.mod.* .c* .t* test Module.symvers *.order *.markers)
