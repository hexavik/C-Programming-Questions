/**
 * @file zero_mover_to_the_left.c
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @date 2025-01-26
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
    int arr[] = {1, 2, 0, 4, 3, 0, 5, 0};

    // Calculate the size of the array
    size_t arr_len = sizeof(arr) / sizeof(arr[0]);

    // Keep all zeroes at the left
    for (int i = 0; i < arr_len; ++i) {
        if (arr[i] == 0) {
            // Swap 0 until it has non-zero number at it's left
            while (arr[i - 1] > 0 && i != 0) {
                swap(arr + i, arr + i - 1);
                i = i - 1;
            }
        }
    }

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
