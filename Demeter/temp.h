#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEQUE_SIZE 100
#define MAX_FILENAME_SIZE 50

typedef struct {
    char player_name[50];
    int level;
    int score;
    char inventory[100];
} GameState;

typedef struct {
    GameState states[MAX_DEQUE_SIZE];
    int front;
    int rear;
    int size;
} GameStateDeque;

void initDeque(GameStateDeque* deque) {
    deque->front = 0;
    deque->rear = -1;
    deque->size = 0;
}

int isDequeFull(GameStateDeque* deque) {
    return deque->size == MAX_DEQUE_SIZE;
}

int isDequeEmpty(GameStateDeque* deque) {
    return deque->size == 0;
}

void saveState(GameStateDeque* deque, GameState state) {
    if (isDequeFull(deque)) {
        printf("Deque is full!\n");
        return;
    }
    deque->rear = (deque->rear + 1) % MAX_DEQUE_SIZE;
    deque->states[deque->rear] = state;
    deque->size++;

    // Save to file
    char filename[MAX_FILENAME_SIZE];
    snprintf(filename, MAX_FILENAME_SIZE, "save_state_%d.bin", deque->rear);
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Failed to create save file.\n");
        return;
    }

    fwrite(&state, sizeof(GameState), 1, file);
    fclose(file);
    printf("Game state saved to %s\n", filename);
}

GameState loadState(GameStateDeque* deque) {
    GameState state = { "", 0, 0, "" };

    if (isDequeEmpty(deque)) {
        printf("Deque is empty!\n");
        return state;
    }

    // Load from file
    char filename[MAX_FILENAME_SIZE];
    snprintf(filename, MAX_FILENAME_SIZE, "save_state_%d.bin", deque->rear);
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Failed to open save file.\n");
        deque->rear = (deque->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;  // Adjust rear
        deque->size--;
        return state;
    }

    fread(&state, sizeof(GameState), 1, file);
    fclose(file);
    printf("Game state loaded from %s\n", filename);

    // Remove file
    if (remove(filename) != 0) {
        printf("Failed to delete save file.\n");
    }

    deque->rear = (deque->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;  // Adjust rear
    deque->size--;
    return state;
}

void printGameState(GameState* state) {
    printf("Player Name: %s\n", state->player_name);
    printf("Level: %d\n", state->level);
    printf("Score: %d\n", state->score);
    printf("Inventory: %s\n", state->inventory);
}
/*
int main() {
    GameStateDeque deque;
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
}*/