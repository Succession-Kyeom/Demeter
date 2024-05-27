#pragma once

typedef int bool;

//����, ��� ����ü--
struct status {
	int day; int money; //��¥, ���� �ݾ�
	int* ingredient[3][4];
	int egg; int milk; int pork; int compost;
	int cabbage; int tomato; int wheat; int corn;
	int cow; int pig; int chicken;
}status;
//--

struct menu {
	char* name[8]; //�޴� �̸�
	char* recipe[8]; //������
	int cost[8]; //����
}menu;

struct account {
	int customer;
	int income;
	int menu[8];
	int cancel;
	int dDay;
}account;

typedef struct PC {
	char* item[4];
	int money[4];
}PC;

PC pc[3];

//�ֹ��� ����Ʈ--
typedef struct Order {
	int orderNum; //�ֹ� ��ȣ
	char* menu; //�޴� �̸�
	char* recipe; //������
	int cost; //����
}Order;

typedef struct List {
	struct List* prev;
	struct Order order;
	struct List* next;
}List;
//--

//��ųƮ�� ����ü--
typedef struct Skill {
	bool isBought; //���� ����
	char* name; //��ų��
	char* descript; //��ų ����
	char* effect; //��ų ȿ��
	int money; //���� ���
}Skill;

Skill* skill[8];
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