#pragma once
#include <stdio.h>
#include <Windows.h>

#include "control.h"
#include "structure.h"

void Frame()
{
    int x = 0;
    int y = 0;

    gotoXY(x, y); printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");
    gotoXY(x, y + 29); printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");
}

// 시작 화면
void Title()
{
    int x = 34;
    int y = 5;
    int z = 13;
    int q = 2;
    int a = 3;
    int b = 25;

    Frame();
    gotoXY(z, q); printf("          \033[1;33m____    __");
    gotoXY(z, q + 1); printf("         |    \\.-``  )");
    gotoXY(z, q + 2); printf("         |---``\\  _.'");
    gotoXY(z, q + 3); printf("      .-`'---``_.'");
    gotoXY(z, q + 4); printf("     (__...--``  ");

    gotoXY(x, y + 0); printf("\033[1;32m★。＼｜／。★");
    gotoXY(x, y + 2); printf("ㅤㅤ 신농!");
    gotoXY(x, y + 3); printf("농사의 데메테르");
    gotoXY(x, y + 5); printf("★。／｜＼。★");

    gotoXY(x - 5, y + 8); printf("\033[1;34m ~ Press Enter To Select ~\033[0m");
    gotoXY(x, y + 10); printf(" ┏━━━━━━━━━━┓");
    gotoXY(x, y + 11); printf("ㅤ 게임 시작");
    gotoXY(x, y + 12); printf(" ┗━━━━━━━━━━┛");

    gotoXY(x, y + 15); printf(" ┏━━━━━━━━━━┓");
    gotoXY(x, y + 16); printf("ㅤ 게임 설명");
    gotoXY(x, y + 17); printf(" ┗━━━━━━━━━━┛");

    gotoXY(x, y + 20); printf(" ┏━━━━━━━━━━┓");
    gotoXY(x, y + 21); printf("ㅤ 불러 오기");
    gotoXY(x, y + 22); printf(" ┗━━━━━━━━━━┛\n \n");

    gotoXY(a, b - 1); printf(" < 이동 >");
    gotoXY(a, b + 1); printf("ㅤ IWIㅤ");
    gotoXY(a, b + 2); printf("IAIISIIDI");
}

// 게임 설명
void Manual()
{
    int a = 2; // 텍스트 x축 위치
    int x = 5; // 버튼 x축 위치
    int y = 2;

    Frame();
    gotoXY(a, y + 1); printf("[신농! 농사의 데메테르]는 농사와 가게 운영이 주가 되는 게임입니다.");
    gotoXY(a, y + 2); printf("설명을 통해 자세한 부분을 확인해주세요!");

    // 선택 버튼 
    gotoXY(x, y + 19); printf(" ┏━━━━━━━━┓");
    gotoXY(x, y + 20); printf("ㅤ농장 운영");
    gotoXY(x, y + 21); printf(" ┗━━━━━━━━┛");

    gotoXY(x + 19, y + 19); printf(" ┏━━━━━━━━┓");
    gotoXY(x + 19, y + 20); printf("ㅤ가게 운영");
    gotoXY(x + 19, y + 21); printf(" ┗━━━━━━━━┛");

    gotoXY(x + 38, y + 19); printf(" ┏━━━━━━━┓");
    gotoXY(x + 38, y + 20); printf("ㅤㅤ 돈");
    gotoXY(x + 38, y + 21); printf(" ┗━━━━━━━┛");

    gotoXY(x + 55, y + 19); printf(" ┏━━━━━━━┓");
    gotoXY(x + 55, y + 20); printf("ㅤ 이벤트");
    gotoXY(x + 55, y + 21); printf(" ┗━━━━━━━┛");

    // 뒤로
    gotoXY(x +28, y + 23); printf(" ┏━━━━━━━━━┓");
    gotoXY(x + 28, y + 24); printf("ㅤㅤ 뒤로");
    gotoXY(x + 28, y + 25); printf(" ┗━━━ ▽━━━┛");

    // 아스키 아트 - 농장
    gotoXY(x - 3, y + 6); printf(" ,             ,");
    gotoXY(x - 3, y + 7); printf(" / '.         .' \\");
    gotoXY(x - 3, y + 8); printf("/    '.     .'    \\");
    gotoXY(x - 3, y + 9); printf(" '-._  '. .'  _.-'");
    gotoXY(x - 3, y + 10); printf("     '-. ; .-'");
    gotoXY(x - 3, y + 11); printf("    _.-;(_);-._");
    gotoXY(x - 3, y + 12); printf("_.-'   .'_'.   '-._");
    gotoXY(x - 3, y + 13); printf("\\    .'/[+]\\'.    /");
    gotoXY(x - 3, y + 14); printf(" \\_.' /     \\ '._/");
    gotoXY(x - 3, y + 15); printf("      |  _  |");
    gotoXY(x - 3, y + 16); printf("      | [_] |");
    gotoXY(x - 3, y + 17); printf("     /III III\\"); // 맨 끝줄

    // 아스키 아트 - 가게
    gotoXY(x + 19, y + 12); printf("  ____||____");
    gotoXY(x + 19, y + 13); printf(" ///////////\\");
    gotoXY(x + 19, y + 14); printf("///////////  \\");
    gotoXY(x + 19, y + 15); printf("|    _    |  |");
    gotoXY(x + 19, y + 16); printf("|[] | | []|[]|");
    gotoXY(x + 19, y + 17); printf("|   | |   |  |"); // 맨 끝줄

    //아스키 아트 - 돈
    gotoXY(x + 38, y + 8); printf("   I :::/  ");
    gotoXY(x + 38, y + 9); printf("    ||-II");
    gotoXY(x + 38, y + 10); printf("   ||===II");
    gotoXY(x + 38, y + 11); printf("  //ㅤㅤ \\\\ ");
    gotoXY(x + 38, y + 12); printf(" ||ㅤㅤㅤㅤ||");
    gotoXY(x + 37, y + 13); printf(" ||ㅤㅤㅤㅤ  ||");
    gotoXY(x + 37, y + 14); printf("||ㅤㅤ $ㅤㅤ  ||");
    gotoXY(x + 38, y + 15); printf("||ㅤㅤㅤㅤㅤ||");
    gotoXY(x + 38, y + 16); printf(" \\\\ㅤㅤㅤㅤ//");
    gotoXY(x + 38, y + 17); printf("   \\------/"); // 맨 끝줄

    //아스키 아트 - 이벤트
    gotoXY(x + 55, y + 11); printf("    _______ ");
    gotoXY(x + 55, y + 12); printf("  /\\       \\  ");
    gotoXY(x + 55, y + 13); printf(" /()\\   ()  \\      ");
    gotoXY(x + 55, y + 14); printf("/    \\_______\\    ");
    gotoXY(x + 55, y + 15); printf("\\    /()     /      ");
    gotoXY(x + 55, y + 16); printf(" \\()/   ()  /       ");
    gotoXY(x + 55, y + 17); printf("  \\/_____()/"); // 맨 끝줄
}   
// 농장운영 상세 설명
void ManualFarm()
{
    int x = 2;
    int y = 2;

    Frame();
    gotoXY(x-2, y); printf(" ┏━━━━━━━━┓");
    gotoXY(x-2, y + 1); printf("ㅤ농장 운영");
    gotoXY(x-2, y + 2); printf(" ┗━━━━━━━━┛");

    // 뒤로
    gotoXY(x + 64, y + 23); printf(" ┏━━━━━━━━━┓");
    gotoXY(x + 64, y + 24); printf("ㅤㅤ 뒤로");
    gotoXY(x + 64, y + 25); printf(" ┗━━━ ▽━━━┛");

    // 설명
    gotoXY(x, y + 4); printf("여기다 설명을 적으면 되겠지");
    gotoXY(x, y + 5); printf("처음하는 거라 이게 맞는 지 궁금하네요");
    gotoXY(x, y + 7); printf("동물 키우고 ");
    gotoXY(x, y + 8); printf("식물 키워서");
    gotoXY(x, y + 9); printf("가게를 운영해보세용~ㅎ.ㅎ");
}
// 가게운영 상세 설명
void ManualStore()
{
    int x = 2;
    int y = 2;

    Frame();
    gotoXY(x - 2, y); printf(" ┏━━━━━━━━┓");
    gotoXY(x - 2, y + 1); printf("ㅤ가게 운영");
    gotoXY(x - 2, y + 2); printf(" ┗━━━━━━━━┛");

    // 뒤로
    gotoXY(x + 64, y + 23); printf(" ┏━━━━━━━━━┓");
    gotoXY(x + 64, y + 24); printf("ㅤㅤ 뒤로");
    gotoXY(x + 64, y + 25); printf(" ┗━━━ ▽━━━┛");

    // 설명
    gotoXY(x, y + 4); printf("여기다 설명을 적으면 되겠지");
    gotoXY(x, y + 5); printf("처음하는 거라 이게 맞는 지 궁금하네요");
    gotoXY(x, y + 7); printf("음식을 만들어서 판매하고 ");
    gotoXY(x, y + 8); printf("PC를 통해 재고를 관리하세요~");
    gotoXY(x, y + 9); printf("멋지게 가게를 운영해보세용~ㅎ.ㅎ");
}
// 돈 상세 설명
void ManualMoney()
{
    int x = 2;
    int y = 2;

    Frame();
    gotoXY(x - 2, y); printf(" ┏━━━━━━━┓");
    gotoXY(x - 2, y + 1); printf("ㅤㅤ 돈");
    gotoXY(x - 2, y + 2); printf(" ┗━━━━━━━┛");

    // 뒤로
    gotoXY(x + 64, y + 23); printf(" ┏━━━━━━━━━┓");
    gotoXY(x + 64, y + 24); printf("ㅤㅤ 뒤로");
    gotoXY(x + 64, y + 25); printf(" ┗━━━ ▽━━━┛");

    // 설명
    gotoXY(x, y + 4); printf("여기다 설명을 적으면 되겠지");
    gotoXY(x, y + 5); printf("처음하는 거라 이게 맞는 지 궁금하네요");
    gotoXY(x, y + 7); printf("음식을 만들어서 판매하여 돈을 벌고");
    gotoXY(x, y + 8); printf("꼬박꼬박 가게세도 상납하세요!");
    gotoXY(x, y + 9); printf("멋지게 가게를 운영해보세용~ㅎ.ㅎ");
}
// 이벤트 상세 설명
void ManualEvent()
{
    int x = 2;
    int y = 2;

    Frame();
    gotoXY(x - 2, y); printf(" ┏━━━━━━━┓");
    gotoXY(x - 2, y + 1); printf("ㅤ 이벤트");
    gotoXY(x - 2, y + 2); printf(" ┗━━━━━━━┛");

    // 뒤로
    gotoXY(x + 64, y + 23); printf(" ┏━━━━━━━━━┓");
    gotoXY(x + 64, y + 24); printf("ㅤㅤ 뒤로");
    gotoXY(x + 64, y + 25); printf(" ┗━━━ ▽━━━┛");

    // 설명
    gotoXY(x, y + 4); printf("여기다 설명을 적으면 되겠지");
    gotoXY(x, y + 5); printf("처음하는 거라 이게 맞는 지 궁금하네요");
    gotoXY(x, y + 7); printf("농장과 가게를 운영하며");
    gotoXY(x, y + 8); printf("다양한 사건을 맞이합니다~");
    gotoXY(x, y + 9); printf("멋지게 가게를 운영해보세용~ㅎ.ㅎ");
}

