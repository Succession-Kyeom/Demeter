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

#define TRUE 1
#define FALSE 0

void gotoXY(int x, int y) {
	COORD pos = { x, y }; //x, y ��ǥ ����

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //pos ��ǥ�� Ŀ�� �̵�
}