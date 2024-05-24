#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

#include "control.h"
#include "structure.h"
#include "init.h"
#include "graphic.h"
#include "description.h"

//랜덤 함수(0 ~ degree - 1)
int random(int degree) {
	srand(time(NULL));

	return rand() % degree;
}

void GoStore() {
	int y = 0;
	int screen = 0; //PC 화면 인덱스
	char* color[4] = { NONE, NONE, NONE, NONE };

	system("cls");
	while (TRUE) {
		system("cls");
		color[y] = GREEN;
		PcOrder(screen, color);
		Status();
		switch (_getch()) {
		case UP:
			if (y > 0) {
				color[y] = NONE;
				y--;
			}
			break;
		case LEFT:
			screen = ((screen - 1) + 4) % 4;
			break;
		case RIGHT:
			screen = ((screen + 1) + 4) % 4;
			break;
		case DOWN:
			if (y < 3) {
				color[y] = NONE;
				y++;
			}
			break;
		case ENTER:
			
			break;
		case ESC:
			return;
		}
	}
}

//장사 시작 전(농장, PC)
void BeforeSales() {
	int x = 0;
	int y = 20;
	int mapKey = 0;

	system("cls");
	MapFarm();
	PlayerFront(x, y);

	while (TRUE) {
		if (26 <= x && x <= 44 && 24 <= y) {
			GoStore();
			system("cls");
			x = 36;
			y = 23;
			PlayerBack(x, y);
		}

		switch (mapKey) {
		case FARM:
			MapFarm();
			break;
		case ANIMAL:
			MapAnimal();
			break;
		}
		Status();

		if (mapKey == FARM && x >= 67 && 19 <= y && y <= 26) {
			mapKey = ANIMAL;
			x = 8;
			y = 25;
		}
		else if (mapKey == ANIMAL && x < 8 && 19 <= y) {
			mapKey = FARM;
			x = 62;
			y = 22;
		}

		switch (_getch()) {
		case UP:
			if (y > 17) {
				y--;
			}
			system("cls");
			PlayerBack(x, y);
			break;
		case LEFT:
			if (x > 0) {
				x--;
			}
			system("cls");
			PlayerLeft(x, y);
			break;
		case RIGHT:
			if (x < 74) {
				x++;
			}
			system("cls");
			PlayerRight(x, y);
			break;
		case DOWN:
			if (y < 26) {
				y++;
			}
			system("cls");
			PlayerFront(x, y);
			break;
		case ENTER:
			return;
			//break;
		}
	}
}

//주문 받기
Order getOrder(int customer) {
	int orderKey = rand() % 8;
	Order order;
	
	//랜덤 돌려서 메뉴 선택
	order.orderNum = customer;
	order.menu = menu.name[orderKey];
	order.cost = menu.cost[orderKey];

	return order;
}

//리스트에 주문 삽입
void InsertList(List* prev, Order order) {
	List* list = (List*)malloc(sizeof(List));

	list->order = order;
	list->prev = prev;
	list->next = prev->next;
	
	prev->next->prev = list;
	prev->next = list;
}

//장사 시작
void StartSales() {
	int max = (rand() % 6) + 5; //하루 최대 손님 수(5 ~ 10명)
	int sandwitch = rand() % 3;
	List* pick = (List*)malloc(sizeof(List));
	if (status.day == 1) { //첫 날만 3명 고정
		max = 3;
	}
	pick->prev = pick;
	pick->next = pick;

	system("cls");
	for (int customer = 1; customer <= max; customer++) {
		Store();
		Status();
		
		Order order = getOrder(customer);
		InsertList(pick, order);
	}

}

void GameStart() {
	while (TRUE) {
		BeforeSales();
		StartSales();

	}
}

void LoadData() {
	system("cls");
	while (!_kbhit()) {
		Load();
		}
}

int MainMenu() {
	int x = 34;
	int y = 16;
	int input = 0;

	while (TRUE) {
		system("cls");

		gotoXY(0, 0);
		Title();

		gotoXY(x, y);
		printf(">");
		switch (_getch()) {
		case UP:
			if (y > 16) {
				y -= 5;
			}
			break;
		case DOWN:
			if (y < 26) {
				y += 5;
			}
			break;
		case ENTER:
			if (y == 16) {
				return 1;
			}
			else if (y == 21) {
				return 2;
			}
			else {
				return 3;
			}
		}
	}
}

int main() {
	int x = 0;
	int y = 0;
	int roop = TRUE;
	int input = 0;

	//초기값 설정
	StatusInit();
	CursorView();
	MenuInit();
	srand(time(NULL));

	while (roop) {
		switch (MainMenu()) {
		case 1:
			GameStart();
			break;
		case 2:
			HowToPlay();
			break;
		case 3:
			LoadData();
			break;
		}
	}

	return 0;
}