// 불러오기
void Load()
{
    int x = 2;
    int y = 2;

    Frame();
    gotoXY(x - 2, y); printf(" ┏━━━━━━━━━┓");
    gotoXY(x - 2, y + 1); printf("ㅤ 불러오기");
    gotoXY(x - 2, y + 2); printf(" ┗━━━━━━━━━┛");

    // 뒤로
    gotoXY(x + 64, y + 23); printf(" ┏━━━━━━━━━┓");
    gotoXY(x + 64, y + 24); printf("ㅤㅤ 뒤로");
    gotoXY(x + 64, y + 25); printf(" ┗━━━ ▽━━━┛");

    gotoXY(x, y + 4); printf("    _________________________   _________________________");
    gotoXY(x, y + 5); printf(".-/|                         \\ /                         |\\-.");
    gotoXY(x, y + 6); printf("||||                          |                          ||||");
    gotoXY(x, y + 7); printf("||||                          |            --==*==--     ||||");
    gotoXY(x, y + 8); printf("||||                          |                          ||||");
    gotoXY(x, y + 9); printf("||||                          |                          ||||");
    gotoXY(x, y + 10); printf("||||                          |                          ||||");
    gotoXY(x, y + 11); printf("||||    --==*==--             |                          ||||");
    gotoXY(x, y + 12); printf("||||                          |                          ||||");
    gotoXY(x, y + 13); printf("||||                          |                          ||||");
    gotoXY(x, y + 14); printf("||||                          |            --==*==--     ||||");
    gotoXY(x, y + 15); printf("||||                          |                          ||||");
    gotoXY(x, y + 16); printf("||||                          |                          ||||");
    gotoXY(x, y + 17); printf("||||                          |                          ||||");
    gotoXY(x, y + 18); printf("||||                          |         --==*==--        ||||");
    gotoXY(x, y + 19); printf("||||                          |                          ||||");
    gotoXY(x, y + 20); printf("||||                          |                          ||||");
    gotoXY(x, y + 21); printf("||||                          |                          ||||");
    gotoXY(x, y + 22); printf("||||                          |                          ||||");
    gotoXY(x, y + 23); printf("||||_________________________ | _________________________||||");
    gotoXY(x, y + 24); printf("||/==========================\\|/==========================\\||");
    gotoXY(x, y + 25); printf("`---------------------------~___~--------------------------''"); // 맨 끝줄

    // 세이브 정보
    gotoXY(x, y + 6); printf("|||| ▶ DAY 00                |                          ");
    gotoXY(x, y + 7); printf("|||| 보유 금액: 0원           |                          ");
    gotoXY(x, y + 8); printf("|||| *---------------------*  |  *---------------------* ");
    gotoXY(x, y + 9); printf("|||| ▶ DAY 00                |                          ");
    gotoXY(x, y + 10); printf("|||| 보유 금액: 0원           |                          ");
    gotoXY(x, y + 11); printf("|||| *---------------------*  |  *---------------------* ");
    gotoXY(x, y + 12); printf("||||                          |                          ");
    gotoXY(x, y + 13); printf("||||                          |                          ");
    gotoXY(x, y + 14); printf("|||| *---------------------*  |  *---------------------* ");
    gotoXY(x, y + 15); printf("||||                          |                          ");
    gotoXY(x, y + 16); printf("||||                          |                          ");
    gotoXY(x, y + 17); printf("|||| *---------------------*  |  *---------------------* ");
    gotoXY(x, y + 18); printf("||||                          |                          ");
    gotoXY(x, y + 19); printf("||||                          |                          ");
    gotoXY(x, y + 20); printf("|||| *---------------------*  |  *---------------------* ");
    gotoXY(x, y + 21); printf("||||                          |                          ");
    gotoXY(x, y + 22); printf("||||                          |                          ");
}

//상태창
void Status()
{
    int a = 64;
    int b = 1;

    gotoXY(a-2, b); printf("┏━━━━━━━━━━━━━━━┓");
    gotoXY(a, b + 1); printf("ㅤㅤ상태창");
    gotoXY(a, b + 2); printf("DAY %2d", status.day);
    gotoXY(a, b + 3); printf("보유 금액:%4d원", status.money);
    gotoXY(a, b + 5); printf("< 재료 >");
    
    gotoXY(a, b + 6); printf("달걀:%2d", status.egg);
    gotoXY(a, b + 7); printf("우유:%2d", status.milk);
    gotoXY(a, b + 8); printf("돼지고기:%2d", status.pork);
    gotoXY(a, b + 9); printf("양상추:%2d", status.cabbage);
    gotoXY(a, b + 10); printf("토마토:%2d", status.tomato);
    gotoXY(a, b + 11); printf("밀:%2d", status.wheat);
    gotoXY(a, b + 12); printf("옥수수:%2d", status.corn);
    gotoXY(a, b + 13); printf("비료:%2d", status.compost);
    gotoXY(a-2, b + 15); printf("┗━━━━━━━━━━━━━━━┛");
}

// 농장 포탈
void FarmPortal()
{
    int x = 2;
    int y = 22;

    gotoXY(x + 28, y + 4); printf(" \033[0;36m┏━━━━━━━━━━━━┓");
    gotoXY(x + 28, y + 5); printf("ㅤ데메테르 가게");
    gotoXY(x + 28, y + 6); printf(" ┗━━━━━━━━━━━━┛\033[0m");

    gotoXY(x + 69, y); printf(" \033[1;33m┏━━━━━┓");
    gotoXY(x + 69, y + 1); printf("ㅤ 동물");
    gotoXY(x + 69, y + 3); printf("ㅤ 농장");
    gotoXY(x + 69, y + 4); printf(" ┗━━━━━┛\033[0m");
}

