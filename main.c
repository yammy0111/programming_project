#include <stdio.h>
#include <string.h>
#include "header.h"

int main() {
    start();
    while (select_menu()) {
        
    }
    return 0;
}

void start() {
    printf("------------------------------\n");
    printf("           타자 연습기         \n");
    printf("------------------------------\n");
}

int select_menu() {
    int menu;
    printf("--------원하는 주제 선택-------\n");
    printf("1. 단어\n2. 문장\n3. 장문\n4.종료\n");
    printf("------------------------------\n");
    printf("메뉴 선택 : ");
    scanf("%d",&menu);
    switch (menu) {
    case 1:
        printf("단어 연습을 시작합니다.\n");
        //단어 연습 함수 호출
        break;
    case 2:
        printf("문장 연습을 시작합니다.\n");
        //문장 연습 함수 호출
        break;
    case 3:
        printf("장문 연습을 시작합니다.\n");
        //장문 연습 함수 호출
        break;  
    case 4:
        printf("프로그램을 종료합니다.");
        return 0;
    default:
        printf("옿바르지 못한 입력입니다.\n");
        break;
    }
    return 1;
}