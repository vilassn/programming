#include<stdio.h>
main()
{
 int i,pow=0,ndigs=0,temp;
 float prod=1.0,num;
 for(i=0; i<5; i++)
 {
   printf("\nEnter the no : ");
   scanf("%f",&num);
   prod=prod*num;
   if(num==0)
      pow=0;
  temp=(int)prod, ndigs=0;
  while((temp/=10)!=0)
      ndigs++;
 
  pow+=ndigs;    
  while(ndigs--)
    prod/=10;
   
  printf("\n%.4f x 10e+%d\n",prod,pow);
 }
}