// 농장 맵: 밭 
void MapFarm()
{
    int x = 1;  
    int y = 7;

    Frame();
    // 밭 1
    gotoXY(x+8, y); printf("\033[0;33m-------------\033[0m");
    gotoXY(x, y + 1); printf("       \033[0;33m/ㅤㅤㅤㅤㅤㅤ/\033[0m");
    gotoXY(x, y + 2); printf("      \033[0;33m/ㅤㅤㅤㅤㅤㅤ/\033[0m");
    gotoXY(x, y + 3); printf("     \033[0;33m/ㅤㅤㅤㅤㅤㅤ/\033[0m");
    gotoXY(x, y + 4); printf("    \033[0;33m/ㅤㅤㅤㅤㅤㅤ/\033[0m");
    gotoXY(x, y + 5); printf("   \033[0;33m/ㅤㅤㅤㅤㅤㅤ/\033[0m");
    gotoXY(x, y + 6); printf("  \033[0;33m/ㅤㅤㅤㅤㅤㅤ/\033[0m");
    gotoXY(x, y + 7); printf(" \033[0;33m/ㅤㅤㅤㅤㅤㅤ/\033[0m");
    gotoXY(x, y + 8); printf("\033[0;33m/ㅤㅤㅤㅤㅤㅤ/\033[0m");
    gotoXY(x, y + 9); printf("\033[0;33m-----\033[0;32m---\033[0;33m-----\033[0m");

    // 밭 2
    gotoXY(x + 21, y); printf("\033[0;33m-------------\033[0m");
    gotoXY(x + 13, y + 1); printf("       \033[0;33m/ㅤㅤㅤㅤㅤㅤ/\033[0m");
    gotoXY(x + 13, y + 2); printf("      \033[0;33m/ㅤㅤㅤㅤㅤㅤ/\033[0m");
    gotoXY(x + 13, y + 3); printf("     \033[0;33m/ㅤㅤㅤㅤㅤㅤ/\033[0m");
    gotoXY(x + 13, y + 4); printf("    \033[0;33m/ㅤㅤㅤㅤㅤㅤ/\033[0m");
    gotoXY(x + 13, y + 5); printf("   \033[0;33m/ㅤㅤㅤㅤㅤㅤ/\033[0m");
    gotoXY(x + 13, y + 6); printf("  \033[0;33m/ㅤㅤㅤㅤㅤㅤ/\033[0m");
    gotoXY(x + 13, y + 7); printf(" \033[0;33m/ㅤㅤㅤㅤㅤㅤ/\033[0m");
    gotoXY(x + 13, y + 8); printf("\033[0;33m/ㅤㅤㅤㅤㅤㅤ/\033[0m");
    gotoXY(x + 13, y + 9); printf("\033[0;33m-----\033[0;32m---\033[0;33m-----\033[0m");

    // 밭 3
    gotoXY(x + 34, y); printf("\033[0;33m-------------\033[0m");
    gotoXY(x + 26, y + 1); printf("       \033[0;33m/ㅤㅤㅤㅤㅤㅤ/\033[0m");
    gotoXY(x + 26, y + 2); printf("      \033[0;33m/ㅤㅤㅤㅤㅤㅤ/\033[0m");
    gotoXY(x + 26, y + 3); printf("     \033[0;33m/ㅤㅤㅤㅤㅤㅤ/\033[0m");
    gotoXY(x + 26, y + 4); printf("    \033[0;33m/ㅤㅤㅤㅤㅤㅤ/\033[0m");
    gotoXY(x + 26, y + 5); printf("   \033[0;33m/ㅤㅤㅤㅤㅤㅤ/\033[0m");
    gotoXY(x + 26, y + 6); printf("  \033[0;33m/ㅤㅤㅤㅤㅤㅤ/\033[0m");
    gotoXY(x + 26, y + 7); printf(" \033[0;33m/ㅤㅤㅤㅤㅤㅤ/\033[0m");
    gotoXY(x + 26, y + 8); printf("\033[0;33m/ㅤㅤㅤㅤㅤㅤ/\033[0m");
    gotoXY(x + 26, y + 9); printf("\033[0;33m-----\033[0;32m---\033[0;33m-----\033[0m");
    //밭 4
    gotoXY(x + 47, y); printf("\033[0;33m-------------\033[0m");
    gotoXY(x + 39, y + 1); printf("       \033[0;33m/ㅤㅤㅤㅤㅤㅤ/\033[0m");
    gotoXY(x + 39, y + 2); printf("      \033[0;33m/ㅤㅤㅤㅤㅤㅤ/\033[0m");
    gotoXY(x + 39, y + 3); printf("     \033[0;33m/ㅤㅤㅤㅤㅤㅤ/\033[0m");
    gotoXY(x + 39, y + 4); printf("    \033[0;33m/ㅤㅤㅤㅤㅤㅤ/\033[0m");
    gotoXY(x + 39, y + 5); printf("   \033[0;33m/ㅤㅤㅤㅤㅤㅤ/\033[0m");
    gotoXY(x + 39, y + 6); printf("  \033[0;33m/ㅤㅤㅤㅤㅤㅤ/\033[0m");
    gotoXY(x + 39, y + 7); printf(" \033[0;33m/ㅤㅤㅤㅤㅤㅤ/\033[0m");
    gotoXY(x + 39, y + 8); printf("\033[0;33m/ㅤㅤㅤㅤㅤㅤ/\033[0m");
    gotoXY(x + 39, y + 9); printf("\033[0;33m-----\033[0;32m---\033[0;33m-----\033[0m");

    FarmPortal(); // 농장 포탈 호출
}

// 작물 선택
void Plant()
{
    int x = 2;
    int y = 22;
    gotoXY(x - 2, y); printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
    gotoXY(x - 1, y + 1); printf("▷ 무엇을 심으시겠습니까?");

    gotoXY(x, y + 4); printf(" ┏━━━━━━━┓");
    gotoXY(x, y + 5); printf("ㅤ 양상추");
    gotoXY(x, y + 6); printf(" ┗━━━━━━━┛");

    gotoXY(x + 20, y + 4); printf(" ┏━━━━━━━┓");
    gotoXY(x + 20, y + 5); printf("ㅤ 토마토");
    gotoXY(x + 20, y + 6); printf(" ┗━━━━━━━┛");

    gotoXY(x + 40, y + 4); printf(" ┏━━━━━━━┓");
    gotoXY(x + 40, y + 5); printf("ㅤㅤ 밀");
    gotoXY(x + 40, y + 6); printf(" ┗━━━━━━━┛");

    gotoXY(x + 60, y + 4); printf(" ┏━━━━━━━┓");
    gotoXY(x + 60, y + 5); printf("ㅤ 옥수수");
    gotoXY(x + 60, y + 6); printf(" ┗━━━━━━━┛");

}

// 거름 선택
void Poo()
{
    int x = 2;
    int y = 22;

    gotoXY(x - 2, y); printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
    gotoXY(x - 1, y + 1); printf("▷ 거름을 주겠습니까?");

    gotoXY(x + 20, y + 4); printf(" ┏━━━━━━━┓");
    gotoXY(x + 20, y + 5); printf("ㅤㅤ 예");
    gotoXY(x + 20, y + 6); printf(" ┗━━━━━━━┛");

    gotoXY(x + 40, y + 4); printf(" ┏━━━━━━━┓");
    gotoXY(x + 40, y + 5); printf("ㅤ 아니요");
    gotoXY(x + 40, y + 6); printf(" ┗━━━━━━━┛");
}

// 새싹 - 모든 작물 공통
void Sprout()
{
    int x = 1;
    int y = 7;

    // 밭 1
    gotoXY(x+10, y + 1); printf("\033[0;32mV  ㅤ V\033[0m");
    gotoXY(x+8, y + 3); printf("\033[0;32mV   ㅤV\033[0m");
    gotoXY(x+6, y + 5); printf("\033[0;32mV   ㅤV\033[0m");
    gotoXY(x+4, y + 7); printf("\033[0;32mV   ㅤV\033[0m");

    // 밭 2
    gotoXY(x + 23, y + 1); printf("\033[0;32mV  ㅤ V\033[0m");
    gotoXY(x + 21, y + 3); printf("\033[0;32mV  ㅤ V\033[0m");
    gotoXY(x + 19, y + 5); printf("\033[0;32mV  ㅤ V\033[0m");
    gotoXY(x + 17, y + 7); printf("\033[0;32mV  ㅤ V\033[0m");

    // 밭 3
    gotoXY(x + 36, y + 1); printf("\033[0;32mV  ㅤ V\033[0m");
    gotoXY(x + 34, y + 3); printf("\033[0;32mV  ㅤ V\033[0m");
    gotoXY(x + 32, y + 5); printf("\033[0;32mV  ㅤ V\033[0m");
    gotoXY(x + 30, y + 7); printf("\033[0;32mV  ㅤ V\033[0m");

    //밭 4
    gotoXY(x + 49, y + 1); printf("\033[0;32mV  ㅤ V\033[0m");
    gotoXY(x + 47, y + 3); printf("\033[0;32mV  ㅤ V\033[0m");
    gotoXY(x + 45, y + 5); printf("\033[0;32mV  ㅤ V\033[0m");
    gotoXY(x + 43, y + 7); printf("\033[0;32mV  ㅤ V\033[0m");

}

void Lettuce()
{
    int x = 6;
    int y =6;


    // 밭 1
    gotoXY(x + 3, y + 3); printf("\033[0;32m .~~~-._\033[0m");
    gotoXY(x + 1, y + 4); printf("\033[0;32m //) ' } //\033[0m");
    gotoXY(x, y + 5); printf("\033[0;32m (`\ , /  ~)\033[0m");
    gotoXY(x, y + 6); printf("\033[0;32m `-.`\/  _.'\033[0m");
    gotoXY(x, y + 7); printf("\033[0;32m    \\--/ \033[0m");

    // 밭 2
    gotoXY(x + 16, y + 3); printf("\033[0;32m .~~~-._\033[0m");
    gotoXY(x + 14, y + 4); printf("\033[0;32m //) ' } //\033[0m");
    gotoXY(x + 13, y + 5); printf("\033[0;32m (`\ , /  ~)\033[0m");
    gotoXY(x + 13, y + 6); printf("\033[0;32m `-.`\/  _.'\033[0m");
    gotoXY(x + 13, y + 7); printf("\033[0;32m    \\--/ \033[0m");


    // 밭 3
    gotoXY(x + 29, y + 3); printf("\033[0;32m .~~~-._\033[0m");
    gotoXY(x + 27, y + 4); printf("\033[0;32m //) ' } //\033[0m");
    gotoXY(x + 26, y + 5); printf("\033[0;32m (`\ , /  ~)\033[0m");
    gotoXY(x + 26, y + 6); printf("\033[0;32m `-.`\/  _.'\033[0m");
    gotoXY(x + 26, y + 7); printf("\033[0;32m    \\--/ \033[0m");

    //밭 4
    gotoXY(x + 42, y + 3); printf("\033[0;32m .~~~-._\033[0m");
    gotoXY(x + 40, y + 4); printf("\033[0;32m //) ' } //\033[0m");
    gotoXY(x + 39, y + 5); printf("\033[0;32m (`\ , /  ~)\033[0m");
    gotoXY(x + 39, y + 6); printf("\033[0;32m `-.`\/  _.'\033[0m");
    gotoXY(x + 39, y + 7); printf("\033[0;32m    \\--/ \033[0m");

}

