
#include <linux/module.h>
#include <linux/init.h>
#include <linux/pci.h>
#include <linux/slab.h>

// int direction = PCI_DMA_TODEVICE ;
// int direction = PCI_DMA_FROMDEVICE ;
static int direction = PCI_DMA_BIDIRECTIONAL;
//int direction = PCI_DMA_NONE;

static void output (char *kbuf, dma_addr_t handle, size_t size, char *string)
{
    unsigned long diff;
    diff = (unsigned long)kbuf - handle;
    printk (KERN_INFO "kbuf=%12p, handle=%12p, size = %d\n", kbuf,
            (unsigned long *)handle, (int)size);
    printk (KERN_INFO "diff=%12p, %12lu, PAGE_OFFSET=%12lu, compare=%lu\n",
            (void *)diff, diff, PAGE_OFFSET, diff - PAGE_OFFSET);
    strcpy (kbuf, string);
    printk (KERN_INFO "string written was, %s\n", kbuf);
}

static int __init my_init (void)
{
    char *kbuf;
    dma_addr_t handle;
    size_t size = (10 * PAGE_SIZE);

    /* pci_alloc_consistent method */

    printk (KERN_INFO "Loading DMA allocation test module\n");
    printk (KERN_INFO "\nTesting pci_alloc_consistent()..........\n\n");
    kbuf = pci_alloc_consistent (NULL, size, &handle);
    output (kbuf, handle, size, "This is the pci_alloc_consistent() string");
    pci_free_consistent (NULL, size, kbuf, handle);

    /* pci_map/unmap_single */

    printk (KERN_INFO "\nTesting pci_map_single()................\n\n");
    kbuf = kmalloc (size, GFP_KERNEL);
    handle = pci_map_single (NULL, kbuf, size, direction);
    output (kbuf, handle, size, "This is the pci_map_single() string");
    pci_unmap_single (NULL, handle, size, direction);
    kfree (kbuf);

    /* let it fail all the time! */

    return 0;
}
static void __exit my_exit (void)
{
    printk (KERN_INFO "Module Unloading\n");
}

module_init (my_init);
module_exit (my_exit);

MODULE_AUTHOR ("Team Veda");
MODULE_DESCRIPTION ("DMA Interface test module");
MODULE_LICENSE ("GPL v2");
