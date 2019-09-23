#include<stdio.H>
main()
{
 int num,i;
 printf("enter the no. of check prime or not");
 scanf("%d",&num);
 for(i=2; i<num;i++)
 {
  if((num%i)==0)
   break;
 }
 if(i==num || num==1)
  printf("\n no. is prime");
  else
   printf("\n no. is not prime");
 }