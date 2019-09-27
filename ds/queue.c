/* Queue with Linked list */
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	void *element;
	struct node *next;
} Node;

typedef struct {
	Node *head;
	Node *tail;
	int size;
} Queue;

Queue *alloc_queue() {

	Queue *q = (Queue *) malloc(sizeof(Queue));

	q->head = q->tail = NULL;
	q->size = 0;

	return q;
}

int push(Queue *q, void *element) {

	Node *new_node = (Node *) malloc(sizeof(Node));

	new_node->element = element;
	new_node->next = NULL;

	if (q->size == 0)
		q->head = new_node;
	else
		q->tail->next = new_node;

	q->tail = new_node;
	q->size++;

	return 0;
}

void *pop(Queue *q) {

	Node *node;
	void *element;

	if (q->size == 0)
		return NULL;

	node = q->head;
	element = q->head->element;

	if (q->size == 1)
		q->head = q->tail = NULL;
	else
		q->head = q->head->next;

	free(node);
	q->size--;

	return element;
}

void free_queue(Queue *q) {

	while (q->size) {

		pop(q);
	}
}

void free_queue_and_qelement(Queue *q) {

	while (q->size) {

		void *element = pop(q);
		if (element != NULL)
			free(element);
	}
}

int main() {

	Queue *q = alloc_queue();

	push(q, (void*) "vilas");
	void *p = pop(q);

	printf("%s is popped\n", (char*) p);
	printf("size %d\n", q->size);

	return 0;
}

