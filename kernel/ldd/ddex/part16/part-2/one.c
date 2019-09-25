/*
  Test program to find how many usb-based devices are currently connected to the system
*/

#include <stdio.h>
#include <libusb-1.0/libusb.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>


struct libusb_device_descriptor desc;
struct libusb_device **dev;

int main()

{
	int ret;
	ssize_t count;
	ret=libusb_init(NULL); /* Initaization of libusb */
	count=libusb_get_device_list(0,&dev); /* Return Number of devices currently connected to the system */
	ret=libusb_get_device_descriptor(*dev,&desc);
	printf("COUNT=%d\n",count);
	//printf("BMAX=%d\n",desc.bMaxPacketSize0);
	libusb_exit(NULL);
	return 0;
}

