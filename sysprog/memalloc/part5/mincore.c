#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>

int main(int argc, char *argv[])
{
	int ret;
	void *ptr;
	unsigned char mincore_vec[5];
	size_t page_size;
	size_t size;
	size_t page_index;

	page_size = getpagesize();
	size = page_size * 5;

	posix_memalign(&ptr,page_size,size);
	
//	memset(ptr,0,size);
	ret = mincore(ptr, size, mincore_vec);
	if(ret<0)
		perror("mincore");

	for (page_index = 0; page_index < 5 ; page_index++) {
		if (mincore_vec[page_index] & 1) 
			printf("%lu ", (unsigned long)page_index);
	}
	printf("\n");
	munmap(ptr, size);
	return 0;
}
