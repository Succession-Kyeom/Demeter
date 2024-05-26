#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

#include "control.h"
#include "structure.h"
#include "init.h"
#include "graphic.h"
#include "description.h"
#include "preparation.h"

//주문 받기
Order getOrder(int customer) {
	Order order;
	int probability = rand() % 100;

	//랜덤 돌려서 메뉴 선택
	order.orderNum = customer;
	if (0 <= probability && probability <= 19) {
		order.menu = menu.name[0];
		order.cost = menu.cost[0];
		order.recipe = menu.recipe[0];
	}
	else if (20 <= probability && probability <= 39) {
		order.menu = menu.name[1];
		order.cost = menu.cost[1];
		order.recipe = menu.recipe[1];
	}
	else if (40 <= probability && probability <= 54) {
		order.menu = menu.name[2];
		order.cost = menu.cost[2];
		order.recipe = menu.recipe[2];
	}
	else if (55 <= probability && probability <= 69) {
		order.menu = menu.name[3];
		order.cost = menu.cost[3];
		order.recipe = menu.recipe[3];
	}
	else if (70 <= probability && probability <= 79) {
		order.menu = menu.name[4];
		order.cost = menu.cost[4];
		order.recipe = menu.recipe[4];
	}
	else if (80 <= probability && probability <= 89) {
		order.menu = menu.name[5];
		order.cost = menu.cost[5];
		order.recipe = menu.recipe[5];
	}
	else if (90 <= probability && probability <= 94) {
		order.menu = menu.name[6];
		order.cost = menu.cost[6];
		order.recipe = menu.recipe[6];
	}
	else if (95 <= probability && probability <= 99) {
		order.menu = menu.name[7];
		order.cost = menu.cost[7];
		order.recipe = menu.recipe[7];
	}

	return order;
}

//리스트에 주문 삽입
void InsertList(List* prev, Order order) {
	List* list = (List*)malloc(sizeof(List));

	list->order = order;
	list->next = prev->next;
	list->prev = prev;

	prev->next->prev = list;
	prev->next = list;
}

void DeleteList(List* prev, List* removed) {
	removed->prev->next = removed->next;
	removed->next->prev = removed->prev;
	
	free(removed);
}

//주문서 수 확인
int CountList(List* pick) {
	int count = 0;
	for (List* p = pick->next; p != pick; p = p->next) {
		count++;
	}
	return count;
}

void SaleFail() {
	printf("%s제작 실패...%s", RED, NONE);
	account.income -= 1500;
	account.cancel++;
	Sleep(1000);
}

