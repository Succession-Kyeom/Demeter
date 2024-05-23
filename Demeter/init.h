#pragma once
#include <stdio.h>
#include <stdlib.h>

#include "structure.h"

#define STORE_ROW 30
#define STORE_COL 80

//����â �ʱ�ȭ
void StatusInit() {
	status.day = 1;
	status.money = 1000;
	status.income = 0;
	
	status.egg = 99;
	status.milk = 99;
	status.pork = 99;
	status.cabbage = 99;
	status.tomato = 99;
	status.wheat = 99;
	status.corn = 99;
	status.compost = 99;
}

//�޴� �̸�, ����
void MenuInit() {
	menu.name[0] = "����Ķ���";
	menu.name[1] = "����";
	menu.name[2] = "������";
	menu.name[3] = "��";
	menu.name[4] = "�ް� �佺Ʈ";
	menu.name[5] = "���ڻ�";
	menu.name[6] = "������";
	menu.name[7] = "������ġ";

	menu.cost[0] = 2500;
	menu.cost[1] = 3500;
	menu.cost[2] = 5000;
	menu.cost[3] = 9000;
	menu.cost[4] = 12000;
	menu.cost[5] = 13000;
	menu.cost[6] = 13000;
	menu.cost[7] = 20000;
}