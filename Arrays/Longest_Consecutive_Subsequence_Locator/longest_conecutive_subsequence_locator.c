/**
 * @file longest_conecutive_subsequence_locator.c
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @date 2024-05-14
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * @brief Sort the input array using quicksort algorithm.
 *
 * @param arr input array to sort
 * @param beg beginning index of the array or it's piece
 * @param end ending index of the array or it's piece
 */
void quicksort(int arr[], int beg, int end) {
    // Last element of the array as a reference
    int pivot = arr[end];
    // Swap position
    int swap = beg - 1;

    // Sorting
    for (int i = beg; i <= end; ++i) {
        if (arr[i] <= pivot) {
            swap++;
            int temp = arr[i];
            arr[i] = arr[swap];
            arr[swap] = temp;
        }
    }

    // Partitioning
    if (beg < swap - 1)
        quicksort(arr, beg, swap - 1);
    if (end > swap + 1)
        quicksort(arr, swap + 1, end);
}

/**
 * @brief Traverse through an array and find the longest consecutive
 * subsequence from tthe array.
 * 1. Set the current count and longest count at zero to initialize
 * 2. Set a variable to calculate the difference between the current
 * index and the value at that index to find the consecutive subsequence
 * 3. If the current index is equal to the subtraction of the element
 * at the current index and the diff value, then increment the current
 * index by one, else update the longest count in case it is less than
 * the current count alogn with resetting the current count and diff
 * variable.
 * 4. Display the longest consecutive subsequence at the last
 *
 * @param arr input array
 * @param len length of the input array
 */
void find_longest_subsequence(int arr[], size_t len) {
    int current_count = 0;
    int diff = arr[0];
    int longest_count = 0;
    int subsequence_index = 0;
    for (int i = 0; i < len; ++i) {
        if (i == arr[i] - diff) {
            current_count++;
        } else {
            if (longest_count < current_count) {
                longest_count = current_count;
                subsequence_index = i - current_count;
            }
            // Reset the counter
            current_count = 1;
            // Recalculte the diff
            diff = arr[i] - i;
        }
    }

    printf("Longest Consecutive Subsequence: ");
    for (int i = subsequence_index; i < subsequence_index + longest_count; ++i) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    // The input array
    int arr[] = {1, 9, 3, 10, 4, 20, 2};

    // Calculate array length
    size_t len = sizeof(arr) / sizeof(int);

    // Let's implement the quicksort algorithm
    quicksort(arr, 0, len - 1);

    printf("Sorted Array: [");
    for (int i = 0; i < len; ++i) {
        printf("%d", arr[i]);
        if (i < len - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    find_longest_subsequence(arr, len);

    return 0;
}
