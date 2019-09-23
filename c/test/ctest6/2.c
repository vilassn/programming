#include<stdio.h>
main()
{
 FILE *ptr;
 char i;
 ptr=fopen("myfile.c","r");
 if(ptr==0)
{
 printf("file cant be open");
 exit(0);
}
 while((i=fgetc(ptr))!=EOF)
 printf("%c",i);
}
