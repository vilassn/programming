#include <stdio.h>

typedef struct node {
	int num;
	struct node *next;
} Node;

Node *head = 0;
main() {
	int i;
	for (i = 1; i <= 10; i++) {
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
	find(3); //find 3rd last
}

find(int index) {
	Node *temp1 = head; //keep temp1 on head
	Node *temp2 = head; //keep temp2 on 3rd

	int i;
	for (i = 1; i <= index; i++) {
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
