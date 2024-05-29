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

//ä�� ���� ��������
int field[4] = { 0, 0, 0, 0 }; //ä�� ���� ĭ �� ����� ����
char* isPlant[4] = { GREEN, GREEN, RED, RED }; //GREEN: �Ĺ� �ɱ� ����, RED: ���� �ȵ�, YELLO: �Ĺ� �ڶ�� ��, BLUE: �Ĺ� ��� ����

//���� ���� ��������
int fence[3] = { 0, 0, 0 }; //���� ���� ĭ �� ����(0: ����, 1: ��, 2: ����, 3: ��)
char* isBreed[3] = { GREEN, RED, RED }; //GREEN: ���� ����, RED: ���� �ȵ�, NONE: ������, BLUE: ��� ���� ����
int last[3] = { 0, 0, 0 }; //���� ���� ��

//PC ȭ��
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
				//��ũ�� �缳��
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

				//������ ���� �� ������ input��ŭ ����
				if (status.money >= cost) {
					status.money -= cost;
					*status.ingredient[screen][y] += input;
				}
			}
			//��ų â�� ��
			else if (screen == 3) {
				//������ ���(��Ʈ ����̹Ƿ� ������ ���)
				if (y == 0 && skill[y].isBought == FALSE) {
					if (status.money >= skill[y].money) { //���� �ݾ��� �� ���� �� ����
						skill[y].isBought = TRUE;
						status.money -= skill[y].money;
					}
					else { //�ƴ� ��� ���� �Ұ�
						color[y] = RED;
						system("cls");
						PcOrder(screen, color);
						Status();
						Sleep(1000);
						color[y] = GREEN;
					}
				}
				//�θ� ��� ���� ���� Ȯ�� �� ���� ����
				else if (skill[(y - (y % 2 == 0 ? 2 : 1)) / 2].isBought == TRUE) {
					if (skill[y].isBought == FALSE && status.money >= skill[y].money) { //���� �ݾ��� �� ���� �� ����
							skill[y].isBought = TRUE;
							status.money -= skill[y].money;
							//�ޱ��� ���� �� �� �߰�
							if (y == 1) {
								isPlant[2] = GREEN;
							}
							else if (y == 3) {
								isBreed[1] = GREEN;
							}
					}
					else { //�ߺ� ���� �� �ݾ� ������ ���� �Ұ�
						color[y] = RED;
						system("cls");
						PcOrder(screen, color);
						Status();
						Sleep(1000);
						color[y] = GREEN;
					}
				}
				//�θ� ��� ���� FALSE�� ���(??? ����) ���� �Ұ�
				else {
					color[y] = RED;
					system("cls");
					PcOrder(screen, color);
					Status();
					Sleep(1000);
					color[y] = GREEN;
				}
			}
			//��ų 2��° â
			else {
				int y2 = y + 4;
				if(skill[(y2 - (y2 % 2 == 0 ? 2 : 1)) / 2].isBought == TRUE) {
					if (skill[y2].isBought == FALSE && status.money >= skill[y2].money) {
						skill[y2].isBought = TRUE;
						status.money -= skill[y2].money;
						//�ܾ簣 ���� �� �� �߰�
						if (y2 == 0) {
							isPlant[3] = GREEN;
						}
						else if (y2 == 7) {
							isBreed[2] = GREEN;
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

//"���� ����" ���� �� PCǰ�� ����
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

//"����Ű����" ���� �� �޴� ���� ���
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

//ä�� ���۹� ���
void Field(int* field) {
	for (int index = 0; index < 4; index++) {
		if (field[index] == CABBAGE_SEED || field[index] == TOMATO_SEED || field[index] == WHEAT_SEED || field[index] == CORN_SEED) {
			Sprout(index);
		}
		else if (field[index] == CABBAGE) {
			Lettuce(index);
		}
		else if (field[index] == TOMATO) {
			Tomato(index);
		}
		else if (field[index] == WHEAT) {
			Wheat(index);
		}
		else if (field[index] == CORN) {
			Corn(index);
		}
	}
}

//ä�� ���� ����(0: �����, 1: �丶��, 2: ��, 3: ������)
int PlantIngredient(int x, int y) {
	int index = 0;

	while (TRUE) {
		system("cls");
		MapFarm(isPlant);
		Status();
		Field(field);
		PlayerBack(x, y);
		Plant();
		gotoXY(1 + index * 20, 27);
		printf("��");
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

void UseCompost(int* ingredient, char** color, int x, int y) {
	int x2 = 0;

	while (TRUE) {
		system("cls");
		MapFarm(isPlant);
		Status();
		Field(field);
		PlayerBack(x, y);
		Poo();

		gotoXY(21 + x2 * 20, 27);
		printf("��");

		switch (_getch()) {
		case LEFT:
			if (x2 > 0) {
				x2--;
			}
			break;
		case RIGHT:
			if (x2 < 1) {
				x2++;
			}
			break;
		case ENTER:
			if (x2 == 0 && status.compost > 0) {
				status.compost--;
				*color = BLUE;
				switch (*ingredient) {
				case CABBAGE_SEED:
					*ingredient = CABBAGE;
					return;
				case TOMATO_SEED:
					*ingredient = TOMATO;
					return;
				case WHEAT_SEED:
					*ingredient = WHEAT;
					return;
				case CORN_SEED:
					*ingredient = CORN;
					return;
				}
			}
			else {
				return;
			}
		}
	}
}

//���۹� ���
void Cultivation(int index) {
	int get = rand() % 100 + 1;
	if (field[index] == CABBAGE) {
		if (1 <= get && get <= 10) {
			status.cabbage += 1;
		}
		else if (11 <= get && get <= 70) {
			status.cabbage += 2;
		}
		else {
			status.cabbage += 3;
		}
	}
	else if (field[index] == TOMATO) {
		if (1 <= get && get <= 30) {
			status.tomato += 1;
		}
		else if (31 <= get && get <= 80) {
			status.tomato += 2;
		}
		else {
			status.tomato += 3;
		}
	}
	else if (field[index] == WHEAT) {
		if (1 <= get && get <= 20) {
			status.wheat += 1;
		}
		else if (21 <= get && get <= 60) {
			status.wheat += 2;
		}
		else {
			status.wheat += 3;
		}
	}
	else if (field[index] == CORN) {
		if (1 <= get && get <= 30) {
			status.corn += 1;
		}
		else if (31 <= get && get <= 90) {
			status.corn += 2;
		}
		else {
			status.corn += 3;
		}
	}
	field[index] = GROUND;
	isPlant[index] = GREEN;
}

//���� ���
void Place(int* fence) {
	for (int index = 0; index < 3; index++) {
		if (fence[index] == COW) {
			Cow(index);
		}
		else if (fence[index] == PIG) {
			Pig(index);
		}
		else if (fence[index] == CHICKEN) {
			Chicken(index);
		}
	}
}

int BreedAnimal(int x, int y) {
	int index = 0;

	while (TRUE) {
		system("cls");
		MapAnimal(isBreed);
		Status();
		Place(fence);
		PlayerBack(x, y);
		Arr();
		gotoXY(11 + index * 20, 26);
		printf("��");
		switch (_getch()) {
		case LEFT:
			if (index > 0) {
				index--;
			}
			break;
		case RIGHT:
			if (index < 2) {
				index++;
			}
			break;
		case ENTER:
			return index;
		}
	}
}

void Feed(int animal, int x, int y) {
	int x2 = 0;

	while (TRUE) {
		system("cls");
		MapAnimal(isBreed);
		Status();
		Place(fence);
		PlayerBack(x, y);
		Peed();

		gotoXY(21 + x2 * 20, 27);
		printf("��");

		switch (_getch()) {
		case LEFT:
			if (x2 > 0) {
				x2--;
			}
			break;
		case RIGHT:
			if (x2 < 1) {
				x2++;
			}
			break;
		case ENTER:
			if (x2 == 0 && status.wheat > 0) {
				status.wheat -= 2;
				status.compost += 2;
				switch (animal) {
				case COW:
					status.milk += 2;
					return;
				case PIG:
					status.pork += 2;
					return;
				case CHICKEN:
					status.egg += 2;
					return;
				}
			}
			else {
				return;
			}
		}
	}
}

void GetIngredient(char** isBreed, int animal) {
	if (animal == COW) {
		status.milk += 2;
	}
	else if (animal == PIG) {
		status.pork += 2;
	}
	else if (animal == CHICKEN) {
		status.egg += 2;
	}
	status.compost += 2;

	*isBreed = NONE;
}

//��� ���� ��(����, PC)
void BeforeSales() {
	int x = 0;
	int y = 20;
	int mapKey = 0;
	bool roop = TRUE;

	system("cls");
	MapFarm(isPlant);
	PlayerFront(x, y);

	//��ų ���Ž� ����
	SetPcCost(skill[2].isBought);
	SetMenuCost(skill[5].isBought);

	while (roop) {
		if (26 <= x && x <= 44 && 24 <= y) {
			roop = GoStore();
			//roop FALSE(������)�̸� ���� â ����
			if (roop == FALSE) {
				return;
			}
			//
			system("cls");
			x = 36;
			y = 23;
			PlayerBack(x, y);
		}

		switch (mapKey) {
		case FARM:
			MapFarm(isPlant);
			FarmPortal();
			Field(field);
			break;
		case ANIMAL:
			MapAnimal(isBreed);
			AnimalPortal();
			Place(fence);
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

		gotoXY(80, 0);
		printf("(%d, %d)", x, y);

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
				if (x == 5 && y == 17) {
					if (isPlant[0] == GREEN) {
						switch (PlantIngredient(x, y)) {
						case 0:
							if (status.cabbage > 0) {
								status.cabbage--;
								field[0] = CABBAGE_SEED;
								isPlant[0] = YELLOW;
							}
							break;
						case 1:
							if (status.tomato > 0) {
								status.tomato--;
								field[0] = TOMATO_SEED;
								isPlant[0] = YELLOW;
							}
							break;
						case 2:
							if (status.wheat > 0) {
								status.wheat--;
								field[0] = WHEAT_SEED;
								isPlant[0] = YELLOW;
							}
							break;
						case 3:
							if (status.corn > 0) {
								status.corn--;
								field[0] = CORN_SEED;
								isPlant[0] = YELLOW;
							}
							break;
						}
					}
					else if (isPlant[0] == YELLOW) {
						UseCompost(&field[0], &isPlant[0], x, y);
					}
					else if (isPlant[0] == BLUE) {
						Cultivation(0);
					}
				}
				else if (x == 18 && y == 17) {
					if (isPlant[1] == GREEN) {
						switch (PlantIngredient(x, y)) {
						case 0:
							if (status.cabbage > 0) {
								status.cabbage--;
								field[1] = CABBAGE_SEED;
								isPlant[1] = YELLOW;
							}
							break;
						case 1:
							if (status.tomato > 0) {
								status.tomato--;
								field[1] = TOMATO_SEED;
								isPlant[1] = YELLOW;
							}
							break;
						case 2:
							if (status.wheat > 0) {
								status.wheat--;
								field[1] = WHEAT_SEED;
								isPlant[1] = YELLOW;
							}
							break;
						case 3:
							if (status.corn > 0) {
								status.corn--;
								field[1] = CORN_SEED;
								isPlant[1] = YELLOW;
							}
							break;
						}
					}
					else if (isPlant[1] == YELLOW) {
						UseCompost(&field[1], &isPlant[1], x, y);
					}
					else if (isPlant[1] == BLUE) {
						Cultivation(1);
					}
				}
				else if (x == 31 && y == 17) {
					if (isPlant[2] == GREEN) {
						switch (PlantIngredient(x, y)) {
						case 0:
							if (status.cabbage > 0) {
								status.cabbage--;
								field[2] = CABBAGE_SEED;
								isPlant[2] = YELLOW;
							}
							break;
						case 1:
							if (status.tomato > 0) {
								status.tomato--;
								field[2] = TOMATO_SEED;
								isPlant[2] = YELLOW;
							}
							break;
						case 2:
							if (status.wheat > 0) {
								status.wheat--;
								field[2] = WHEAT_SEED;
								isPlant[2] = YELLOW;
							}
							break;
						case 3:
							if (status.corn > 0) {
								status.corn--;
								field[2] = CORN_SEED;
								isPlant[2] = YELLOW;
							}
							break;
						}
					}
					else if (isPlant[2] == YELLOW) {
						UseCompost(&field[2], &isPlant[2], x, y);
					}
					else if (isPlant[2] == BLUE) {
						Cultivation(2);
					}
				}
				else if (x == 44 && y == 17 && isPlant[3] == GREEN) {
					if (isPlant[3] == GREEN) {
						switch (PlantIngredient(x, y)) {
						case 0:
							if (status.cabbage > 0) {
								status.cabbage--;
								field[3] = CABBAGE_SEED;
								isPlant[3] = YELLOW;
							}
							break;
						case 1:
							if (status.tomato > 0) {
								status.tomato--;
								field[3] = TOMATO_SEED;
								isPlant[3] = YELLOW;
							}
							break;
						case 2:
							if (status.wheat > 0) {
								status.wheat--;
								field[3] = WHEAT_SEED;
								isPlant[3] = YELLOW;
							}
							break;
						case 3:
							if (status.corn > 0) {
								status.corn--;
								field[3] = CORN_SEED;
								isPlant[3] = YELLOW;
							}
							break;
						}
					}
					else if (isPlant[3] == YELLOW) {
						UseCompost(&field[3], &isPlant[3], x, y);
					}
					else if (isPlant[3] == BLUE) {
						Cultivation(3);
					}
				}
				system("cls");
				PlayerBack(x, y);
			}
			else if (mapKey == ANIMAL) {
				if (x == 10 && y == 17) {
					if (isBreed[0] == GREEN) {
						switch (BreedAnimal(x, y)) {
						case 0: //�� ����
							if (status.cow > 0) {
								status.cow--;
								fence[0] = COW;
								isBreed[0] = NONE;
								last[0] = 5;
							}
							break;
						case 1: //���� ����
							if (status.pig > 0) {
								status.pig--;
								fence[0] = PIG;
								isBreed[0] = NONE;
								last[0] = 5;
							}
							break;
						case 2: //�� ����
							if (status.chicken > 0) {
								status.chicken--;
								fence[0] = CHICKEN;
								isBreed[0] = NONE;
								last[0] = 5;
							}
							break;
						}
					}
					else if (isBreed[0] == NONE) {
						Feed(fence[0], x, y);
					}
					else if (isBreed[0] == BLUE) {
						GetIngredient(&isBreed[0], fence[0]);
					}
				}
				else if (x == 30 && y == 17) {
					if (isBreed[1] == GREEN) {
						switch (BreedAnimal(x, y)) {
						case 0: //�� ����
							if (status.cow > 0) {
								status.cow--;
								fence[1] = COW;
								isBreed[1] = NONE;
								last[1] = 5;
							}
							break;
						case 1: //���� ����
							if (status.pig > 0) {
								status.pig--;
								fence[1] = PIG;
								isBreed[1] = NONE;
								last[1] = 5;
							}
							break;
						case 2: //�� ����
							if (status.chicken > 0) {
								status.chicken--;
								fence[1] = CHICKEN;
								isBreed[1] = NONE;
								last[1] = 5;
							}
							break;
						}
					}
					else if (isBreed[1] == NONE) {
						Feed(fence[1], x, y);
					}
					else if (isBreed[1] == BLUE) {
						GetIngredient(&isBreed[1], fence[1]);
					}
				}
				else if (x == 50 && y == 17) {
					if (isBreed[2] == GREEN) {
						switch (BreedAnimal(x, y)) {
						case 0: //�� ����
							if (status.cow > 0) {
								status.cow--;
								fence[2] = COW;
								isBreed[2] = NONE;
								last[2] = 5;
							}
							break;
						case 1: //���� ����
							if (status.pig > 0) {
								status.pig--;
								fence[2] = PIG;
								isBreed[2] = NONE;
								last[2] = 5;
							}
							break;
						case 2: //�� ����
							if (status.chicken > 0) {
								status.chicken--;
								fence[2] = CHICKEN;
								isBreed[2] = NONE;
								last[2] = 5;
							}
							break;
						}
					}
					else if (isBreed[2] == NONE) {
						Feed(fence[2], x, y);
					}
					else if (isBreed[2] == BLUE) {
						GetIngredient(&isBreed[2], fence[2]);
					}
				}
				system("cls");
				PlayerBack(x, y);
			}
			break;
		}
	}
}