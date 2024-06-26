#pragma once
#include <stdio.h>
#include <stdlib.h>

#include "structure.h"

//상태창 초기화
void StatusInit() {
	status.day = 1;
	status.money = 100000;
	
	status.egg = 99;
	status.milk = 99;
	status.pork = 99;
	status.cabbage = 99;
	status.tomato = 99;
	status.wheat = 99;
	status.corn = 99;
	status.compost = 99;

	//동물 수(스탯창엔 표기X)
	status.cow = 99;
	status.pig = 99;
	status.chicken = 99;

	//pc 구매창용 포인터 설정
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

	menu.recipe[0] = "달걀×1";
	menu.recipe[1] = "옥수수×1";
	menu.recipe[2] = "돼지고기×1";
	menu.recipe[3] = "밀×2, 우유×1";
	menu.recipe[4] = "밀×2, 우유×1, 달걀×1";
	menu.recipe[5] = "옥수수×1, 밀×1, 우유×1, 토마토×1";
	menu.recipe[6] = "옥수수×1, 토마토×1, 달걀×1, 양상추×1";
	menu.recipe[7] = "밀×1, 우유×1, 토마토×1, 돼지고기×1, 달걀×1, 양상추×1";

	menu.cost[0] = 2500;
	menu.cost[1] = 3500;
	menu.cost[2] = 5000;
	menu.cost[3] = 9000;
	menu.cost[4] = 12000;
	menu.cost[5] = 13000;
	menu.cost[6] = 13000;
	menu.cost[7] = 20000;
}

//매출 정산 초기화
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
	pc[0].item[0] = "달걀";
	pc[0].money[0] = 2000;
	pc[0].item[1] = "우유";
	pc[0].money[1] = 4000;
	pc[0].item[2] = "양상추";
	pc[0].money[2] = 3000;
	pc[0].item[3] = "토마토";
	pc[0].money[3] = 2000;

	pc[1].item[0] = "밀";
	pc[1].money[0] = 1500;
	pc[1].item[1] = "옥수수";
	pc[1].money[1] = 3000;
	pc[1].item[2] = "돼지고기";
	pc[1].money[2] = 4000;

	pc[2].item[0] = "돼지";
	pc[2].money[0] = 8000;
	pc[2].item[1] = "소";
	pc[2].money[1] = 9000;
	pc[2].item[2] = "닭";
	pc[2].money[2] = 8500;
}