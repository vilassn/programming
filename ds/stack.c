#include<stdio.h>
int sp = -1, tos = 19;
int a[20];

void push(int *a, int data) {

	if (sp == tos) {
		printf("\nstack is full");
	} else {
		sp++;
		a[sp] = data;
	}
}

int pop() {

	if (sp == -1) {
		printf("\nStack is empty.");
		return 0;
	}

	int temp = a[sp];
	sp--;

	return temp;
}

void print(int *a) {

	int i;
	for (i = 0; i <= sp; i++) {
		printf("\n%d ", a[i]);
	}
}

int main() {

	int n;
	while (1) {
		printf("\nEnter the data: ");
		scanf("%d", &n);
		push(a, n);
		pop();
		print(a);
	}

	return 0;
}
