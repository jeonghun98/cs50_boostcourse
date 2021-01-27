#include <stdio.h>
#include <cs50.h>

int find_grade(int grade);

int main(void){
    
    string grade_string[9] = {"A+", "A", "B+","B","C+","C","D+","D","F"};
    int grade_number[9] = {95,90,85,80,75,70,65,60,0};

    printf("학점 프로그램\n");
    printf("종료를 원하면 \"999\" 를 입력\n");
    printf("[학점 테이블]\n");

    printf("점수 : ");
    for(int i = 0; i < 9; i++) printf("%d\t", grade_number[i]);
    printf("\n학점 : ");
    for(int i = 0; i < 9; i++) printf("%s\t", grade_string[i]);
    printf("\n");

    int input_grade = -1, index = -1;                                //입력받을 성적과 인덱스 번호 저장 변수
    while(true) {
        input_grade = get_int("성적을 입력하세요 (0 ~ 100) : ");
        if(input_grade == 999) break;                               //999입력하면 종료됨 (while문 벗어남)
        if(input_grade > 100 || input_grade < 0) {                  //범위내 입력안하면 다시 입력받음(while문 다시 시작)
            printf("** %d 성적을 올바르게 입력하세요. 범위는 0 ~ 100 입니다.\n", input_grade);
            continue;
        }
        index = find_grade(input_grade);                            //입력받은 성적에 맞는 index구하기
        //if(index == -1) continue;
        printf("학점은 %s 입니다.\n", grade_string[index]);
    }
    printf("학점 프로그램을 종료합니다.\n");   
}

int find_grade(int grade){
    int index = -1;
    switch(grade/10){
        case 10:
        case 9:
            if (grade > 94) index = 0;      //A+
            else index = 1;                 //A
            break;
        case 8:
            if (grade > 84) index = 2;      //B+
            else index = 3;                 //B
            break;
        case 7:
            if (grade > 74) index = 4;      //C+
            else index = 5;                 //C
            break;
        case 6:
            if (grade > 64) index = 6;      //D+
            else index = 7;                 //D
            break;
        default:
            index = 8;                      //F
    }
    return index;
}


