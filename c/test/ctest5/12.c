#include<stdio.h>
main()
{
 char a[]="Aabcd";
 fun(a);
 }
 fun(char *p)
{
 p[0]? fun(++p) : 1;
 printf("%c",*p);
}
