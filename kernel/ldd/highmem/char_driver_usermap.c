#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/sched.h>
#include <linux/errno.h>
#include <asm/current.h>
#include <linux/device.h>
#include <linux/mm.h>
#include <linux/pagemap.h>

#define MAJORNO 300
#define MINORNO  0
#define CHAR_DEV_NAME "veda_cdrv"
#define MAX_LENGTH 4000
#define SUCCESS 0

static char *char_device_buf;
struct cdev *veda_cdev;
dev_t mydev;
int count=1;
static struct class *veda_class;

static int char_dev_open(struct inode *inode,
			    struct file  *file)
{
	static int counter = 0;
	counter++;
	printk(KERN_INFO "Number of times open() was called: %d\n", counter);
	printk (KERN_INFO " MAJOR number = %d, MINOR number = %d\n",imajor (inode), iminor (inode));
	printk(KERN_INFO "Process id of the current process: %d\n",current->pid );
	printk (KERN_INFO "ref=%d\n", module_refcount(THIS_MODULE));
	return SUCCESS;
}

static int char_dev_release(struct inode *inode,
		            struct file *file)
{
	return SUCCESS;
}

static ssize_t mycdrv_rw (struct file *file, unsigned long buf, size_t lbuf, loff_t * ppos, int rw)
{
    int j, nb, rc, npages;
    struct page **pages;
    char *uaddr, *ktmp;

    /* get the total number of pages of memory needed */
    npages = (lbuf - 1) / PAGE_SIZE + 1;

    /* allocate space for array of page structures */

    printk (KERN_INFO "npages = %d for %ld bytes\n", npages, (long)lbuf);
    if (!(pages = kmalloc (npages * sizeof (pages), GFP_KERNEL))) {
        printk (KERN_ERR "allocating pages failed\n");
        return -ENOMEM;
    }

    /* get the page structures, protect with a lock */

    down_read (&current->mm->mmap_sem);
    rc = get_user_pages (current, current->mm,
                         (unsigned long)buf, npages, 1, 0, pages, NULL);
    up_read (&current->mm->mmap_sem);
    printk (KERN_INFO " I received %d pages from the user \n", rc);

    for (j = 0, nb = PAGE_SIZE, ktmp = char_device_buf; j < npages;
         j++, ktmp += PAGE_SIZE) {

        /* remap the page address; could also use page_address(page) */

        uaddr = kmap (pages[j]);

        if (j == npages - 1)
            nb = (lbuf - 1) % PAGE_SIZE + 1;

        /* do the actual i/o operation ; for now just to a kernel buffer */

        /* should put the switch outside the loop; for now live with it */

        switch (rw) {
        case 0:             /* read */
            memcpy (uaddr, ktmp, nb);
            printk (KERN_INFO " kernel sees on a read:\n%s\n", uaddr);
            break;
        case 1:             /* write */
            memcpy (ktmp, uaddr, nb);
            printk (KERN_INFO " kernel sees on a write:uaddr:\n%s\n", uaddr);
            break;
        default:                /* should never hit here */
            printk (KERN_INFO "Error in rw routine, rw=%d\n", rw);
            break;
        }

        /* release the page cache -- no surprises to apps */
        lock_page (pages[j]);
        set_page_dirty (pages[j]);  /* make sure it is flushed */
        unlock_page (pages[j]);

        //set_page_dirty_lock(pages[j]);
        page_cache_release (pages[j]);  /* make sure it is released from cache */

        /* release the remap; don't need to do if use page_address() */
        kunmap (pages[j]);
    }
	kfree (pages);

    printk (KERN_INFO "\n Leaving the READ  function, nbytes=%ld\n", (long)lbuf);
    return lbuf;
}

static int char_dev_read(struct file *file, 
		            char *buf,
			    size_t lbuf,
			    loff_t *ppos)
{
	int rw = 0;
        return mycdrv_rw (file, (unsigned long)buf, lbuf, ppos, rw);

}

static int char_dev_write(struct file *file,
		            const char *buf,
			    size_t lbuf,
			    loff_t *ppos)
{
	 int rw =1;
	 printk("write invoked\n");
         return mycdrv_rw (file, (unsigned long)buf, lbuf, ppos, rw);
}



static loff_t char_dev_lseek (struct file *file, loff_t offset, int orig)
{
    loff_t testpos;
    switch (orig) {

    case 0:                 /* SEEK_SET */
            testpos = offset;
            break;
    case 1:                 /* SEEK_CUR */
            testpos = file->f_pos + offset;
            break;
    case 2:                 /* SEEK_END */
           testpos = MAX_LENGTH + offset;
           break;
    default:
          return -EINVAL;
    }
   
    testpos = testpos < MAX_LENGTH ? testpos : MAX_LENGTH;
    testpos = testpos >= 0 ? testpos : 0;
    file->f_pos = testpos;
    printk (KERN_INFO "Seeking to pos=%ld\n", (long)testpos);
    return testpos;
}
static struct file_operations char_dev_fops = {
	.owner = THIS_MODULE,
	.read = char_dev_read,
	.write = char_dev_write,
	.open = char_dev_open,
	.release = char_dev_release,
	.llseek = char_dev_lseek
};

static __init int char_dev_init(void)
{
	int ret;

	if (alloc_chrdev_region (&mydev, 0, count, CHAR_DEV_NAME) < 0) {
            printk (KERN_ERR "failed to reserve major/minor range\n");
            return -1;
    }

        if (!(veda_cdev = cdev_alloc ())) {
            printk (KERN_ERR "cdev_alloc() failed\n");
            unregister_chrdev_region (mydev, count);
            return -1;
 	}
	cdev_init(veda_cdev,&char_dev_fops);

	ret=cdev_add(veda_cdev,mydev,count);
	if( ret < 0 ) {
		printk(KERN_INFO "Error registering device driver\n");
	        cdev_del (veda_cdev);
                unregister_chrdev_region (mydev, count); 	
		return -1;
	}

	veda_class = class_create (THIS_MODULE, "VIRTUAL");
        device_create (veda_class, NULL, mydev, NULL, "%s", "veda_cdrv");

	printk(KERN_INFO"\nDevice Registered: %s\n",CHAR_DEV_NAME);
	printk (KERN_INFO "Major number = %d, Minor number = %d\n", MAJOR (mydev),MINOR (mydev));

	char_device_buf =(char *)kmalloc(MAX_LENGTH,GFP_KERNEL);
	return 0;
}

static __exit void  char_dev_exit(void)
{
	 device_destroy (veda_class, mydev);
         class_destroy (veda_class);
	 cdev_del(veda_cdev);
	 unregister_chrdev_region(mydev,1);
	 kfree(char_device_buf);
	 printk(KERN_INFO "\n Driver unregistered \n");
}
module_init(char_dev_init);
module_exit(char_dev_exit);

MODULE_AUTHOR("VEDA");
MODULE_DESCRIPTION("Character Device Driver - Test");
MODULE_LICENSE("GPL");
