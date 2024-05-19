#pragma once
#include <stdio.h>
#include <stdlib.h>

#include "structure.h"

#define STORE_ROW 30
#define STORE_COL 80

//상태창 초기화
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

//메뉴 이름, 가격
void MenuInit() {
	menu.name[0] = "계란후라이";
	menu.name[1] = "팝콘";
	menu.name[2] = "베이컨";
	menu.name[3] = "빵";
	menu.name[4] = "달걀 토스트";
	menu.name[5] = "피자빵";
	menu.name[6] = "샐러드";
	menu.name[7] = "샌드위치";

	menu.cost[0] = 2500;
	menu.cost[1] = 3500;
	menu.cost[2] = 5000;
	menu.cost[3] = 9000;
	menu.cost[4] = 12000;
	menu.cost[5] = 13000;
	menu.cost[6] = 13000;
	menu.cost[7] = 20000;
}