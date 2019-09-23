#include <stdio.h>
#include <stdlib.h>

int main() {
	int len_max = 12;
	int current_size = len_max;
	char *pStr = malloc(len_max);

	printf("\nEnter a very very very long String value:");

	//accept user input until hit enter or end of file
	int i = 0;
	char c = 0;
	while ((c = getchar()) != '\n') {

		pStr[i++] = (char) c;

		//if i reached maximize size then realloc size
		if (i == current_size) {
			current_size = i + len_max;
			pStr = realloc(pStr, current_size);
			printf("\nreallocated\n");
		}
	}

	pStr[i] = '\0';
	printf("\nLong String: %s \n\n", pStr);

	//free it
	free(pStr);
	pStr = NULL;

	return 0;
}
