#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/slab.h>
#include <asm/current.h>
#include <linux/sched.h>
#include <asm/uaccess.h>
#include <linux/delay.h>
#include "vbus.h"
#include "ioctl_const.h"

#define DEV_NAME "vbufdev"

struct drvpriv{
	struct device *dev;
	struct vbufdev *vdev;
	uint32_t devlen;
    	int ucount;
};

static struct drvpriv *priv;

static int drv_open(struct inode *inode, struct file *file)
{
        priv->ucount++;
        dev_info(priv->dev, "driver ucount %d", priv->ucount);
        dev_info(priv->dev, "MAJOR number = %d, MINOR number = %d",imajor (inode), iminor (inode));
        dev_info(priv->dev, "Process id of the current process: %d",current->pid );
        return SUCCESS;
}

static int drv_release(struct inode *inode, struct file *file)
{
	priv->ucount--;
	return SUCCESS;
}


static ssize_t drv_write(struct file *file,        	/*pointer to file object/inode*/
                           const char __user *buf,   	/* pointer to user buffer */
                            size_t lbuf,        	/* length of user buffer */
                            loff_t *ppos)       	/* present offset position */

{
        int maxbytes;  		
        int bytes_to_do;  	/* number of bytes to read */
        int nbytes,ret;  	/* number of bytes actually read */
        void *drvbuf;
        loff_t offset;
	struct vbus_data *data;

        maxbytes = priv->devlen - *ppos;
        offset = *ppos;

        if( lbuf > maxbytes ) {
                dev_err(priv->dev,"Req exceeds vbufdev limit");
                return -EINVAL;
        }
        bytes_to_do = lbuf;
        if( bytes_to_do == 0 ) {
                dev_err(priv->dev, "Reached end of device");
                return -ENOSPC; /* Causes read() to return EOF */
        }

        drvbuf = kzalloc(bytes_to_do, GFP_KERNEL);
        if (!buf) {
                dev_err(priv->dev, "Out of memory");
                return -ENOMEM;
        }
	
	nbytes = bytes_to_do -
                 copy_from_user( drvbuf, /* to */
                                 buf, /* from */
                                 bytes_to_do ); /* how many bytes */


	data = alloc_vdata();
	data->dev = priv->vdev;
	data->buf = drvbuf;
	data->size = nbytes;
	data->offset = offset;

        ret = vbus_write(data);

        *ppos += ret;

	kfree(drvbuf);
	kfree(data);
        return ret;
}


static ssize_t drv_read(struct file *file, 	/*pointer to file object/inode*/
                            char __user *buf,	/* pointer to user buffer */
                            size_t lbuf,    	/* length of user buffer */
                            loff_t *ppos)       /* present offset position */
{
        int maxbytes;  /* number of bytes from ppos to MAX_LENGTH */
        int bytes_to_do;  /* number of bytes to read */
        int nbytes,ret;  /* number of bytes actually read */
	char *drvbuf;
	loff_t offset;
	struct vbus_data *data;
        
	maxbytes = priv->devlen - *ppos;
	offset = *ppos;	

        if( lbuf > maxbytes ) {
		dev_err(priv->dev,"Req exceeds vbufdev limit");
		return -EINVAL;
	}
	bytes_to_do = lbuf;
        if( bytes_to_do == 0 ) {
                dev_err(priv->dev, "Reached end of device");
                return -ENOSPC; 	/* Causes read() to return EOF */
        }
	
	drvbuf = (char *) kzalloc(bytes_to_do, GFP_KERNEL);
	if (!buf) {
		dev_err(priv->dev, "Out of memory");
		return -ENOMEM;
	}	

	data = alloc_vdata();
	if(!data) {
		dev_err(priv->dev,"vdata alloc failed");
		return -ENOMEM;
	}
        data->dev = priv->vdev;
        data->buf = drvbuf;
        data->size = bytes_to_do;
        data->offset = offset;
	nbytes = vbus_read(data);
        ret = nbytes -
                 copy_to_user( buf, /* to */
                               drvbuf, /* from */
                               nbytes); /* how many bytes */

        *ppos += ret;
	kfree(drvbuf);
	free_vdata(data);
      
	return ret;
}

static loff_t drv_lseek (struct file *file, loff_t offset, int orig)
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
           testpos = priv->devlen;
           break;
    default:
          return -EINVAL;
    }

    if(testpos > priv->devlen){
	dev_err(priv->dev, "seek out of device range");
	return -EINVAL;
    }
    file->f_pos = testpos;
    return testpos;
}

