#include<stdio.h>
float fun(int a,int b)
{
return(a+b);
}
main()
{
float res;
float (*p)(int,int);// just like prototype of function
p=fun;
res=(p)(3,5); 
printf("res=%f\n",res);
}
