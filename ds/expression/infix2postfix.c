#include<stdio.h>
#include<string.h>
#define MAX 50
char pop(void);
int push(char);
unsigned char infix[MAX];
unsigned char postfix[MAX];
unsigned char stack[MAX];
int tos = 0;
main() {
	printf("Enter the infix expression: ");
	scanf("%s", infix);    // A*(B+C^D)-E^F*(G/H)
	infix2postfix();     //4*(4+7^2)-5^2*(1/5)
	printf("\nPostfix expression is %s\n", postfix);
	printf("\nValue of expression is %d", eval_postfix());
}

infix2postfix() {
	int len, p = 0, i, type, priority;
	char next;
	stack[tos] = '#';
	len = strlen(infix);
	infix[len] = '#';
	for (i = 0; infix[i] != '#'; i++) {
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
		default:/* if operand comes */
			postfix[p++] = infix[i];
		}
	}
	while (stack[tos] != '#')
		postfix[p++] = pop();
	postfix[p] = '\0';
} /* end of infix_to_postfix */

findpriority(int symbol) {
	switch (symbol) {
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
int push(char symbol) {
	if (tos > MAX) {
		printf("Stack overflow");
		exit(1);
	} else {
		tos++;
		stack[tos] = symbol;
	}
}

char pop() {
	if (tos == -1) {
		printf("Stack underflow");
		exit(2);
	} else
		return (stack[tos--]);
}

int eval_postfix() {
	int a, b, temp, result, len, i;
	len = strlen(postfix);
	postfix[len] = '#';
	for (i = 0; postfix[i] != '#'; i++) {
		if (postfix[i] <= '9' && postfix[i] >= '0')
			push(postfix[i] - 48);
		else {
			a = pop();
			b = pop();
			switch (postfix[i]) {
			case '+':
				temp = b + a;
				break;
			case '-':
				temp = b - a;
				break;
			case '*':
				temp = b * a;
				break;
			case '/':
				temp = b / a;
				break;
			case '%':
				temp = b % a;
				break;
			case '^':
				temp = power(b, a);
			}
			push(temp);
		}
	}
	result = pop();
	return result;
}

int power(int b, int a) {
	int res = 1;
	while (a--) {
		res = res * b;
	}
	return res;
}

