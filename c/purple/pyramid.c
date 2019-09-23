#include<stdio.h>
main()
{
 int i,j,k, status,flag=0;
 char ch, ori;
 printf("Enter the character: ");
 scanf("%c",&ch);
 ori=ch;
 status=ch-'a';
 status++;
 for(i=0; status--; i++)
 { 
   do
   {
    if(!(ch>'a'))
       break;
    printf(" ");
   }while(--ch);
  for(j=0; j<=i; j++)
   {
    flag++;
    printf("%c",ori+j);
   }
  k=0;
  while(--flag)
   {
    printf("%c",ori+j+k);
    k++;
   }
   printf("\n");
    ch=(--ori);
 }
 printf("\n");

}
