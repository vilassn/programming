#include <linux/device.h>
#include <linux/types.h>

#define SUCCESS 0
#define VBUFSIZE 1024
#define RESOURCE_MEM 1
#define RESOURCE_IO  2

struct vbufdev {
        struct device *dev;
        unsigned long *start;
        uint32_t len;
        long flags;
};

struct vbus_driver {
        struct device_driver driver;
        int (*probe) (struct vbufdev *);
        int (*remove) (void);
};

struct vbus_data {
	struct vbufdev *dev;
	char *buf;
	size_t size;
	loff_t offset;
};

int vbus_register_driver(struct vbus_driver *);
int vbus_unregister_driver(struct vbus_driver *, struct vbufdev *);
struct vbus_data *alloc_vdata(void);
void free_vdata(struct vbus_data *obj);
int vbus_setsize(struct vbufdev *, uint32_t );
uint32_t vbus_getsize(struct vbufdev *);
int vbus_write(struct vbus_data *);
int vbus_read(struct vbus_data *);
