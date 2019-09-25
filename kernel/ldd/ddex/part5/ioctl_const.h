#ifndef _VEDA_CHAR_DEVICE_H_
#define _VEDA_CHAR_DEVICE_H_

#include <asm/ioctl.h>

/* ioctl constants are defined in this header file for our 
   char_driver_ioctl driver.
   
   This file explains how the constants are defined with
   the use of inline comments */

/* Constants have to be globally unique. Though this is not
   compulsory, it is necessary. This is because of the simple
   reason: we do not want our commands to clash with the commands
   in other drivers. we dont want the right command going to
   the wrong driver or vice-versa */
   
/* We have to base our constants based on a majic number */
#define VEDA_MAGIC 'L'

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

/* VEDA_FILL_ZERO: to fill our character array with zeros
   As we can see there is not data transfer. The moment
   our driver gets this command, it executes the following
   for loop
   	for(i=0; i<MAX_LENGTH; i++) char_device_buf[i] = 0;
*/
#define VEDA_FILL_ZERO		_IO( VEDA_MAGIC, 1 )

/* VEDA_FILL_ZERO: to fill our character array with a character
   As we can see there is not data transfer. The moment
   our driver gets this command, it executes the following
   for loop
   	for(i=0; i<MAX_LENGTH; i++) char_device_buf[i] = c;
   where c is the character. This involves something to be 
   transfered from user to kernel
*/
#define VEDA_FILL_CHAR		_IOW( VEDA_MAGIC, 2, char )

/* VEDA_SET_SIZE: to set the size of the character array */

#define VEDA_SET_SIZE		_IOW( VEDA_MAGIC, 3, uint )

/* VEDA_GET_SIZE: to get the size of the character array */
#define VEDA_GET_SIZE		_IOR( VEDA_MAGIC, 4, uint )

#define VEDA_MAX_CMDS		4

#endif /* _VEDA_CHAR_DEVICE_H_ */
