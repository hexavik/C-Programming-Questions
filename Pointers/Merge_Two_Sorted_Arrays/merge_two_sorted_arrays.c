/**
 * @file merge_two_sorted_arrays.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-26
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int * merge_arrays(int * arr1, size_t size1, int * arr2, size_t size2) {
    int * result = (int * )malloc(sizeof(int) * (size1 + size2));
    size_t result_index = 0;

    int * end1 = arr1 + size1;
    int * end2 = arr2 + size2;

    while (arr1 < end1 && arr2 < end2) {
        if (*arr1 < *arr2) {
            *(result + result_index) = *arr1;
            arr1++;
            result_index++;
        } else if (*arr2 < *arr1) {
            *(result + result_index) = *arr2;
            arr2++;
            result_index++;
        }
    }

    if (arr1 < end1) {
        while (arr1 < end1) {
            *(result + result_index) = *arr1;
            arr1++;
            result_index++;
        }
    } else {
        while (arr2 < end2) {
            *(result + result_index) = *arr2;
            arr2++;
            result_index++;
        }
    }

    return result;
}

int main() {
    // Input arrays
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6};

    // Calculate the size of arrays
    size_t size1 = sizeof(arr1) / sizeof(arr1[0]);
    size_t size2 = sizeof(arr2) / sizeof(arr2[0]);
    size_t merge_len = size1 + size2;

    int * result = merge_arrays(arr1, size1, arr2, size2);
    printf("Merged: {");
    for (int i = 0; i < merge_len; ++i) {
        printf("%d", *(result + i));
        if (i < merge_len - 1) {
            printf(", ");
        }
    }
    printf("}\n");
    free(result);

    return 0;
}
