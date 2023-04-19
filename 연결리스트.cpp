#include <stdio.h>
#define MAX_LIST_SIZE 10
typedef int element;
typedef struct {
	element array[MAX_LIST_SIZE];
	int size;
}ArrayListType;

void init(ArrayListType* L) {
	L->size = 0; //������ �ʱ�ȭ
}
int is_full(ArrayListType* L) {
	return (L->size == MAX_LIST_SIZE);
}
void insert(ArrayListType* L, int pos, element item) {
	if (!is_full(L) && pos >= 0 && pos <= L->size) {
		for (int i = (L->size - 1); i >= pos; i--) {
			L->array[i + 1] = L->array[i]; //��ĭ�� �δ�.
		}
		L->array[pos] = item;
		L->size++;
	}
}

void print_list(ArrayListType* L) {
	for (int i = 0; i < L->size; i++) {
		printf("%d->", L->array[i]);
	}
	printf("\n");
}

element delete_arr(ArrayListType* L, int pos) {
	element item;
	if (pos < 0 || pos >= L->size)
		printf("�������� ����.\n");
	item = L->array[pos];
	for (int i = pos; i < (L->size - 1); i++) {
		L->array[i] = L->array[i + 1];
	}
	L->size--;
	return item;
}
void insert_last(ArrayListType* L, element item) {
	if (!is_full(L)) {
		L->array[L->size] = item;
		L->size++;
	}
	else {
		printf("error : ����Ʈ �����÷ο�!\n");
	}
		
}

int main() {
	ArrayListType list;

	init(&list);
	insert(&list, 0, 10);
	insert(&list, 0, 20);
	insert(&list, 0, 30);

	print_list(&list);

	element data = delete_arr(&list, 0);
	printf("���� ���� %3d\n", data);
	print_list(&list);

	insert_last(&list, 40);
}