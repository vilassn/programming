#include<stdio.h>
main()
{
 int x=0;
for(;;)
{
 if(x++==4)
      break;
continue;
}
 printf("x=%d\n",x);
}
