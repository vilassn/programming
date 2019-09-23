//#include<stdio.h>
#define m 1
main()
{
 int x=2, y=3;
 #if m==1
   printf("%d",sum(x,y));
 #endif

 #if m==2
   printf("%d",mul(x,y));
 #endif
}

#if m==1
 sum(int a, int b)
 {
  return (a+b);
 }
#endif

#if m==2
 mul(int a, int b)
 {
  return (a*b);
 }
#endif
