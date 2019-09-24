/* Queue with Linked list */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	void *element;
	struct Node *next;
} Node;

typedef struct {
	Node *head;
	Node *tail;
	int current_size;
} Queue;

void *pop(Queue *q) {
	Node *temp;
	void *element;

	if (q->current_size == 0)
		return NULL;

	temp = q->head;
	element = temp->element;

	if (q->current_size == 1)
		q->head = q->tail = NULL;
	else
		q->head = q->head->next;

	free(temp);
	q->current_size--;
	return element;
}

int push(Queue *q, void * element) {
	Node *new_node = (Node *) malloc(sizeof(Node));

	if (new_node == NULL)
		return -1;

	new_node->element = element;
	new_node->next = NULL;

	if (q->current_size == 0)
		q->head = new_node;
	else
		q->tail->next = new_node;

	q->tail = new_node;
	q->current_size++;

	return 0;
}

Queue *alloc_queue() {
	Queue *q = (Queue *) malloc(sizeof(Queue));
	if (q) {
		q->head = q->tail = NULL;
		q->current_size = 0;
	}
	return q;
}

void free_queue(Queue *q) {
	while (q->current_size)
		pop(q);
}

void free_queue_and_qelement(Queue *q) {
	while (q->current_size) {
		void *element = pop(q);
		if (element)
			free(element);
	}
}

int main() {

	Queue *q = alloc_queue();

	push(q, (void*) "vilas");
	void *p = pop(q);

	printf("%s is popped\n", (char*) p);
	printf("current_size %d\n", q->current_size);

	return 0;
}

