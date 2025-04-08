/**
 * @file find_two_unique_numbers_in_array.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-08
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>

void find_two_unique_numbers(int arr[], size_t arr_len) {
    int xor_result = 0;
    // XOR all the elements to cancel out the duplicates
    for (int i = 0; i < arr_len; ++i) {
        xor_result ^= arr[i];
    }

    int set = 1;
    if (xor_result != 0) {
        // Find the set bit
        while (!(set & xor_result)) {
            set <<= 1;
        }

        int x = xor_result;
        for (int i = 0; i < arr_len; ++i) {
            if (arr[i] & set) {
                x ^= arr[i];
            }
        }

        printf("Result: %d & %d\n", x, x ^ xor_result);
    }
}

int main() {
    // Input
    int arr[] = {4, 1, 2, 1, 2, 5};

    // Get the length of the array
    size_t arr_len = sizeof(arr) / sizeof(arr[0]);

    find_two_unique_numbers(arr, arr_len);

    return 0;
}
