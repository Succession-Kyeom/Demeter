#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structure.h"

void InitDeque(GameDataDeque* datas) {
    datas->front = datas->rear = 0;
    datas->size = 0;
}

int IsDequeFull(GameDataDeque* datas) {
    return datas->size == MAX_DEQUE_SIZE;
}

int IsDequeEmpty(GameDataDeque* datas) {
    return datas->size == 0;
}

void SaveData(GameDataDeque* datas, GameData data) {
    if (IsDequeFull(datas)) {
        datas->front = ((datas->front + 1) + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
        datas->size--;
    }
    datas->rear = (datas->rear + 1) % MAX_DEQUE_SIZE;
    datas->data[datas->rear] = data;
    datas->size++;

    // Save to file
    char filename[MAX_FILENAME_SIZE];
    snprintf(filename, MAX_FILENAME_SIZE, "save_data_%d.bin", datas->data[datas->rear].status.day);
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Failed to create save file.\n");
        return;
    }

    fwrite(&data, sizeof(GameData), 1, file);
    fclose(file);
    printf("Game state saved to %s\n", filename);
}

GameData LoadData(GameDataDeque* datas, int index) {
    GameData data = {NULL, 0, 0, 0, 0, 0, 0 };

    if (IsDequeEmpty(datas)) {
        printf("Deque is empty!\n");
        return data;
    }

    // Load from file
    char filename[MAX_FILENAME_SIZE];
    snprintf(filename, MAX_FILENAME_SIZE, "save_state_%d.bin", datas->rear);
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Failed to open save file.\n");
        datas->rear = (datas->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;  // Adjust rear
        datas->size--;
        return data;
    }

    fread(&data, sizeof(GameData), 1, file);
    fclose(file);
    printf("Game state loaded from %s\n", filename);

    //datas->rear = (datas->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;  // Adjust rear
    //datas->size--;
    return data;
}
/*
int main() {
    GameDataDeque deque;
    initDeque(&deque);

    GameState state1 = { "Alice", 5, 1500, "sword,shield,potion" };
    GameState state2 = { "Bob", 10, 3000, "bow,arrow,potion" };
    GameState loadedState;

    // 게임 상태 저장
    saveState(&deque, state1);
    saveState(&deque, state2);

    // 가장 최근의 상태 불러오기
    loadedState = loadState(&deque);
    printf("Loaded state:\n");
    printGameState(&loadedState);

    // 그 이전 상태 불러오기
    loadedState = loadState(&deque);
    printf("Previous state:\n");
    printGameState(&loadedState);

    return 0;
}
*/