#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

int shortest_distance(string input);
int search_median(int* array, int number_len);
int* mergeSort(int* array, int p, int r);
void merge(int* array, int p, int q, int r);

int main(void){
    
    int check;

    printf("\n[친구들과 최단거리에 있는 집 구하기]\n\n");
    printf("종료를 원하면 \"999\" 를 입력해주세요.\n");
    printf("띄어쓰기로 구분해주시고 중복 가능합니다. ex)1 2 2 4 5\n\n");

    while(1) {
        string input = get_string("친구들의 집을 정수로 입력해주세요 : ");
        check = shortest_distance(input);
        if(check == 1) break;
    }
}

int shortest_distance(string input) {             // 최단거리 찾기 : int 배열에 숫자넣고, 병합정렬, 중앙값 찾기

    int string_len = strlen(input);
    int* number_array = (int *)malloc(sizeof(int) * string_len);
    int number_len = 0;
    int integer = 0;

    if(number_array == NULL) {
        printf("malloc error\n");
        exit(-1);
    }
    
    for (int i = 0, j = 0; i < string_len; i++) {   //입력받은 string에서 숫자만 array에 넣기
        if(input[i] == 32) {
            if(integer == 999) return 1;
            number_array[j] = integer;
            integer = 0; j++;
            continue;
        }

        integer *= 10;
        integer += input[i] - '0';
        if(integer == 999) return 1;

        if(i == (string_len - 1)){
            number_array[j] = integer;
            integer = 0; j++; number_len = j;
        }
    }

    number_array = mergeSort(number_array, 0, number_len-1);    // 배열 정렬

    printf("정렬된 친구들의 집위치 : ");
    for (int i = 0; i < number_len; i++) printf("%d ", number_array[i]);
    printf("\n");

    int median = search_median(number_array, number_len);              //중앙값 찾기
    printf("친구들과 최단거리에 있는 집위치(중앙값) : %d\n\n", median);

    free(number_array);                                         
    return 0;
}

int* mergeSort(int* array, int p, int r) {  //합병정렬
    int q;
    if(p<r) {
        q = (p+r)/2;
        mergeSort(array, p , q);
        mergeSort(array, q+1, r);
        merge(array, p, q, r);
    }
    return array;
}

void merge(int* array, int p, int q, int r) {
    int i = p, j = q+1, k = p;
    int tmp[r+1];
    while(i<=q && j<=r) {
        if(array[i] <= array[j]) tmp[k++] = array[i++];
        else tmp[k++] = array[j++];
    }
    while(i<=q) tmp[k++] = array[i++];
    while(j<=r) tmp[k++] = array[j++];
    for(int a = p; a<=r; a++) array[a] = tmp[a];
}


int search_median(int* array, int number_len)      // 배열에서 중앙값 찾기
{
  int median = 0;
  if(number_len % 2 == 1) {                 // 배열이 홀수
      median = array[(number_len - 1) / 2];
  }     
  else {                                    // 배열이 짝수
      int m = array[number_len / 2];
      int n = array[(number_len / 2) - 1];
      median = (m + n) / 2;
  }
  return median;
}

/*int* bubble(int* array, int number_len) //버블정렬
{
  int temp;
  for (int i=0; i < number_len; i++) {
    for (int j=0; j < number_len - i - 1; j++ ) {
      if (array[j] > array[j+1]) {
        temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
      }
    }
  }
  return array;
}*/
