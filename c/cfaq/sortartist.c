#include <stdio.h>

typedef struct song {
	int duration;
	char artist[10];
} Song;

Song array[10];

int main() {
	int i;
	for (i = 0; i < 10; i++) {
		Song temp = { 10 - i, "artist" };
		array[i] = temp;
	}
	print();
	sort();
	print();
	return 0;
}

sort() {
	int total;
	total = sizeof(array) / sizeof(Song);
	printf("Total %d\n", total);

	int i, j;
	for (i = 0; i < total - 1; i++) {
		for (j = i + 1; j < total; j++) {
			if (array[i].duration > array[j].duration) {
				Song temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}

print() {
	int i;
	for (i = 0; i < 10; i++)
		printf("dur:%d, art:%s\n", array[i].duration, array[i].artist);
}
