#include<stdio.h>
main()
{
 int *a,i,j,temp,num;
 printf("Enter no. of elements to be entered: ");
 scanf("%d",&num);
 a=(int *)malloc(num*4);
 //printf("%d %d \n",a, a+1);
 printf("Enter %d elements: ",num);
 for(i=0; i<num; i++)
 {
  scanf("%d",&a[i]);
 }
i=0;j=1;
//logic for sorting
while(1)
{   
    if(j==num)
     {
       i=i+1;
       if(i==(num-1))
         break;
       j=i+1;
     }
    if(a[i]>a[j])
    {
     temp=a[i];
     a[i]=a[j];
     a[j]=temp;
    }
   j++;
}
//printf("second largest is %d\n",a[1]);
//printing
for(i=0; i<num; i++)
printf("%d ",a[i]);
}
 
