#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/miscdevice.h>
#include "clock.h"

#define DEV_NAME "clock"
#define SUCCESS 0

static int inuse = 0;
unsigned char cmd_arr[] = {
	DAY_CMD,
	MONTH_CMD,
	YEAR_CMD,
	HOURS_CMD,
	MINUTES_CMD,
	SECONDS_CMD
};

/* above array is used to simplify writing code for read/write according
   to the design as described in Readme.clock.
*/
static int clock_open(struct inode *inode, struct file *file)
{
	if (inuse) {
		pr_err("Device busy %s", DEV_NAME);
		return -EBUSY;
	}
	inuse = 1;
	pr_info("Open operation invoked");
	return SUCCESS;
}

static int clock_release(struct inode *inode, struct file *file)
{
	inuse = 0;
	return SUCCESS;
}

/* Limitation : can write only one byte at a point of time,can extend 
   this by slightly modifying the code . We leave this as exercise
   for students 
*/

static ssize_t clock_write(struct file *file, const char __user * buf,
			   size_t lbuf, loff_t * f_pos)
{

	unsigned char cmd, data;
	if (lbuf > 1)
		return -EIO;	// IO error.
	if (*f_pos >= FILE_SIZE)
		return -EIO;	// IO error.
	cmd = cmd_arr[*f_pos];
	if (copy_from_user(&data, buf, 1))
		return -EFAULT;
	pr_info("cmd = %d  data = %d", cmd, data);
	WRITE_TO_CLOCK(cmd, data);
	(*f_pos)++;
	return 1;

}

static ssize_t clock_read(struct file *fil, char __user * buf, size_t lbuf,
			  loff_t * f_pos)
{
	unsigned char cmd = 0, data = 0;
	data = 0;
	if (lbuf > 1)
		return -EIO;	// IO error.
	if (*f_pos >= FILE_SIZE)
		return -EIO;	// IO error.
	cmd = cmd_arr[*f_pos];
	READ_FROM_CLOCK(cmd, data);
	if (copy_to_user(buf, &data, 1))
		return -EFAULT;
	pr_info("data = %d cmd = %d ", data, cmd);
	(*f_pos)++;
	return 1;
}

static struct file_operations clock_ops = {
	.owner = THIS_MODULE,
	.write = clock_write,
	.read = clock_read,
	.open = clock_open,
	.release = clock_release
};

static struct miscdevice clkMisc = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = DEV_NAME,
	.fops = &clock_ops,
};

/* Register Driver with Misc interface */
static int __init char_dev_init(void)
{
	int ret;
	ret = misc_register(&clkMisc);
	if (ret < 0) {
		pr_err("failed registering with minor %d", clkMisc.minor);
		return ret;
	}
	pr_info("driver registered with Minor %d", clkMisc.minor);

	return SUCCESS;
}

static void __exit char_dev_exit(void)
{
	misc_deregister(&clkMisc);
	pr_info("Misc dev unregistered");
}

module_init(char_dev_init);
module_exit(char_dev_exit);

MODULE_AUTHOR("support@techveda.org");
MODULE_DESCRIPTION("LKD_CW: simple rtc driver");
MODULE_LICENSE("GPL");
/* End of code */
