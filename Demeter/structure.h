#pragma once

typedef int ingredient;
typedef int bool;

//상태, 재료 구조체--
struct status {
	int day; int money; int income; //날짜, 보유 금액, 수익
	int egg; int milk; int pork; int compost;
	int cabbage; int tomato; int wheat; int corn;
}status;
//--

struct menu {
	char* name[8]; //메뉴 이름
	int cost[8]; //가격
}menu;

//주문서 리스트--
typedef struct Order {
	int orderNum; //주문 번호
	char* menu; //메뉴 이름
	int cost; //가격
}Order;

typedef struct List {
	struct List* prev;
	struct Order order;
	struct List* next;
}List;
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