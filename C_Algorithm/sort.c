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
// 1. 입력 배열을 두 개의 배열로 분할, 합병 함수 호출
// 2. 결과 배열과 두 개의 합병할 배열을 받아 결과 배열에 정렬하는 함수
void merge(int* input_arr, int* left, int left_len, int* right, int right_len);
void merge_sort(int* input_arr, int len);

// 힙 정렬
// 1. 입력 배열을 힙 트리로 변환
// 2. 루트 값을 결과 배열의 맨 뒤에 삽입
// 3. 힙 트리를 다시 정렬
void heapify(int* input_arr, int len, int root_idx);
void build_heap(int* input_arr, int len);
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

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

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
    // 왼쪽과 오른쪽의 대소 비교를 하며 기존의 배열에 삽입
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

    int mid = (len)/2; // 인덱스가 아닌 길이이기 때문에 -1 X
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

void heapify(int* input_arr, int len, int root_idx) {
    int largest = root_idx;  // 루트를 가장 큰 값으로 초기화
    int left = 2 * root_idx + 1;  // 왼쪽 자식 노드
    int right = 2 * root_idx + 2; // 오른쪽 자식 노드

    // 왼쪽 자식이 루트보다 크다면 largest를 왼쪽 자식으로 변경
    if (left < len && input_arr[left] > input_arr[largest])
        largest = left;

    // 오른쪽 자식이 largest보다 크다면 largest를 오른쪽 자식으로 변경
    if (right < len && input_arr[right] > input_arr[largest])
        largest = right;

    // largest가 루트가 아니라면 두 요소를 교환하고 재귀적으로 힙을 구성
    if (largest != root_idx) {
        swap(&input_arr[root_idx], &input_arr[largest]);

        heapify(input_arr, len, largest);
    }
}

void build_heap(int* input_arr, int len) {
    for (int idx = len / 2 - 1; idx >= 0; idx--)
        heapify(input_arr, len, idx);
}

void heap_sort(int* input_arr, int len) {
    build_heap(input_arr, len);

    for (int i = len - 1; i > 0; i--) {
        swap(&input_arr[0], &input_arr[i]);

        heapify(input_arr, i, 0);
    }
}
