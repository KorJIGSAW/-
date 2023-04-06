#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "stack.h"
#define MAX_SIZE 10

typedef struct {
	int score;
	int count;
	element NowPos;
	char maze[MAX_SIZE][MAX_SIZE];
}GameData;

int CheckMaze(char maz[MAX_SIZE][MAX_SIZE]) {
	element here = { 1,0 };
	int count = 0;
	StackType s;
	init_stack(&s);
	char maze[MAX_SIZE][MAX_SIZE];

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			maze[i][j] = maz[i][j];
		}
	}

	while (maze[here.r][here.c] != 'x') {
		if (maze[here.r][here.c] == 1) {
			return 0;
		}
		maze[here.r][here.c] = '.';
		//�̷��� �����¿� ����
		//��
		if (maze[here.r + 1][here.c] != '1' && maze[here.r + 1][here.c] != '.' && maze[here.r + 1][here.c] != '|' && maze[here.r + 1][here.c] != '-') {
			push_loc(&s, ++here.r, here.c);
			count++;
		}
		//��
		else if (maze[here.r][here.c + 1] != '1' && maze[here.r][here.c + 1] != '.' && maze[here.r][here.c ] != '|' && maze[here.r][here.c + 1] != '-') {
			push_loc(&s, here.r, ++here.c);
			count++;
		}
		//��
		else if (maze[here.r - 1][here.c] != '1' && maze[here.r - 1][here.c] != '.' && maze[here.r - 1][here.c] != '|' && maze[here.r - 1][here.c] != '-') {
			push_loc(&s, --here.r, here.c);
			count++;
		}
		//��
		else if (maze[here.r][here.c - 1] != '1' && maze[here.r][here.c - 1] != '.' && maze[here.r][here.c - 1] != '|' && maze[here.r][here.c - 1] != '-') {
			push_loc(&s, here.r, --here.c);
			count++;
		}

		else if (is_empty(&s)) {
			return 0;
		}
		else {
			here = pop(&s);
			count++;
		}
	}
	return 1; //�̷� �˻� ���!
}

void RanMaze(char maze[MAX_SIZE][MAX_SIZE], int k) {
	for (int i = 0; i < 10; i++) {
		maze[i][0] = '|';
		maze[i][9] = '|';
		maze[0][i] = '-';
		maze[9][i] = '-';
	}
	maze[9][0] = '-';
reset:
	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			//k=3 ����� ���̵��� ���� ������ 70%
			//k=2 ���� ���̵��� �� ������ 50%
			//k=1 ���� ���̵��� �� ������ 30%
			if (rand() % 100 >= 30 + (k-3) * -20) {
				maze[i][j] = '1';
			}
			else if (rand() % 100 < 10) {
				//�� 10���� Ȯ���� ��ź�ο�
				maze[i][j] = 'B';
			}
			else {
				maze[i][j] = '0';
			}

		}
	}
	maze[9][8] = 'x';
	maze[1][0] = 'E';
	if (CheckMaze(maze) == 0) {
		goto reset;
	}
}

void PrtMaze(char maze[MAX_SIZE][MAX_SIZE]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == 0 || i == 9) {
				printf("%c-", maze[i][j]);
			}
			else {
				printf("%c ", maze[i][j]);
			}
		}
		printf("\n");
	}
}

int Check_Ready() {//�����غ��۾�, �꼳��
	int n;
	int k;
	printf("������ �÷��� �Ͻ� �غ� �Ǽ̴ٸ� 1�� �Է����ּ��� : ");
	scanf("%d", &n);
	if (n == 1) {
		printf("������ �����մϴ�!\n");
		printf("--------Game Rule--------\n");
		printf("�����϶����� 1��, ��ź�� ������ -3���Դϴ�.\n");
		printf("�Դ����� �ǵ��ư��� �ൿ���� ������ �������� �ʽ��ϴ�!\n");
		printf("���ӳ��̵��� �������ּ���!\n");
		printf("1�ܰ�: (����) | 2�ܰ�: (����) | 3�ܰ�: (����)\n");
		scanf("%d", &k);
		printf("-------------------------\n");
		printf("10���� ������ ���۵˴ϴ�!\n");
		Sleep(10);
		for (int i = 10; i > 0; i--) {
			printf("%d ", i);
			Sleep(1000);
		}
		system("cls");
		return k;
	}
	else {
		printf("�÷����� �غ� ��ġ�ø� �ٽ� �������ּ���!");
		Sleep(3000);
		return 0;
	}
}

