#include<stdio.h>
//int x=5;
void print(int x)
{
 printf("%d",x--);
}
main()
{
 int x=5;
 print(x++);
}