void Tomato()
{
    int x = 6;
    int y = 7;

    // 밭 1
    gotoXY(x + 6, y + 1); printf("\033[0;31m  ,\033[0;32mv\033[0;31m.\033[0m");
    gotoXY(x+ 6, y + 2); printf("\033[0;31m ((  )\033[0m");
    gotoXY(x + 2, y + 3); printf("\033[0;31m ,\033[0;32mv\033[0;31m.ㅤ`\"'\033[0m");
    gotoXY(x, y + 4); printf("\033[0;31m ((  )\033[0m");
    gotoXY(x, y + 5); printf("\033[0;31m  `\"'\033[0m");
    gotoXY(x + 2, y + 6); printf("\033[0;31m ,\033[0;32mv\033[0;31m.\033[0m");
    gotoXY(x + 1, y + 7); printf("\033[0;31m ((  )\033[0m");
    gotoXY(x + 2, y + 8); printf("\033[0;31m `\"'\033[0m"); 

    // 밭 2
    gotoXY(x + 19, y + 1); printf("\033[0;31m  ,\033[0;32mv\033[0;31m.\033[0m");
    gotoXY(x + 19, y + 2); printf("\033[0;31m ((  )\033[0m");
    gotoXY(x + 15, y + 3); printf("\033[0;31m ,\033[0;32mv\033[0;31m.ㅤ`\"'\033[0m");
    gotoXY(x + 13, y + 4); printf("\033[0;31m ((  )\033[0m");
    gotoXY(x + 13, y + 5); printf("\033[0;31m  `\"'\033[0m");
    gotoXY(x + 15, y + 6); printf("\033[0;31m ,\033[0;32mv\033[0;31m.\033[0m");
    gotoXY(x + 14, y + 7); printf("\033[0;31m ((  )\033[0m");
    gotoXY(x + 15, y + 8); printf("\033[0;31m `\"'\033[0m");

    // 밭 3
    gotoXY(x + 32, y + 1); printf("\033[0;31m  ,\033[0;32mv\033[0;31m.\033[0m");
    gotoXY(x + 32, y + 2); printf("\033[0;31m ((  )\033[0m");
    gotoXY(x + 28, y + 3); printf("\033[0;31m ,\033[0;32mv\033[0;31m.ㅤ`\"'\033[0m");
    gotoXY(x + 26, y + 4); printf("\033[0;31m ((  )\033[0m");
    gotoXY(x + 26, y + 5); printf("\033[0;31m  `\"'\033[0m");
    gotoXY(x + 28, y + 6); printf("\033[0;31m ,\033[0;32mv\033[0;31m.\033[0m");
    gotoXY(x + 27, y + 7); printf("\033[0;31m ((  )\033[0m");
    gotoXY(x + 28, y + 8); printf("\033[0;31m `\"'\033[0m");

    //밭 4
    gotoXY(x + 45, y + 1); printf("\033[0;31m  ,\033[0;32mv\033[0;31m.\033[0m");
    gotoXY(x + 45, y + 2); printf("\033[0;31m ((  )\033[0m");
    gotoXY(x + 41, y + 3); printf("\033[0;31m ,\033[0;32mv\033[0;31m.ㅤ`\"'\033[0m");
    gotoXY(x + 39, y + 4); printf("\033[0;31m ((  )\033[0m");
    gotoXY(x + 39, y + 5); printf("\033[0;31m  `\"'\033[0m");
    gotoXY(x + 41, y + 6); printf("\033[0;31m ,\033[0;32mv\033[0;31m.\033[0m");
    gotoXY(x + 40, y + 7); printf("\033[0;31m ((  )\033[0m");
    gotoXY(x + 41, y + 8); printf("\033[0;31m `\"'\033[0m");
}

void Wheat()
{
    int x = 4;
    int y = 7;

    // 밭 1
    gotoXY(x + 6, y + 1); printf("\033[1;33m  \\ /\033[0m");
    gotoXY(x + 6, y + 2); printf("\033[1;33mˇ\\|/\033[0m");
    gotoXY(x + 6, y + 3); printf("\033[1;33m  \\|/ˇ\033[0m");
    gotoXY(x + 6, y + 4); printf("\033[1;33m   |\033[0m");
    gotoXY(x + 2, y + 5); printf("\033[1;33m  \\ /\033[0m");
    gotoXY(x + 2, y + 6); printf("\033[1;33mˇ\\|/\033[0m");
    gotoXY(x + 2, y + 7); printf("\033[1;33m  \\|/ˇ\033[0m");
    gotoXY(x + 2, y + 8); printf("\033[1;33m   |\033[0m");

    // 밭 2
    gotoXY(x + 19, y + 1); printf("\033[1;33m  \\ /\033[0m");
    gotoXY(x + 19, y + 2); printf("\033[1;33mˇ\\|/\033[0m");
    gotoXY(x + 19, y + 3); printf("\033[1;33m  \\|/ˇ\033[0m");
    gotoXY(x + 19, y + 4); printf("\033[1;33m   |\033[0m");
    gotoXY(x + 15, y + 5); printf("\033[1;33m  \\ /\033[0m");
    gotoXY(x + 15, y + 6); printf("\033[1;33mˇ\\|/\033[0m");
    gotoXY(x + 15, y + 7); printf("\033[1;33m  \\|/ˇ\033[0m");
    gotoXY(x + 15, y + 8); printf("\033[1;33m   |\033[0m");

    // 밭 3
    gotoXY(x + 32, y + 1); printf("\033[1;33m  \\ /\033[0m");
    gotoXY(x + 32, y + 2); printf("\033[1;33mˇ\\|/\033[0m");
    gotoXY(x + 32, y + 3); printf("\033[1;33m  \\|/ˇ\033[0m");
    gotoXY(x + 32, y + 4); printf("\033[1;33m   |\033[0m");
    gotoXY(x + 28, y + 5); printf("\033[1;33m  \\ /\033[0m");
    gotoXY(x + 28, y + 6); printf("\033[1;33mˇ\\|/\033[0m");
    gotoXY(x + 28, y + 7); printf("\033[1;33m  \\|/ˇ\033[0m");
    gotoXY(x + 28, y + 8); printf("\033[1;33m   |\033[0m");

    //밭 4
    gotoXY(x + 45, y + 1); printf("\033[1;33m  \\ /\033[0m");
    gotoXY(x + 45, y + 2); printf("\033[1;33mˇ\\|/\033[0m");
    gotoXY(x + 45, y + 3); printf("\033[1;33m  \\|/ˇ\033[0m");
    gotoXY(x + 45, y + 4); printf("\033[1;33m   |\033[0m");
    gotoXY(x + 41, y + 5); printf("\033[1;33m  \\ /\033[0m");
    gotoXY(x + 41, y + 6); printf("\033[1;33mˇ\\|/\033[0m");
    gotoXY(x + 41, y + 7); printf("\033[1;33m  \\|/ˇ\033[0m");
    gotoXY(x + 41, y + 8); printf("\033[1;33m   |\033[0m");
}

void Corn()
{
    int x = 3;
    int y = 8;

    // 밭 1
    gotoXY(x + 5, y + 1); printf("\033[1;32m |\\\033[1;33m∴ \033[1;32m/|");
    gotoXY(x + 4, y + 2); printf(" |\\\033[1;33m∴∵\033[1;32m/|");
    gotoXY(x + 5, y + 3); printf("\\\\\033[1;33m:::\033[1;32m//");
    gotoXY(x + 5, y + 4); printf(" |---|");
    gotoXY(x + 6, y + 5); printf(" :_:\033[0m");

    // 밭 2
    gotoXY(x + 18, y + 1); printf("\033[1;32m |\\\033[1;33m∴ \033[1;32m/|");
    gotoXY(x + 17, y + 2); printf(" |\\\033[1;33m∴∵\033[1;32m/|");
    gotoXY(x + 18, y + 3); printf("\\\\\033[1;33m:::\033[1;32m//");
    gotoXY(x + 18, y + 4); printf(" |---|");
    gotoXY(x + 19, y + 5); printf(" :_:\033[0m");

    // 밭 3
    gotoXY(x + 31, y + 1); printf("\033[1;32m |\\\033[1;33m∴ \033[1;32m/|");
    gotoXY(x + 30, y + 2); printf(" |\\\033[1;33m∴∵\033[1;32m/|");
    gotoXY(x + 31, y + 3); printf("\\\\\033[1;33m:::\033[1;32m//");
    gotoXY(x + 31, y + 4); printf(" |---|");
    gotoXY(x + 32, y + 5); printf(" :_:\033[0m");

    //밭 4
    gotoXY(x + 44, y + 1); printf("\033[1;32m |\\\033[1;33m∴ \033[1;32m/|");
    gotoXY(x + 43, y + 2); printf(" |\\\033[1;33m∴∵\033[1;32m/|");
    gotoXY(x + 44, y + 3); printf("\\\\\033[1;33m:::\033[1;32m//");
    gotoXY(x + 44, y + 4); printf(" |---|");
    gotoXY(x + 45, y + 5); printf(" :_:\033[0m");
}

