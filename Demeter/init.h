#pragma once
#include <stdio.h>
#include <stdlib.h>

#include "structure.h"

//����â �ʱ�ȭ
void StatusInit() {
	status.day = 1;
	status.money = 10000;
	
	status.egg = 99;
	status.milk = 99;
	status.pork = 99;
	status.cabbage = 99;
	status.tomato = 99;
	status.wheat = 99;
	status.corn = 99;
	status.compost = 99;

	//���� ��(����â�� ǥ��X)
	status.cow = 99;
	status.pig = 99;
	status.chicken = 99;

	//pc ����â�� ������ ����
	status.ingredient[0][0] = &status.egg;
	status.ingredient[0][1] = &status.milk;
	status.ingredient[0][2] = &status.cabbage;
	status.ingredient[0][3] = &status.tomato;
	
	status.ingredient[1][0] = &status.wheat;
	status.ingredient[1][1] = &status.corn;
	status.ingredient[1][2] = &status.pork;

	status.ingredient[2][0] = &status.pig;
	status.ingredient[2][1] = &status.cow;
	status.ingredient[2][2] = &status.chicken;
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

	menu.recipe[0] = "�ް���1";
	menu.recipe[1] = "��������1";
	menu.recipe[2] = "������⡿1";
	menu.recipe[3] = "�С�2, ������1";
	menu.recipe[4] = "�С�2, ������1, �ް���1";
	menu.recipe[5] = "��������1, �С�1, ������1, �丶�䡿1";
	menu.recipe[6] = "��������1, �丶�䡿1, �ް���1, ����ߡ�1";
	menu.recipe[7] = "�С�1, ������1, �丶�䡿1, ������⡿1, �ް���1, ����ߡ�1";

	menu.cost[0] = 2500;
	menu.cost[1] = 3500;
	menu.cost[2] = 5000;
	menu.cost[3] = 9000;
	menu.cost[4] = 12000;
	menu.cost[5] = 13000;
	menu.cost[6] = 13000;
	menu.cost[7] = 20000;
}

//���� ���� �ʱ�ȭ
void AccountInit() {
	account.customer = 0;
	account.income = 0;
	account.cancel = 0;
	for (int index = 0; index < 8; index++) {
		account.menu[index] = 0;
	}
	account.dDay = (status.day % 5 == 0) ? 0 : 5 - status.day % 5;
}

void PcInit() {
	pc[0].item[0] = "�ް�";
	pc[0].money[0] = 2000;
	pc[0].item[1] = "����";
	pc[0].money[1] = 4000;
	pc[0].item[2] = "�����";
	pc[0].money[2] = 3000;
	pc[0].item[3] = "�丶��";
	pc[0].money[3] = 2000;

	pc[1].item[0] = "��";
	pc[1].money[0] = 1500;
	pc[1].item[1] = "������";
	pc[1].money[1] = 3000;
	pc[1].item[2] = "�������";
	pc[1].money[2] = 4000;

	pc[2].item[0] = "����";
	pc[2].money[0] = 8000;
	pc[2].item[1] = "��";
	pc[2].money[1] = 9000;
	pc[2].item[2] = "��";
	pc[2].money[2] = 8500;
}

//��ų Ʈ�� �ʱ�ȭ
Skill** SkillInit() {/*
	Skill* skill[8] = {{FALSE, "������", "���� ��� ������ �� �ִ�!", "��ų Ʈ���� ������ �� �ִ�.", 5000},
					{FALSE, "�ޱ���", "���� �� ���� �� �� �ִ�!", "���� ������ 1�� �߰��ȴ�.", 10000},
					{FALSE, "��������", "������ �ΰ� ������ �� �ִ�.", "PCâ���� �����ϴ� ��� ��ǰ(��ų ����)�� 5% ���εȴ�.", 15000},
					{FALSE, "�ܾ簣", "������ �� ���� ������ �� �ִ�!", "���� ������ ũ�Ⱑ 1 �����Ѵ�.", 10000},
					{FALSE, "����", "���� ���ϰ� ���� �� �� �ִ�!", "���� ������ 1�� �߰��ȴ�.", 25000},
					{FALSE, "����Ű����", "������ �þ �� ���� ����� ���!", "��� �޴��� ������ 500�� �����Ѵ�.", 30000},
					{FALSE, "---", "---", "---", 0},
					{FALSE, "�ܾ簣 Ȯ��", "������ �� ���� ������ �� �ִ�.", "���� ������ ũ�Ⱑ 1 �����Ѵ�.", 25000} };

	return skill;*/
}

