/**
 * @file sorted_array_merger.c
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @date 2025-01-24
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Combines two sorted array as input into one array while
 * maintaining incremental sorting.
 * @param arr1 First input sorted array
 * @param arr2 Second input sorted array
 * @param arr1_size Size of the first array
 * @param arr2_size Size of the second array
 * @param result Pointer of the result array
 */
void merge_arrays(int arr1[], int arr2[], size_t arr1_size, size_t arr2_size, int * result) {
    int i = 0;  // Index for the first array
    int j = 0;  // Index for the second array
    int k = 0;  // Index for the result array

    while (k < arr1_size + arr2_size) {
        if (i == arr1_size) {
            result[k++] = arr2[j++];
        } else if (j == arr2_size) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr1[i] < arr2[j] ? arr1[i++] : arr2[j++];
        }
    }
}

int main() {
    // Input arrays
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6};

    // Calculate the size of both arrays
    size_t arr_len1 = sizeof(arr1) / sizeof(arr1[0]);
    size_t arr_len2 = sizeof(arr2) / sizeof(arr2[0]);

    int * result;
    result = (int * )malloc((arr_len1 + arr_len2) * sizeof(int));

    merge_arrays(arr1, arr2, arr_len1, arr_len2, result);

    // Display the array
    printf("result: [");
    for (int i = 0; i < arr_len1 + arr_len2; ++i) {
        printf("%d", result[i]);
        if (i < (arr_len1 + arr_len2 - 1)) {
            printf(", ");
        }
    }
    printf("]\n");

    // Free memory
    free(result);
    result = NULL;

    return 0;
}
