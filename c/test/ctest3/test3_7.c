#include<stdio.h>
#include<string.h>
main()
{
 char s1[]="abcd";
 char s2[10];
 char s3[40]="efgh";
 int i;
 i=strcmp(strcat(s3,strcpy(s2,s1)),strcat(s3,"abcd"));
 printf("%d",i);
}
