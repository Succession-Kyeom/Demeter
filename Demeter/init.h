#pragma once
#include <stdio.h>
#include <stdlib.h>

#include "structure.h"

#define STORE_ROW 30
#define STORE_COL 80

//상태창 초기화
void StatusInit() {
	status.day = 1;
	status.money = 1000;
	status.income = 0;
	for (int index = 0; index < 8; index++) {
		status.ingredient[index] = 0;
	}
}

//인벤토리 초기화
Inventory* InventoryInit() {
	Inventory* inven = (Inventory*)malloc(8 * sizeof(Inventory));

	for (int index = 0; index < 8; index++) {
		inven[index].prev = &inven[((index - 1) + 8) % 8];
		inven[index].item = status.ingredient[index];
		inven[index].next = &inven[(index + 1) % 8];
	}

	return inven;
}