#include<stdio.h>
main()
{
 int x,y,z, res=0;
 printf("Enter x and y for (x^y): ");
 scanf("%d%d",&x,&y);
z=y; 
 while(y--)
 {
  res = res + x;
 }
 printf("%d^%d = %d",x,z,res);
}
