#include <stdio.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link; //�ٸ� ����� �ּҸ� �޾ƾ��ϱ⶧���� ����Ʈ Ÿ���� ListNode
	//�ڱ���������ü
}ListNode;

int main() {
	ListNode a, b;
	ListNode* head = &a;
	a.data = 10;
	b.data = 20;
	a.link = &b; // a�� ��ũ�κп� b�� �ּҸ� �ִ´�.
	b.link = NULL;
	printf("%d\n", a.data);
	printf("%d\n", head->data);
}