#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	int data;
	struct tree *left;
	struct tree *right;
} Node;

Node *root = NULL;

enum OPTION {
	ADD = 1, DELETE, SEARCH, PRINT, EXIT
};

//non recursive
void insert(int data) {

	Node *node = malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	// Add with recursion
	// insert(&root, node);

	//Add without recursion
	// Find correct location for new node and insert it
	if (root == NULL) {
		root = node;
	} else {
		int inserted = 0;
		Node *loc = root;

		while (inserted == 0) {
			if (node->data < loc->data) {
				if (loc->left == NULL) {
					loc->left = node;
					inserted = 1;
				} else
					loc = loc->left;
			} else {
				if (loc->right == NULL) {
					loc->right = node;
					inserted = 1;
				} else
					loc = loc->right;
			}
		}
	}
}

//recursive
void insert(Node **node, Node *data) {

	Node *loc = *node;
	if (loc == NULL) {
		loc = data;
		return;
	}

	if (data->data < loc->data) {
		insert(&loc->left, data);
	} else {
		insert(&loc->right, data);
	}
}

//non recursive
void remove(char* data) {

	node *temp = root;
	node *prev = root;

	while (1) {

		if (temp == NULL)
			return;

		if (strcmp(temp->key, data) == 0) {

			int left = 0;

			if (prev->left == temp)
				left = 1;

			if (temp->left == NULL && left) {
				prev->left = temp->right;
				free(temp);
				return;
			}

			if (temp->right == NULL && left) {
				prev->left = temp->left;
				free(temp);
				return;
			}

			if (temp->left == NULL && left == 0) {
				prev->right = temp->right;
				free(temp);
				return;
			}

			if (temp->right == NULL && left == 0) {
				prev->right = temp->left;
				free(temp);
				return;
			}

			while (temp->left != NULL && temp->right != NULL) {
				temp->key = temp->right->key;
				prev = temp;
				temp = temp->right;
			}

			if (temp->right == NULL)
				prev->right = temp->left;

			if (temp->left == NULL)
				prev->right = temp->right;

			free(temp);
			return;
		}

		prev = temp;
		if (strcmp(temp->key, data) < 0)
			temp = temp->right;
		else
			temp = temp->left;
	}
}

//recursive
remove(Node *node, int num) {

	static Node *parent = NULL;

	if (node != NULL && node->data != num) {

		parent = node;

		if (num < node->data)
			remove(node->lchild, num);
		else
			remove(node->rchild, num);
	}
}

node* find(char * ch) {

	node* curr = root;

	while (curr) {

		if (!strcmp(ch, curr->key))
			return curr;
		else if (strcmp(ch, curr->key) > 0)
			curr = curr->right;
		else if (strcmp(ch, curr->key) < 0)
			curr = curr->left;
	}

	return NULL;
}

void mirror(Tree* node) {

	if (node == NULL) {
		return;
	} else {

		Tree * temp;

		/* do the subtrees */
		mirror(node->left);
		mirror(node->right);

		/* swap the pointers in this node */
		temp = node->left;
		node->left = node->right;
		node->right = temp;
	}
}

void inorder(Tree* node) {

	if (node == NULL)
		return;

	inorder(node->left);
	printf("%d ", node->data);
	inorder(node->right);
}

print(Node *node) {

	if (node != 0) {
		printf("\n%d ", node->data);
		print(node->lchild);
		print(node->rchild);
	}
}

void destroy_tree(Node *p) {

	if (p != NULL) {
		destroy_tree(p->left);
		destroy_tree(p->right);
		free(p);
	}
}

int maxDepth(Node *node) {

	if (node == NULL)
		return 0;
	else {
		/* compute the depth of each subtree */
		int lDepth = maxDepth(node->left);
		int rDepth = maxDepth(node->right);

		/* use the larger one */
		if (lDepth > rDepth)
			return (lDepth + 1);
		else
			return (rDepth + 1);
	}
}

void main() {

	int i, num;
	char ch;

	while (1) {

		printf("Enter choice: \n");
		printf("%d. Add\n", ADD);
		printf("%d. Delete\n", DELETE);
		printf("%d. Search\n", SEARCH);
		printf("%d. Print\n", PRINT);
		printf("%d. Exit\n", EXIT);

		scanf(" %c", &ch);

		switch (ch) {
		case ADD:
			printf("Enter num to add: ");
			scanf("%d", &num);
			add(num, head);
			break;
		case DELETE:
			printf("Enter num to delete: ");
			scanf("%d", &num);
			delete(num);
			break;
		case SEARCH:
			printf("Enter num to search: ");
			scanf("%d", &num);
			search(num);
			break;
		case PRINT:
			inOrder(head);
			break;
		case EXIT:
			exit(0);
		default:
			printf("Invalid choice");
		}
		printf("\n");
	}
}

