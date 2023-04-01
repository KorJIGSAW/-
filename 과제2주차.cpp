#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct com {
	double x;
	double y;
};

struct com sum(struct com complex1, struct com complex2) {
	struct com complex3;
	complex3.x = complex1.x + complex2.x;
	complex3.y = complex1.y + complex2.y;

	return complex3;
}

struct com sub(struct com complex1, struct com complex2) {
	struct com complex3;
	complex3.x = complex1.x - complex2.x;
	complex3.y = complex1.y - complex2.y;

	return complex3;
}

struct com mul(struct com complex1, struct com complex2) {
	struct com complex3;
	complex3.x = complex1.x * complex2.x - complex1.y * complex2.y;
	complex3.y = complex1.y * complex2.x + complex1.x * complex2.y;

	return complex3;
}

struct com div(struct com complex1, struct com complex2) {
	struct com complex3;
	//mother�� ���Ҽ��� ������ ������ �и�
	//(complex2.x + complex2.yi)�и� (complex2.x - complex2.yi)�� �������鼭
	//�и�� (complex2.x)^2 - (complex2.y)^2�� �ȴ�.
	double mother = (complex2.x) * (complex2.x) + (complex2.y) * (complex2.y);
	//���ڴ� �и��� �ӷ����Ҽ��� ���������Ƿ�
	//(complex1.x + complex1.yi) * (complex2.x - complex2.yi)�� �ȴ�.
	complex3.x = (complex1.x * complex2.x + complex1.y * complex2.y) / mother;
	complex3.y = (complex1.y * complex2.x - complex1.x * complex2.y) / mother;

	return complex3;
}

void print(struct com complex3) {
	if (complex3.x == 0 && complex3.y != 0) {
		printf("%lfi\n", complex3.y);
	}
	else if (complex3.x != 0 && complex3.y != 0) {
		if (complex3.y > 0) {
			printf("%lf +%lfi\n", complex3.x, complex3.y);
		}
		else {
			printf("%lf %lfi\n", complex3.x, complex3.y);
		}
	}
	else if (complex3.x != 0 && complex3.y == 0) {
		printf("%lf\n", complex3.x);
	}
}

int main() {
	struct com complex1;
	struct com complex2;
	struct com complex3;
	int num;
	while (1) {
		printf("***���Ҽ� ����***\n");
		printf("1. ������ �Է�\n");
		printf("2. ���Ҽ� ����\n");
		printf("3. ���Ҽ� ����\n");
		printf("4. ���Ҽ� ����\n");
		printf("5. ���Ҽ� ������\n");
		printf("6. ���α׷� ����\n\n");
		printf("���۾��� ��ȣ�� �Է� >> ");
		scanf("%d", &num);

		if (num == 1) {
			scanf("%lf", &complex1.x);
			scanf("%lf", &complex1.y);
			scanf("%lf", &complex2.x);
			scanf("%lf", &complex2.y);
		}
		else if (num == 2) {
			complex3 = sum(complex1, complex2);
			print(complex3);
		}
		else if (num == 3) {
			complex3 = sub(complex1, complex2);
			print(complex3);
		}
		else if (num == 4) {
			complex3 = mul(complex1, complex2);
			print(complex3);
		}
		else if (num == 5) {
			complex3 = div(complex1, complex2);
			print(complex3);
		}
		else if (num == 6) {
			break;
		}
	}
}