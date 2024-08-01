#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge(int* input_arr, int len, int* left_arr, int left_len, int* right_arr, int right_len) {
    // 각각 input_arr, left_arr, right_arr의 인덱스
    int idx = 0, jdx = 0, kdx = 0;

    while (jdx < left_len && kdx < right_len) {
        if (left_arr[jdx] <= right_arr[kdx]) {
            input_arr[idx++] = left_arr[jdx++];
        } else {
            input_arr[idx++] = right_arr[kdx++];
        }
    }

    while (jdx < left_len) {
        input_arr[idx++] = left_arr[jdx++];
    }

    while (kdx < right_len) {
        input_arr[idx++] = right_arr[kdx++];
    }
}

void merge_sort(int* input_arr, int len) {
    if (len < 2)
        return;

    int mid = len / 2;
    int* left_arr = (int*)malloc((mid) * sizeof(int));
    int* right_arr = (int*)malloc((len - mid) * sizeof(int));

    for (int idx = 0; idx < mid; idx++)
        left_arr[idx] = input_arr[idx];
    
    for (int idx = mid; idx < len; idx++)
        right_arr[idx - mid] = input_arr[idx];

    merge_sort(left_arr, mid);
    merge_sort(right_arr, len - mid);
    merge(input_arr, len, left_arr, mid, right_arr, len - mid);
}

void print_array(int* arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int len = sizeof(arr) / sizeof(arr[0]);

    merge_sort(arr, len);

    print_array(arr, len);

    return 0;
}