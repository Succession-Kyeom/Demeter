#pragma once
#include <Windows.h>

//����Ű �ƽ�Ű �ڵ� ��
#define ARROW 224
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32
#define ENTER 13
#define ESC 27

//bool ����
#define TRUE 1
#define FALSE 0

//�� Ű�ڵ�
#define FARM 0
#define STORE 1
#define ANIMAL 2

//�ؽ�Ʈ ����
#define NONE "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"

//�Ĺ� �ڵ� ����
#define GROUND 0

#define CABBAGE_SEED 2
#define CABBAGE 4

#define TOMATO_SEED 3
#define TOMATO 6

#define WHEAT_SEED 5
#define WHEAT 10

#define CORN_SEED 7
#define CORN 14

//���� �ڵ� ����
#define COW 1
#define PIG 2
#define CHICKEN 3

#define MAX_DEQUE_SIZE 5
#define MAX_FILENAME_SIZE 50

//Ŀ�� ��ǥ �̵�
void gotoXY(int x, int y) {
	COORD pos = { x, y }; //x, y ��ǥ ����

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //pos ��ǥ�� Ŀ�� �̵�
}

//Ŀ�� �����
void CursorView(int visible) {
	CONSOLE_CURSOR_INFO cursorInfo = { 0 };

	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = visible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}