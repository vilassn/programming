/* Shows how to use mmap sys call
Version : 1.0
Author : Team -C
Note : All modern OS supports memory mapping of files.
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdio.h>

main()
{
	int fd, i;
	unsigned char *ptr = NULL, *temp;
	

	fd = open("/dev/zero",O_RDWR);
	if(fd<0) {
		perror("open ");
		exit(1);
	}	
			
	ptr = (char *)mmap((void *)0, 60, PROT_READ | PROT_WRITE,
						MAP_PRIVATE, fd, 0);

	if (ptr == NULL) {
		perror("Maping Failed");
		exit(1);
	}
	close(fd);

	getchar();	
	temp = ptr;

	for (i = 0; i < 60; i++, ptr++)
		*ptr = (char)(i + 65);

	ptr = temp;
	for (i = 0; i < 60; i++, ptr++)
		printf("%c", *ptr);

	i = munmap(temp, 60);
	getchar();
	if (i != 0)
		printf(" failed to unmap\n");
}
