#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

Node *head = NULL;

enum {
	ADD = 1, DELETE, SEARCH, SORT, PRINT, EXIT
};

void add() {

	int data;
	printf("Enter value to add: ");
	scanf("%d", &data);

	Node *node = (Node *) malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	if (head == NULL) {
		head = node;
	} else //add at end
	{
		Node *temp = head;
		while (temp->next != NULL)
			temp = temp->next;

		temp->next = node;
	}
}

void delete() {

	int data;
	printf("Enter value to delete: ");
	scanf("%d", &data);

	if (head == NULL)
		printf("List is empty\n");
	else {

		Node *temp = NULL;

		if (head->data == data) {
			temp = head;
			head = head->next;
			free(temp);
		}

		temp = head;
		Node *prev = NULL;

		while (temp) {
			if (temp->data == data) {
				prev->next = temp->next;
				free(temp);
				return;
			}

			prev = temp;
			temp = temp->next;
		}
	}
}

void search() {

	int data, index = 0;
	printf("Enter value to search: ");
	scanf("%d", &data);

	if (head == NULL) {
		printf("List is empty\n");
	} else {

		Node *temp = head;
		while (temp) {
			if (temp->data == data) {
				printf("Data found at index: %d\n", index);
				return;
			}

			index++;
			temp = temp->next;
		}

		printf("Data not found\n");
	}
}

void sort() {

}

void print() {

	printf("Linked list values are: \n");

	Node *temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}

	printf("\n");
}

int main() {

	int opt = 0;

	while (1) {

		printf("Enter choice:\n");
		printf("%d. ADD\n", ADD);
		printf("%d. DELETE\n", DELETE);
		printf("%d. SEARCH\n", SEARCH);
		printf("%d. SORT\n", SORT);
		printf("%d. PRINT\n", PRINT);
		printf("%d. EXIT\n", EXIT);

		scanf("%d", &opt);

		switch (opt) {
		case ADD:
			add();
			break;
		case DELETE:
			delete();
			break;
		case SEARCH:
			search();
			break;
		case SORT:
			sort();
			break;
		case PRINT:
			print();
			break;
		case EXIT:
			exit(0);
			break;
		default:
			printf("Enter correct option");
		}
	}
}
