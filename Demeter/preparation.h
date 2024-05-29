#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

#include "control.h"
#include "structure.h"
#include "init.h"
#include "graphic.h"

int field[4] = { 0, 0, 0, 0 };

bool GoStore() {
	int y = 0;
	int screen = 0; //PC 화면 인덱스
	int input = 0; //buy
	int cost = 0;
	int index = 19;
	bool roop = TRUE;
	char* color[4] = { NONE, NONE, NONE, NONE };

	system("cls");
	while (roop) {
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
			screen = ((screen - 1) + 5) % 5;
			if ((screen == 1 || screen == 2) && y == 3) {
				color[y] = NONE;
				y--;
			}
			break;
		case RIGHT:
			screen = ((screen + 1) + 5) % 5;
			if ((screen == 1 || screen == 2) && y == 3) {
				color[y] = NONE;
				y--;
			}
			break;
		case DOWN:
			if (screen == 1 || screen == 2) {
				if (y < 2) {
					color[y] = NONE;
					y++;
				}
			}
			else {
				if (y < 3) {
					color[y] = NONE;
					y++;
				}
			}
			break;
		case ENTER:
			//재료 구매창일 때
			if (screen < 3) {
				system("cls");
				PcPur(screen, y);
				gotoXY(23, 15);
				CursorView(TRUE);
				scanf("%d", &input);
				CursorView(FALSE);
				//input 개수가 5이상이면 할인
				if (input >= 5) {
					cost = (int)pc[screen].money[y] * input * 0.95;
				}
				else {
					cost = pc[screen].money[y] * input;
				}

				//보유한 돈이 더 많으면 구매
				if (status.money >= cost) {
					status.money -= cost;
					*status.ingredient[screen][y] += input;
				}
			}
			//스킬 창일 때
			else if (screen == 3) {
				if (y == 0 && skill[y].isBought == FALSE) {
					if (status.money >= skill[y].money) {
						skill[y].isBought = TRUE;
						status.money -= skill[y].money;
					}
					else {
						color[y] = RED;
						system("cls");
						PcOrder(screen, color);
						Status();
						Sleep(1000);
						color[y] = GREEN;
					}
				}
				else if (skill[(y - (y % 2 == 0 ? 2 : 1)) / 2].isBought == TRUE) {
					if (skill[y].isBought == FALSE && status.money >= skill[y].money) {
							skill[y].isBought = TRUE;
							status.money -= skill[y].money;
					}
					else {
						color[y] = RED;
						system("cls");
						PcOrder(screen, color);
						Status();
						Sleep(1000);
						color[y] = GREEN;
					}
				}
				else {
					color[y] = RED;
					system("cls");
					PcOrder(screen, color);
					Status();
					Sleep(1000);
					color[y] = GREEN;
				}
			}
			else {
				int y2 = y + 4;
				if(skill[(y2 - (y2 % 2 == 0 ? 2 : 1)) / 2].isBought == TRUE) {
					if (skill[y2].isBought == FALSE && status.money >= skill[y2].money) {
						skill[y2].isBought = TRUE;
						status.money -= skill[y2].money;
					}
					else {
						color[y] = RED;
						system("cls");
						PcOrder(screen, color);
						Status();
						Sleep(1000);
						color[y] = GREEN;
					}
				}
				else {
					color[y] = RED;
					system("cls");
					PcOrder(screen, color);
					Status();
					Sleep(1000);
					color[y] = GREEN;
				}
			}
			break;
		case ESC:
			color[y] = NONE;
			while (roop) {
				system("cls");
				gotoXY(65, index);
				printf(">");
				PcOrder(screen, color);
				Status();
				switch (_getch()) {
				case UP:
					index = 19;
					break;
				case DOWN:
					index = 22;
					break;
				case ENTER:
					if (index == 19) {
						return TRUE;
					}
					else {
						return FALSE;
					}
					break;
				case ESC:
					roop = FALSE;
				}
			}
			roop = TRUE;
			break;
		}
	}
}

void SetPcCost(bool coupon) {
	if (coupon == TRUE) {
		pc[0].money[0] = 1900;
		pc[0].money[1] = 3800;
		pc[0].money[2] = 2850;
		pc[0].money[3] = 1900;

		pc[1].money[0] = 1425;
		pc[1].money[1] = 2850;
		pc[1].money[2] = 3800;

		pc[2].money[0] = 7600;
		pc[2].money[1] = 8550;
		pc[2].money[2] = 8075;
	}
}

void SetMenuCost(bool manekineko) {
	if (manekineko == TRUE) {
		menu.cost[0] = 3000;
		menu.cost[1] = 4000;
		menu.cost[2] = 5500;
		menu.cost[3] = 9500;
		menu.cost[4] = 12500;
		menu.cost[5] = 13500;
		menu.cost[6] = 13500;
		menu.cost[7] = 20500;
	}
}

int PlantIngredient(int x, int y) {
	int index = 0;

	while (TRUE) {
		system("cls");
		MapFarm();
		Status();
		PlayerBack(x, y);
		Plant();
		gotoXY(1 + index * 20, 27);
		printf("▷");
		switch (_getch()) {
		case LEFT:
			if (index > 0) {
				index--;
			}
			break;
		case RIGHT:
			if (index < 3) {
				index++;
			}
			break;
		case ENTER:
			return index;
		}
	}
}

//장사 시작 전(농장, PC)
void BeforeSales() {
	int x = 0;
	int y = 20;
	int mapKey = 0;
	bool roop = TRUE;

	system("cls");
	MapFarm();
	PlayerFront(x, y);

	SetPcCost(skill[2].isBought);
	SetMenuCost(skill[5].isBought);
	while (roop) {
		if (26 <= x && x <= 44 && 24 <= y) {
			roop = GoStore();
			if (roop == FALSE) {
				return;
			}
			system("cls");
			x = 36;
			y = 23;
			PlayerBack(x, y);
		}

		switch (mapKey) {
		case FARM:
			MapFarm();
			FarmPortal();
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
			if (mapKey == FARM) {
				if ((x == 5 || x == 18) && y == 17) {
					switch (PlantIngredient(x, y)) {
					case 0:
						if (status.cabbage > 0) {
							status.cabbage--;
							Sprout(0);
						}
					}
				}
				else if (x == 31 && y == 17 && skill[1].isBought == TRUE) {
					switch (PlantIngredient(x, y)) {

					}
				}
				else if (x == 44 && y == 17 && skill[4].isBought == TRUE) {
					system("cls");
					MapFarm();
					Status();
					PlayerBack(x, y);
					Plant();
					_getch();
				}
			}
			break;
		}
	}
}