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

//��ų �ʱ�ȭ
Skill skill[8] = {
					{FALSE, "������", "���� ������ ������ �� �ִ�!", "��ų Ʈ���� ����ȴ�", 5000},
					{FALSE, "�ޱ���", "���� �� ���� �� �� �ִ�!", "���� ������ 1�� �߰��ȴ�.", 10000},
					{FALSE, "��������", "������ �ΰ� ������ �� �ִ�.", "��� ��ǰ(��ų ����)�� 5% ���εȴ�.", 15000},
					{FALSE, "�ܾ簣", "������ �� ���� ������ �� �ִ�!", "���� ������ ũ�Ⱑ 1 �����Ѵ�.", 10000},
					{FALSE, "����", "���� ���ϰ� ���� �� �� �ִ�!", "���� ������ 1�� �߰��ȴ�.", 25000},
					{FALSE, "����Ű����", "������ �þ �� ���� ����� ���!", "��� �޴��� ������ 500�� �����Ѵ�.", 30000},
					{FALSE, "---", "---", "---", 0},
					{FALSE, "�ܾ簣 Ȯ��", "������ �� ���� ������ �� �ִ�.", "���� ������ ũ�Ⱑ 1 �����Ѵ�.", 25000}
};
//--

//���̺� ������--
//���̺� ���
typedef struct GameData {
	struct status status;
	struct Skill skill[8];
	int field[4];
	char* isPlant[4];
	int fence[3];
	char* isBreed[3];
	int last[3];
} GameData;

//��
typedef struct GameDataDeque{
	struct GameData data[MAX_DEQUE_SIZE];
	int front;
	int rear;
	int size;
} GameDataDeque;