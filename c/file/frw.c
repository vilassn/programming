/* Write some non-character data to a disk file
 and read it back. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	FILE *fp;
	double d = 12.23;
	int i = 101;
	long l = 123023L;

	if ((fp = fopen("test", "wb+")) == NULL) {
		printf("Cannot open file.\n");
		exit(l);
	}

	fwrite(&d, sizeof(double), 1, fp);
	fwrite(&i, sizeof(int), 1, fp);
	fwrite(&l, sizeof(long), 1, fp);
	rewind(fp);
	fread(&d, sizeof(double), 1, fp);
	fread(&i, sizeof(int), 1, fp);
	fread(&l, sizeof(long), 1, fp);
	printf("%f    %d    %ld", d, i, l);

	fclose(fp);

	return 0;
}

