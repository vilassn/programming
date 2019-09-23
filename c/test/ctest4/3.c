#include<stdio.h>
main()
{
 char a[5][5], flag;
 a[0][0]='A';
 flag=((a==*a) && (*a==a[0]));
 printf("\n %d", flag);
printf(" %p",a);
printf(" %p",*a);
printf(" %p",a[0]);
}
