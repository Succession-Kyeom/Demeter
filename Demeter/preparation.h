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
	int screen = 0; //PC ȭ�� �ε���
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
			//��� ����â�� ��
			if (screen < 3) {
				system("cls");
				PcPur(screen, y);
				gotoXY(23, 15);
				CursorView(TRUE);
				scanf("%d", &input);
				CursorView(FALSE);
				//input ������ 5�̻��̸� ����
				if (input >= 5) {
					cost = (int)pc[screen].money[y] * input * 0.95;
				}
				else {
					cost = pc[screen].money[y] * input;
				}

				//������ ���� �� ������ ����
				if (status.money >= cost) {
					status.money -= cost;
					*status.ingredient[screen][y] += input;
				}
			}
			//��ų â�� ��
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

void SetCost(bool coupon) {
	if (coupon == TRUE) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				pc[i].money[j] *= 0.95;
			}
		}
	}
}

void SetMenu(bool manekineko) {
	if (manekineko == TRUE) {
		for (int index = 0; index < 8; index++) {
			menu.cost[index] -= 500;
		}
	}
}

//��� ���� ��(����, PC)
void BeforeSales() {
	int x = 0;
	int y = 20;
	int mapKey = 0;
	bool roop = TRUE;

	SetCost(skill[2].isBought);
	SetMenu(skill[5].isBought);
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
				if ((x == 5 || x == 18) && y == 17) {
					Plant();
				}
				else if (x == 31 && y == 17 && skill[1].isBought == TRUE) {
					Plant();
				}
				else if (x == 44 && y == 17 && skill[4].isBought == TRUE) {
					Plant();
				}
			}
			break;
		}
	}
}