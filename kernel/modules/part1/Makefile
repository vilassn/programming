obj-m :=hello.o
obj-m +=modex.o
obj-m +=moddep1.o
obj-m +=moddep2.o
#obj-m +=modcounter.o
#obj-m +=modcorrupt.o
obj-m +=modexfunc.o
obj-m +=tfunc.o
obj-m +=modparam.o

#obj-m +=procinfo.o

KDIR= /lib/modules/$(shell uname -r)/build

all:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
clean: 
	 rm -rf $(wildcard *.o *.ko *.mod.* .c* .t* test Module.symvers *.order *.markers)
