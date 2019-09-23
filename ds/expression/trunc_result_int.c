#include<stdio.h>
main()
{
 int res2,ndigs=0,temp, num;
 float res1;
 printf("Enter the no. ");
 scanf("%d",&num);
 
 if(num<32768)
  printf("%d\n",num);
 else
 {
   temp=num; 
   while(temp!=0)
   {
    ndigs++;
    temp=temp/10;
   }
    res2=ndigs-1;
    res1=num;
    while(--ndigs)
     res1=res1/10;
   printf("%f x 10e+%d\n",res1,res2);
 }
}
