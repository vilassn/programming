/* finding you are male or female */
#include<stdio.h>
#include<string.h>

void main() {

	while (1) {

		char name[40];
		printf("Enter the name:\n");

		scanf("%s", name);
		printf("%s\n", name);
		int i = strlen(name) - 1;
		if (name[i] == 'a' || name[i] == 'i' || name[i] == 'u'
				|| name[i] == 'y')
			printf("%s is girl\n", name);
		else
			printf("%s is boy\n", name);
	}
}
