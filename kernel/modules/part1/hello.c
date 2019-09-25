#include <linux/module.h>	//kmod interface
#include <linux/version.h>	// kernel version stamp
#include <linux/kernel.h>	// resolve kernel symbol calls

void func (void)
{
	printk (KERN_INFO "Hello world");
}

int init_module (void)
{
	printk (KERN_INFO "module inserted ");
	return 0;
}

void cleanup_module (void)
{
	printk (KERN_INFO "module removed ");
}

/*Kernel module Comments*/
MODULE_AUTHOR ("support@techveda.org");
MODULE_DESCRIPTION ("LKD_CW: First kernel module");
MODULE_LICENSE ("GPL");
