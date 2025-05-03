/**
 * @file kth_max_min_element_retriever.c
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @date 2023-12-25
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Merge the elements of an array into a single element array.
 *
 * @param array Input integer array
 * @param left Array to merge elements from array
 * @param median
 * @param right
 */
void merge(int array[], int left, int median, int right) {
    int n1 = median - left + 1;
    int n2 = right - median;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; ++i)
        L[i] = array[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = array[median + 1 + i];

    // Merge the temporary arrays back into arr[left ... right]
    int i = 0;  // Initial index of first subarray
    int j = 0;  // Initial index of second subarray
    int k = left;   // Initial index of merged subarray
    while (i < n1 && j < n2) {
        array[k] = (L[i] <= R[j]) ? L[i++] : R[j++];
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], id there are any
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

/**
 * @brief Sort the unsorted array using merge sort algorithm.
 *
 * @param array Input integer array
 * @param length Array length
 */
void merge_sort(int array[], size_t length) {
    int curr_size;  // Current size of subarrays to be merged
    int left_start; // Starting index of the left subarray

    //
    // Merge subarrays in bottom-up manner. First merge subarrays of size 1
    // to create sorted subarrays of size 2, then merge subarrays of size 2
    // to create subarrays of size 4, and so on.
    //
    for (curr_size = 1; curr_size < length; curr_size = 2 * curr_size) {
        // Pick starting point of different subarrays of current size
        for (left_start = 0; left_start < length - 1; left_start += 2 * curr_size) {
            // Find ending point of left subarray. mid + 1 is starting point of right
            int mid = left_start + curr_size - 1;
            int right_end = (left_start + 2 * curr_size - 1 < length - 1)
                            ? left_start + (2 * curr_size) - 1
                            : length - 1;

            // Merge subarrays array[left_start ... mid] and array[mid + 1 ... right_end]
            merge(array, left_start, mid, right_end);
        }
    }
}

int main() {
    // Input array
    int arr[] = {7, 10, 4, 3, 20, 15};

    // Calculate array length
    size_t len = sizeof(arr) / sizeof(int);

    // Input the kth index to find max and min
    int k;
    printf("Enter value of max and min index: ");
    scanf("%d", &k);

    if (k <= 0) {
        printf("Error: Invalid kth index, cannot be zero or negative number");
        return 0;
    }

    if (k > len) {
        printf("Error: Invalid kth index, array length: %zu\n", len);
        return 0;
    }

    // Sort an input array
    merge_sort(arr, len);

    printf("Sorted: [");
    for (int i = 0; i < len; ++i) {
        printf("%d", arr[i]);
        if (i < len - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    // Print kth min
    printf("kth Min: %d\n", arr[k - 1]);
    // Print kth max
    printf("kth Max: %d\n", arr[len - k]);

    return 0;
}
