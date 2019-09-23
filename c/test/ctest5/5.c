#include<stdio.h>
main()
{
 static i=3;
 printf("%d",i--);
 return i>0 ? main():0;
}
