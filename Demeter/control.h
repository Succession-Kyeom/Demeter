#pragma once
#include <Windows.h>

//방향키 아스키 코드 값
#define ARROW 224
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32
#define ENTER 13
#define ESC 27

//bool 지정
#define TRUE 1
#define FALSE 0

//맵 키코드
#define FARM 0
#define STORE 1
#define ANIMAL 2

//텍스트 색상
#define NONE "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"

//식물 코드 지정
#define GROUND 0

#define CABBAGE_SEED 2
#define CABBAGE 4

#define TOMATO_SEED 3
#define TOMATO 6

#define WHEAT_SEED 5
#define WHEAT 10

#define CORN_SEED 7
#define CORN 14

//동물 코드 지정
#define COW 1
#define PIG 2
#define CHICKEN 3

#define MAX_DEQUE_SIZE 5
#define MAX_FILENAME_SIZE 50

//커서 좌표 이동
void gotoXY(int x, int y) {
	COORD pos = { x, y }; //x, y 좌표 설정

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //pos 좌표로 커서 이동
}

//커서 지우기
void CursorView(int visible) {
	CONSOLE_CURSOR_INFO cursorInfo = { 0 };

	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = visible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}