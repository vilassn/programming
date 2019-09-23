#include<stdio.h>
main()
{
 int a, f;
 printf("enter a number");
 scanf("%d", &a);
 f=fact(a);
 printf("factorial is %d",f);
}
 fact(int n)
{
 if(n==0)
 return 0;
 if(n==1)
 return 1;
 return (n*fact(n-1));
}
