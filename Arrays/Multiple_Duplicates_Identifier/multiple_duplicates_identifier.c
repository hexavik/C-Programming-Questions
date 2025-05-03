/**
 * @file multiple_duplicates_identifier.c
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @date 2025-01-19
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Input array
    int arr[] = {4, 3, 2, 7, 8, 2, 3, 1};

    // Calculate the size of the array
    size_t arr_len = sizeof(arr) / sizeof(arr[0]);

    if (!arr_len) {
        printf("Input array is invalid (size zero)\n");
        exit(1);
    }

    // Find the maximum element in the array
    int max_element = arr[0];
    for (int i = 1; i < arr_len; ++i) {
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
    }

    // Create a hash table dynamically sized
    int * duplicate_elements =
        (int * )calloc(max_element + 1, sizeof(arr[0]));
    if (duplicate_elements == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Output array to store duplicates
    int * duplicates = (int * )malloc(arr_len * sizeof(arr[0]));
    if (!duplicates) {
        printf("Memory allocation failed\n");
        free(duplicate_elements);
        duplicate_elements = NULL;
        exit(1);
    }

    // Index of the output array
    int duplicate_arr_index = 0;

    for (int i = 0; i < arr_len; ++i) {
        duplicate_elements[arr[i]]++;

        // If the occurrence of the element is twice thenstore the
        // element in the output array. Do not repeat the duplicated
        // element.
        if (duplicate_elements[arr[i]] == 2) {
            duplicates[duplicate_arr_index] = arr[i];
            duplicate_arr_index++;
        }
    }

    // Display the output array
    printf("result: [");
    for (int i = 0; i < duplicate_arr_index; ++i) {
        printf("%d", duplicates[i]);
        if (i < duplicate_arr_index - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}