void up(GameData &gd) {
	if (gd.maze[gd.NowPos.r - 1][gd.NowPos.c] == '1' || gd.maze[gd.NowPos.r - 1][gd.NowPos.c] == '|' || gd.maze[gd.NowPos.r - 1][gd.NowPos.c] == '-') {//������?
		printf("�����ֽ��ϴ�.\n");
		return;
	}
	if (gd.maze[gd.NowPos.r - 1][gd.NowPos.c] == 'B') {//��ź�̸�?
		printf("��ź�� ��ҽ��ϴ�! 3�� ����!\n");
		gd.score -= 3;
	}
	gd.maze[gd.NowPos.r][gd.NowPos.c] = '0';
	gd.count++;
	gd.NowPos.r--;
	gd.score--;
}

void down(GameData &gd) {
	if (gd.maze[gd.NowPos.r + 1][gd.NowPos.c] == '1' || gd.maze[gd.NowPos.r + 1][gd.NowPos.c] == '|' || gd.maze[gd.NowPos.r + 1][gd.NowPos.c] == '-') {//������?
		printf("�����ֽ��ϴ�.\n");
		return;
	}
	if (gd.maze[gd.NowPos.r + 1][gd.NowPos.c] == 'B') {//��ź�̸�?
		printf("��ź�� ��ҽ��ϴ�! 3�� ����!\n");
		gd.score -= 3;
	}
	gd.maze[gd.NowPos.r][gd.NowPos.c] = '0';
	gd.count++;
	gd.NowPos.r++;
	gd.score--;
}

void left(GameData &gd) {
	if (gd.maze[gd.NowPos.r][gd.NowPos.c - 1] == '1' || gd.maze[gd.NowPos.r][gd.NowPos.c - 1] == '|' || gd.maze[gd.NowPos.r][gd.NowPos.c - 1] == '-') {//������?
		printf("�����ֽ��ϴ�.\n");
		return;
	}
	if (gd.maze[gd.NowPos.r][gd.NowPos.c - 1] == 'B') {//��ź�̸�?
		printf("��ź�� ��ҽ��ϴ�! 3�� ����!\n");
		gd.score -= 3;
	}
	gd.maze[gd.NowPos.r][gd.NowPos.c] = '0';
	gd.count++;
	gd.NowPos.c--;
	gd.score--;
}

void right(GameData &gd) {
	if (gd.maze[gd.NowPos.r][gd.NowPos.c + 1] == '1' || gd.maze[gd.NowPos.r][gd.NowPos.c + 1] == '|' || gd.maze[gd.NowPos.r][gd.NowPos.c + 1] == '-') {//������?
		printf("�����ֽ��ϴ�.\n");
		return;
	}
	if (gd.maze[gd.NowPos.r][gd.NowPos.c + 1] == 'B') {//��ź�̸�?
		printf("��ź�� ��ҽ��ϴ�! 3�� ����!\n");
		gd.score -= 3;
	}
	gd.maze[gd.NowPos.r][gd.NowPos.c] = '0';
	gd.count++;
	gd.NowPos.c++;
	gd.score--;
}

int main() {
	srand((unsigned)time(NULL));
	element Destination;
	Destination = { 9, 8 };
	GameData GD;
	int k;
	
	if (k = Check_Ready()) {
		GD.NowPos = { 1,0 };
		system("cls");
		RanMaze(GD.maze, k);
		GD.score = 100;
		GD.count = 0;
		while (GD.NowPos.r != 9 || GD.NowPos.c != 8) {//NowPos�� Destination�� �������� �ʾҴٸ� �ݺ�.
			GD.maze[GD.NowPos.r][GD.NowPos.c] = '.';
			PrtMaze(GD.maze);
			//������ ������ �Ÿ� ��� ���
			if (GD.score <= 0) {
				printf("Ż��!");
				break;
			}
			printf("���� : %d    ������ Ƚ�� : %d\n", GD.score, GD.count);
			//�ѹ��� ����Ű �Է¹ޱ�
			int key1, key2;
			key1 = _getch();
			key2 = _getch();
			system("cls");
			if (key1 == 224) {
				switch (key2) {
				case 72://��
					up(GD);
					break;
				case 80://��
					down(GD);
					break;
				case 75://��
					left(GD);
					break;
				case 77://��
					right(GD);
					break;
				}
			}
		}
		PrtMaze(GD.maze);
		printf("�����մϴ�! Ŭ���� �߾��!\n");
		printf("����� ���� : %d    �� ������ Ƚ�� : %d\n", GD.score, GD.count);
	}
}