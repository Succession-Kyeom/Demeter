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

//스킬 초기화
Skill skill[8] = {
					{FALSE, "도구함", "여러 도구를 보관할 수 있다!", "스킬 트리가 개방된다", 5000},
					{FALSE, "달구지", "밭을 더 쉽게 갈 수 있다!", "밭의 개수가 1개 추가된다.", 10000},
					{FALSE, "할인쿠폰", "물건을 싸게 구매할 수 있다.", "모든 상품(스킬 제외)이 5% 할인된다.", 15000},
					{FALSE, "외양간", "동물을 더 많이 관리할 수 있다!", "동물 농장의 크기가 1 증가한다.", 10000},
					{FALSE, "경운기", "밭을 어마어마하게 쉽게 갈 수 있다!", "밭의 개수가 1개 추가된다.", 25000},
					{FALSE, "마네키네코", "수익이 늘어날 것 같은 기분이 든다!", "모든 메뉴의 가격이 500원 증가한다.", 30000},
					{FALSE, "---", "---", "---", 0},
					{FALSE, "외양간 확장", "동물을 더 많이 관리할 수 있다.", "동물 농장의 크기가 1 증가한다.", 25000}
};
//--

//세이브 데이터--
//세이브 노드
typedef struct GameData {
	struct status status;
	struct Skill skill[8];
	int field[4];
	char* isPlant[4];
	int fence[3];
	char* isBreed[3];
	int last[3];
} GameData;

//덱
typedef struct GameDataDeque{
	struct GameData data[MAX_DEQUE_SIZE];
	int front;
	int rear;
	int size;
} GameDataDeque;