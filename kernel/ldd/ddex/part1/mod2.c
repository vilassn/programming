/*Module exporting choosen symbols
Author:Team-c
Version:1.0
Tested with: Linux kernel version 2.6.29 also
*/


#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>

/*Kernel module Comments*/
MODULE_AUTHOR("TEAM VEDA");
MODULE_DESCRIPTION("FIRST MODULE");
MODULE_LICENSE("GPL");

void func(void);

EXPORT_SYMBOL(func); //func exported

static int val=300; 

void func(void)
{
	printk("func invoked\n ");
	printk(" val = %d",val);
}

void func1(void)
{
	printk(KERN_INFO" func 1 invoked\n");
}	

int myinit(void)
{
	printk(KERN_DEBUG" module inserted\n ");
	return 0;
}

void myexit(void)
{
	printk(" module removed\n ");
}

module_init(myinit);
module_exit(myexit);


/*Kernel module Comments*/
MODULE_AUTHOR("TEAM VEDA");
MODULE_DESCRIPTION("FIRST MODULE");
MODULE_LICENSE("GPL and additional rights");
//Note: All the log levels are defined as part of /linux/kernel.h
