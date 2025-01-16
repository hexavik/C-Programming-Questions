/**
 * @file minimum_sum_subarray_finder.c
 * 
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * 
 * @date 2024-05-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <limits.h>

int main(void) {
    // Input array
    int arr[] = {3, 1, -4, 2, 0};

    // Calculate the size of the array
    int len = sizeof(arr) / sizeof(int);

    // Initialize minimum sum to maximum possible intger value
    int min_sum = INT_MAX;

    // Minimum sum of subarrays always consist of two numbers only.
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            // Take a number and save it's minimim sum to a variable
            int current_sum = arr[i] + arr[j];

            if (min_sum > current_sum) {
                min_sum = current_sum;
            }
        }
    }

    printf("Minimum sum of subarrays = %d\n", min_sum);

    return 0;
}