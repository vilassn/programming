#ifndef _VEDA_CHAR_DEVICE_H_
#define _VEDA_CHAR_DEVICE_H_

#include <asm/ioctl.h>
  
/* ioctl constants are defined in this header file for our 
   char_driver_ioctl driver.
   
   This file explains how the constants are defined with
   the use of inline comments 

   Constants have to be globally unique. Though this is not
   compulsory, it is necessary. This is because of the simple
   reason: we do not want our commands to clash with the commands
   in other drivers. we dont want the right command going to
   the wrong driver or vice-versa 
   We have to base our constants based on a majic number 
*/ 
#define VBUFDEV_MAGIC 'V'
  
/* Defining constants require us to decide folllowing values

	1. type or magic number (type)
	2. sequence number which is eigth bits wide. This means
	   we can have up to 256 ioctl commands (nr)
	3. direction if the arg is involved, whether we are reading or writing 
	4. size(composition) of the arguement.
	   
   To arrive at unique numbers easily we use the following macros
   _IO(type, nr);
   _IOW(type, nr, dataitem) the fourth item calculated using sizeof 
   _IOR(type, nr, dataitem)
   _IOWR(type, nr, dataitem)
*/ 
  
#define VBUFDEV_FILL_ZERO		_IO( VBUFDEV_MAGIC, 1 )
  
#define VBUFDEV_FILL_CHAR		_IOW( VBUFDEV_MAGIC, 2, char )
  
#define VBUFDEV_SET_SIZE		_IOW( VBUFDEV_MAGIC, 3, uint )
  
#define VBUFDEV_GET_SIZE		_IOR( VBUFDEV_MAGIC, 4, uint )
  
#define VBUFDEV_MAX_CMDS		4
  
#endif	/* _VEDA_CHAR_DEVICE_H_ */
