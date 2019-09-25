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
	int fd,i,count=0;
	char ch,buf[5];
	fd = open("Demo.txt",O_RDWR|O_SYNC,S_IRWXU|S_IRWXG);
	printf("\n New File Desp : %d\n",fd);
	count=read(fd,buf,5);
	for(i=0;i<count;i++)
	printf("%c",buf[i]);
	printf("\n");
	//getchar();
	close(fd);
}
