#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include <fcntl.h>

#define BASE_ADDRESS 0x0

static unsigned char *ptr;

int main(void)
{
	int fd;

	fd = open("/dev/mem", O_RDWR);
	if ( fd < 0 ) {
	   printf("Error opening memory file\n");
	   return -1;
	}
	if ( !BASE_ADDRESS ) {
	   printf("Use physical address and recompile !\n");
	   return -2;
	}
	ptr = mmap(0,4096,PROT_READ | PROT_WRITE,MAP_SHARED,fd,BASE_ADDRESS);
	if ( !ptr ) {
	   printf("Could not mmap()\n");
	   return -1;
	}
	/*  use the ptr */

	printf("%s",ptr);
	munmap(ptr, 4096);
	close(fd);
	return 0;
}
