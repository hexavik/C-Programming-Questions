/**
 * @file occurrence_counter_in_a_sorted_array.c
 *
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 *
 * @date 2025-01-19
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>

int findFirstOccurrence(int arr[], int arr_len, int target) {
    int low = 0;
    int high = arr_len - 1;
    int mid;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            // If found, check if it's the first occurrence
            if (mid == 0 || arr[mid - 1] != target) {
                return mid;
            } else {
                high = mid - 1; // Continue searching in the first half
            }
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // Target not found
}

int findLastOccurrence(int arr[], int arr_len, int target) {
    int low = 0;
    int high = arr_len - 1;
    int mid;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            // If found, check if it's the last occurrence
            if (mid == arr_len - 1 || arr[mid + 1] != target) {
                return mid;
            } else {
                low = mid + 1; // Continue searching in the second half
            }
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;  // Target not found
}

int countTargetOccurrences(int arr[], int arr_len, int target) {
    int first = findFirstOccurrence(arr, arr_len, target);
    if (first == -1) {
        return 0;   // Target not found
    }

    int last = findLastOccurrence(arr, arr_len, target);
    if (last == -1) {
        return 0;   // Target not found
    }

    return last - first + 1;
}

int main() {
    // Input array
    int arr[] = {1, 2, 2, 2, 3};

    // Input target element to be search for
    int target = 2;

    // Calculate the size of the array
    int arr_len = sizeof(arr) / sizeof(arr[0]);

    // Use binary search
    int result = countTargetOccurrences(arr, arr_len, target);
    !result ? 
    printf("Target not found\n") :
    printf("Target occurred for %d times\n", result);

    return 0;
}
