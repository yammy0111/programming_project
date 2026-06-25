#include <stdio.h>
#include <string.h>
#include <time.h>
#include "header.h"

int main(){
    start();
    while(1) {
        int m = select_menu(); //메뉴 입력 받기
        if (m==0) return 0;
        else if (m==9) print_record(); //기록 출력
        else if ( (m>=1) && (m<=3) ){ 
            clock_t start = clock();//타자 연습 시작
            typing(m-1);
            if(result(m,start)==0) return 0;
        }
    }
}

void start()/*시작 전 처리*/ {
    struct record_type record[1000] = {0,0,0,0};
    printf("-------------------------------\n");
    printf("-         타자 연습기         -\n");
    printf("-------------------------------\n");
}

int select_menu()/*메뉴 선택*/ {
    char menu;
    printf("--------원하는 주제 선택-------\n");
    printf("1. 단어\n2. 문장\n3. 장문\n9. 기록\n0. 종료\n");
    printf("------------------------------\n");
    printf("메뉴 선택 : ");
    scanf(" %c",&menu);
    menu -= 48;
    while(getchar() != '\n');
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
    case 9:
        printf("현재까지의 기록을 확인합니다.\n");
        break;
    case 0:
        printf("프로그램을 종료합니다.");
        break;
    default:
        printf("올바르지 못한 입력입니다.\n");
        return -1;
    }
    return menu;
}

double calculate_accurate(int index)/*정확도 계산*/ {
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

void typing(int n) /*타자 입력*/ {
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

int result(int m, int start) /*결과(정확도, 시간, 타자수) 출력*/ {
    double typing_time = (clock()-(double)start)/CLOCKS_PER_SEC;
    double accurate = calculate_accurate(m-1); //정확도
    int input_num = 0; //총 타자수
    for(int i = 0; i<100;i++) /*입력 초기화*/{
        for(int j = 0; j<1000; j++) {
            if (input[i][j]) {
                input_num += 1;
                input[i][j] = 0;
            }
        }
    }
    printf("분당 타자 수: %d\n시간: %.1f초\n정확도: %.1f%%\n",((int)typing_time)!=0 ? (int)(input_num/(typing_time/60)) : input_num*60, typing_time, accurate);
    record[total_tried].time = typing_time; //기록 저장
    record[total_tried].accurate = accurate;
    record[total_tried].tying_speed = (((int)typing_time)!=0 ? (int)(input_num/(typing_time/60)) : input_num*60);
    if (m==1) strcpy(record[total_tried].type,"단어");
    else if (m==2) strcpy(record[total_tried].type,"문장");
    else if (m==3) strcpy(record[total_tried].type,"장문");
    total_tried+=1;
    printf("계속하려면 1, 끝내시려면 0을 입력해주세요.\n");
    int n;
    scanf("%d", &n);
    while(getchar() != '\n');
    if (n==0) {
    printf("프로그램을 종료합니다.");
            return 0;
    }
    else return 1;
}

void print_record()/*기록 출력*/ {
    if(total_tried==0) printf("기록이 없습니다.\n");
    for(int i = 0;i < total_tried;i++){
        printf("항목: %s | 분당 타자 수: %d | 시간: %.1f초 | 정확도: %.1f%%\n",record[i].type, record[i].tying_speed, record[i].time, record[i].accurate);
    }
    printf("기록 확인을 종료하려면 엔터키를 눌러주세요");
    while(getchar()!='\n');
}