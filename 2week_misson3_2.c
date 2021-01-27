#include <stdio.h>
//#include <cs50.h>
#include <string.h> //strcmp

int main(void){

    char menu[7][2][20] = {{"월요일", "청국장"}, {"화요일", "비빔밥"}, {"수요일", "된장찌개"},
    {"목요일", "칼국수"}, {"금요일", "냉면"}, {"토요일","소불고기"},{"일요일","오삼불고기"}};
    
    int day = -1; int k;
    while(day == -1){
    	char str[20];
    	printf("요일을 입력하세요 : ");
    	scanf("%s", str);
        for(int i = 0; i < 7; i++){
            if(strcmp(menu[i][0], str) == 0){
                day = i; break;
            }
        }
    }
    printf("%s : %s\n", menu[day][0], menu[day][1]);
}
