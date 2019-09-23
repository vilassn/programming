#include<stdio.h>
#include<stdlib.h>
struct bintree {
	struct bintree *lchild;
	int data;
	struct bintree *rchild;
};
main() {
	int i, num;
	char choice;
	struct bintree *head = 0;
	while (1) {
		printf("\n1. Add   2. Delete   3. Search  4. Print  5. Exit");
		printf("\nEnter choice: ");
		scanf(" %c", &choice);
		//  system("clear");
		switch (choice) {
		case '1':
			printf("Enter element to be add: ");
			scanf("%d", &num);
			add(&head, num);
			break;
		case '2':
			printf("Enter the element to be delete: ");
			scanf("%d", &num);
			if (search(head, num) == 1)
				delete(head, num);
			else
				printf("Node to be deleted is not present ");
			break;
		case '3':
			printf("Enter the element to be search: ");
			scanf("%d", &num);
			if (search(head, num) == 1)
				printf("Num found");
			else
				printf("Not found");
			break;
		case '4':
			print(head);
			break;
		case '5':
			exit(0);
		default:
			printf("Invalid choice");
		}
	}
}

add(struct bintree **node, int num) {
	if ((*node) == 0) {
		(*node) = (struct bintree*) malloc(sizeof(struct bintree));
		(*node)->data = num;
		(*node)->lchild = 0;
		(*node)->rchild = 0;
	} else {
		if (num < ((*node)->data))
			add(&(*node)->lchild, num);
		else
			add(&(*node)->rchild, num);
	}
}

delete(struct bintree *node, int num) {
	static struct bintree *parent;
	if (node != 0) {
		if ((node->data) != num) {
			parent = node;
			if (num < (node->data))
				delete(node->lchild, num);
			else
				delete(node->rchild, num);
		}
	}

}

int search(struct bintree *node, int num) {
	if (node != 0) {
		if ((node->data) == num) {
			return 1;
		} else {
			if (num < (node->data))
				search(node->lchild, num);
			else
				search(node->rchild, num);
		}
	}
}

print(struct bintree *node) {
	if (node != 0) {
		printf("\n%d ", node->data);
		print(node->lchild);
		print(node->rchild);
	}
}

