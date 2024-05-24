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
#define GREEN "\033[0;32m"

//Ŀ�� ��ǥ �̵�
void gotoXY(int x, int y) {
	COORD pos = { x, y }; //x, y ��ǥ ����

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //pos ��ǥ�� Ŀ�� �̵�
}

//Ŀ�� �����
void CursorView() {
	CONSOLE_CURSOR_INFO cursorInfo = { 0 };

	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}