#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

const int NUMBER_OF_GRADES = 9;
const int SCORES[NUMBER_OF_GRADES] = {95, 90, 85, 80, 75, 70, 65, 60, 0};
const char *GRADES[NUMBER_OF_GRADES] = {"A+", "A", "B+", "B", "C+", "C", "D+", "D", "F"};

void find_grade(int);
void menu_intro(void);
int check_grade(int);

int main(void){
    menu_intro();

    int input_grade = -1, check;
    while(1) {
        //printf("성적을 입력하세요 (0 ~ 100) : ");
        //scanf(" %d", &input_grade);
        input_grade = get_int("성적을 입력하세요 (0 ~ 100) : ");        
        check = check_grade(input_grade);
        if(check == 0) break;
        else if(check == -1) continue;
        find_grade(input_grade);
    }
    printf("학점 프로그램을 종료합니다.\n");   
}

void menu_intro(void){ 
    printf("학점 프로그램\n");
    printf("종료를 원하면 \"999\" 를 입력\n");
    printf("[학점 테이블]\n");

    printf("점수 : ");
    for(int i = 0; i < NUMBER_OF_GRADES; i++) printf("%d\t", SCORES[i]);
    printf("\n학점 : ");
    for(int i = 0; i < NUMBER_OF_GRADES; i++) printf("%s\t", GRADES[i]);
    printf("\n");
}
int check_grade(int grade){
        if(grade == 999) return 0;
        else if(grade > 100 || grade < 0) {
            printf("** %d 성적을 올바르게 입력하세요. 범위는 0 ~ 100 입니다.\n", grade);
            return -1;
        }
        else return 1;
}

void find_grade(int grade){
    int index = -1;
    if(grade >= SCORES[0]) index = 0;
    else if(grade >= SCORES[1]) index = 1;
    else if(grade >= SCORES[2]) index = 2;
    else if(grade >= SCORES[3]) index = 3;
    else if(grade >= SCORES[4]) index = 4;
    else if(grade >= SCORES[5]) index = 5;
    else if(grade >= SCORES[6]) index = 6;
    else if(grade >= SCORES[7]) index = 7;
    else if(grade >= SCORES[8]) index = 8;

    if(index != -1) printf("학점은 %s 입니다.\n", GRADES[index]);
}
