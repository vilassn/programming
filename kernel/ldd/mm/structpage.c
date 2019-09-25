#include <linux/module.h>
#include <linux/mm.h>
#include <linux/slab.h>

static unsigned char *ptr;
static unsigned int pa;

int init_module(void)
{
	printk("Size of struct page = %d\n",sizeof(struct page));
	ptr = kmalloc(4096, GFP_KERNEL);
	printk("Value of ptr (Virtual Address) = %p\n",ptr);
	pa = __pa(ptr);
	printk("Value of pa (Physical Address) = %08x\n",pa);
	strcpy(ptr,"data written to page\n");
	
	return 0;
}

void cleanup_module(void)
{
	kfree(ptr);
	printk("Unloading\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Veda");
