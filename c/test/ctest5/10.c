#include<stdio.h>
 struct xx
 {
 int x;
 char name[4];
 };
 struct xx v,*s;
main()
{
 s=&v;
 scanf("%d",&s->x);
 printf("%s",&(s->x));

}
