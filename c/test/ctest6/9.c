#include<stdio.h>
main()
{
 static int x=1;
 display(++x);
 }
 display(static int y)
{
 printf("%d",y);
}
