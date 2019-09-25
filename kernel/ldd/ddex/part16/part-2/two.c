#include <libusb-1.0/libusb.h>
#include <ctype.h>
#include <math.h>
#include <errno.h>
#include <poll.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define  VENDOR 0x413c 
#define  PRODUCT 0x8161

struct libusb_device **dev;
struct libusb_device_handle *hand=NULL;
const struct libusb_interface_descriptor *alt;
struct libusb_config_descriptor *config;
const struct libusb_endpoint_descriptor *ep;
struct libusb_device_descriptor desc;
struct libusb_device *dev1;
unsigned char key_code;
unsigned char buf[8]; 

static unsigned char key_codes[10]={98,89,90,91,92,93,94,95,96,97};

/* scancodes of 0,1,2,3,4,5,6,7,8,9 on numeric pad */

static unsigned char key_ascii_codes[10]={49,50,51,52,53,54,55,56,57,58};

unsigned char key_find(unsigned int scan)
	{
	//printf("KEY_FIND=%d\n",scan);
	int l;
	for(l=0;l<10;l++)
	{
	if(key_codes[l]==scan)
	printf("PRESSED KEY:%d\n",l);
	}	
}

static int device_configuration(struct libusb_device *neww)
{       
	int r;
	uint8_t config_index;
	//const struct libusb_interface_descriptor *alt;
	r=libusb_get_config_descriptor(neww,config_index,&config);
	r=libusb_get_active_config_descriptor(neww,&config);
	if(r<0){printf("error\n");exit(1);}
	printf("DEVICE CONFIGURATION=%d\n",config->wTotalLength );	
	struct libusb_interface *inter=(struct libusb_interface *)config->interface;
	alt=inter->altsetting;
	ep=alt->endpoint;
	printf("END-POINT ADDRESS=%04x\n",ep->bEndpointAddress);
	return 0;
}
	
static int  device_descriptor(struct libusb_device *new)
{	
	int r;
	r=libusb_get_device_descriptor(new,&desc);
	if(r<0)exit(1);
	printf("%04x:%04x (bus %d, device %d)\n",
            desc.idVendor, desc.idProduct,
            libusb_get_bus_number(new), libusb_get_device_address(new));
	return 0;
}

static struct libusb_device**  find_device(struct libusb_device **devfs)
{
	int r,i=0;	
	printf("Trying to find logging ......\n");
	while ((dev1 = devfs[i++]) != NULL)
       	{
	 	r=libusb_get_device_descriptor(dev1, &desc);
		if(r<0)
		   {
			printf("DEVICE NOT FOUND\n");
		        exit(1);
	           }
	if ( desc.idVendor==VENDOR && desc.idProduct== PRODUCT)
	  {
		printf("Found Arexx TL-500.\n");	
		return dev1; 	}
}
	//return 0;	

}


int main(void)
{	
	ssize_t cnt;
	int r,trans;
	char buffer,kc;
	r = libusb_init(NULL);
	if (r < 0) {
		fprintf(stderr, "failed to initialise libusb\n");
	exit(1);
	}
	cnt=libusb_get_device_list(0, &dev); /* Currently usb devices connected to the system */
	printf("CNT=%d\n",cnt);
	struct libusb_device *new = find_device(dev); 
	if (new==NULL) {
		fprintf(stderr, "Could not find/open device\n");
		exit(1);
	}
	
	r= device_descriptor(new) ;
	if(r<0){
		fprintf(stderr,"Could not find device description\n");
		exit(1);}
	r=device_configuration(new);
	if(r<0){
		fprintf(stderr,"could not find device configuration\n");
		exit(1);}
	hand =libusb_open_device_with_vid_pid(NULL,, );
	if(hand==NULL)
	{
		printf("DEVICE OPEN FAIL\n");
		exit(1);}	
	printf("DEVICE OPENED\n");
	r=libusb_kernel_driver_active(hand,0);
	if(r==0)
	{printf("NO KERNEL DRIVER ACTIVE\n");
	}else{printf("KERNEL DRIVER ACTIVE\n");}
	libusb_detach_kernel_driver(hand,0);
	if(r<0){printf("value r=%d\n",r);exit(1);}
	/*r = libusb_set_configuration(hand, 1);
		if(r<0)exit(1);*/
		r=libusb_claim_interface(hand,0);
		if(r<0)printf("failed to claim\n");
	while(1){
		printf("hai\n");
		r=libusb_interrupt_transfer(hand,0x81,buf,sizeof(buf),&trans,0);
		key_code=buf[2];
		key_find(key_code);	
	}				
        
	

printf("END OF THE PROGRAM\n");	
//out:
//	libusb_close(hand);
	//libusb_exit();
}

