#include<stdio.h>
main()
{
 char ch='e';
 int flag=1,i,j,f;
 int line=ch-'a';
 for(i=0; i<=line; i++)
 {
   f=ch;
   while(f>'a')
   {
    printf(" ");
    f--;
   }
   for(j=0; j<flag; j++)
   {
    printf("%c", ch+j);
   }
   printf("\n");
   flag=flag+2;
   ch--;
 }
} 
