#include <stdio.h>

struct student {
	int rollno;
	char name[10];
	struct student *next;
};

union result {
	int array[5];
	int i;
} uni;

int main() {

	printf("size of char %lu\n", sizeof(char));
	printf("size of short int %lu\n", sizeof(short int));
	printf("size of int %lu\n", sizeof(int));
	printf("size of long int %lu\n", sizeof(long int));
	printf("size of long long %lu\n", sizeof(long long));
	printf("size of float %lu\n", sizeof(float));
	printf("size of double %lu\n", sizeof(double));
	printf("size of long double %lu\n", sizeof(long double));
	printf("size of int* %lu\n\n", sizeof(int*));

	enum ch {
		VILAS = 52, VIKAS = 40
	};

	printf("size of enum ch %lu\n", sizeof(enum ch));
	printf("size of enum VILAS %lu\n\n", sizeof(VILAS));

	union result res;
	printf("size of union result %lu\n", sizeof(union result));
	printf("size of uni %lu\n", sizeof uni);
	printf("size of res %lu\n\n", sizeof res);

	printf("size of (struct student) %lu\n", sizeof(struct student));
	printf("size of (struct student*) %lu\n", sizeof(struct student *));
	printf("size of (void) %lu\n", sizeof(void));
	printf("size of (void*) %lu\n", sizeof(void*));
}