void Sale(List* pick, int index) {
	List* list = pick->next;
	for (int i = 0; i < index; i++) {
		list = list->next;
	}
	gotoXY(1, 26);
	if (!strcmp(list->order.menu, "계란후라이")) {
		if (status.egg >= 1) {
			printf("%s제작 완료!%s", GREEN, NONE);
			status.egg -= 1;
			account.income += menu.cost[0];
			account.menu[0]++;
			Sleep(1000);
		}
		else {
			SaleFail();
		}
	}
	else if (!strcmp(list->order.menu, "팝콘")) {
		if (status.corn >= 1) {
			printf("%s제작 완료!%s", GREEN, NONE);
			status.corn -= 1;
			account.income += menu.cost[1];
			account.menu[1]++;
			Sleep(1000);
		}
		else {
			SaleFail();
		}
	}
	else if (!strcmp(list->order.menu, "베이컨")) {
		if (status.pork >= 1) {
			printf("%s제작 완료!%s", GREEN, NONE);
			status.pork -= 1;
			account.income += menu.cost[2];
			account.menu[2]++;
			Sleep(1000);
		}
		else {
			SaleFail();
		}
	}
	else if (!strcmp(list->order.menu, "빵")) {
		if (status.wheat >= 2 && status.milk >= 1) {
			printf("%s제작 완료!%s", GREEN, NONE);
			status.wheat -= 2;
			status.milk -= 1;
			account.income += menu.cost[3];
			account.menu[3]++;
			Sleep(1000);
		}
		else {
			SaleFail();
		}
	}
	else if (!strcmp(list->order.menu, "달걀 토스트")) {
		if (status.wheat >= 2 && status.milk >= 1 && status.egg >= 1) {
			printf("%s제작 완료!%s", GREEN, NONE);
			status.wheat -= 2;
			status.milk -= 1;
			status.egg -= 1;
			account.income += menu.cost[4];
			account.menu[4]++;
			Sleep(1000);
		}
		else {
			SaleFail();
		}
	}
	else if (!strcmp(list->order.menu, "피자빵")) {
		if (status.corn >= 1 && status.wheat >= 1 && status.milk >= 1 && status.tomato >= 1) {
			printf("%s제작 완료!%s", GREEN, NONE);
			status.corn -= 1;
			status.wheat -= 1;
			status.milk -= 1;
			status.tomato -= 1;
			account.income += menu.cost[5];
			account.menu[5]++;
			Sleep(1000);
		}
		else {
			SaleFail();
		}
	}
	else if (!strcmp(list->order.menu, "샐러드")) {
		if (status.corn >= 1 && status.tomato >= 1 && status.egg >= 1 && status.cabbage >= 1) {
			printf("%s제작 완료!%s", GREEN, NONE);
			status.corn -= 1;
			status.tomato -= 1;
			status.egg -= 1;
			status.cabbage -= 1;
			account.income += menu.cost[6];
			account.menu[6]++;
			Sleep(1000);
		}
		else {
			SaleFail();
		}
	}
	else if (!strcmp(list->order.menu, "샌드위치")) {
		if (status.wheat >= 1 && status.milk >= 1 && status.tomato >= 1 && status.pork >= 1 && status.egg >= 1 && status.cabbage >= 1) {
			printf("%s제작 완료!%s", GREEN, NONE);
			status.wheat -= 1;
			status.milk -= 1;
			status.tomato -= 1;
			status.pork -= 1;
			status.egg -= 1;
			status.cabbage -= 1;
			account.income += menu.cost[7];
			account.menu[7]++;
			Sleep(1000);
		}
		else {
			SaleFail();
		}
	}
	DeleteList(pick, list);
}

//장사 시작
void StartSales() {
	int index = 0;
	int count = 0;
	int max = (rand() % 6) + 5; //하루 최대 손님 수(5 ~ 10명)
	List* pick = (List*)malloc(sizeof(List));
	if (status.day == 1) { //첫 날만 3명 고정
		max = 3;
	}
	AccountInit();
	account.customer = max;

	pick->prev = pick;
	pick->next = pick;

	for (int customer = max; customer >= 1; customer--) {		
		Order order = getOrder(customer);
		InsertList(pick, order);
	}
	while (pick->next != pick) {
		system("cls");
		count = CountList(pick);
		Store(pick, index);
		Status();
		switch (_getch()) {
		case LEFT:
			if (index > 0) {
				index--;
			}
			break;
		case RIGHT:
			if (count >= 4) {
				count = 4;
			}
			count--;
			if (index < count) {
				index++;
			}
			break;
		case ENTER:
			Sale(pick, index);
			if (index == count - 1) {
				index--;
			}
			break;
		}
	}
}

void AfterSales() {
	int input = 0;

	system("cls");
	while (!input) {
		StoreClose();
		input = _getch();
	}
	input = 0;
	system("cls");
	while (!input) {
		StoreCal();
		input = _getch();
	}
	status.money += account.income;
}

bool PayTax() {
	if (status.money >= 50000) {
		status.money -= 50000;
		return TRUE;
	}
	else {
		return FALSE;
	}
}

void GameStart() {
	bool roop = TRUE;

	while (roop) {
		BeforeSales();
		StartSales();
		AfterSales();
		if (account.dDay == 0) {
			roop = PayTax();
		}
		status.day++;
	}
	system("cls");
	do {
		BadEnd();
	} while (!_getch());
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
	PcInit();
	MenuInit();
	SkillInit();
	CursorView(FALSE);
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