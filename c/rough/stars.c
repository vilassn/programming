/* program to print following pattern
         *
       *   *
     *   *   *

*/
#include<stdio.h>
main()
{
 int i,l,j,k,n;
 printf("Enter the level upto which you want to print");
 scanf("%d",&n);
 for(i=-n; i<=n;i++)
 {
   j=i;
  // if(j<0)
     j=-(j);
  for(k=n; k>=0; k--)
  {
     if(k<=n-j)
     {
     if(k==0)
     {
     for(l=0; l<=25; l++)
     printf(" *");
     }
     printf(" *");
     }
     else
     printf(" ");
  }
     printf("\n"); 
}
}
