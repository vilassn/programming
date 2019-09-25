#include <stdio.h>

typedef struct tree {
	int data;
	struct tree *left;
	struct tree *right;
} Tree;

Tree *head = 0;
void main() {
	Tree st = { 5, 0, 0 };
	head = &st;

	func1(head); //passing value of head
	func2(&head); //passing address of head
}

func1(Tree *localhead) {
	localhead = 0; //can't change value of head
}

func2(Tree **headaddr) {
	*headaddr = malloc(sizeof(Tree)); //changing value of head
}
