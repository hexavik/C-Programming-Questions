/**
 * @file segragate_even_and_odd_using_pointers.c
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

void segragate_even_odd(int * arr, int len) {
    int * left = arr;
    int * right = arr + len - 1;

    while (left < right) {
        if (*left % 2 == 0 && left < right) {
            left++;
        }

        if (*right % 2 == 1 && left < right) {
            right--;
        }

        if (*left % 2 == 1 && *right % 2 == 0) {
            // Swap
            int temp = *left;
            *left = *right;
            *right = temp;
            left++;
            right--;
        }
    }
}

int main() {
    // Input array
    int arr[] = {12, 34, 9, 8, 45, 90};

    // Calculate the size of the array
    int size = sizeof(arr) / sizeof(arr[0]);

    segragate_even_odd(arr, size);
    display_arr(arr, size);

    return 0;
}
