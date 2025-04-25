/**
 * @file find_array_intersection.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-25
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

void swap(int * a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int split(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
             ++i;
            swap(arr + i, arr + j);
        }
    }

    swap(arr + i + 1, arr + high);

    return i + 1;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        // split index is the split return index of pivot
        int split_index = split(arr,low, high);

        quick_sort(arr, low, split_index - 1);
        quick_sort(arr, split_index + 1, high);
    }
}

int * find_intersection_in_sorted(int * arr1, int * arr2, size_t size1, size_t size2, size_t * intersection_size) {
    int * result = (int * )malloc(sizeof(int) * MIN(size1, size2));
    int result_counter = 0;

    int * end1 = arr1 + size1;
    int * end2 = arr2 + size2;

    int i = 0;
    int j = 0;
    while (arr1 < end1 && arr2 < end2) {
        if (*arr1 < *arr2) {
            arr1++;
        } else if (*arr1 > *arr2) {
            arr2++;
        } else if (*arr1 == *arr2) {
            if (result_counter == 0 || *(result + result_counter - 1) != *arr1) {
                *(result + result_counter) = *arr1;
                result_counter++;
            }
            arr1++;
            arr2++;
        }
    }

    *intersection_size = result_counter;
    return result;
}

int * find_intersection_in_unsorted(int * arr1, int * arr2, size_t size1, size_t size2, size_t * intersection_size) {
    // Sort the arrays and pass it to the previously written function
    // for sorted arrays
    quick_sort(arr1, 0, size1 - 1);
    quick_sort(arr2, 0, size2 - 1);

    return find_intersection_in_sorted(arr1, arr2, size1, size2, intersection_size);
}

int main() {
    // Input arrays
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {3, 4, 5, 6};

    // Calculate the size of input arrays
    size_t arr_len1 = sizeof(arr1) / sizeof(arr1[0]);
    size_t arr_len2 = sizeof(arr2) / sizeof(arr2[0]);

    size_t intersection_size = 0;

    //int * result = find_intersection_in_sorted(arr1, arr2, arr_len1, arr_len2, &intersection_size);
    int * result = find_intersection_in_unsorted(arr1, arr2, arr_len1, arr_len2, &intersection_size);

    printf("{");
    for (int i = 0; i < intersection_size; ++i) {
        printf("%d", *(result + i));
        if (i != intersection_size - 1) {
            printf(", ");
        }
    }
    printf("}\n");

    free(result);

    return 0;
}
