obj-m :=vbus.o
obj-m +=vbusdrv_misc.o
obj-m +=vbusdrv_ioctl.o

KDIR= /lib/modules/$(shell uname -r)/build

all:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

clean:
	@rm -rf $(wildcard *.o *.ko Mo* *.mod.c a.out .*.cmd *.order .tmp_versions .*.swp)
