#include<stdio.h>
#include<string.h>
#define MAX 50
int pop(void);
void push(int);
void string2infix();
void infix2postfix();
void print_expr(int *);
char string[MAX];
int infix[MAX];
int postfix[MAX];
int stack[MAX];
int tos = 0;
main() {
	printf("Enter the string expression:\n\n\t\t ");
	scanf("%s", string);
	string2infix();
	printf("\nInfix expression is:\n\n\t\t ");
	print_expr(infix);
	infix2postfix();
	printf("\nPostfix expression is:\n\n\t\t ");
	print_expr(postfix);
	printf("\nValue of expression is %d\n\n", eval_postfix());
}

/* String to infix expression */
void string2infix() {
	char temp;
	int res = 0, i = 0, j = 0, state = 1;
	while (1) {
		temp = string[i];
		if (temp >= '0' && temp <= '9') {
			state = 0;
			res = (temp - 48) + res * 10;
		} else {
			if (state == 0) {
				infix[j++] = (res + 128);
				res = 0;
				state = 1;
			}
			infix[j++] = temp;
		}
		if (temp == 0) {
			infix[--j] = '#';
			break;
		}
		i++;
	}
} /********* end of string to infix*********/

void infix2postfix() {
	int p = 0, i, next, priority;
	stack[tos] = '#';
	for (i = 0; infix[i] != '#'; i++) {
		if (infix[i] < 128) {
			switch (infix[i]) {
			case '(':
				push(infix[i]);
				break;
			case ')':
				while ((next = pop()) != '(')
					postfix[p++] = next;
				break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			case '^':
				priority = findpriority(infix[i]);
				while (stack[tos] != '#' && priority <= findpriority(stack[tos]))
					postfix[p++] = pop();
				push(infix[i]);
				break;
			default:
				printf("\nSyntax Error\n");
				exit(0);
			}
		} else
			postfix[p++] = infix[i]; /* if operand comes */
	} //for end
	while (stack[tos] != '#')
		postfix[p++] = pop();
	postfix[p] = '#';
} /********** end of infix to postfix **********/

void print_expr(int *exp) {
	int i = 0;
	while (exp[i] != '#') {
		if (exp[i] < 128)
			printf("%c ", exp[i]);
		else
			printf("%d ", exp[i] - 128);
		i++;
	}
}

int findpriority(int op) {
	switch (op) {
	case '(':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
	case '%':
		return 2;
	case '^':
		return 3;
	}
}

void push(int op) {
	if (tos == (MAX - 1)) {
		printf("Stack overflow");
		// exit(0);
	} else {
		tos++;
		stack[tos] = op;
	}
}

int pop() {
	if (tos == -1) {
		printf("Stack underflow");
		//exit(0);
	} else
		return (stack[tos--]);
}

int eval_postfix() {
	int a, b, temp, result, i;
	for (i = 0; postfix[i] != '#'; i++) {
		if (postfix[i] >= 128)
			push(postfix[i] - 128);
		else {
			if (tos >= 2)  // to avoid wrong o/p when string is  "-1"
					{
				b = pop();
				a = pop();
			} else {
				b = pop();
				a = 0;
			}
			switch (postfix[i]) {
			case '+':
				temp = a + b;
				break;
			case '-':
				temp = a - b;
				break;
			case '*':
				temp = a * b;
				break;
			case '/':
				temp = a / b;
				break;
			case '%':
				temp = a % b;
				break;
			case '^':
				temp = power(a, b);
			}
			push(temp);
		}
	}
	result = pop();
	return result;
}

int power(int a, int b)     //a^b =>b times product of a
{
	int res = 1;
	while (b--) {
		res = res * a;
	}
	return res;
}

