#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int num;
	struct node *next;
} Node;

Node *head = 0;

void print() {

	Node *temp = head;
	while (temp != 0) {
		printf("%d ", temp->num);
		temp = temp->next;
	}

	printf("\n");
}

void find(int index) {

	Node *temp1 = head; //keep temp1 on head
	Node *temp2 = head; //keep temp2 on 3rd

	for (int i = 1; i <= index; i++) {
		if (temp2->next != 0)
			temp2 = temp2->next;
		else
			return;
	}

	//then go and check one by one
	while (temp2->next != 0) {
		temp1 = temp1->next;
		temp2 = temp2->next;
	}

	printf("%dth last is %d\n", index, temp1->num);
}

void getmiddle(Node *p) {

	int mid;
	Node *p1, *p2;
	p1 = p2 = p;

	while (p2->next != NULL && p2->next->next != NULL) {
		p1 = p1->next;
		p2 = p2->next->next;
	}

	printf("middle is %d\n", p1->num);
}

int main() {

	for (int i = 1; i <= 10; i++) {

		Node *new = malloc(sizeof(Node));
		new->num = i;
		new->next = 0;

		if (head == 0)
			head = new;
		else {
			Node *temp = head;
			while (temp->next != 0)
				temp = temp->next;

			temp->next = new;
		}
	}

	print();
	find(3); //find 3rd last
	getmiddle(head);

	return 0;
}

