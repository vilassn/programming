#include<stdio.h>
main()
{
 union var
{
 int a,b;
};
 union var v;
 v.a=10;
 v.b=20;
 printf("%d",v.a);
}
