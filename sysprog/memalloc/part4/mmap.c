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
#include <malloc.h>

#define SIZE 1024*128	/* 128KB */
int main()
{
	int i;
	unsigned char *ptr[3] , *temp;

	if (!mallopt(M_MMAP_MAX, 1)) {
                printf("mallopt() failed\n");
        }
	
	ptr[0] = malloc(128*1024);

	if (ptr[0] == NULL) {
		perror("Malloc Failed");
		exit(1);
	}
	malloc_stats();	
	getchar();	
	
	
	ptr[1] = malloc(128*1024);	

        if (ptr[1] == NULL) {
                perror("Malloc Failed");
                exit(1);
        }
        malloc_stats();
        getchar(); 
	
	free(ptr[0]);
	malloc_stats();	
        getchar();
	
	free(ptr[1]);
	malloc_stats();	
        getchar();

}
