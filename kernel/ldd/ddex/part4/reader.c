
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>

/**
* This program uses the device driver veda_chr_driver and opens a file on it.
* It performs the read, write and lseek operation apart from open() and close()
* Hence it checks the drivers functionality
*/
void handler(int);

int main()
{
	int fd, i;
	ssize_t ret;
	char my_buf[4000];
	signal(SIGINT,handler);
	/* open the device for read/write/lseek */
	printf("[%d] - Opening device veda_chr_driver\n", getpid() );
	fd = open( "/dev/veda_cdrv", O_RDWR );
	
	again:
        if ((ret = read(fd, my_buf, 4000)) < 0) {
            if (errno == EINTR)
                	goto again;     /* just an interrupted system call */
        }
	printf(" read frm device %s \n", my_buf);
	close(fd);
}

void handler(int signum)
{
	printf("interrupt signal handled \n");
}
	
