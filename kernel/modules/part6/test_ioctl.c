#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

#include "ioctl_const.h"

int main()
{
	int fd, i;
	char my_buf[4096];
	unsigned int  size;
	char c;
	
	printf("[%d] - Opening device veda_cdrv\n", getpid() );
	
	fd = open( "/dev/vbufdev", O_RDWR );
	if( fd < 0 ) {
		printf("\n\nDevice could not be opened\n\n");
		return 1;
	}
	printf("Device opened with ID [%d]\n", fd);
	
	ioctl( fd, VBUFDEV_GET_SIZE, &size );

	printf("Present size of the buffer is %d\n", size);

	size = 4096;
	if( ioctl( fd, VBUFDEV_SET_SIZE, &size ) < 0 )
		printf("ioctl failed\n");

	ioctl( fd, VBUFDEV_GET_SIZE, &size );
	printf("New size of the buffer is %d\n", size);		

	/* lets fill the buffer with character '=' */
	c = '=';
	ioctl(fd, VBUFDEV_FILL_CHAR, &c);

	lseek(fd, 10, SEEK_SET);
      	/* test if it worked */
	read( fd, my_buf, 100 );
	printf("New contents%s\n", my_buf);

	close(fd);
	exit(0);
}


