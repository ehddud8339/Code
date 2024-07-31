#include <stdio.h>
#include <stdlib.h>

// 함수 선언 ===========================

// 선택 정렬
// 정렬하려는 값을 나머지 데이터와 비교하여 정렬
// 이미 정렬되어 있는 경우에 삽입/제거 또는 배열이 작은 경우
void selection_sort(int* input_arr, int len);

// 삽입 정렬, 안정성
// 데이터를 순회하면서 정렬이 필요한 요소를 위치에 삽입
void insertion_sort(int* input_arr, int len);

// 버블 정렬, 안정성
// 인접한 두 요소를 비교하며 정렬
void bubble_sort(int* input_arr, int len);

// 병합 정렬, 안정성
// 둘 이상의 집합으로 나누어 정렬하고 합쳐서 정렬
void merge(int* input_arr, int* left, int left_len, int* right, int right_len);
void merge_sort(int* input_arr, int len);

// 힙 정렬
// 트리 기반으로 힙 트리를 구성해 정렬, 완전 이진 트리 필요
void heap_sort(int* input_arr, int len);

// 퀵 정렬
// 집합 내의 임의의 pivot을 설정, 두 개의 집합으로 분리
void quick_sort(int* input_arr, int len);

// 기수 정렬
// 낮은 자리수부터 비교하며 정렬, 메모리 공간 필요
void radix_sort(int* input_arr, int len);

// 팀 정렬
// 병합 + 삽입 정렬, 병합보다 적은 메모리 사용


// main ================================

int main(int argc, char* argv[]) {

    return 0;
}

// 함수 정의 ============================

void selection_sort(int* input_arr, int len) {
    int idx, jdx, min, temp;

    for(idx = 0; idx < len - 1; idx++) {
        min = idx;
        // min idx 찾기
        for(jdx = idx + 1; jdx < len; jdx++) {
            if(input_arr[min] > input_arr[jdx])
                min = jdx;
        }
        // 현재 idx와 min idx 바꾸기
        temp = input_arr[idx];
        input_arr[idx] = input_arr[min];
        input_arr[min] = temp;
    }
}

void insertion_sort(int* input_arr, int len) {
    int idx, jdx, temp;

    for(idx = 1; idx < len; idx++) {
        for(jdx = 0; jdx < idx; jdx++) {
            if(input_arr[idx] < input_arr[jdx]) {
                temp = input_arr[idx];
                input_arr[idx] = input_arr[jdx];
                input_arr[jdx] = temp;
            }
        }
    }
}

void bubble_sort(int* input_arr, int len) {
    int idx, jdx, temp;

    for(idx = len-1; idx >= 0; idx--) {
        for(jdx = 0; jdx < idx; jdx++) {
            if(input_arr[jdx] > input_arr[jdx+1]) {
                temp = input_arr[jdx];
                input_arr[jdx] = input_arr[jdx+1];
                input_arr[jdx+1] = temp;
            }
        }
    }
}
// 두 개의 정렬된 배열을 병합하는 함수
void merge(int* input_arr, int* left, int left_len, int* right, int right_len) {
    int idx = 0, jdx = 0, kdx = 0;
    // 왼쪽과 오른쪽의 대소 비교를 하며 기존의 배열에 할당
    while(idx < left_len && jdx < right_len) {
        if(left[idx] <= right[jdx]) {
            input_arr[kdx++] = left[idx++];
        } else {
            input_arr[kdx++] = right[jdx++];
        }
    }

    while(idx < left_len)
        input_arr[kdx++] = left[idx++];
    
    while(jdx < right_len)
        input_arr[kdx++] = right[jdx++];
}

void merge_sort(int* input_arr, int len) {
    if(len < 2)
        return;

    int mid = (len)/2;
    int* left = (int*)malloc(mid * sizeof(int));
    int* right = (int*)malloc((len - mid) * sizeof(int));

    for (int idx = 0; idx < mid; idx++)
        left[idx] = input_arr[idx];
    
    for (int idx = mid; idx < len; idx++)
        right[idx - mid] = input_arr[idx];

    merge_sort(left, mid);
    merge_sort(right, len-mid);
    merge(input_arr, left, mid, right, len-mid);

    free(left);
    free(right);
}

void heap_sort(int* input_arr, int len) {
    
}
