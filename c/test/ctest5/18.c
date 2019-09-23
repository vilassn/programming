#include<stdio.h>
main()
{
 fun(1);
 }
 fun(int i)
{
 static char *str[]={"one","two","three","four"};
 printf("%s\n", str[i++]);
 return;
}
