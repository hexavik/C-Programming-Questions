/**
 * @file duplicate_number_detector.c
 * 
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * 
 * @date 2023-12-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Determine if the input array contains any duplicate elements 
 * using two for loops. This function has O(n * n) time complexity.
 * 
 * @param arr Input int array.
 * @param len Length of array.
 * @return true In case duplicate elements found.
 * @return false In case of duplicate elements not found.
 */
bool checkDuplicate_for(int arr[], int len) {
    // Validate the length of input array
    if (len < 2) {
        printf("ERROR: array has only one element.");
        return false;
    }

    //
    // Using two for loops will let us pick up one element from array
    // and compare it with other elements. At the time we find any 
    // duplicate value, true will be returned.
    //
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            // Skip the comparing the same element with itself
            if (i == j)
                continue;
            // If the duplication found return true
            if (arr[i] == arr[j])
                return true;
        }
    }

    // No duplicates found
    return false;
}

/**
 * @brief Determine if the input array contains any duplicate elements 
 * using hash table. This function has max O(n) time complexity.
 * 
 * @param arr Input int array.
 * @param len Length of array.
 * @return true In case duplicate elements found.
 * @return false In case of duplicate elements not found.
 */
bool checkDuplicate_hash(int arr[], int len) {
    // Validate the length of input array
    if (len < 2) {
        printf("ERROR: array has only one element.");
        return false;
    }

    // Create a hash table assuming values are within 0-1000
    int freq[1001] = {0};

    for (int i = 0; i < len; ++i) {
        freq[arr[i]]++;
        if (freq[arr[i]] > 1) {
            // Duplicate found
            return true;
        }
    }

    // No duplicates found
    return false;
}

int main() {
    // Input array
    int arr[] = {3, 1, 4, 2, 3};

    // Calculate the lenght of array
    int len = sizeof(arr) / sizeof(int);

    /*checkDuplicate(arr, len) 
        ? printf("Result: True\n") : printf("Result: False\n");*/

    checkDuplicate_hash(arr, len) 
        ? printf("Result: True\n") : printf("Result: False\n");

    return 0;
}
