#include <stdio.h>
#include <stdlib.h>

// ���Ŀ� ������ �ʿ��ϸ� ���⸸ �����Ͽ� ���δ�. 
// ===== ���� �ڵ��� ���� ===== 
#define MAX_STACK_SIZE 100

typedef int element;


typedef struct {
	element* data;
	//ũ�⸦ �󸶳� Ȯ���ų����
	int capacity;
	int top;
} StackType;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType* s)
{
	s->top = -1;
	s->capacity = 1;
	s->data = (element *)malloc(s->capacity * sizeof(element));
}

// ���� ���� ���� �Լ�
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType* s)
{
	return (s->top == s->capacity);
}
// �����Լ�
void push(StackType* s, element item)
{
	if (is_full(s)) {
		//�޸𸮸� �߰� ��û��
		s->capacity = s->capacity * 2;
		//realloc -> realloc(���?, �󸶸�ŭ?;
		s->data = (element *)realloc(s ->data, s->capacity*sizeof(element));
	}
	else s->data[++(s->top)] = item;
}
// �����Լ�
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
// ��ũ�Լ�
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}
// ===== ���� �ڵ��� �� ===== 

//�����߿� �޸��Ҵ� -> �����Ҵ�
//���α׷� 4.5 ���� �迭 ���� ���α׷�(117��)
int main(void)
{
	StackType s;
	
	init_stack(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	printf("pop value = %d\n", pop(&s));
}
