#include<stdio.h>
main()
{
 char choice, another='y';
 int  num,bitpos,bit,m,n,ori,i,j;
 while(another=='y')
{
 printf("\nEnter the number to be operate \n");
 scanf("%d",&num);
 ori=num;
 printf("Bits pattern of entered number is:\n");
 for(bit=31; bit>=0; bit--)
 num & (1<<bit) ? printf("1"): printf("0");
 printf("\nEnter choice:\n");
 printf("S to set bit\n");
 printf("C to clear bit\n");
 printf("r to reverse bits \n");
 scanf(" %c", &choice);
 switch(choice)
{
 case 's': 
           printf("which bit you want to set\n");
           scanf("%d",&bitpos);
           num |= (1<<bitpos);
           break;
case 'c':  
           printf("which bit you want to clear\n");
           scanf("%d",&bitpos);
           num &= ~(1<<bitpos);
           break;
case 'r':  
           printf("U r trying to reverse bits pattern\n");
             
          i=0, j=31;
          while(i<j)
         {
           m=(num>>i)& 1;
           n=(num>>j)& 1;
           if(m!=n)
           {        
             num= num^(1<<i);
             num= num^(1<<j);
           }
           i++;
           j--;
          }   
          break;
default :
          printf(" You have entered invalid choice\n");
}
 printf("The modified bit pattern is:\n");
 for(bit=31; bit>=0; bit--)
 num & (1<<bit)? printf("1"): printf("0");
 printf("\n%d is converted into %d\n",ori, num);

printf("\n Are you ready to play next pass? (y/n)\n");
scanf(" %c",&another);
}
}
