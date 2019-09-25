#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include "vbus.h"

static struct class *vbus_class;
static int vbufdev_count;
static struct kmem_cache *cache;

int vbus_setsize(struct vbufdev *dev,uint32_t size)
{
	void *p;

	p = krealloc(dev->start, size, GFP_KERNEL);
	if (!p) {
		pr_err("Cannot resize device mem");
		return -EINVAL;
	}
	dev->start = p;
	dev->len = size;
	
	return SUCCESS;
}

EXPORT_SYMBOL_GPL(vbus_setsize);


uint32_t vbus_getsize(struct vbufdev *dev)
{
	return dev->len;
}

EXPORT_SYMBOL_GPL(vbus_getsize);

int vbus_write(struct vbus_data *data)
{
	unsigned long *start = data->dev->start;
	uint32_t size;
	size = data->size;
	if(data->offset > data->dev->len || size > data->dev->len)
		return -EIO;

	start = start + data->offset;
	pr_info("%s",data->buf);
	memcpy(start, data->buf, size);
	
	return size;
	
}

EXPORT_SYMBOL_GPL(vbus_write);

int vbus_read(struct vbus_data *data)
{
	unsigned long *start = data->dev->start;
	uint32_t size;
	
	size = data->size;

        if(data->offset > data->dev->len || data->size > data->dev->len)
                return -EIO;

        start = start + data->offset;
        memcpy(data->buf, start, size);

        return size;
}

EXPORT_SYMBOL_GPL(vbus_read);

struct vbus_data *alloc_vdata(void)
{
	struct vbus_data *data;
	data =(struct vbus_data *) kmem_cache_alloc(cache, GFP_KERNEL);
	if(!data) {
		pr_err("vbus_data allocation failed");
		return data;
	}
	return data;
}
EXPORT_SYMBOL_GPL (alloc_vdata);

void free_vdata(struct vbus_data *obj)
{
	kmem_cache_free(cache, (void *)obj);
}

EXPORT_SYMBOL_GPL (free_vdata);	

int vbus_register_driver(struct vbus_driver *dri)
{
	struct vbufdev *vdev;
	struct device *dev;

	vdev = kzalloc(sizeof(struct vbufdev), GFP_KERNEL);
	if (!vdev) {
		pr_err("Device not found");
		return -ENOMEM;
	}
	vdev->start = kzalloc(VBUFSIZE, GFP_KERNEL);
	if (!vdev->start) {
		pr_err("Device not found");
		kfree(vdev);
		return -ENOMEM;
	}
	dev = device_create(vbus_class, NULL, MKDEV(0, 0), NULL, "vbufdev%d",
			  vbufdev_count++);
	if (!dev) {
		pr_err("Device not found");
		kfree(vdev->start);
		kfree(vdev);
		return -ENOMEM;
	}
	vdev->dev = dev;
	vdev->len = VBUFSIZE;
	vdev->flags = RESOURCE_MEM;

	pr_info(" vbus device found");

	/* driver hotplug support */
	if (dri->probe(vdev)) {
		pr_err("probe interface not initialized");
		kfree(vdev->start);
		kfree(vdev);
		vbufdev_count--;
		device_destroy(vbus_class, MKDEV(0, 0));
		return -EINVAL;
	}
	return SUCCESS;
}

int vbus_unregister_driver(struct vbus_driver *dri, struct vbufdev *vdev) {

	kfree(vdev->start);
	kfree(vdev);
	device_destroy(vbus_class, MKDEV(0, 0));
	if (dri->remove()) 
		pr_err("remove interface not initialized");
	return SUCCESS;
}	

static int __init vbus_init(void)
{
	vbus_class = class_create(THIS_MODULE, "vbus");
	cache =  kmem_cache_create("vbusdata", sizeof(struct vbus_data), 0, SLAB_POISON, NULL);
	if (!cache){
		pr_err("vbus cache init failed");
		return  -ENOMEM;
	}

	pr_info("vbus interface registerd");
	return SUCCESS;
}

static void __exit vbus_exit(void)
{
	class_destroy( vbus_class );
	kmem_cache_destroy(cache);
	pr_info("vbus interface unregisterd");
}

EXPORT_SYMBOL_GPL(vbus_register_driver);
EXPORT_SYMBOL_GPL(vbus_unregister_driver);

module_init(vbus_init);
module_exit(vbus_exit);

MODULE_AUTHOR("support@techveda.org");
MODULE_DESCRIPTION("LKD_CW: vbus implementation");
MODULE_LICENSE("GPL");
