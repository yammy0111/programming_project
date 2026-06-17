#include <stdio.h>
#include <string.h>
#include <time.h>
#include "header.h"

int main(){
    start();
    while(1){
        int m = select_menu();
        if (m==0) {
            printf("프로그램을 종료합니다.");
            return 0;
        }


        if ( (m>=1) && (m<=2) ){
            typing(m-1);
            printf("시간: %.1f\n정확도: %.1f%%\n", 0, calculate_accurate(m-1));
            printf("계속하려면 1, 끝내시려면 0을 입력해주세요.\n");
            int n;
            scanf("%d", &n);
            while(getchar() != '\n');
            if (n==0) {
                printf("프로그램을 종료합니다.");
                return 0;
            }
        }
    }


    //typing(0);
    //printf("정확도: %f%%",calculate_accurate(0));
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
    getchar();
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
        return -1;
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

void typing(int n)
{
    printf("위의 텍스트를 따라서 입력해주세요.\n");
    int i = 0;
    while(str[n][i][0]!='*'){
        printf("# ");
        puts(str[n][i]);
        printf("> ");
        fgets(input[i],sizeof(input[i]),stdin);
        input[i][strcspn(input[i], "\n")] = '\0';
        i++;
    }
}



