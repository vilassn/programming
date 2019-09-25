#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
int main()
{
	int fd, i;
	unsigned char data;
	fd = open("/dev/clock", O_WRONLY);
	if (fd < 0) {
		perror("clock:");
		exit(1);
	}
	data = 0x04;
	for (i = 0; i < 6; i++) {
		write(fd, &data, 1);
		printf(" .... %x....\n", data);
	}
	exit(EXIT_SUCCESS);
}
