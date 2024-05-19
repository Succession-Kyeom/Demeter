#pragma once
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#include "graphic.h"

//설명 출력
void explain(int order) {
	int input = 0;
	system("cls");
	switch (order) {
	case 1:
		ManualFarm();
		break;
	case 2:
		ManualStore();
		break;
	case 3:
		ManualMoney();
		break;
	case 4:
		ManualEvent();
		break;
	}
	while (!input) {
		input = _getch();
	}
}

//게임 설명 선택 화면
void HowToPlay() {
	int x = 5;
	int y = 22;
	int upX = 5;
	int downX = 33;

	while (TRUE) {
		system("cls");
		Manual();
		gotoXY(x, y);
		printf(">");
		switch (_getch()) {
		case UP:
			if (y == 26) {
				y -= 4;
				x = upX;
			}
			break;
		case LEFT:
			if (x == 24) {
				x -= 19;
			}
			else if (x == 43) {
				x -= 19;
			}
			else if (x == 60) {
				x -= 17;
			}
			break;
		case RIGHT:
			if (x == 5) {
				x += 19;
			}
			else if (x == 24) {
				x += 19;
			}
			else if (x == 43) {
				x += 17;
			}
			break;
		case DOWN:
			if (y == 22) {
				y += 4;
				x = downX;
			}
			break;
		case ENTER:
			switch (x) {
			case 5:
				explain(1);
				break;
			case 24:
				explain(2);
				break;
			case 43:
				explain(3);
				break;
			case 60:
				explain(4);
				break;
			case 33:
				return;
			}
			break;
		}
	}
}