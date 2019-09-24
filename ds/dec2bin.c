#include <stdio.h>

struct linklist {
	int data;
	struct linklist *next;
}*head = 0;

int printbin() {

	printf("\nCoverted number into binary is:\n");

	struct linklist *temp = head;
	while (temp != 0) {
		printf("%d", temp->data);
		temp = temp->next;
	}

	return 0;
}

int addbit(int bit) {

	struct linklist *node, *temp = head;
	node = (struct linklist *) malloc(sizeof(struct linklist));
	node->data = bit;
	node->next = 0;

	if (head == 0) {
		head = node;
	} else {
		while ((temp->next) != 0)
			temp = temp->next;
		temp->next = node;
	}

	return 0;
}

int main() {

	int num;
	printf("Enter the number: ");
	scanf("%d", &num);

	for (int i = 31; i >= 0; i--)
		((1 << i) & num) ? addbit(1) : addbit(0);

	printbin();

	return 0;
}
