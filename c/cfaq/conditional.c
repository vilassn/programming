#include<stdio.h>

main() {

	int x = 0, y = 0, z = 0, result;
	result = (x ? y ? z ? printf("1") : printf("2"):printf("3"):printf("4"));
	printf("\n%d", result);

	//in if..else

	if (x)
		if (y)
			if (z)
				printf("1");
			else
				printf("2");
		else
			printf("3");
	else
		printf("4");
}
