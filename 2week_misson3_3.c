#include <stdio.h>
#include <cs50.h>
#include <string.h> //strcmp

string find(string week){
    string menu;
    //string mon = "월요일";
    //if(strcmp(week, mon)==0) menu = "청국장";
    if(strcmp(week, "월요일")==0) menu = "청국장";
    else if(strcmp(week, "화요일")==0) menu = "비빔밥";
    else if(strcmp(week, "수요일")==0) menu = "된장찌개";
    else if(strcmp(week, "목요일")==0) menu = "칼국수";
    else if(strcmp(week, "금요일")==0) menu = "냉면";
    else if(strcmp(week, "토요일")==0) menu = "소불고기";
    else if(strcmp(week, "일요일")==0) menu = "오삼불고기";
    else menu = "메뉴없음";
    return menu;
}

int main(void){
    string week;
    string menufind;
    string nofind = "메뉴없음";

    while(true){
        week = get_string("요일을 입력하세요 : ");
        menufind = find(week);
        if(strcmp(menufind, nofind)==0) continue; //메뉴를 못찾으면 계속 while문 반복
        else break; //메뉴를 찾으면 while문 빠져나가기
    }
    printf("%s : %s\n", week, menufind);
}

