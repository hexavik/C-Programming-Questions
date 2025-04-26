/**
 * @file flatten_2d_array_to_1d.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-26
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int * flatten_array(const int * arr, const size_t size) {
    int * result = (int * )malloc(sizeof(int) * size);

    for (int i = 0; i < size; ++i) {
        *(result + i) = *arr;
        arr++;
    }

    return result;
}

int main() {
    // Input array
    int arr[][2] = {{1, 2}, {3, 4}};

    // Calculate the size of the array
    size_t len = sizeof(arr) / sizeof(arr[0][0]);

    int * result = flatten_array(*arr, len);
    printf("Flattened array: {");
    for (int i = 0; i < len; ++i) {
        printf("%d", *(result + i));
        if (i != len - 1) {
            printf(", ");
        }
    }
    printf("}\n");

    free(result);
    return 0;
}
