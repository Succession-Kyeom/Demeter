#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <process.h>

#define TRUE 1
#define FALSE 0

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define SPACE 32
#define ESC 27

//전역 변수
int x = 0;
int y = 0;
int input = 0;
int roop = TRUE;

typedef int bool;

//대기 줄
typedef struct Waiting {
	Waiting* next;
}Waiting;

struct player {
	char player;
}Player;

void PlayerInit() {
	Player.player = '>';
}

void gotoXY(int x, int y) {
	COORD pos;

	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CursorView() {
	CONSOLE_CURSOR_INFO cursorInfo = { 0 };

	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

//게임 시작
bool isStartGame = FALSE;
void StartGame() {

}

//게임 설명
bool isHowToPlay = FALSE;
void HowToPlay() {
	system("cls");
	printf("설명설명\n");
	printf("돌아가려면 아무 키나 입력");
	while (TRUE) {
		input = _getch();
		if (input == ESC) {
			break;
		}
	}
}

//메인 화면
void MainMenu() {
	x = 0;
	y = 2;
	while (TRUE) {
		gotoXY(0, 0);
		printf("신농! 농사의 데메테르\n\n");
		printf("  게임 시작\n");
		printf("  게임 설명\n");
		printf("  게임 종료\n");
		
		gotoXY(x, y);
		printf("%c", Player.player);
		
		input = _getch();
		switch (input) {
		case UP:
			if (y <= 2) {
				y = 2;
			}
			else {
				y--;
			}
			break;
		case DOWN:
			if (y >= 4) {
				y = 4;
			}
			else {
				y++;
			}
			break;
		case SPACE:
			if (y == 2) {
				isStartGame = TRUE;
			}
			else if (y == 3) {
				isHowToPlay = TRUE;
			}
			else if (y == 4) {
				roop = FALSE;
				return;
			}
			break;
		}
		system("cls");
	}
}

int main() {
	PlayerInit();
	CursorView();
	while (roop) {
		MainMenu();
	}

	return 0;
}