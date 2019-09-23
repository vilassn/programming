#include<stdio.h>
#include<string.h>
#include<strings.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/dir.h>
#include<stdlib.h>
#include<fcntl.h>
#include<dirent.h>
struct info
{
 int sqno;
 char histstr[128];
};

char *sysname(char **);
void exit(int);
void ls(int);
void hist(int);
void curpid();
void ppid();
void cd();
void quit();
void cat(int);
void help();
