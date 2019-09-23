#include<stdio.h>/*
main()
{
 int i;
 int num=2;
// printf("enter a number to check it is prime or not");
 while(num<=100)
{
   for(i=2; i<num; i++)
  {
    if(num%i==0)
    { 
    //  printf("entered no. is not prime no.");
      break;
    }
  } 
   if(i==num)
   printf("%d ",num);
   num++;
}
}
*/
//another code for same program
main()
{  
 int a,b,count;
 for (a=1; a<=100; a++)
 {
    count=0;
    for(b=1; b<=a; b++)
    { 
      if(a%b==0)
       count++; 
    }
    if (count==2)
    printf("%d ", a);
 }
}
