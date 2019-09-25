#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>
#include<linux/init.h>

static struct usb_device *udev;
 struct usb_bus *bus;

void update(struct usb_bus *ubus)
	{
	printk("BUS num=%d\n",ubus->busnum);
	}
static int usb_notify_subscriber(struct notifier_block *self, unsigned long action, void *dev)

{
//	printk(KERN_INFO "usb_notify_subscriber \n");
  //      udev=(struct usb_device *)dev;
//	printk("DEVNUM=%d\n",udev->devnum);
	bus=(struct usb_bus*)dev;
	switch (action) {
        	printk("hai hai hai hai\n");
	       case USB_DEVICE_ADD:
        	              printk(KERN_INFO "usb_notify_subscriber:USB device added \n");
			      update(bus);
                      	      break;
               case USB_DEVICE_REMOVE:
	                      printk(KERN_INFO "usb_notify_subscriber:USB device removed \n");
                	      break;
               case USB_BUS_ADD:
              		      printk(KERN_INFO "usb_notify_subscriber added \n");
                	      break;
               case USB_BUS_REMOVE:
               		      printk(KERN_INFO "usb_notify_subscriber:USB Bus removed \n");
  }
  return NOTIFY_OK;
}
static struct notifier_block usb_simple_nb = {

.notifier_call = usb_notify_subscriber,

};

 int s_module(void)
{
       printk(KERN_INFO "Init USB simple subscriber.\n");
       /*
 *        * Register to the USB core to get notification on any addition or
 *               removal of USB devices
 *                      */
       usb_register_notify(&usb_simple_nb);
       return 0;
}
void clean_module(void)
{
	
/*
          Remove the notifier
*/
       usb_unregister_notify(&usb_simple_nb);
       printk(KERN_INFO "Remove USB simple subscriber\n");
}
module_init(s_module);
module_exit(clean_module);
MODULE_LICENSE ("GPL");

