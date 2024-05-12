#pragma once

typedef int ingredient;

//상태, 재료 구조체
struct status {
	int day; int money; int income; //날짜, 보유 금액, 수익
	ingredient ingredient[8]; //0: 달걀, 1: 우유, 2: 양상추, 3: 토마토, 4: 밀, 5: 옥수수, 6: 오이, 7: 비료
}status;

typedef struct frame {
	int** frame;
}Frame;

//인벤토리 구조체
typedef struct inventory {
	struct Inventory* prev;
	ingredient item;
	struct Inventory* next;
}Inventory;