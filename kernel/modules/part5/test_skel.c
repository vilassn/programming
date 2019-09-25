#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
int main() 
{
	int fd, i;
	ssize_t ret;
	char my_buf[1024] = "Hello world";
	fd = open("/dev/vbufdev", O_RDWR);
	if (fd < 0)
		printf("failed acquiring file descriptor return status %d\n",fd);
	    /* write the contents of my buffer into the device */
	ret = write(fd, my_buf, 20);
	if(ret < 0){
		printf(" write failed\n");
		return -1;
	}
	lseek(fd, SEEK_SET, 0);
	ret = read(fd, my_buf, 20);
	if (ret < 0){
		printf("read operation failed with return status %d\n", ret);
		return -1;
	}
	close(fd);
}
