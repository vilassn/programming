#include<stdio.h>
main()
{
 int x=0xFF;
 printf("x=%d",x);//x=255
 x=(0xFF>>1);   
 printf("\nx=%d",x); //x=127
 x=(0xFFFF>>0); //x=65535
 printf("\nx=%d",x);
}
