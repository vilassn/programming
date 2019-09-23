#include<stdio.h>
#define N 5
main()
{
	int i,j,m,k;
	for(i=-N+1; i<N; i++)
	{
		printf("\nvilas");
		i<=0 ? (k=i, m=0) : (k=-i, m=i);
		for(j=0; j<N; j++)
		if(k)
		{
			k++;
			printf("  ");
		}
		else
		printf(" %c  ",'a'+m++);
		printf("\n");
	}
}

