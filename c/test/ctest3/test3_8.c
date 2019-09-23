#include<stdio.h>
#include<string.h>
main()
{
 char str[]="sales\0man\0";
 printf("%d  %d", sizeof(str), strlen(str));
}
