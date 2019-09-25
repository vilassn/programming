#include<linux/module.h>
#include<linux/version.h>
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/slab.h>
#include<linux/mempool.h>

#define SUCCESS 0

mempool_t *mem;
struct kmem_cache *cache;
int *ret;

typedef struct abc{
	int a;
	int b;
	int c;
}abc_t;

abc_t *ptr;

static void func(void);


void myalloc(void *data)
{
	static atomic_t counter = ATOMIC_INIT(0);
	abc_t *obj =(abc_t *) data;
	obj->a=0;
	obj->b=0;
	obj->c=0;
	atomic_inc(&counter);
	printk(" Allocator counter %d \n", atomic_read(&counter));
}
	

static void func(void)
{
	ptr=(struct abc *)mempool_alloc(mem,GFP_KERNEL);
	printk("val is %d",ptr->a);
}
static int  __init init_mod(void)
{
	cache=kmem_cache_create("pool cache ", sizeof(abc_t), 0, SLAB_HWCACHE_ALIGN, myalloc);
	mem=mempool_create(20, mempool_alloc_slab, mempool_free_slab, cache);
            if(mem==NULL)
	         return -ENOMEM;

	 func();

         return SUCCESS;
}

void cleanup_mod(void)
{

	mempool_free(ptr,mem);
	mempool_destroy(mem);
	kmem_cache_destroy(cache);

}

module_init(init_mod);
module_exit(cleanup_mod);

/*Kernel module Comments*/
MODULE_AUTHOR("TEAM VEDA");
MODULE_DESCRIPTION("FIRST MODULE");
MODULE_LICENSE("GPL");
