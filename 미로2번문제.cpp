//�̷θ� �������� �����ϱ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
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

int Check_Ready() {//�����غ��۾�, �꼳��
	int n;
	printf("������ �÷��� �Ͻ� �غ� �Ǽ̴ٸ� 1�� �Է����ּ��� : ");
	scanf("%d", &n);
	if (n == 1) {
		printf("������ �����մϴ�!\n");
		printf("�����϶����� 1��, ��ź�� ������ -3���Դϴ�.\n");
		printf("�Դ����� �ǵ��ư��� �ൿ���� ������ �������� �ʽ��ϴ�!\n");
		printf("10���� ������ ���۵˴ϴ�!\n");
		Sleep(10);
		for (int i = 10; i > 0; i--) {
			printf("%d ", i);
			
		}
		system("cls");
		return 1;
	}
	else {
		printf("�÷����� �غ� ��ġ�ø� �ٽ� �������ּ���!");
		Sleep(3000);
		return 0;
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
			else if (rand()% 100< 10) {
				//�� 10���� Ȯ���� ��ź�ο�
				maze[i][j] = 'B'; 
			}
			else {
				maze[i][j] = '0';
			}
		}
	}
}

int main() {
	if (Check_Ready()) {
	reset:
		srand((unsigned)time(NULL));
		int r, c, count = 0;
		int key1, key2, score = 0;
		char maze[MAX_SIZE][MAX_SIZE];
		RanMaze(maze);
		//scanf_s("%d", &r);
		StackType s;
		init_stack(&s);

		maze[9][8] = 'x';
		maze[1][0] = 'e';
		while (maze[here.r][here.c] != 'x') {
			/*
			if (maze[here.r][here.c] == 1) {
				printf("����\n");
				return 0;
			}*/

			maze[here.r][here.c] = '.';
			//�̷����, 2���迭�� ��� �Լ�
			printf("0 : ��, 1 : ��\n"); //��, �� ����
			PrtMaze(maze);

			printf("���� : %d    ", score);
			printf("Ǯ �� ���� �̷ζ�� r �Ǵ� R�� �Է�\n\n");

			key1 = _getch();
			if (key1 == 'r' || key1 == 'R') {
				goto reset;
			}
			key2 = _getch();

			//����Ű �Է¹޾Ƽ� �����̱�
			if (key1 == 224) {
				switch (key2) {
				case 72://��
					if (maze[here.r - 1][here.c] != '1' && maze[here.r - 1][here.c] != '.') {
						//push_loc(&s, --here.r, here.c);
						count++;
						score++;
					}
					else if (maze[here.r - 1][here.c] == '1') {
						printf("�����ֽ��ϴ�.\n");
						Sleep(1000);
						system("cls");
						continue;
					}
				case 80://��
					if (maze[here.r + 1][here.c] == '1') {
						printf("�����ֽ��ϴ�.\n");
						Sleep(1000);
						system("cls");
						continue;
					}
					else if (maze[here.r + 1][here.c] != '1' && maze[here.r + 1][here.c] != '.') {
						push_loc(&s, ++here.r, here.c);
						count++;
						score++;
					}

				case 75://��
					if (maze[here.r][here.c - 1] != '1' && maze[here.r][here.c - 1] != '.') {
						push_loc(&s, here.r, --here.c);
						count++;
						score++;
					}
					else if (maze[here.r][here.c - 1] == '1') {
						printf("�����ֽ��ϴ�.\n");
						Sleep(1000);
						system("cls");
						continue;
					}
				case 77://��
					if (maze[here.r][here.c + 1] != '1' && maze[here.r][here.c + 1] != '.') {
						push_loc(&s, here.r, ++here.c);
						count++;
						score++;
					}
					else if (maze[here.r][here.c + 1] == '1') {
						printf("�����ֽ��ϴ�.\n");
						Sleep(1000);
						system("cls");
						continue;
					}
				}
			}
			else if (is_empty(&s)) {
				printf("����\n");
				return 0;
			}
			else {
				here = pop(&s);
				count++;
			}

			system("cls");
		}
	exit:
		printf("%d���� �������� Ż��\n", count);
		printf("�ִܰŸ� : %d\n", s.top + 2);
		printf("���� : %d", score);
	}
}

//��, �Ʒ��� ������ �� �����ֽ��ϴ� ����Ʈ ����
//��ź ������ -3�� �߰�
//cls ����ȭ
//�ѹ��� ����Ű �Է½� ���� ��� ����
//UI ���ڰ�
//���� = 100 - �����ΰŸ�
