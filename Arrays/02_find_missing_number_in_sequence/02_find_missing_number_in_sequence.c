/**
 * @file missing_number_finder_in_a_1-to-500_sequence.c
 * @author Vikrant A. P. (vikrant_ap@hotmail.com
 * @date 2025-01-17
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stddef.h>
#include <stdio.h>

int main() {
    // Input array
    int arr[] = {1, 2, 4, 5};

    // Calculate the length of the array
    size_t len = (&arr)[1] - arr;

    // Calculate the sum of all the numbers from 1 to n (length of an array)
    // Sum of all natural number n is n * (n + 1) / 2
    int expected_sum = len * (len + 1) / 2;

    // Calculate the sum of all array elements
    int actual_sum = 0;
    for (int i = 0; i < len; ++i) {
        actual_sum += arr[i];
    }

    // Calculate the missing number using following formula
    int missing_num = expected_sum - actual_sum + len + 1;

    printf("Missing number: %d\n", missing_num);

    return 0;
}