// 바구니
void Basket()
{
    int x = 0;
    int y = 19;

    gotoXY(x, y); printf("\033[0;33m┏━━━━━━━┓");
    gotoXY(x, y + 1); printf("│ 바구니│");
    gotoXY(x, y + 2); printf("┗━━━━━━━┛\033[0m");

}

//  **채소 농장쪽 포탈이랑 미묘하게 크기 안맞는 부분 있어서 어색하면 수정해도 될듯(바꿀 때 포탈 이동하는 좌표 범위도 수정해야함)**
// 동물 농장 포탈
void AnimalPortal()
{
    int x = 0;
    int y = 22;

    gotoXY(x + 30, y + 4); printf(" \033[0;36m┏━━━━━━━━━━━━┓");
    gotoXY(x + 30, y + 5); printf("ㅤ데메테르 가게");
    gotoXY(x + 30, y + 6); printf(" ┗━━━━━━━━━━━━┛\033[0m");

    gotoXY(x, y + 1); printf("\033[1;32m┏━━━━━┓");
    gotoXY(x, y + 3); printf("ㅤ채소");
    gotoXY(x, y + 4); printf("ㅤ농장");
    gotoXY(x, y + 6); printf("┗━━━━━┛\033[0m");
}

//  **사육장 전부 한칸씩만 내리면 좋을듯**
// 동물 농장: 사육장
void MapAnimal()
{
    int x = 5;
    int z = 25;
    int q = 45;
    int y = 2;
    int r = 10;

    Frame();
    //사육장1
    gotoXY(x, y); printf("┌────────────┐");
    gotoXY(x, y + 1); printf("│");
    gotoXY(x + 13, y + 1); printf("│");
    gotoXY(x, y + 2); printf("│");
    gotoXY(x + 13, y + 2); printf("│");
    gotoXY(x, y + 3); printf("│");
    gotoXY(x + 13, y + 3); printf("│");
    gotoXY(x, y + 4); printf("│");
    gotoXY(x + 13, y + 4); printf("│");
    gotoXY(x, y + 5); printf("└────────────┘");

    // 사육장2
    gotoXY(z, y); printf("┌────────────┐");
    gotoXY(z, y + 1); printf("│");
    gotoXY(z + 13, y + 1); printf("│");
    gotoXY(z, y + 2); printf("│");
    gotoXY(z + 13, y + 2); printf("│");
    gotoXY(z, y + 3); printf("│");
    gotoXY(z + 13, y + 3); printf("│");
    gotoXY(z, y + 4); printf("│");
    gotoXY(z + 13, y + 4); printf("│");
    gotoXY(z, y + 5); printf("└────────────┘");
    
    //사육장3
    gotoXY(q, y); printf("┌────────────┐");
    gotoXY(q, y + 1); printf("│");
    gotoXY(q + 13, y + 1); printf("│");
    gotoXY(q, y + 2); printf("│");
    gotoXY(q + 13, y + 2); printf("│");
    gotoXY(q, y + 3); printf("│");
    gotoXY(q + 13, y + 3); printf("│");
    gotoXY(q, y + 4); printf("│");
    gotoXY(q + 13, y + 4); printf("│");
    gotoXY(q, y + 5); printf("└────────────┘");

    //사육장4
    gotoXY(x, r); printf("┌────────────┐");
    gotoXY(x, r + 1); printf("│");
    gotoXY(x + 13, r + 1); printf("│");
    gotoXY(x, r + 2); printf("│");
    gotoXY(x + 13, r + 2); printf("│");
    gotoXY(x, r + 3); printf("│");
    gotoXY(x + 13, r + 3); printf("│");
    gotoXY(x, r + 4); printf("│");
    gotoXY(x + 13, r + 4); printf("│");
    gotoXY(x, r + 5); printf("└────────────┘");

    // 사육장5
    gotoXY(z, r); printf("┌────────────┐");
    gotoXY(z, r + 1); printf("│");
    gotoXY(z + 13, r + 1); printf("│");
    gotoXY(z, r + 2); printf("│");
    gotoXY(z + 13, r + 2); printf("│");
    gotoXY(z, r + 3); printf("│");
    gotoXY(z + 13, r + 3); printf("│");
    gotoXY(z, r + 4); printf("│");
    gotoXY(z + 13, r + 4); printf("│");
    gotoXY(z, r + 5); printf("└────────────┘");

    //사육장6
    gotoXY(q, r); printf("┌────────────┐");
    gotoXY(q, r + 1); printf("│");
    gotoXY(q + 13, r + 1); printf("│");
    gotoXY(q, r + 2); printf("│");
    gotoXY(q + 13, r + 2); printf("│");
    gotoXY(q, r + 3); printf("│");
    gotoXY(q + 13, r + 3); printf("│");
    gotoXY(q, r + 4); printf("│");
    gotoXY(q + 13, r + 4); printf("│");
    gotoXY(q, r + 5); printf("└────────────┘");

    Basket();
    AnimalPortal();
}

void Cow()
{
    int x = 9;
    int z = 29;
    int q = 49;
    int y = 2;
    int r = 10;

    // 사육장1 - 소
    gotoXY(x - 2, y + 1); printf("\033[1;33m\|/     (__)");
    gotoXY(x - 1, y + 2); printf("`\-----(oo)");
    gotoXY(x, y + 3); printf("||   (__)");
    gotoXY(x, y + 4); printf("||w--||\033[0m");

    // 사육장2 - 소
    gotoXY(z - 2, y + 1); printf("\033[1;33m\|/     (__)");
    gotoXY(z - 1, y + 2); printf("`\-----(oo)");
    gotoXY(z, y + 3); printf("||   (__)");
    gotoXY(z, y + 4); printf("||w--||\033[0m");

    // 사육장3 - 소
    gotoXY(q - 2, y + 1); printf("\033[1;33m\|/     (__)");
    gotoXY(q - 1, y + 2); printf("`\-----(oo)");
    gotoXY(q, y + 3); printf("||   (__)");
    gotoXY(q, y + 4); printf("||w--||\033[0m");

    // 사육장4 - 소
    gotoXY(x - 2, r + 1); printf("\033[1;33m\|/     (__)");
    gotoXY(x - 1, r + 2); printf("`\-----(oo)");
    gotoXY(x, r + 3); printf("||   (__)");
    gotoXY(x, r + 4); printf("||w--||\033[0m");

    // 사육장5 - 소
    gotoXY(z - 2, r + 1); printf("\033[1;33m\|/     (__)");
    gotoXY(z - 1, r + 2); printf("`\-----(oo)");
    gotoXY(z, r + 3); printf("||   (__)");
    gotoXY(z, r + 4); printf("||w--||\033[0m");

    // 사육장6 - 소
    gotoXY(q - 2, r + 1); printf("\033[1;33m\|/     (__)");
    gotoXY(q - 1, r + 2); printf("`\-----(oo)");
    gotoXY(q, r + 3); printf("||   (__)");
    gotoXY(q, r + 4); printf("||w--||\033[0m");
}

void Pig()
{
    int x = 8;
    int z = 28;
    int q = 48;
    int y = 2;
    int r = 10;

    // 사육장1 - 돼지
    gotoXY(x - 1, y + 2); printf("\033[1;31m  ⌒⌒__");
    gotoXY(x, y + 3); printf("c' '    )@");
    gotoXY(x, y + 4); printf("  '' ''\033[0m");

    // 사육장2 - 돼지
    gotoXY(z - 1, y + 2); printf("\033[1;31m  ⌒⌒__");
    gotoXY(z, y + 3); printf("c' '    )@");
    gotoXY(z, y + 4); printf("  ' ' ' '\033[0m");

    // 사육장3 - 돼지
    gotoXY(q - 1, y + 2); printf("\033[1;31m  ⌒⌒__");
    gotoXY(q, y + 3); printf("c' '    )@");
    gotoXY(q, y + 4); printf("  ' ' ' '\033[0m");

    // 사육장4 - 돼지
    gotoXY(x - 1, r + 2); printf("\033[1;31m  ⌒⌒__");
    gotoXY(x, r + 3); printf("c' '    )@");
    gotoXY(x, r + 4); printf("  ' ' ' '\033[0m");

    // 사육장5 - 돼지
    gotoXY(z - 1, r + 2); printf("\033[1;31m  ⌒⌒__");
    gotoXY(z, r + 3); printf("c' '    )@");
    gotoXY(z, r + 4); printf("  ' ' ' '\033[0m");

    // 사육장6 - 돼지
    gotoXY(q - 1, r + 2); printf("\033[1;31m  ⌒⌒__");
    gotoXY(q, r + 3); printf("c' '    )@");
    gotoXY(q, r + 4); printf("  ' ' ' '\033[0m");
}

