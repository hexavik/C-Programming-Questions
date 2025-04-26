/**
 * @file rotate_array_by_k_elements.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-26
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>

void display_arr(int * arr, size_t len) {
    printf("{");
    for(int i = 0; i < len; ++i) {
        printf("%d", *(arr + i));
        if (i < len - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

void reverse_array(int * arr, size_t beg, size_t end) {
    for (int i = beg; i < (beg + end) / 2; ++i) {
        int * right = (arr + end - 1 - (i - beg));
        int temp = *(arr + i);
        *(arr + i) = *right;
        *right = temp;
    }
}

void rotate_array(int * arr, const size_t len, const int positions) {
    if (positions >= len) {
        fprintf(stderr, "Error: Position value is greater than the size of the array.");
        return;
    }

    // Reverse the array
    reverse_array(arr, 0, len);
    // Reverse the first k elements
    reverse_array(arr, 0, positions);
    // Reverse the remaining n - k elements
    reverse_array(arr, positions, len);
}

int main() {
    // Input array
    int arr[] = {1, 2, 3, 4, 5};

    // Input positions
    int k = 2;

    // Calculate the size of the array
    size_t size = sizeof(arr) / sizeof(arr[0]);

    rotate_array(arr, size, k);
    display_arr(arr, size);

    return 0;
}
