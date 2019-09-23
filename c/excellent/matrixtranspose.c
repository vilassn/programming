#include<stdio.h>
main()
{
 int i,j,temp;
 int a[4][4];
 printf("Enter elements of matrix: ");
 for(i=0; i<4; i++)
  for(j=0; j<4; j++)
    scanf("%d",&a[i][j]);
 //to make transpose
 for(i=0; i<2; i++)
   for(j=0; j<2; j++)
    {
     temp=a[j][i];
     a[j][i]=a[i][j];
     a[i][j]=temp;
    }
 //printing transpose
 for(i=0; i<4; i++)
  {
   for(j=0; j<4; j++)
      {
       printf("%d  ",a[i][j]);
      }
    printf("\n");
  }
}

