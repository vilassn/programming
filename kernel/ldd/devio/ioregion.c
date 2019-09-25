#define IOSTART  0x200
#define IOEXTEND 0x40

#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/io.h>
#include <linux/init.h>

static unsigned long iostart = IOSTART, ioextend = IOEXTEND, ioend;
module_param (iostart, ulong, S_IRUGO);
module_param (ioextend, ulong, S_IRUGO);

static int __init my_init (void)
{
    unsigned long ultest = (unsigned long)100;
    ioend = iostart + ioextend;

    printk (KERN_INFO " requesting the IO region from 0x%lx to 0x%lx\n",
            iostart, ioend);

    if (!request_region (iostart, ioextend, "my_ioport")) {
        printk (KERN_INFO "the IO REGION is busy, quitting\n");
        return -EBUSY;
    }

    printk (KERN_INFO " writing a long=%ld\n", ultest);
    outl (ultest, iostart);

    ultest = inl (iostart);
    printk (KERN_INFO " reading a long=%ld\n", ultest);

    return 0;
}
static void __exit my_exit (void)
{
    printk (KERN_INFO " releasing  the IO region from 0x%lx to 0x%lx\n",
            iostart, ioend);
    release_region (iostart, ioextend);
}

module_init (my_init);
module_exit (my_exit);

MODULE_AUTHOR ("Team veda");
MODULE_DESCRIPTION ("io port access");
MODULE_LICENSE ("GPL");
