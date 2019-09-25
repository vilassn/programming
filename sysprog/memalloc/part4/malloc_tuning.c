#include <stdio.h>
#include <malloc.h>

int main(int argc, char **argv)
{

	int thr;
	char *p1;
	struct mallinfo status;

	status = mallinfo();
	
	
	thr = 4096*4; /* Three Pages */
	if (!mallopt(M_TOP_PAD, thr)) {
		printf("mallopt() failed\n");
	}

	p1 = malloc(4096*2);
	status = mallinfo();
	printf("\n top-most, releasable (via malloc_trim) space : %d\n",
	       status.keepcost);

	malloc_stats();

	printf("\nNow freeing 100k\n");
	free(p1);
	malloc_stats();
	getchar();
	malloc_trim(4096*2);
	malloc_stats();
}
