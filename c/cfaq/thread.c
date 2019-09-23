#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

struct Handle
{
 pthread_t tid;
};

void *func(void *data)
{
    struct Handle *handle = (struct Handle *) data;

    //pthread_exit(NULL);
    //sleep(1);
    free(handle);
    handle = NULL;

	printf("func tid: %lu\n", pthread_self());

	if (!pthread_detach(pthread_self()))
		printf("func Thread detached successfully !!!\n");
	else
		printf("func Thread detached unsuccessful !!!\n");

	if (!pthread_detach(pthread_self()))
		printf("func Thread detached successfully !!!\n");
	else
		printf("func Thread detached unsuccessful !!!\n");


    printf("func dying...\n");
    return NULL;
}

int main()
{
  struct Handle *handle = ( struct Handle *) malloc(sizeof(struct Handle));
	pthread_t thread_id = 0;

    if (!pthread_create(&thread_id, NULL, func, handle))
    {
        printf("Thread create successfully !!!\n");

    	sleep(1);

		printf("tid: %lu\n", thread_id);
		if (!pthread_detach(thread_id))
			printf("Thread detached successfully !!!\n");
		else
			printf("Thread detached unsuccessful !!!\n");
    }

    printf("Main thread dying...\n");
    return 0;
}