void Chicken()
{
    int x = 9;
    int z = 29;
    int q = 49;
    int y = 2;
    int r = 10;

    // 사육장1 - 닭
    gotoXY(x, y + 1); printf("\033[0;33m\MM");
    gotoXY(x, y + 2); printf("<' \\__/|");
    gotoXY(x, y + 3); printf(" \\_  _/ ");
    gotoXY(x, y + 4); printf("  ][ \033[0m");

    // 사육장2 - 닭
    gotoXY(z, y + 1); printf("\033[0;33m\MM");
    gotoXY(z, y + 2); printf("<' \\__/|");
    gotoXY(z, y + 3); printf(" \\_  _/ ");
    gotoXY(z, y + 4); printf("  ][ \033[0m");

    // 사육장3 - 닭
    gotoXY(q, y + 1); printf("\033[0;33m\MM");
    gotoXY(q, y + 2); printf("<' \\__/|");
    gotoXY(q, y + 3); printf(" \\_  _/ ");
    gotoXY(q, y + 4); printf("  ][ \033[0m");

    // 사육장4 - 닭
    gotoXY(x, r + 1); printf("\033[0;33m\MM");
    gotoXY(x, r + 2); printf("<' \\__/|");
    gotoXY(x, r + 3); printf(" \\_  _/ ");
    gotoXY(x, r + 4); printf("  ][ \033[0m");

    // 사육장5 - 닭
    gotoXY(z, r + 1); printf("\033[0;33m\MM");
    gotoXY(z - 1, r + 2); printf("<' \\__/|");
    gotoXY(z, r + 3); printf(" \\_  _/ ");
    gotoXY(z, r + 4); printf("  ][ \033[0m");

    // 사육장6 - 닭
    gotoXY(q, r + 1); printf("\033[0;33m\MM");
    gotoXY(q - 1, r + 2); printf("<' \\__/|");
    gotoXY(q, r + 3); printf(" \\_  _/ ");
    gotoXY(q, r + 4); printf("  ][ \033[0m");
}

// 사료 급여 선택
void Peed()
{
    int x = 2;
    int y = 22;

    gotoXY(x - 2, y); printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
    gotoXY(x - 1, y + 1); printf("▷ 사료를 주겠습니까?");

    gotoXY(x + 20, y + 4); printf(" ┏━━━━━━━┓");
    gotoXY(x + 20, y + 5); printf("ㅤㅤ 예");
    gotoXY(x + 20, y + 6); printf(" ┗━━━━━━━┛");

    gotoXY(x + 40, y + 4); printf(" ┏━━━━━━━┓");
    gotoXY(x + 40, y + 5); printf("ㅤ 아니요");
    gotoXY(x + 40, y + 6); printf(" ┗━━━━━━━┛");
}

// 동물 배치 선택
void Arr()
{
    int x = 12;
    int z = 2;
    int y = 22;
    gotoXY(z - 2, y); printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
    gotoXY(z - 1, y + 1); printf("▷ 무엇을 배치하겠습니까?");

    gotoXY(x, y + 3); printf(" ┏━━━━━━━━━━┓");
    gotoXY(x, y + 4); printf("ㅤㅤㅤ 소");
    gotoXY(x, y + 5); printf("ㅤ  보유: n");
    gotoXY(x, y + 6); printf(" ┗━━━━━━━━━━┛");

    gotoXY(x + 20, y + 3); printf(" ┏━━━━━━━━━━┓");
    gotoXY(x + 20, y + 4); printf("ㅤㅤㅤ돼지");
    gotoXY(x + 20, y + 5); printf("ㅤ  보유: n");
    gotoXY(x + 20, y + 6); printf(" ┗━━━━━━━━━━┛");

    gotoXY(x + 40, y + 3); printf(" ┏━━━━━━━━━━┓");
    gotoXY(x + 40, y + 4); printf("ㅤㅤㅤ 닭");
    gotoXY(x + 40, y + 5); printf("ㅤ  보유: n");
    gotoXY(x + 40, y + 6); printf(" ┗━━━━━━━━━━┛");
}

// PC 메뉴
void PcMenu1()
{
    int x = 6;
    int y = 4;

    // 칸 1
    gotoXY(x, y + 1); printf("%s", pc[0].item[0]);
    gotoXY(x, y + 3); printf("구매금액: %d원", pc[0].money[0]);

    // 칸 2
    gotoXY(x, y + 6); printf("%s", pc[0].item[1]);
    gotoXY(x, y + 8); printf("구매금액: %d원", pc[0].money[1]);

    // 칸 3
    gotoXY(x, y + 11); printf("%s", pc[0].item[2]);
    gotoXY(x, y + 13); printf("구매금액: %d원", pc[0].money[2]);

    // 칸 4
    gotoXY(x, y + 16); printf("%s", pc[0].item[3]);
    gotoXY(x, y + 18); printf("구매금액: %d원", pc[0].money[3]);

}
void PcMenu2()
{
    int x = 6;
    int y = 4;

    // 칸 1
    gotoXY(x, y + 1); printf("%s", pc[1].item[0]);
    gotoXY(x, y + 3); printf("구매금액: %d원", pc[1].money[0]);

    // 칸 2
    gotoXY(x, y + 6); printf("%s", pc[1].item[1]);
    gotoXY(x, y + 8); printf("구매금액: %d원", pc[1].money[1]);

    // 칸 3
    gotoXY(x, y + 11); printf("%s", pc[1].item[2]);
    gotoXY(x, y + 13); printf("구매금액: %d원", pc[1].money[2]);
    
    // 칸 4
    gotoXY(x, y + 16); printf("--");
    gotoXY(x, y + 18); printf("--");

}
void PcMenu3()
{
    int x = 6;
    int y = 4;

    // 칸 1
    gotoXY(x, y + 1); printf("%s", pc[2].item[0]);
    gotoXY(x, y + 3); printf("구매금액: %d원", pc[2].money[0]);

    // 칸 2
    gotoXY(x, y + 6); printf("%s", pc[2].item[1]);
    gotoXY(x, y + 8); printf("구매금액: %d원", pc[2].money[1]);

    // 칸 3
    gotoXY(x, y + 11); printf("%s", pc[2].item[2]);
    gotoXY(x, y + 13); printf("구매금액: %d원", pc[2].money[2]);

    // 칸 4
    gotoXY(x, y + 16); printf("--");
    gotoXY(x, y + 18); printf("--");
}
void PcPur(int screen, int index)
{
    int x = 20;
    int z = 52;
    int y = 8;

    gotoXY(x, y); printf("┌───────────────────────────────┐");

    gotoXY(x, y + 1); printf("│");
    gotoXY(z, y + 1); printf("│");
    gotoXY(x, y + 2); printf("│");
    gotoXY(z, y + 2); printf("│");

    gotoXY(x, y + 3); printf("│");
    gotoXY(z, y + 3); printf("│");
    gotoXY(x + 3, y + 3); printf("%s을 몇 개 구입하겠습니까?", pc[screen].item[index]);

    gotoXY(x, y + 4); printf("│");
    gotoXY(z, y + 4); printf("│");
    gotoXY(x, y + 5); printf("│");
    gotoXY(z, y + 5); printf("│");
    gotoXY(x + 3, y + 5); printf("5개 이상 구매 시 10%% 할인");

    gotoXY(x, y + 6); printf("│");
    gotoXY(z, y + 6); printf("│");
    gotoXY(x, y + 7); printf("│");
    gotoXY(z, y + 7); printf("│");
    gotoXY(x, y + 8); printf("│");
    gotoXY(z, y + 8); printf("│");
    gotoXY(x, y + 9); printf("│");
    gotoXY(z, y + 9); printf("│");

    gotoXY(x, y + 10); printf("└───────────────────────────────┘");
}

// 스킬 메뉴
void PcSkill()
{
    int x = 6;
    int y = 4;

    // 칸 1
    gotoXY(x, y + 1); printf("%s - %d원", skillTree->skill.name, skillTree->skill.money);
    gotoXY(x, y + 3); printf("▶ %s", skillTree->skill.descript);
    gotoXY(x, y + 4); printf("\033[1;34m%s\033[0m", skillTree->skill.effect);

    // 칸 2
    gotoXY(x, y + 6); printf("달구지 - 10,000원");
    gotoXY(x, y + 8); printf("▶ 소를 데려와 밭을 쉽게 갈 수 있다!");
    gotoXY(x, y + 9); printf("\033[1;34m밭+1 사육장+1 소+1\033[0m");

    // 칸 3
    gotoXY(x, y + 11); printf("경운기 - 25,000원");
    gotoXY(x, y + 13); printf("▶ 밭을 어마어마하게 쉽게 갈 수 있다!");
    gotoXY(x, y + 14); printf("\033[1;34m밭+1\033[0m");

    // 칸 4
    gotoXY(x, y + 16); printf("외양간 - 10,000원");
    gotoXY(x, y + 18); printf("▶ 동물을 더 많이 관리할 수 있다!");
    gotoXY(x, y + 19); printf("\033[1;34m사육장+1\033[0m");

    gotoXY(x + 60, y + 20); printf(" \033[1;34m┏━━━━━━━━━┓");
    gotoXY(x + 60, y + 21); printf("ㅤ 스킬트리");
    gotoXY(x + 60, y + 22); printf(" ┗━━━━━━━━━┛\033[0m");
}

