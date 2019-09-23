#include<stdio.h>
main()
{
volatile int x=40;
printf("%d %d %d",x<20, x=20, x=10);
} 
