#include <stdio.h>
#include <string.h>
#include "header.h"

char str[100][100][1000] = { {"test1", "test2", "*"}, {"apple", "banana", "*"} };
char input[100][1000] = {"test1", "te", "end"};

int main() {
    start();
    while (1) {
        int menu = select_menu();
        if(menu == 0)
            break;
        typing(input,menu);
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
    printf("1. 단어\n2. 문장\n3. 장문\n0.종료\n");
    printf("------------------------------\n");
    printf("메뉴 선택 : ");
    scanf("%d",&menu);
    switch (menu) {
    case 1:
        printf("단어 연습을 시작합니다.\n");
        
        break;
    case 2:
        printf("문장 연습을 시작합니다.\n");
        
        break;
    case 3:
        printf("장문 연습을 시작합니다.\n");
        
        break;  
    case 0:
        printf("프로그램을 종료합니다.");
        break;;
    default:
        printf("올바르지 못한 입력입니다.\n");
        break;
    }
    return menu;
}




double calculate_accurate(int index){
    int sum = 0;
    int fail = 0;
    int i = 0;
    while(str[index][i][0]!='*'){
        int j = 0;
        while(str[index][i][j]!='\0'){
            sum++;
            if (str[index][i][j] != input[i][j]) fail++;
            j++;
        }
        i++;
    }


    return 1.0*(sum-fail)/sum*100;
}

void typing(char input[100][1000],int n) //n은 select_menu에서 받은 메뉴 번호
{
   int i;
   for (i = 0; i < sizeof(input[100]); i++)
   {
       printf("%s\n> ",str[n-1][i]);
       fgets(input[i], sizeof(input[100]),stdin);
       input[i][strcspn(input[i], "\n")] = '\0';
   }
   input[i+1][0] = '*';
}

