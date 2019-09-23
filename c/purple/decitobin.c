/* program to convert decimal to binary */
#include<stdio.h>
main()
{
 int num,i;
 printf("Enter the number : ");
 scanf("%d",&num);
 for(i=31; i>=0; i--)
 {
  (1<<i) & num ? printf("1") : printf("0");
 }
}
 
