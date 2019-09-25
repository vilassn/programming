#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
int main()
{
	int fd, i;
	unsigned char data;
	fd = open("/dev/clock", O_RDONLY);
	if (fd < 0) {
		perror("clock:");
		exit(1);
	}
	for (i = 0; i < 6; i++) {
		read(fd, &data, 1);
		printf(" .... %x....\n", data);
		
	}
	exit(EXIT_SUCCESS);
}
