#include<stdio.h>
main()
{
 int a[3], i;
 for(i=0; i<3; i++)
  a[i]=i++;
for(i=0; i<3;i++)
 printf("\t%d", a[i]);
}
