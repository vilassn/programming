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


#define SIZE 1024*128	/* 128KB */
int main()
{
	int i;
	unsigned char *ptr = NULL, *temp;
	
	getchar();
	ptr = (char *)mmap((void *)0, SIZE, PROT_READ | PROT_WRITE,
				MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);

	if (ptr == NULL) {
		perror("Maping Failed");
		exit(1);
	}
	
	getchar();	
	
	temp = ptr;

	for (i = 0; i < 60; i++, ptr++)
		*ptr = (char)(i + 65);

	ptr = temp;
	for (i = 0; i < 60; i++, ptr++)
		printf("%c", *ptr);

	i = munmap(temp, SIZE);
	getchar();
	if (i != 0)
		printf(" failed to unmap\n");
}
