#include<stdio.h>
int i=4;
main()
{
 clrscr();
 print();
 printf("%d",i);        //i=3
}
print()
{
 return (i--);
}
