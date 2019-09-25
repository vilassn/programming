/*

This program explains about open system call from creating a new file descriptor

Author	: Team Veda
Usage	: int open (const char *filename, int flags[, mode_t mode]);
	  The flags argument must include exactly one of these values to specify the file access: 
	  O_RDONLY 
		Open the file for read access. 
 	  O_WRONLY 
		Open the file for write access. 
	  O_RDWR 
		Open the file for both reading and writing. 	
	  
Version	: 1.0

*/

#include<stdio.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	int fd,count;
	char ch[10],buf[10];
	fd = open("Demo.txt",O_RDWR); // Opening a file with READ/WRITE permissions
	printf(" New File Desp : %d\n",fd);
	count=read(fd,buf,10); // Returns number of bytes read
	printf("Number of bytes read:%d\n",count);
	printf("DATA=%s",buf);
	//getchar();
	close(fd);
}
