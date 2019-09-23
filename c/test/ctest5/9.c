#include<stdio.h>
enum{false,true}
main()
{
 int i=1;
  do
 {
   i++;
   printf("%d\n",i);
   if(i<15);
   continue;  
 } while(false);
}
