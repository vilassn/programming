#include<stdio.h>
main()
{
 int a[]={1,2,3,4};
 int i=1;
 //i=a[i]+a[--i];
 i=printf("a[i]=a[%d]=%d ",i,a[i])+printf(" a[--i]=a[%d]=%d",i,a[--i]);
 printf("\ni=%d",i);
}
