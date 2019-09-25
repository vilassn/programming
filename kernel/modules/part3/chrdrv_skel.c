#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>

#define MAJORNO 300
#define MINORNO  0
#define CHAR_DEV_NAME "vDev1"
#define SUCCESS 0

static struct cdev *veda_cdev;
static dev_t mydev;
static int count = 1, inuse = 0;

static int char_dev_open(struct inode *inode, struct file *file)
{
	if (inuse) {
		pr_err("Device busy %s", CHAR_DEV_NAME);
		return -EBUSY;
	}
	inuse = 1;
	pr_info("Open operation invoked");
	return SUCCESS;
}

static int char_dev_release(struct inode *inode, struct file *file)
{
	inuse = 0;
	return SUCCESS;
}

static ssize_t char_dev_write(struct file *file, const char __user * buf,
			      size_t lbuf, loff_t * offset)
{
	pr_info("Rec'vd data : %s, of len=%ld", buf, lbuf);
	return lbuf;
}

static struct file_operations char_dev_fops = {
	.owner = THIS_MODULE,
	.write = char_dev_write,
	.open = char_dev_open,
	.release = char_dev_release
};

/* Register Driver with I/O abstarction layer
 *
 *  step 1: Reserve Driver/Device ID.
 *  step 2: Register file operations
 *
*/
static int __init char_dev_init(void)
{
	int ret;
	mydev = MKDEV(MAJORNO, MINORNO);
	register_chrdev_region(mydev, count, CHAR_DEV_NAME);

	veda_cdev = cdev_alloc();
	cdev_init(veda_cdev, &char_dev_fops);
	ret = cdev_add(veda_cdev, mydev, count);
	if (ret < 0) {
		pr_err("Error registering device driver");
		return ret;
	}
	pr_info("Device Registered %s", CHAR_DEV_NAME);
	return SUCCESS;
}

static void __exit char_dev_exit(void)
{
	cdev_del(veda_cdev);
	unregister_chrdev_region(mydev, count);
	pr_info("Driver unregistered");
}

module_init(char_dev_init);
module_exit(char_dev_exit);

MODULE_AUTHOR("VEDA");
MODULE_DESCRIPTION("Character Device Driver - Test");
MODULE_LICENSE("GPL");
/* End of code */
