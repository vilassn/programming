/* program to check byte ordering*/
#include<stdio.h>
main()
{
 int i=1;
 char *c;
 c=&i;
 if(*c)
  printf("Lower byte ordering used with Intel processor\n");
 else
  printf("Higher byte ordering used with nonIntel processor\n");
}
 