// PC 화면
void PcOrder(int screen, char** color)
{
    int x = 4;
    int z = 52;
    int y = 4;

    Frame();
    // 칸 1
    gotoXY(x, y); printf("┌───────────────────────────────────────────────┐");
    gotoXY(z - 8, y); printf("┬");
    gotoXY(x, y + 1); printf("│");
    gotoXY(z - 8, y + 1); printf("│");
    gotoXY(z, y + 1); printf("│");
    gotoXY(x, y + 2); printf("│");
    gotoXY(z - 8, y + 2); printf("│");
    gotoXY(z, y + 2); printf("│");
    gotoXY(x, y + 3); printf("│");
    gotoXY(z - 8, y + 3); printf("│");
    gotoXY(z, y + 3); printf("│");
    gotoXY(x, y + 4); printf("│");
    gotoXY(z - 8, y + 4); printf("│");
    gotoXY(z, y + 4); printf("│");

    gotoXY(z - 5, y + 2); printf("%s발주", color[0]);
    gotoXY(z - 5, y + 3); printf("신청%s", NONE);

    // 칸 2
    gotoXY(x, y + 5); printf("├───────────────────────────────────────────────┤");
    gotoXY(z - 8, y + 5); printf("┼");
    gotoXY(x, y + 6); printf("│");
    gotoXY(z - 8, y + 6); printf("│");
    gotoXY(z, y + 6); printf("│");
    gotoXY(x, y + 7); printf("│");
    gotoXY(z - 8, y + 7); printf("│");
    gotoXY(z, y + 7); printf("│");
    gotoXY(x, y + 8); printf("│");
    gotoXY(z - 8, y + 8); printf("│");
    gotoXY(z, y + 8); printf("│");
    gotoXY(x, y + 9); printf("│");
    gotoXY(z - 8, y + 9); printf("│");
    gotoXY(z, y + 9); printf("│");

    gotoXY(z - 5, y + 7); printf("%s발주", color[1]);
    gotoXY(z - 5, y + 8); printf("신청%s", NONE);

    // 칸 3
    gotoXY(x, y + 10); printf("├───────────────────────────────────────────────┤");
    gotoXY(z - 8, y + 10); printf("┼");
    gotoXY(x, y + 11); printf("│");
    gotoXY(z - 8, y + 11); printf("│");
    gotoXY(z, y + 11); printf("│");
    gotoXY(x, y + 12); printf("│");
    gotoXY(z - 8, y + 12); printf("│");
    gotoXY(z, y + 12); printf("│");
    gotoXY(x, y + 13); printf("│");
    gotoXY(z - 8, y + 13); printf("│");
    gotoXY(z, y + 13); printf("│");
    gotoXY(x, y + 14); printf("│");
    gotoXY(z - 8, y + 14); printf("│");
    gotoXY(z, y + 14); printf("│");

    gotoXY(z - 5, y + 12); printf("%s발주", color[2]);
    gotoXY(z - 5, y + 13); printf("신청%s", NONE);

    // 칸 4
    gotoXY(x, y + 15); printf("├───────────────────────────────────────────────┤");
    gotoXY(z - 8, y + 15); printf("┼");
    gotoXY(x, y + 16); printf("│");
    gotoXY(z - 8, y + 16); printf("│");
    gotoXY(z, y + 16); printf("│");
    gotoXY(x, y + 17); printf("│");
    gotoXY(z - 8, y + 17); printf("│");
    gotoXY(z, y + 17); printf("│");
    gotoXY(x, y + 18); printf("│");
    gotoXY(z - 8, y + 18); printf("│");
    gotoXY(z, y + 18); printf("│");
    gotoXY(x, y + 19); printf("│");
    gotoXY(z - 8, y + 19); printf("│");
    gotoXY(z, y + 19); printf("│");
    
    gotoXY(z - 5, y + 17); printf("%s발주", color[3]);
    gotoXY(z - 5, y + 18); printf("신청%s", NONE);

    gotoXY(x, y + 20); printf("└───────────────────────────────────────────────┘");
    gotoXY(z - 8, y + 20); printf("┴");

    // A <-> D
    gotoXY(x - 1, y + 22); printf("\033[1;35m◁");
    gotoXY(z + 1, y + 22); printf("▷");
    gotoXY(x - 1, y + 23); printf("A");
    gotoXY(z + 1, y + 23); printf(" D\033[0m");

    // 농장으로
    gotoXY(x + 62, y + 14); printf(" \033[1;32m┏━━━━━━━━━┓");
    gotoXY(x + 62, y + 15); printf("ㅤ 농장으로");
    gotoXY(x + 62, y + 16); printf(" ┗━━━━━━━━━┛\033[0m");
    // 장사 시작
    gotoXY(x + 62, y + 17); printf(" \033[1;35m┏━━━━━━━━━┓");
    gotoXY(x + 62, y + 18); printf("ㅤ 장사시작");
    gotoXY(x + 62, y + 19); printf(" ┗━━━━━━━━━┛\033[0m");

    switch (screen) {
    case 0:
        PcMenu1();
        break;
    case 1:
        PcMenu2();
        break;
    case 2:
        PcMenu3();
        break;
    case 3:
        PcSkill();
        break;
    }
}

void Recipe(List* pick, int index)
{
    int x = 1;
    int y = 22;
    List* p = pick->next;

    gotoXY(x - 1, y); printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
    gotoXY(x, y + 1); printf("★ 레시피");
    for (int i = 0; i < index; i++) {
        p = p->next;
    }
    gotoXY(x, y + 3); printf("%s", p->order.recipe);
}

// 가게
void Store(List* pick, int index)
{
    int x = 0;
    int y = 1;
    int a = 15;
    int b = 30;
    int c = 45;
    int x2 = 2;
    char* color[4] = { NONE, NONE, NONE, NONE };

    color[index] = GREEN;
    Frame();
    gotoXY(x, y); printf("\033[0;33m┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    gotoXY(x, y + 1); printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\033[0m");

    for (List* p = pick->next; p != pick && x2 <= 47; p = p->next, x2 += 15) {
        gotoXY(x2, y + 2); printf("주문 번호");
        gotoXY(x2, y + 3); printf("%2d", p->order.orderNum);
        gotoXY(x2, y + 5); printf("메뉴 이름");
        gotoXY(x2, y + 6); printf("%s", p->order.menu);
        gotoXY(x2, y + 8); printf("금액");
        gotoXY(x2, y + 9); printf("%d", p->order.cost);
        gotoXY(x2 + 2, y + 11); printf("┏━━━━━┓");
        gotoXY(x2 + 2, y + 12); printf("ㅤ%s제작%s", color[x2 / 15], NONE);
        gotoXY(x2 + 2, y + 13); printf("┗━━━━━┛");
    }

    // 주문서 1
    gotoXY(x, y + 2); printf("│");
    gotoXY(x, y + 3); printf("│");
    gotoXY(x, y + 4); printf("│");
    gotoXY(x, y + 5); printf("│");
    gotoXY(x, y + 6); printf("│");
    gotoXY(x, y + 7); printf("│");
    gotoXY(x, y + 8); printf("│");
    gotoXY(x, y + 9); printf("│");
    gotoXY(x, y + 10); printf("│");
    gotoXY(x, y + 11); printf("│");
    gotoXY(x, y + 12); printf("│");
    gotoXY(x, y + 13); printf("│");
    gotoXY(x, y + 14); printf("└────────────");

    gotoXY(a - 1, y + 2); printf("│");
    gotoXY(a - 1, y + 3); printf("│");
    gotoXY(a - 1, y + 4); printf("│");
    gotoXY(a - 1, y + 5); printf("│");
    gotoXY(a - 1, y + 6); printf("│");
    gotoXY(a - 1, y + 7); printf("│");
    gotoXY(a - 1, y + 8); printf("│");
    gotoXY(a - 1, y + 9); printf("│");
    gotoXY(a - 1, y + 10); printf("│");
    gotoXY(a - 1, y + 11); printf("│");
    gotoXY(a - 1, y + 12); printf("│");
    gotoXY(a - 1, y + 13); printf("│");
    gotoXY(a - 1, y + 14); printf("┘");

    // 주문서 2
    gotoXY(a, y + 2); printf("│");
    gotoXY(a, y + 3); printf("│");
    gotoXY(a, y + 4); printf("│");
    gotoXY(a, y + 5); printf("│");
    gotoXY(a, y + 6); printf("│");
    gotoXY(a, y + 7); printf("│");
    gotoXY(a, y + 8); printf("│");
    gotoXY(a, y + 9); printf("│");
    gotoXY(a, y + 10); printf("│");
    gotoXY(a, y + 11); printf("│");
    gotoXY(a, y + 12); printf("│");
    gotoXY(a, y + 13); printf("│");
    gotoXY(a, y + 14); printf("└────────────");

    gotoXY(b - 1, y + 2); printf("│");
    gotoXY(b - 1, y + 3); printf("│");
    gotoXY(b - 1, y + 4); printf("│");
    gotoXY(b - 1, y + 5); printf("│");
    gotoXY(b - 1, y + 6); printf("│");
    gotoXY(b - 1, y + 7); printf("│");
    gotoXY(b - 1, y + 8); printf("│");
    gotoXY(b - 1, y + 9); printf("│");
    gotoXY(b - 1, y + 10); printf("│");
    gotoXY(b - 1, y + 11); printf("│");
    gotoXY(b - 1, y + 12); printf("│");
    gotoXY(b - 1, y + 13); printf("│");
    gotoXY(b - 1, y + 14); printf("┘");

    // 주문서 3
    gotoXY(b, y + 2); printf("│");
    gotoXY(b, y + 3); printf("│");
    gotoXY(b, y + 4); printf("│");
    gotoXY(b, y + 5); printf("│");
    gotoXY(b, y + 6); printf("│");
    gotoXY(b, y + 7); printf("│");
    gotoXY(b, y + 8); printf("│");
    gotoXY(b, y + 9); printf("│");
    gotoXY(b, y + 10); printf("│");
    gotoXY(b, y + 11); printf("│");
    gotoXY(b, y + 12); printf("│");
    gotoXY(b, y + 13); printf("│");
    gotoXY(b, y + 14); printf("└────────────");

    gotoXY(c - 1, y + 2); printf("│");
    gotoXY(c - 1, y + 3); printf("│");
    gotoXY(c - 1, y + 4); printf("│");
    gotoXY(c - 1, y + 5); printf("│");
    gotoXY(c - 1, y + 6); printf("│");
    gotoXY(c - 1, y + 7); printf("│");
    gotoXY(c - 1, y + 8); printf("│");
    gotoXY(c - 1, y + 9); printf("│");
    gotoXY(c - 1, y + 10); printf("│");
    gotoXY(c - 1, y + 11); printf("│");
    gotoXY(c - 1, y + 12); printf("│");
    gotoXY(c - 1, y + 13); printf("│");
    gotoXY(c - 1, y + 14); printf("┘");

    // 주문서 4
    gotoXY(c, y + 2); printf("│");
    gotoXY(c, y + 3); printf("│");
    gotoXY(c, y + 4); printf("│");
    gotoXY(c, y + 5); printf("│");
    gotoXY(c, y + 6); printf("│");
    gotoXY(c, y + 7); printf("│");
    gotoXY(c, y + 8); printf("│");
    gotoXY(c, y + 9); printf("│");
    gotoXY(c, y + 10); printf("│");
    gotoXY(c, y + 11); printf("│");
    gotoXY(c, y + 12); printf("│");
    gotoXY(c, y + 13); printf("│");
    gotoXY(c, y + 14); printf("└────────────");

    gotoXY(c + 14, y + 2); printf("│");
    gotoXY(c + 14, y + 3); printf("│");
    gotoXY(c + 14, y + 4); printf("│");
    gotoXY(c + 14, y + 5); printf("│");
    gotoXY(c + 14, y + 6); printf("│");
    gotoXY(c + 14, y + 7); printf("│");
    gotoXY(c + 14, y + 8); printf("│");
    gotoXY(c + 14, y + 9); printf("│");
    gotoXY(c + 14, y + 10); printf("│");
    gotoXY(c + 14, y + 11); printf("│");
    gotoXY(c + 14, y + 12); printf("│");
    gotoXY(c + 14, y + 13); printf("│");
    gotoXY(c + 14, y + 14); printf("┘");

    Recipe(pick, index);
}

