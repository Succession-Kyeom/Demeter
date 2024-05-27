#pragma once

typedef int bool;

//상태, 재료 구조체--
struct status {
	int day; int money; //날짜, 보유 금액
	int* ingredient[3][4];
	int egg; int milk; int pork; int compost;
	int cabbage; int tomato; int wheat; int corn;
	int cow; int pig; int chicken;
}status;
//--

struct menu {
	char* name[8]; //메뉴 이름
	char* recipe[8]; //레시피
	int cost[8]; //가격
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

//주문서 리스트--
typedef struct Order {
	int orderNum; //주문 번호
	char* menu; //메뉴 이름
	char* recipe; //레시피
	int cost; //가격
}Order;

typedef struct List {
	struct List* prev;
	struct Order order;
	struct List* next;
}List;
//--

//스킬트리 구조체--
typedef struct Skill {
	bool isBought; //구매 여부
	char* name; //스킬명
	char* descript; //스킬 설명
	char* effect; //스킬 효과
	int money; //구매 비용
}Skill;

Skill* skill[8];
//--

//세이브 데이터--
typedef struct data {
	struct data* nextDay;
	struct status stat;
}Data;

typedef struct Save {
	struct data* latest;
}Save;
//--