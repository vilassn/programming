#include <stdio.h>

struct Bit {
	int bit;
	struct bit *next;
}*head = 0;

void print() {

	struct Bit *node = head;
	while (node != NULL) {

		printf("%d", node->bit);
		node = node->next;
	}

	printf("\n");
}

void addbit(int bit) {

	struct Bit *node = (struct Bit *) malloc(sizeof(struct Bit));
	node->bit = bit;
	node->next = NULL;

	if (head == NULL) {
		head = node;
	} else {
		struct Bit *temp = head;
		while (temp->next != NULL)
			temp = temp->next;

		temp->next = node;
	}
}

int main() {

	int num;

	printf("Enter number to print in binary: ");
	scanf("%d", &num);

	for (int i = 31; i >= 0; i--)
		addbit((num & (1 << i)) ? 1 : 0);

	print();
}
