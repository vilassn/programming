#include <stdio.h>
#include <string.h>
#include <fcntl.h>

static char buf[30];

int main(void)
{
	int fd, nbr;
	int resp;

	strcpy(buf,"Test string");

	fd = open("/dev/addtrans", O_RDONLY);
	if ( fd < 0 ) {
	   printf("Error opening file /dev/addtrans\n");
	   return -1;
	}
	printf("USER:Address of buf = %08x\n",buf);
	nbr = read(fd, buf, 30);
	printf("Enter num to continue : ");
	scanf("%d",&resp);
	close(fd);
	return 0;
}
