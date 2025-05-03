/**
 * @file target_sum_pairs_locator.c
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @date 2025-01-25
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stddef.h>
#include <stdio.h>

#define HASHMAP_SIZE 1000

int main() {
    // Input array
    int arr[] = {2, 4, 3, 5, 6, -2, 4, 6, 8, 9};

    // Input target
    int target = 7;

    // Calculate the size of the array
    size_t arr_len = sizeof(arr) / sizeof(arr[0]);

    //
    // In order to store numbers between -500 and 500, we employ a
    // hashmap with 1000 elements. Increase the number at the arr[i]th
    // index in the hashmap by iterating through an input array.
    //
    int num_frequencies[HASHMAP_SIZE] = {0};
    int offset = HASHMAP_SIZE / 2;
    for (int i = 0; i < arr_len; ++i) {
        num_frequencies[offset + arr[i]]++;
    }

    // Using a variable as a complement, we determine the current
    // array element's complement and determine whether it is
    // available inside the hashmap.
    int complement = 0;
    printf("result: [");
    for (int i = 0; i < arr_len; ++i) {
        complement = target - arr[i];
        if (num_frequencies[offset + complement] > 0) {
            printf("(%d, %d), ", arr[i], complement);
            // To avoid the repeatation of pair we make them both 0
            // in the hashmap.
            num_frequencies[offset + arr[i]] = 0;
            num_frequencies[offset + complement] = 0;
        }
    }
    printf("]\n");

    return 0;
}
