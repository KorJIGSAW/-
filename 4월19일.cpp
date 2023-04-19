#include <stdio.h>
#include <stdlib.h>

typedef int element;
//��� ���� ����
typedef struct ListNode{
	element data;
	struct ListNode* link; // ListNode�� �ϸ�ȵȴ� // �ڱ���������ü
}ListNode;

ListNode * insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //�����Ҵ�
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode * delete_first(ListNode *head) {
	ListNode* removed = head;
	head = head->link; // head = removed->link;
	free(removed);
	return head;
}

void print_list(ListNode *head) {
	for (ListNode* p = head; p != NULL; p = p->link) {//��忡�� ����ؼ� p->link�� NULL�� �ƴҶ����� p�� p->link�� ��ȯ�Ѵ�.
		printf("%d->", p->data);
	}
	printf("\n");
}

ListNode * search_list(ListNode *head, element x) {
	ListNode * p = head;
	while (p != NULL) {
		if (p->data == x) {
			return p;
		}
		p = p->link; // p�� ������ ���� x�� �ƴ϶�� �� ���� link�� ����Ű�� ���̶� ���ؾ��ϹǷ� ���� ��ȯ������Ѵ�.
	}
	return NULL;
}

int main() {
	ListNode* head = NULL;
	head = insert_first(head, 10);
	head = insert_first(head, 20);
	head = insert_first(head, 30);
	head = insert_first(head, 40);
	head = insert_first(head, 50);

	ListNode* s = search_list(head, 20);
	if (s != NULL) {
		printf("�����Ͱ� ������\n");
	}
	else {
		printf("�����Ͱ� �������� ����\n");
	}

	print_list(head);

	head = delete_first(head);
	
	print_list(head);
}