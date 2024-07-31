#include <stdio.h>
#include <stdlib.h>

// sizeof() 함수는 매개 변수의 크기를 "바이트" 단위로 계산
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

void get_array_none_size(int* input_arr);
void get_array_known_size(int* input_arr, int size);
int get_minimum(int* input_arr);
int get_maximnum(int* input_arr);
void baek_10810();
void baek_10811();

int main() {


    return 0;
}

void get_array_none_size(int* input_arr) {
    int size;
    scanf("%d", &size);

    int numbers[size];
    for(int idx = 0; idx < size; idx++)
        scanf("%d", &numbers[idx]);

    input_arr = numbers;
}

void get_array_known_size(int* input_arr, int size) {
    input_arr = (int*)calloc(size, sizeof(int));
    int check = 0;

    printf("1 : 0~size-1 오름차순\n2 : 1~size 오름차순\n3 : 직접 입력\n선택: ");
    scanf("%d", &check);
    switch(check) {
        case 1:
            for(int idx = 0; idx < size; idx++)
                input_arr[idx] = idx;
            break;
        case 2:
            for(int idx = 0; idx < size; idx++)
                input_arr[idx] = idx+1;
            break;
        case 3:
            for(int idx = 0; idx < size; idx++)
                scanf("%d", &input_arr[idx]);
            break;
        default:
            printf("선택에 존재하지 않는 경우입니다.");
    }
}

int get_minimum(int* input_arr) {
    int* temp = input_arr;
    if(temp == NULL) {
        printf("get_minimum: 입력받은 배열이 NULL입니다.\n");
        return -1;
    }

    int len = ARRAY_SIZE(temp);
    int min = temp[0];
    
    for(int idx=1; idx < len; idx++) {
        if(temp[idx] < min)
            min = temp[idx];
    }

    return min;
}

int get_maximnum(int* input_arr) {
    int* temp = input_arr;
    if(temp == NULL) {
        printf("get_maximnum: 입력받은 배열이 NULL입니다.\n");
        return -1;
    }

    int len = ARRAY_SIZE(temp);
    int max = temp[0];
    
    for(int idx=1; idx < len; idx++) {
        if(temp[idx] > max)
            max = temp[idx];
    }

    return max;
}

void baek_10810() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    // 동적 배열 할당 및 0으로 초기화
    int *numbers = (int *)calloc(N, sizeof(int));
    if (numbers == NULL) {
        fprintf(stderr, "메모리 할당 실패\n");
        return;
    }

    for(int iter = 0; iter < M; iter++) {
        int i, j, k;
        scanf("%d %d %d", &i, &j, &k);

        for(int idx = i-1; idx < j; idx++)
            numbers[idx] = k;
    }

    for(int idx = 0; idx < N; idx++)
        printf("%d ", numbers[idx]);
    printf("\n");
}

void baek_10811() {
    int N, M;
    scanf("%d %d", &N, &M);
}
