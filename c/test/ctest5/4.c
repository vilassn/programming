#include<stdio.h>
main()
{
 const int x=5;
 int *ptr;
 ptr=&x;
*ptr=10;
printf("%d",x);
}
