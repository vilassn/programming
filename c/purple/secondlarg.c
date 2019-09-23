#include<stdio.h>
main()
{
 int a[]={2, 6,4,3,7,8};
 int max[10],j=0,flag=5;
 for(i=0; i<=5; i++)
 {
  if(a[i]<a[i+1])
  {
   max[j]=a[i+1];
   j++;
  }
  if(i==5)
  {
   flag--;
   i=i-flag;
  }
 }
for(i=0; i<6; i++)
 printf("%d",a[i]);
}
