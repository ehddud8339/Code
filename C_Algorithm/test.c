#include <stdio.h>
#include <stdlib.h>

void swap (int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array (int* arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition (int* input_arr, int low, int high) {
    int pivot = input_arr[high];
    // pivot보다 작은 값을 가지는 요소들의 마지막 인덱스
    int low_idx = low - 1;

    // 배열을 순회하면서 피봇보다 작은 값을 탐색
    for (int cur_idx = low; cur_idx < high; cur_idx++) {
        if (input_arr[cur_idx] <= pivot) {
            low_idx ++;

            swap(&input_arr[low_idx], &input_arr[cur_idx]);
        }
    }

    swap(&input_arr[low_idx + 1], &input_arr[high]);

    return low_idx + 1;
}

void quick_sort(int* input_arr, int low, int high) {
    if (low < high) {
        int pivot = partition(input_arr, low, high);
        // 피봇의 위치는 정렬이 완료된 상태
        quick_sort(input_arr, low, pivot - 1);
        quick_sort(input_arr, pivot + 1, high);
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int len = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, 0, len - 1);

    print_array(arr, len);


    return 0;
}