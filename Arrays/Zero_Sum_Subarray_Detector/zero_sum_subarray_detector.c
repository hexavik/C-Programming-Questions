/**
 * @file zero_sum_subarray_detector.c
 *
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * 
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Splits array into subarrays starting with the maximum 
 * possible size of subarrays and checks their sum, if it is zero
 * return true else continue till subarray size reaches to one.
 * 
 * @param arr Input array
 * @param arr_size Length of the array
 * @return true if sum of the subarray elements is zero
 * @return false if subarray of sum equals to zero not found
 */
bool zero_sum_subarray_detector(int arr[], int arr_size) {
    int subarray_size = arr_size - 1;
    int sum;

    while (subarray_size > 1) {
        // Create subarrays
        for (int i = 0; i < (arr_size - subarray_size + 1); ++i) {
            printf("i: %d | subarray_size: %d\n", i, subarray_size);
            for (int j = 0; j < subarray_size; ++j) {
                sum += arr[j + i];
            }
            if (sum == 0) {
                return true;
            } else {
                sum = 0;
            }
        }

        // Increment subarray size
        subarray_size--;
    }

    return false;
}

int main() {
    // Input array
    int arr[] = {4, 2, -3, 1, 6};
    //int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Calculate the size of the array
    int arr_len = sizeof(arr) / sizeof(arr[0]);

    bool result = zero_sum_subarray_detector(arr, arr_len);
    result ? printf("true\n") : printf("false\n");
    
    return 0;
}
