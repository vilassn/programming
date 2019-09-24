#include <stdio.h>

#define PRINT_SUM 1

int main() {

#if PRINT_SUM == 1
	printf("%d\n", (2 + 3));
#endif

////////////////////////

#define PRINT 1
#define VILAS 1

#if PRINT && VILAS
	printf("vilas\n");
#else
	printf("vikas\n");
#endif

////////////////////////////

#define SUM(a,b) a+b
#define MUL(a,b) a*b

	int val = MUL(2, SUM(3,4)); // 2 * 3 + 4
	printf("%d\n", val);

	return 0;
}

