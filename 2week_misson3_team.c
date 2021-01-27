#include <cs50.h>
#include <stdio.h>
#include <string.h> //strcmp

string find(string);

int main(void)
{   
    string week; //입력받을 요일변수
    string menufind; //요일에 맞는 메뉴
    string nofind = "메뉴없음"; //메뉴를 찾지 못했을때 사용할 변수
    char rechoose;

    //안내 문구 출력
    printf("\n\t\t어서 오세요 고객님!\n");
    printf("\t현재 '오늘의 메뉴'를 할인 판매 중입니다.\n");
    //요일 입력, 정해진 숫자 외 입력시 다시 입력하게 됨
Retry:
    printf("============================================================\n");
    week = get_string("오늘의 요일을 입력해주세요 : ");
    menufind = find(week);
    if(strcmp(menufind, nofind)==0) goto Retry; //메뉴를 못찾으면 계속 while문 반복

    //최종 요일과 메뉴 출력
    printf("%s의 할인 메뉴는 %s입니다.\n", week, menufind);
    printf("------------------------------------------------------------\n"); 
	
    //요일 재선택 기회
Retry2:  
    rechoose = get_char("요일을 다시 선택하시겠습니까?(y/n): ");
    if(rechoose == 'y'){
        printf("\n");
        goto Retry;
    }
    else if(rechoose == 'n'){
        printf("감사합니다! 즐거운 하루 되십시오.\n");
    }        
    else {
        printf("잘못된 입력입니다. y 또는 n 을 입력해 주십시오.\n");
        goto Retry2;
    }
}

string find(string week){
    string menu;
    //string mon = "월요일";
    //if(strcmp(week, mon)==0) menu = "청국장"; 이것도 가능한 방법

    if(strcmp(week, "월요일")==0) menu = "청국장"; //입력값이 월요일이면 청국장 return
    else if(strcmp(week, "화요일")==0) menu = "비빔밥";
    else if(strcmp(week, "수요일")==0) menu = "된장찌개";
    else if(strcmp(week, "목요일")==0) menu = "칼국수";
    else if(strcmp(week, "금요일")==0) menu = "냉면";
    else if(strcmp(week, "토요일")==0) menu = "소불고기";
    else if(strcmp(week, "일요일")==0) menu = "오삼불고기";
    else menu = "메뉴없음";
    return menu;
}
