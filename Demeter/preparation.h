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
			screen = ((screen - 1) + 4) % 4;
			break;
		case RIGHT:
			screen = ((screen + 1) + 4) % 4;
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
			system("cls");
			PcPur(screen, y);
			gotoXY(23, 15);
			CursorView(TRUE);
			scanf("%d", &input);
			CursorView(FALSE);
			if (input >= 5) {
				cost = (int)pc[screen].money[y] * input * 0.95;
			}
			else {
				cost = pc[screen].money[y] * input;
			}

			if (status.money >= cost) {
				status.money -= cost;
				*status.ingredient[screen][y] += input;
				//스탯 변화 출력
			}
			break;
		case ESC:
			color[y] = NONE; //
			//system("cls");
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

//장사 시작 전(농장, PC)
void BeforeSales() {
	int x = 0;
	int y = 20;
	int mapKey = 0;
	bool roop = TRUE;

	system("cls");
	MapFarm();
	PlayerFront(x, y);

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
				//if
			}
			break;
		}
	}
}