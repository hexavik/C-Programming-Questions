/**
 * @file quicksort_array_sorter.c
 *
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * 
 * @date 2025-01-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <endian.h>
#include <stdio.h>

/**
 * @brief Swap the places of two intgers.
 * 
 * @param a pointer of the first integer
 * @param b pointer of the second integer
 */
void swap(int * a, int * b) {
    printf("Swapping %d and %d\n", *a, *b);
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief 
 * 
 * @param arr 
 * @param low 
 * @param high 
 * @return int 
 */
int split(int arr[], int low, int high) {
    // Select the pivot
    int pivot = arr[high];

    // Index of a smaller element and points to the right position of
    // pivot found til now
    int i = low - 1;

    // Traverses from the lowest index till the index before pivot
    // Traverses through an array from the lowest index till the index
    // before pivot. If the current element is greater than the pivot
    // go to the next position else increment the smaller element
    // index and swap the current element with it.
    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
             ++i;
            swap(arr + i, arr + j);
        }
    }

    // Update the pivot element to the next position of the smaller 
    // number index.
    swap(arr + i + 1, arr + high);

    return i + 1;
}

/**
 * @brief Quick sort algorithm using recursive method.
 * 
 * @param arr Input unsorted array
 * @param low lowest position (extreme left) of the array
 * @param high highest position (extreme right) of the array
 */
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        // split index is the split return index of pivot
        int split_index = split(arr,low, high);
        printf("split index: %d\n", split_index);

        quick_sort(arr, low, split_index - 1);
        quick_sort(arr, split_index + 1, high);
    }
}

int main() {
    // Input array
    int arr[] = {64, 34, 25, 12, 22, 11, 90};

    // Calculate the size of the array
    int arr_len = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, 0, arr_len - 1);

    // Display sorted array
    printf("Sorted Array: ");
    for (int i = 0; i < arr_len; ++i) {
        printf("%d, ", arr[i]);
    }
    printf("\n");

    return 0;
}
