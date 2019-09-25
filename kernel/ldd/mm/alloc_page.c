#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/gfp.h>
#include <linux/mm.h>

int mod_init(void)
{
	struct page *p;
	char *lmem;
	int i;
	unsigned int pfn,size;
	
	/*
	 * Print Page size
	 */
	size = PAGE_SIZE;
	printk("\nPage Size = %d", size);
	
	/*
	 * Print number of pages
	 */	
	printk("\nNumber of physical pages %ld", num_physpages);

	/*
	 * Allocate memory using alloc_page
	 */
	p = alloc_page(GFP_KERNEL);
	if (!p) {
		printk("\nCannot Allocate Memory\n");
		return -ENOMEM;
	}

	/*
	 * print page frame number corresponding to
 	 * page allocated above
	 */
	printk("\nPage Frame Number %ld", page_to_pfn(p));
	
	/*
	 * Get linear address for the above page
	 */
	lmem = page_address(p);
	printk("\nLinear Address %p\n", lmem);

	/* Write some thing into the memory, and print it*/
	memset(lmem, 'A', PAGE_SIZE);

	for (i = 0; i < PAGE_SIZE; i++)
		printk("%c", lmem[i]);

	/*
	 * free the page
	 */
	__free_page(p);
	
	/*Get memory using __get_free_page() */

	lmem = (char *)__get_free_page(GFP_KERNEL);
	if (!lmem) {
		printk("\nCannot Allocate memory\n");
		return -ENOMEM;
	}	
	printk("\nLinear Address %p", lmem);

	/*
	 * Get liner address page frame number
	 */
	pfn = __pa(lmem) >> PAGE_SHIFT;
	printk("\nPage frame number %d", pfn);

	/*
	 * Get address to page object
	 */
	printk("\nPage Object %p\n", pfn_to_page(pfn));
	/*Free the memory*/
	free_page((unsigned long)lmem);

	return 0;
}

void mod_exit(void)
{

}

module_init(mod_init);
module_exit(mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Veda Solutions");

