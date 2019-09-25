/* Probing device related information through usb notifier */

#include <linux/module.h>

#include <linux/kernel.h>

#include <linux/usb.h>

#include<linux/init.h>



void device_descriptor( struct usb_device_descriptor  , struct usb_endpoint_descriptor );

static struct usb_device *udev;

static struct usb_device_descriptor desc;

static struct usb_endpoint_descriptor  ep;

void device_descriptor(struct usb_device_descriptor device, struct usb_endpoint_descriptor ep0)

{
	printk("DEVICE VENDOR-ID=%04x\n",device.idVendor);
	printk("DEVICE PRODUCT-ID=%04x\n",device.idProduct);
}

static int usb_notify_subscriber(struct notifier_block *self, unsigned long action, void *dev)

{
        printk(KERN_INFO "usb_notify_subscriber \n");
        
	udev=(struct usb_device *)dev;
        desc=udev->descriptor;
	ep=udev->ep0.desc;
	switch (action) {

               case USB_DEVICE_ADD:  
			printk(KERN_INFO "usb_notify_subscriber:USB device added \n");
			device_descriptor(desc,ep);
                        break;
               case USB_DEVICE_REMOVE:
                        printk(KERN_INFO "usb_notify_subscriber:USB device removed \n");
                        break;
               case USB_BUS_ADD:
                        printk(KERN_INFO "usb_notify_subscriber:USB Bus added \n");
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
 Register to the USB core to get notification on any addition or removal of USB devices

*/
       usb_register_notify(&usb_simple_nb);
       return 0;
}

void clean_module(void)

{
       usb_unregister_notify(&usb_simple_nb);
       printk(KERN_INFO "Remove USB simple subscriber\n");
}
module_init(s_module);
module_exit(clean_module);

MODULE_AUTHOR("VEDA");
MODULE_DESCRIPTION("Test");
MODULE_LICENSE("GPL");


                              
