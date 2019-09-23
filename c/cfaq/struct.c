#include <stdio.h>

struct demo {
	int i;
	char name[10];
	struct demo* ptr;
} d1; //d1 is a variable

typedef struct stu {
	int num;
	struct stu *left;
	struct stu *right;
} Node; //Node is new data type

main() {
	struct demo d;
	d.i = 2;
	strcpy(d.name, "Vilas");
	printf("In %s, d.i=%d, d.name=%s\n", __func__, d.i, d.name);

	func(&d);
	printf("In %s, d.i=%d, d.name=%s\n\n", __func__, d.i, d.name);

	Node n, *ptr;
	printf("size of (Node)=%lu, (n)=%lu, (*ptr)=%lu\n", sizeof(Node), sizeof(n),
			sizeof(*ptr));
}

func(struct demo *d) {
	printf("In %s, d->i=%d, d->name=%s\n", __func__, d->i, d->name);

	d->i = 3;
	d->name[0] += 32;
}
