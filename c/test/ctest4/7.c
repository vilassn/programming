#include<stdio.h>
main()
{
 char a[5]="abcd";
 int b=3;
 printf("%c\n", a[b]);
 printf("%c\n",((char*)b)[(int)a]);
}
