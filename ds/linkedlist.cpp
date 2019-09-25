#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	Node *next;
};

Node *head = 0;

int add() {
	printf("in add\n");

	static int i = 0;
	Node * node = (Node*) malloc(sizeof(struct Node));
	node->data = i++;
	node->next = 0;

	if (head == 0) {
		printf("in add, list is empty\n");
		head = node;
	} else {
		printf("in add, list is not empty\n");
		Node *temp = head;
		while (temp->next != 0)
			temp = temp->next;
		temp->next = node;
	}

	return 0;
}

int remove() {
	printf("in remove\n");

	Node *temp = head;
	Node *prev = 0;
	while (temp != 0) {
		if (temp->data == 5) {
			head = temp->next;
			delete temp;
			break;
		}

		prev = temp;
		temp = temp->next;
	}

	return 0;
}

int sort() {
	printf("in sort\n");
	return 0;
}

int print() {
	printf("in print\n");

	Node *temp = head;
	while (temp != 0) {
		printf("data: %d\n", temp->data);
		temp = temp->next;
	}

	return 0;
}

int exit() {
	printf("in exit\n");

	exit(0);
	return 0;
}

int main() {

	while (1) {

		int opt = 0;

		printf("1.add, 2.remove, 3.sort, 4.print, 5.exit\n");
		printf("Enter option\n");
		scanf("%d", &opt);

		switch (opt) {
		case 1:
			add();
			break;
		case 2:
			remove();
			break;
		case 3:
			sort();
			break;
		case 4:
			print();
			break;
		case 5:
			exit();
			break;
		default:
			printf("Select proper option\n");
			break;
		}
	}

	return 0;
}
