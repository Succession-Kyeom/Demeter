#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

#include "control.h"
#include "structure.h"
#include "init.h"
#include "graphic.h"

#define STORE_ROW 30
#define STORE_COL 80

void PrintStatus() {
	char* ingredientName[8] = { "달걀", "우유", "양상추", "토마토", "밀", "옥수수", "오이", "비료" };
	for (int index = 0; index < 8; index++) {
		printf("%-8s: %4d\n", ingredientName[index], status.ingredient[index]);
	}
}

void GameStart() {

}

void HowToPlay() {

}

void MainMenu() {
	int x = 0;
	int y = 0;
	int input = 0;
	int roop = TRUE;

	while (roop) {
		system("cls");

		gotoXY(0, 10);
		printf("(%d, %d)", x, y);

		gotoXY(0, 0);
		printf("  게임 시작\n");
		printf("  게임 설명\n");
		printf("  게임 종료\n");

		gotoXY(x, y);
		printf(">");
		input = _getch();
		if (input == ARROW) {
			input = _getch();
			switch (input) {
			case UP:
				if (y <= 0) {
					y = 0;
				}
				else {
					y--;
				}
				break;
			case DOWN:
				if (y >= 2) {
					y = 2;
				}
				else {
					y++;
				}
				break;
			}
		}
		else if (input == ENTER) {
			if (y == 0) {
				GameStart();
			}
			else if (y == 1) {
				HowToPlay();
			}
			else if (y == 2) {
				exit(0);
			}
		}
	}
}

		gotoXY(0, 0);
		printf("  게임 시작\n");
		printf("  게임 설명\n");
		printf("  게임 종료\n");

		gotoXY(x, y);
		printf(">");
		input = _getch();
		if (input == ARROW) {
			input = _getch();
			switch (input) {
			case UP:
				if (y <= 0) {
					y = 0;
				}
				else {
					y--;
				}
				break;
			case DOWN:
				if (y >= 2) {
					y = 2;
				}
				else {
					y++;
				}
				break;
			}
		}
		else if (input == ENTER) {
			if (y == 0) {
				GameStart();
			}
			else if (y == 1) {
				HowToPlay();
			}
			else if (y == 2) {
				exit(0);
			}
		}
	}
}

int main() {
	int x = 0;
	int y = 0;
	int roop = TRUE;
	int input = 0;

	Inventory* inventory = InventoryInit();

	while (roop) {
		MainMenu();
	}

	return 0;
}