void StoreClose()
{
    int x = 10;
    int y = 10;

    Frame();
    gotoXY(x + 10, y + 4); printf("\033[1;34m오늘의 장사가 종료 되었습니다.");
    gotoXY(x + 13, y + 5); printf("장사 결과를 확인하세요!");
    gotoXY(x + 39, y + 9); printf("\033[1;35m▷ Enter\033[0m");

    gotoXY(x, y); printf("┌----------------------------------------------┐");
    gotoXY(x, y + 1); printf("│");
    gotoXY(x + 47, y + 1); printf("│");
    gotoXY(x, y + 2); printf("│");
    gotoXY(x + 47, y + 2); printf("│");
    gotoXY(x, y + 3); printf("│");
    gotoXY(x + 47, y + 3); printf("│");
    gotoXY(x, y + 4); printf("│");
    gotoXY(x + 47, y + 4); printf("│");
    gotoXY(x, y + 5); printf("│");
    gotoXY(x + 47, y + 5); printf("│");
    gotoXY(x, y + 6); printf("│");
    gotoXY(x + 47, y + 6); printf("│");
    gotoXY(x, y + 7); printf("│");
    gotoXY(x + 47, y + 7); printf("│");
    gotoXY(x, y + 8); printf("│");
    gotoXY(x + 47, y + 8); printf("│");
    gotoXY(x, y + 9); printf("│");
    gotoXY(x + 47, y + 9); printf("│");

    gotoXY(x, y + 10); printf("└----------------------------------------------┘");

}

void StoreCal()
{
    int x = 14;
    int y = 3;

    Frame();
    gotoXY(x, y); printf("   \033[0;33m______________________________");
    gotoXY(x, y + 1); printf(" / \\                             \\.");
    gotoXY(x, y + 2); printf("|   |                            |.");
    gotoXY(x, y + 3); printf(" \\_ |                            |.");
    gotoXY(x, y + 4); printf("    |                            |.");
    gotoXY(x, y + 5); printf("    |                            |.");
    gotoXY(x, y + 6); printf("    |                            |.");
    gotoXY(x, y + 7); printf("    |                            |.");
    gotoXY(x, y + 8); printf("    |                            |.");
    gotoXY(x, y + 9); printf("    |                            |.");
    gotoXY(x, y + 10); printf("    |                            |.");
    gotoXY(x, y + 11); printf("    |                            |.");
    gotoXY(x, y + 12); printf("    |                            |.");
    gotoXY(x, y + 13); printf("    |                            |.");
    gotoXY(x, y + 14); printf("    |                            |.");
    gotoXY(x, y + 15); printf("    |                            |.");
    gotoXY(x, y + 16); printf("    |                            |.");
    gotoXY(x, y + 17); printf("    |                            |.");
    gotoXY(x, y + 18); printf("    |   _________________________|___");
    gotoXY(x, y + 19); printf("    |  /                            /.");
    gotoXY(x, y + 20); printf("    \\_/____________________________/.\033[0m");

    gotoXY(x + 8, y + 2); printf("\033[1;34m온 손님의 수: %d", account.customer);
    gotoXY(x + 8, y + 3); printf("순 이익: %d\033[0m", account.income);
    gotoXY(x + 8, y + 5); printf("- 판매된 메뉴");
    gotoXY(x + 11, y + 6); printf("계란후라이: %d", account.menu[0]);
    gotoXY(x + 11, y + 7); printf("팝콘: %d", account.menu[1]);
    gotoXY(x + 11, y + 8); printf("베이컨: %d", account.menu[2]);
    gotoXY(x + 11, y + 9); printf("빵: %d", account.menu[3]);
    gotoXY(x + 11, y + 10); printf("달걀 토스트: %d", account.menu[4]);
    gotoXY(x + 11, y + 11); printf("피자빵: %d", account.menu[5]);
    gotoXY(x + 11, y + 12); printf("샐러드: %d", account.menu[6]);
    gotoXY(x + 11, y + 13); printf("샌드위치: %d", account.menu[7]);
    gotoXY(x + 8, y + 15); printf("주문 취소 횟수: %d", account.cancel);
    gotoXY(x + 8, y + 17); printf("\033[1;31m가게세 지불까지 %d일", account.dDay);
    gotoXY(x + 35, y + 22); printf("\033[1;35m▷ Enter\033[0m");
}

// end
void BadEnd()
{
    int x = 1;
    int y = 1;

    Frame();
    gotoXY(x, y); printf("     \033[0;33m_________________________________________________");
    gotoXY(x, y + 1); printf("    /\\                                                \\");
    gotoXY(x, y + 2); printf("(O)===)><><><><><><><><><><><><><><><><><><><><><><><><)==(O)");
    gotoXY(x, y + 3); printf("    \\/''''''''''''''''''''''''''''''''''''''''''''''''/");
    gotoXY(x, y + 4); printf("    (                                                (");
    gotoXY(x, y + 5); printf("     )                                                )");
    gotoXY(x, y + 6); printf("    (                                                (");
    gotoXY(x, y + 7); printf("     )                                                )");

    gotoXY(x, y + 9); printf("    (                                                (");
    gotoXY(x, y + 10); printf("     )                                                )");
    gotoXY(x, y + 11); printf("    (                                                (");
    gotoXY(x, y + 12); printf("     )                                                )");

    gotoXY(x, y + 14); printf("    (                                                (");
    gotoXY(x, y + 15); printf("     )                                                )");
    gotoXY(x, y + 16); printf("    (                                                (");
    gotoXY(x, y + 17); printf("     )                                                )");

    gotoXY(x, y + 19); printf("    (                                                (");
    gotoXY(x, y + 20); printf("     )                                                )");
    gotoXY(x, y + 21); printf("    (                                                (");
    gotoXY(x, y + 22); printf("    /\\''''''''''''''''''''''''''''''''''''''''''''''''\\");
    gotoXY(x, y + 23); printf("(O)===)><><><><><><><><><><><><><><><><><><><><><><><><)==(O)");
    gotoXY(x, y + 24); printf("    \\/________________________________________________/\033[0m");

    gotoXY(x + 18, y + 6); printf("\033[0;35m가게세를 지불하지 못했다!");
    gotoXY(x + 28, y + 10); printf("\033[0;31mGAME");
    gotoXY(x + 28, y + 11); printf("OVER");
    gotoXY(x + 18, y + 17); printf(" \033[1;33m.∧_∧     다음엔 잘될거야");
    gotoXY(x + 18, y + 18); printf("(´'ω')∧∧");
    gotoXY(x + 18, y + 19); printf("./⌒,つ⌒ )");
    gotoXY(x + 18, y + 20); printf("(___ (＿＿)\033[0m");
}

void PlayerFront(int x, int y)
{
    gotoXY(x, y); printf(" ///");
    gotoXY(x, y + 1); printf("(o o)");
    gotoXY(x, y + 2); printf(" ( )");
}
void PlayerBack(int x, int y)
{
    gotoXY(x, y); printf(" \\\\\\");
    gotoXY(x, y + 1); printf("(   )");
    gotoXY(x, y + 2); printf(" ( )");
}
void PlayerRight(int x, int y)
{
    gotoXY(x, y); printf(" ///");
    gotoXY(x, y + 1); printf("(@ o)");
    gotoXY(x, y + 2); printf(" ( )");
}
void PlayerLeft(int x, int y)
{
    gotoXY(x, y); printf(" ///");
    gotoXY(x, y + 1); printf("(o @)");
    gotoXY(x, y + 2); printf(" ( )");
}