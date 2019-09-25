#include <stdio.h>
#include <malloc.h>

main()
{
	void *p;

	p = malloc(16);
	printf("\n allocated bytes : %d \n",malloc_usable_size(p));

}
