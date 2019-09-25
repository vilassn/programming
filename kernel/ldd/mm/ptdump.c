#include <linux/module.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <asm/page.h>
#include <asm/pgtable.h>
#include <linux/highmem.h>

static int major;
static void *kptr1, *kptr2;

int ptd_open(struct inode *i, struct file *filp)
{
	return 0;
}

int ptd_close(struct inode *i, struct file *filp)
{
	return 0;
}

static unsigned long getDirEntry(const pgd_t *pgd, void *address)
{
	unsigned long d_index;
	unsigned long *pgd_array = (unsigned long *)pgd;
	unsigned long tmp;

	unsigned long t = (unsigned long)address;
	d_index = t >> 22;
	tmp = pgd_array[d_index];
	tmp = tmp >> 12;
	tmp = tmp << 12;
	return tmp;
}

static unsigned long getPageTableEntry(unsigned long d, void *address)
{
	unsigned long t;
	unsigned long *pte_array = (unsigned long *)d;
	unsigned long tmp;

	t = (unsigned long)address;
	t = t << 10;
	t = t >> 22;

	tmp = pte_array[t];
	tmp = tmp >> 12;
	tmp = tmp << 12;
	return tmp;
}

ssize_t ptd_read(struct file *filp,char *buf, size_t count, loff_t *fpos)
{
	unsigned long d, pte, t;
	unsigned int pfn, pfn2;
	struct page *pptr, *pptr2;
	
	struct mm_struct *mm = current->mm;
	pgd_t *pgd = mm->pgd;
	printk("KERNEL:Address (virtual) of buf received = %p\n",buf);
	printk("KERNEL:Address of page global directory = %p\n",pgd);
	d = getDirEntry(pgd,buf);
	printk("KERNEL: Address of page Table  = %08x\n",
						(unsigned int)d);
	pfn = d >> 12;
	printk("frame number of page Table = %08x\n",pfn);
	pptr = pfn_to_page(pfn);
	printk("Address of struct page of Page Table = %p\n",pptr);
	kptr1 = kmap(pptr);
	pte = getPageTableEntry((unsigned long)kptr1,buf);
	printk("KERNEL:Physical address of frame = %08x\n",
						(unsigned int)pte);
	pfn2 = pte >>12;
	pptr2 = pfn_to_page(pfn2);
	kptr2 = kmap(pptr2);
	printk("KERNEL:Frame mapped to page  = %p\n",kptr2);
	t = (unsigned long)buf;
	t = t << 20;
	t = t >> 20;
	printk("Value of string inside physical page = %s\n",(char *)kptr2+t);

	return 0;
}

struct file_operations ptd_fops = {
	.open		= ptd_open,
	.release	= ptd_close,
	.read		= ptd_read,
	.owner		= THIS_MODULE,
};

int init_module(void)
{
	printk("Loading ptdump\n");
	major = register_chrdev(0,"addtrans",&ptd_fops);
	if ( major <= 0 ) {
	   printk("Error in registering character device\n");
	   return -1;
	}
	else printk("Assigned major number = %d\n",major);
	
	return 0;
}

void cleanup_module(void)
{
	unregister_chrdev(major,"addtrans");
	kunmap(kptr1);
	kunmap(kptr2);
	printk("Unloading\n");
}
MODULE_LICENSE("GPL");
MODULE_AUTHOR("support@techveda.org");

