/*Fully reetrant driver test 3 : using spinlocks to  construct critical regions */

#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/sched.h>
#include <linux/errno.h>
#include <asm/current.h>
#include <linux/device.h>
#include <asm/atomic.h>
#include <linux/spinlock.h>
#include <linux/delay.h>


#define CHAR_DEV_NAME "veda_cdrv"
#define MAX_LENGTH 4000
#define SUCCESS 0


static spinlock_t myspin;
static char *char_device_buf;
struct cdev *veda_cdev;
dev_t mydev;
int count=1;
static struct class *veda_class;
static int recursive_lock(void);
static int accidental_release(void);

static int char_dev_open(struct inode *inode,
			    struct file  *file)
{
	static atomic_t counter =ATOMIC_INIT(0);
	atomic_inc(&counter);
	printk(KERN_INFO "Number of times open() was called: %d\n",atomic_read(&counter));
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

static ssize_t char_dev_read(struct file *file, 
		            char *buf,
			    size_t lbuf,
			    loff_t *ppos)
{
	int maxbytes; /* number of bytes from ppos to MAX_LENGTH */
	int bytes_to_do; /* number of bytes to read */
	int nbytes; /* number of bytes actually read */

	maxbytes = MAX_LENGTH - *ppos;
	
	if( maxbytes > lbuf ) bytes_to_do = lbuf;
	else bytes_to_do = maxbytes;
	
	if( bytes_to_do == 0 ) {
		printk("Reached end of device\n");
		return -ENOSPC; /* Causes read() to return EOF */
	}

   /* Tesing for accidental release */
//  		accidental_release(); 

	printk(KERN_DEBUG "READER: trying for critical region lock \n");
	
	spin_lock(&myspin);/*begin of critical region */
		
		printk(KERN_DEBUG "READER : acquired lock: executing critical code\n");
	 	nbytes = bytes_to_do - 
			 copy_to_user( buf, /* to */
				       char_device_buf + *ppos, /* from */
			     	       bytes_to_do ); /* how many bytes */


  	spin_unlock(&myspin); /* end of critical region */
	*ppos += nbytes;
	return nbytes;	
}

static ssize_t char_dev_write(struct file *file,
		            const char *buf,
			    size_t lbuf,
			    loff_t *ppos)
{
	int nbytes; /* Number of bytes written */
	int bytes_to_do; /* Number of bytes to write */
	int maxbytes; /* Maximum number of bytes that can be written */

	maxbytes = MAX_LENGTH - *ppos;

	if( maxbytes > lbuf ) bytes_to_do = lbuf;
	else bytes_to_do = maxbytes;

	if( bytes_to_do == 0 ) {
		printk("Reached end of device\n");
		return -ENOSPC; /* Returns EOF at write() */
	}

	spin_lock(&myspin); /*begin of critical region */
	 
//	 recursive_lock(); /* may stall machine make sure lock checks are enabled */
	  
           printk(KERN_DEBUG "WRITER: Acquired Write lock : executing code \n");
		nbytes = bytes_to_do -
		         copy_from_user( char_device_buf + *ppos, /* to */
					 buf, /* from */
					 bytes_to_do ); /* how many bytes */
	   printk(KERN_DEBUG "WRITER :entering delay routine \n");
 
		/*shouldn't sleep by rule, inserted for debug  */	
		ssleep(30);

	   printk(KERN_DEBUG "WRITER:  out of delay releasing lock \n");

	spin_unlock(&myspin); /*end of critical region */

	*ppos += nbytes;
	return nbytes;
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


static int recursive_lock(void)
{
	printk(KERN_DEBUG " acquiring lock \n");
		
	spin_lock(&myspin);
 		// something went wrong with wait 
                return -ERESTARTSYS;

		printk(KERN_INFO "updating .....\n");
	
 	spin_unlock(&myspin);
	return SUCCESS;

}

static int accidental_release(void)
{
    printk(KERN_INFO "testing accidental release with mutex \n");
		spin_unlock(&myspin);
	return SUCCESS;
}


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
