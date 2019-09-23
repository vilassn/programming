/* finding you are male or female */
#include<stdio.h>
#include<string.h>
main() {
	char name[40];
	int i;
	printf("Enter the name:\n");
	while (1) {
		//bzero(stdin, 40);
		scanf("%s", name);
		printf("%s\n", name);
		i = strlen(name) - 1;
		if (name[i] == 'a' || name[i] == 'y' || name[i] == 'i'
				|| name[i] == 'u')
			printf("%s is girl\n", name);
		else
			printf("%s is boy\n", name);
	}
}
