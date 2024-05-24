#pragma once
#include <stdio.h>
#include <stdlib.h>

#include "structure.h"

//상태창 초기화
void StatusInit() {
	status.day = 1;
	status.money = 100000;
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
	SkillTree skillTree[8];

	
}