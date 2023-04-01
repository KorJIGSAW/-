//�̷θ� �������� �����ϱ�
#include <stdio.h>
#include <time.h>
#include "stack.h"
#define MAX_SIZE 10

element here = { 1,0 };
element entry = { 1,0 };


void PrtMaze(char maze[MAX_SIZE][MAX_SIZE]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%c ", maze[i][j]);
		}
		printf("\n");
	}
}

//������ 1�� �ʱ�ȭ ������ ������ ������ 0,1�ο�
void RanMaze(char maze[MAX_SIZE][MAX_SIZE]) {
	for (int i = 0; i < 10; i++) {
		maze[i][0] = '1';
		maze[0][i] = '1';
		maze[i][9] = '1';
		maze[9][i] = '1';
	}

	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			//�� 70���� Ȯ���� 1�ο�
			if (rand() % 100 >= 70) {
				maze[i][j] = '1';
			}
			else {
				maze[i][j] = '0';
			}
		}
	}
}

int main() {
	srand((unsigned)time(NULL));
	int r, c, count = 0;
	char maze[MAX_SIZE][MAX_SIZE];
	RanMaze(maze);
	//scanf_s("%d", &r);
	StackType s;
	init_stack(&s);
	maze[9][8] = 'x';
	maze[1][0] = 'e';
	while (maze[here.r][here.c] != 'x') {
		if (maze[here.r][here.c] == 1) {
			printf("����\n");
			return 0;
		}
		maze[here.r][here.c] = '.';
		//�̷����, 2���迭�� ��� �Լ�
		PrtMaze(maze);
		//�̷��� �����¿� ����
		//��
		if (maze[here.r+1][here.c] != '1' && maze[here.r+1][here.c] != '.') {
			push_loc(&s, ++here.r, here.c);
			count++;
		}
		//��
		else if (maze[here.r][here.c + 1] != '1' && maze[here.r][here.c + 1] != '.') {
			push_loc(&s, here.r, ++here.c);
			count++;
		}
		//��
		else if (maze[here.r - 1][here.c] != '1' && maze[here.r - 1][here.c] != '.') {
			push_loc(&s, --here.r , here.c);
			count++;
		}
		//��
		else if (maze[here.r][here.c - 1] != '1' && maze[here.r][here.c - 1] != '.') {
			push_loc(&s, here.r, --here.c);
			count++;
		}

		else if (is_empty(&s)) {
			printf("����\n");
			return 0;
		}
		else {
			here = pop(&s);
			count++;
		}
		printf("\n\n");
	}
	printf("%d���� �������� Ż��\n", count);
	printf("�ִܰŸ� : %d", s.top + 2);

	return 0;
}