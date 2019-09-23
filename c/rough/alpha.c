#include<stdio.h>
main() 
{
 int i, j;
char n;
 printf(" Enter the character to be print in graphics");
 scanf("%c",&n);
 if(n=='T')
 for(i=0; i<5;i++)
  
//   printf("*");
 

 for(j=1; j<5;j++)
{
 if(j==2)
 printf("*");
else
 printf(" ");
 }
/* 
 for(i=1; i<5;i++)
{
 for(j=0; j<5; j++)
 {
   if(j==2)
   printf("*");
   else
   //printf(" "); 
   printf("\n");   
}
  */
 printf("*");
else
 printf(" ");
}
