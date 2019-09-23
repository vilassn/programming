#include<string.h>
#include<stdio.h>
main()
{
 char *str ="india pvt. ltd.";
 char *str1 = "Vector";
 //char str2[24];
 printf("str is %s\n", str);
 printf("str1 is %s\n", str1);
 strcpy(str,str1);
 printf("str is %s\n", str);
}
