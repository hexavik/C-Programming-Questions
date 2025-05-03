/**
 * @file array_intersection_calculator.c
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @date 2023-12-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort
int compareInt(const void * a, const void * b) {
    return *(int * )a - *(int * )b;
}

int main() {
    int array1[] = {1, 2, 4, 5, 2};
    int array2[] = {2, 3, 5, 7};

    // Get the length of the arrays
    int len1 = sizeof(array1) / sizeof(int);
    int len2 = sizeof(array2) / sizeof(int);
    //printf("len1: %d & len2: %d\n", len1, len2);

    // Sort both arrays so that it is easy to avoid duplication in result
    qsort(array1, len1, sizeof(int), compareInt);
    qsort(array2, len2, sizeof(int), compareInt);

    // Declare and allocate memory to the result variable
    // Since we have two different size of arrays, so we
    // allocate maximum memory equal to the lenght of the smaller array.
    int * result = (int * )malloc((len1 > len2) ? len2 : len1);

    int i = 0;
    int j = 0;
    int result_len = 0;

    // Compare and match
    while (i < len1 && j < len2) {
        if (array1[i] == array2[j]) {
            // Match found, add only if not already present
            if (result_len == 0 || result[result_len - 1] != array1[i]) {
                result[result_len++] = array1[i];
            }
            ++i;
            ++j;
            continue;
        }

        // Since we are using sorted arrays so we need to increment
        // either of them based on their value
        (array1[i] < array2[j]) ? ++i : ++j;
    };

    // Reallocate the memory
    result = realloc(result, sizeof(int) * result_len);

    // Display result
    printf("result: [");
    for (int i = 0; i < result_len; ++i) {
        printf("%d", result[i]);
        if (i < result_len - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    // Release the memory
    free(result);

    return 0;
}
