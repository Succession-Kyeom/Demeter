#pragma once
#include <stdio.h>
#include <stdlib.h>

#include "structure.h"

//상태창 초기화
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

//스킬 트리 초기화
void SkillInit() {
	Skill skill[8] = { {FALSE, "도구함", "여러 장비를 보관할 수 있다!", "스킬 트리를 개방할 수 있다.", 5000},
					   {FALSE, "달구지", "밭을 더 쉽게 갈 수 있다!", "밭의 개수가 1개 추가된다.", 10000},
					   {FALSE, "할인쿠폰", "물건을 싸게 구매할 수 있다.", "PC창에서 구매하는 모든 상품(스킬 제외)이 5% 할인된다.", 15000},
					   {FALSE, "외양간", "동물을 더 많이 관리할 수 있다!", "동물 농장의 크기가 1 증가한다.", 10000},
					   {FALSE, "경운기", "밭을 어마어마하게 쉽게 갈 수 있다!", "밭의 개수가 1개 추가된다.", 25000},
					   {FALSE, "마네키네코", "수익이 늘어날 것 같은 기분이 든다!", "모든 메뉴의 가격이 500원 증가한다.", 30000},
					   {FALSE, "---", "---", "---", 0},
					   {FALSE, "외양간 확장", "동물을 더 많이 관리할 수 있다.", "동물 농장의 크기가 1 증가한다.", 25000} };
	for (int index = 0; index < 3; index++) {
		skillNode[index].left = &skillNode[index * 2 + 1];
		skillNode[index].skill = skill[index];
		skillNode[index].right = &skillNode[index * 2 + 2];
	}
	skillNode[3].left = &skillNode[7];
	skillNode[3].skill = skill[3];
	skillNode[3].right = NULL;
	for (int index = 4; index < 8; index++) {
		skillNode[index].left = NULL;
		skillNode[index].skill = skill[index];
		skillNode[index].right = NULL;
	}

	SkillTree skill8 = { NULL, skill[7], NULL }; //외양간 확장
	SkillTree skill7 = { NULL, skill[6], NULL }; //NULL
	SkillTree skill6 = { NULL, skill[5], NULL }; //마네키네코
	SkillTree skill5 = { NULL, skill[4], NULL }; //경운기
	SkillTree skill4 = { &skill8, skill[3], NULL }; //외양간
	SkillTree skill3 = { &skill6, skill[2], &skill7 }; //할인쿠폰
	SkillTree skill2 = { &skill4, skill[1], &skill5 }; //달구지
	SkillTree skill1 = { &skill2, skill[0], &skill3 }; //도구함

	skillTree = &skillNode[0];
}

