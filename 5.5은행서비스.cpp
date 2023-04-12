#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "queue.h"

int main() {
	QueueType queue;
	int sec = 60; //���翡���� min���� ��.
	int total_wait = 0;
	int service_time = 0;
	int service_customer;
	int total_customer = 0;

	init_queue(&queue);
	srand((unsigned)time(NULL));
	for (int clock = 0; clock < sec; clock++) {
		Sleep(1000);
		printf("����ð� = %d\n", clock);
		if (rand() % 10 < 3) { // ������� 
			
			element customer;
			customer.id = total_customer++;
			customer.arrival_time = clock;
			customer.service_time = rand() % 3 + 1;
			enqueue(&queue, customer);
			service_customer = customer.id;
			printf("�� ��ȣ %d���� %d�ʿ� ���ɴϴ�. ����ó���ð� = %d��\n", customer.id, customer.arrival_time, customer.service_time);
		}
		if (service_time > 1) { //���������� ��������.
			printf("�� %d ����ó�����Դϴ�.\n", service_customer);
			service_time--;
		}
		else {
			if (!is_empty(&queue)) {
				element customer = dequeue(&queue);
				service_customer = customer.id; //�������� �ο��� ���� �� �ٷ� ������ �� �� �ְ� ���ش�.
				service_time = customer.service_time;
				printf("�� %d���� %d�ʿ� ������ �����մϴ�. ���ð��� %d���Դϴ�.\n", customer.id, clock, clock - customer.arrival_time);
				total_wait += clock - customer.arrival_time;
			}
		}
	}
	printf("��ü ���ð� = %d��\n", total_wait);
	return 0;
}