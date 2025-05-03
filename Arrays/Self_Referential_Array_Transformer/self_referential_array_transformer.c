/**
 * @file self_referential_array_transformer.c
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @date 2025-01-24
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stddef.h>
#include <stdio.h>

/**
 * @brief Swap the places of two intgers.
 *
 * @param a pointer of the first integer
 * @param b pointer of the second integer
 */
void swap(int * a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    // Input array
    int arr[] = {2, 0, 1, 3};

    // Calculate the size of the array
    size_t arr_len = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < arr_len; ++i) {
        if (arr[i] != i) {
            swap(arr + i, arr + (arr[i]));
        }
    }

    // Display the array
    printf("result: [");
    for (int i = 0; i < arr_len; ++i) {
        printf("%d", arr[i]);
        if (i < arr_len - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}
