#pragma once

typedef int ingredient;

//����, ��� ����ü
struct status {
	int day; int money; int income; //��¥, ���� �ݾ�, ����
	ingredient ingredient[8]; //0: �ް�, 1: ����, 2: �����, 3: �丶��, 4: ��, 5: ������, 6: ����, 7: ���
}status;

typedef struct frame {
	int** frame;
}Frame;

//�κ��丮 ����ü
typedef struct inventory {
	struct Inventory* prev;
	ingredient item;
	struct Inventory* next;
}Inventory;