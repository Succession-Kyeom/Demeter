#pragma once

typedef int ingredient;
typedef int bool;

//����, ��� ����ü--
struct status {
	int day; int money; int income; //��¥, ���� �ݾ�, ����
	int egg; int milk; int pork; int compost;
	int cabbage; int tomato; int wheat; int corn;
}status;
//--

struct menu {
	char* name[8]; //�޴� �̸�
	int cost[8]; //����
}menu;

//�ֹ��� ����Ʈ--
typedef struct Order {
	int orderNum; //�ֹ� ��ȣ
	char* menu; //�޴� �̸�
	int cost; //����
}Order;

typedef struct List {
	struct List* prev;
	struct Order order;
	struct List* next;
}List;
//--

//���̺� ������--
typedef struct data {
	struct data* nextDay;
	struct status stat;
}Data;

typedef struct Save {
	struct data* latest;
}Save;
//--