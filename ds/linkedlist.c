#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

Node *head = NULL;

enum OPTION {
	ADD = 1,
	DELETE,
	SEARCH,
	SORT,
	REVERSE,
	GET3RDLAST,
	GETMIDDLE,
	LOAD,
	SAVE,
	PRINT,
	EXIT
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
	}
	//add at begin
//	else {
//		node->next = head;
//		head = node;
//	}
	//add at end
//	else {
//		Node *temp = head;
//		while (temp->next != NULL)
//			temp = temp->next;
//
//		temp->next = node;
//	}
	//add sorted
	else {
		Node *temp = head;
		while (temp->next != NULL && temp->next->data < data)
			temp = temp->next;

		if (temp->next == NULL) {
			temp->next = node;
		} else {
			node->next = temp->next;
			temp->next = node;
		}
	}
}

void delete() {

	int data;
	printf("Enter value to delete: ");
	scanf("%d", &data);

	if (head == NULL) {
		printf("List is empty\n");
	} else {

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

void get3rdlast(int index) {

	Node *temp0 = head;
	Node *temp3 = head;

	if (head == NULL) {
		printf("List is empty\n");
	} else {
		for (int i = 1; i < index; i++) {

			if (temp3->next != NULL) {
				temp3 = temp3->next;
			} else {
				printf("List has less than 3 elements\n");
				return;
			}
		}

		while (temp3->next != NULL) {
			temp0 = temp0->next;
			temp3 = temp3->next;
		}

		printf("3rd last element is %d\n", temp0->data);
	}
}

void getmiddle() {

	Node *temp1 = head;
	Node *temp2 = head;

	if (head == NULL) {
		printf("List is empty\n");
	} else {
		while (temp2->next != NULL && temp2->next->next != NULL) {

			temp1 = temp1->next;
			temp2 = temp2->next->next;
		}

		printf("Middle of list is %d\n", temp1->data);
	}
}

void sort() {

	Node *tempi = head;
	Node *tempj = head;

	if (head == NULL) {
		printf("List is empty\n");
	} else {

		while (tempi->next != NULL) {
			tempj = tempi->next;

			while (tempj) {
				if (tempi->data > tempj->data) {
					int data = tempi->data;
					tempi->data = tempj->data;
					tempj->data = data;
				}
				tempj = tempj->next;
			}
			tempi = tempi->next;
		}
	}
}

void reverse() {

	if (head == NULL) {
		printf("List is empty\n");
	} else {

		Node *prev = head;

		prev->next = NULL;
		head = head->next;

		while (head->next != NULL) {
			Node *next = head->next;
			head->next = prev;
			prev = head;
			head = next;
		}

		head->next = prev;
	}
}

void load() {

	char filename[20];

	printf("Enter the name of database file: ");
	scanf("%s", filename);

	FILE *fp = fopen(filename, "ab+");
	if (fp == 0) {
		printf("File can not be accessed\n");
		return;
	}

	Node node, *temp;
	while (fread(&node, sizeof(Node) - 4, 1, fp)) {

		Node *new = (Node *) malloc(sizeof(Node));
		new->data = node.data;
		new->next = NULL;

		if (head == NULL) {
			head = new;
			temp = head;
		} else {
			temp->next = new;
			temp = new;
		}
	}

	fclose(fp);
}

void save() {

	char filename[20];

	printf("Enter the database file name: ");
	scanf("%s", filename);

	FILE *fp = fopen(filename, "wb");
	if (fp == 0) {
		printf("File can not be opened\n");
		return;
	}

	Node *temp = head;
	while (temp) {
		fwrite(temp, sizeof(Node) - 4, 1, fp);
		temp = temp->next;
	}

	fclose(fp);
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
		printf("%d. REVERSE\n", REVERSE);
		printf("%d. GET3RDLAST\n", GET3RDLAST);
		printf("%d. GETMIDDLE\n", GETMIDDLE);
		printf("%d. LOAD\n", LOAD);
		printf("%d. SAVE\n", SAVE);
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
		case REVERSE:
			reverse();
			break;
		case GET3RDLAST:
			get3rdlast(3);
			break;
		case GETMIDDLE:
			getmiddle();
			break;
		case LOAD:
			load();
			break;
		case SAVE:
			save();
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
