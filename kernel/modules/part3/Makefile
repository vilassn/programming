#obj-m := chrdrv_skel.o
#obj-m += chrdrv_dyn.o
obj-m += chrdrv_udev.o
#obj-m += chrdrv_reg.o
#obj-m += chrdrv_misc.o

KDIR= /lib/modules/$(shell uname -r)/build

all:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
clean:
	@rm -rf $(wildcard *.o *.ko  Mo* *.mod.c .*.cmd .tmp* modules.order a.out)
