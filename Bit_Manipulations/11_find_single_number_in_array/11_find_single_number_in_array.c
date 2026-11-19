/**
 * @file single_number_in_array.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stddef.h>
#include <stdio.h>

void single_number_finder(unsigned int arr[], size_t arr_len) {
    unsigned int result = 0;
    for (int i = 0; i < arr_len; ++i) {
        result ^= arr[i];
    }

    printf("%d\n", result);
}

int main() {
    // Input
    unsigned int arr[] = {4, 1, 2, 1, 2};
    size_t arr_len = sizeof(arr) / sizeof(arr[0]);

    single_number_finder(arr, arr_len);

    return 0;
}
