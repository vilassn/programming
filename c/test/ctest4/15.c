#include<stdio.h>
main()
{
 int x,y,z,k=10;
k+=(x=5,y=x+2,z=x+y);
printf("%d%d%d%d", x,y,z,k);
}

