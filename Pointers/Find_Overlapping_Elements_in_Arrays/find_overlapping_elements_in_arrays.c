/**
 * @file find_overlapping_elements_in_arrays.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-26
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int * get_overlapping_elements(int * arr1, size_t size1, int * arr2, size_t size2, size_t * overlapping_count) {
    int * result = (int * )malloc(sizeof(int) * MIN(size1, size2));
    size_t result_counter = 0;

    int * end1 = arr1 + size1 - 1;
    int * end2 = arr2 + size2 - 1;

    bool in_sequence = false;

    while (end1 >=  arr1 && end2 >= arr2) {
        if (*end1 > *end2) {
            end1--;
            in_sequence = false;
        } else if (*end2 > *end1) {
            end2--;
            in_sequence = false;
        } else if (*end1 == *end2) {
            if (*overlapping_count == 0 || in_sequence) {
                *(result + result_counter) = *end1;
                in_sequence = true;
                result_counter++;
            }
            end1--;
            end2--;
        }
    }

    *overlapping_count = result_counter;
    return result;
}

int main() {
    // Input arrays
    int arr1[] = {1, 2, 3, 4, 5, 6};
    int arr2[] = {5, 6, 7, 8};

    // Calculate the size of input arrays
    size_t size1 = sizeof(arr1) / sizeof(arr1[0]);
    size_t size2 = sizeof(arr2) / sizeof(arr2[0]);

    size_t overlapping_count = 0;

    int * result = get_overlapping_elements(arr1, size1, arr2, size2, &overlapping_count);

    printf("{");
    for (int i = overlapping_count - 1; i >= 0; --i) {
        printf("%d", *(result + i));
        if (i != 0) {
            printf(", ");
        }
    }
    printf("}\n");

    free(result);
    return 0;
}