static long  drv_ioctl(struct file *filp,
                          unsigned int cmd,
                          unsigned long arg)
{
 /*     step 1: verify args */

        uint32_t size;
	struct vbus_data *data;
	void *drvbuf;
        int ret;
	char c;
	void  __user *uarg;
	
        if( _IOC_TYPE(cmd) != VBUFDEV_MAGIC ) return -ENOTTY;
        if( _IOC_NR(cmd) > VBUFDEV_MAX_CMDS ) return -ENOTTY;


	data = alloc_vdata();
	if(!data) {
                dev_err(priv->dev,"vdata alloc failed");
                return -ENOMEM;
        }

        /* implement support of commands using switch/case */
        switch(cmd) {

        case VBUFDEV_FILL_ZERO:
		drvbuf = kzalloc(priv->devlen, GFP_KERNEL);
        	if (!drvbuf){
			pr_err("allocation failed");
                	return -ENOMEM;
		}
		memset(drvbuf, 0, priv->devlen);
		data->dev = priv->vdev;
          	data->buf = drvbuf;
        	data->size = priv->devlen;
        	data->offset = 0;
		ret = vbus_write(data);
		kfree(drvbuf);
		break;

        case VBUFDEV_FILL_CHAR:
		drvbuf = kzalloc(priv->devlen, GFP_KERNEL);
                if (!drvbuf){
			pr_err("allocation failed");
			return -ENOMEM; 
		}
		uarg = (char __user *) arg;
		get_user(c, (char *) uarg); 
                memset(drvbuf, (int)c, priv->devlen);
                data->dev = priv->vdev;
                data->buf = drvbuf;
                data->size = priv->devlen;
                data->offset = 0;
                ret = vbus_write(data);
		kfree(drvbuf);
		break;

        case VBUFDEV_SET_SIZE:
                 if (!capable(CAP_SYS_ADMIN))
                 	 return -EPERM;
		uarg = (uint32_t __user *) arg;
                copy_from_user(&size, (uint32_t *)uarg,
                                  sizeof(uint32_t) );
		ret = vbus_setsize(priv->vdev, size);
		priv->devlen = priv->vdev->len;
                break;

        case VBUFDEV_GET_SIZE:
                if (!capable(CAP_SYS_ADMIN))
                        return -EPERM;
		uarg = (uint32_t __user *) arg;
		size = vbus_getsize(priv->vdev);
                copy_to_user( (uint32_t *)uarg, &size , sizeof(uint32_t) );
                break;
        }

        return SUCCESS;
}


static struct file_operations drv_fops = {
	.owner = THIS_MODULE,
	.unlocked_ioctl = drv_ioctl,
	.read = drv_read,
	.write = drv_write,
	.open = drv_open,
	.release = drv_release,
	.llseek = drv_lseek
};

static struct miscdevice vDevMisc = {
	.minor = MISC_DYNAMIC_MINOR,
	.name =  DEV_NAME,
	.fops = &drv_fops
};

static int drv_probe(struct vbufdev *vdev) {
	
	int ret;
	if (!vdev->flags == RESOURCE_MEM){
		dev_err(vdev->dev," Error Device");
		return -EINVAL;
	}
	
	priv = (struct drvpriv *)kmalloc(sizeof(struct drvpriv), GFP_KERNEL);
	priv->dev = vdev->dev;
	priv->vdev =  vdev;
	priv->devlen = vdev->len;
	priv->ucount = 0;
	dev_info( priv->dev, "Device Length %d", priv->devlen);
        
	ret = misc_register(&vDevMisc);
        if (ret < 0) {
                dev_err(vdev->dev,"failed registering with minor %d", vDevMisc.minor);
                return ret;
        }
        dev_info(vdev->dev, "driver registered with Minor %d", vDevMisc.minor);
	return SUCCESS;	
	
}

static int drv_remove(void) {
		
	kfree(priv);
        misc_deregister(&vDevMisc);
	return SUCCESS;
}

static struct vbus_driver drv = {
        .driver = {
                   .name = "testdrv",
                   .owner = THIS_MODULE,
                   },
        .probe = drv_probe,
        .remove = drv_remove
};

static int __init mod_init(void)
{
	int ret;
	ret = vbus_register_driver(&drv);
	if (ret < 0) {
		pr_err("failed registering with vbus");
		return ret;
	}
	pr_info("driver registered with vbus");

	return SUCCESS;
}

static void __exit mod_exit(void)
{

	vbus_unregister_driver(&drv,priv->vdev); 
	pr_info("vbus Driver unregistered");
}

module_init(mod_init);
module_exit(mod_exit);

MODULE_AUTHOR("VEDA");
MODULE_DESCRIPTION("Character Device Driver - Test");
MODULE_LICENSE("GPL");
/* End of code */
