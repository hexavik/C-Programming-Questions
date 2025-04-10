/**
 * @file find_a_unique_number_in_an_array.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-08
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>

void get_a_unique_number(int arr[], int arr_len) {
    int set[5] = {0};
    int set_bit_count = 0;

    for (int i = 0; i < arr_len; ++i) {
        for (int j = 0; j < 5; ++j) {
            if ((arr[i] >> j) & 1) {
                set[j] = (set[j] + 1) % 3;
            }
        }
    }

    // Convert an array to a number
    int num = 0;
    num = (set[0] % 3) +
          ((set[1] % 3) << 1) +
          ((set[2] % 3) << 2) +
          ((set[3] % 3) << 3) +
          ((set[4] % 3) << 4);
    printf("num: %d\n", num);
}

int main() {
    // Input
    //int arr[] = {6, 1, 3, 3, 3, 6, 6};
    int arr[] = {13, 14, 13, 20, 20, 13, 20};

    // Get the length of an array
    size_t arr_len = sizeof(arr) / sizeof(arr[0]);

    get_a_unique_number(arr, arr_len);

    return 0;
}
