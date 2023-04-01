#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 20

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType* s) {
	s->top = -1;
}

//Underflow
int is_empty(StackType* s) {
	return (s->top == -1);
}

//Overflow
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

// �����Լ�
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// �����Լ�
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

element peek(StackType* s) {//peek �Լ��� top�� ���� ��ȭ�� ����.
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)];
}

int prec(char ch) {
	if (ch == '+' || ch == '-') {
		return 2;
	}
	else if (ch == '(' || ch == ')') {
		return 1;
	}
	else if (ch == '*' || ch == '/') {
		return 3;
	}
}

void infix_to_postfix(const char exp[]) {
	StackType s;
	char ch;
	char op_top;
	init_stack(&s);
	int len = strlen(exp);
	for (int i = 0; i < len; i++) {
		ch = exp[i];
		//ch�� ���������� ����.
		switch (ch) {
		case '+': case '-': case '*': case '/': //���� �ȿ��ִ� �����ں��� �� �������� �켱������ �� ������
			while (!is_empty(&s) && prec(peek(&s)) >= prec(ch)) 	//�ȿ��ִ� �����ڸ� pop�ϰ� ����Ʈ�Ѵ�. �׸��� �� �����ڸ� �о�ִ´�.
				printf("%c", pop(&s));
			push(&s, ch);
			break;

		case '(':
			push(&s, ch);
			break;
		case ')': // '('���� ã�ư��� ����ϱ�
			op_top = pop(&s);
			while (op_top != '(') {
				printf("%c", op_top);
				op_top = pop(&s);
			}
			break;
		default:
			printf("%c", ch);
			break;
		}
	}
	while (!is_empty(&s)) {
		printf("%c", pop(&s));
	}
}

int main() {
	const char* s = "(3+2)*8+4";
	infix_to_postfix(s);
}
"32+8*4+"