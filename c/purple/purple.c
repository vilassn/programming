#include<stdio.h>
main()
{
 char ch='c';
 int i, j,k;
 int no_of_line='c'-'a',flag=0;
 for(i=0; i<=no_of_line; i++)
 {
   
  for(j=ch;j>'a';j--)
  {
    printf(" ");
  }
   flag=0;
   for(k=0; k<=i; k++)
   {
     flag++;
     printf("%c",ch+k);
   }
    while(--flag)
    {
    printf("%c",ch+k);
    k++;
    }
    printf("\n");
    ch--;
 }
} 
