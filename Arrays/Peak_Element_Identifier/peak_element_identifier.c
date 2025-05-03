/**
 * @file peack_element_identifier.c
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @date 2025-01-21
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void display_peak_element(int element) {
    printf("The peak element: %d\n", element);
}

void find_peak_element(int arr[], size_t arr_len) {
    if (arr_len == 0) {
        printf("Invalid size of an array.\n");
        return;
    }

    if (arr_len == 1) {
        display_peak_element(arr[0]);
        return;
    }

    if (arr_len == 2) {
        int peak_element = arr[0] > arr[1] ? arr[0] : arr[1];
        display_peak_element(peak_element);
        return;
    }

    // Skip the first and last element of the array of size mroe than
    // two as they both are insvalid contestants
    for (int i = 1; i < arr_len - 1; ++i) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            display_peak_element(arr[i]);
        }
    }
}

int main() {
    // Input array
    int arr[] = {1, 3, 20, 4, 1, 0};

    // Calculate the size of the array
    size_t arr_len = sizeof(arr) / sizeof(arr[0]);

    find_peak_element(arr, arr_len);

    return 0;
}
