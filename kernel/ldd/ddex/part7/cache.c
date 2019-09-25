#include<linux/module.h>
#include<linux/version.h>
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/slab.h>
#include<linux/gfp.h>
#include<linux/types.h>


#define SUCCESS 0

struct kmem_cache *my_cache;

typedef struct{
	int a;
	int b;
	int c;
}private_data;

private_data *handle;

static int __init myinit(void)
{


/* create  private slab cache list and align it with hardare cache */
my_cache = kmem_cache_create("mycache",sizeof(private_data), 0, SLAB_HWCACHE_ALIGN, NULL);
if(my_cache==NULL)
	 return -ENOMEM;

/* Alloc an object from list */
handle =  (private_data *)kmem_cache_alloc(my_cache,GFP_KERNEL);

handle->a=400;
handle->b=40;
handle->c=60;

printk(" private data state \na=%d\nb=%d\nc=%d\n", handle->a,handle->b,handle->c);

kmem_cache_free(my_cache,handle);

return SUCCESS;
}

static void __exit myexit(void)
{
kmem_cache_destroy(my_cache);
}

module_init(myinit);
module_exit(myexit);

/*Kernel module Comments*/
MODULE_AUTHOR("TEAM VEDA");
MODULE_DESCRIPTION("FIRST MODULE");
MODULE_LICENSE("GPL");
