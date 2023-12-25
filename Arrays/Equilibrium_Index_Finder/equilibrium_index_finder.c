/**
 * @file equilibrium_index_finder.c
 * 
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * 
 * @date 2023-12-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>

/**
 * @brief Finds the equilibrium inde in an array, where the sum of elements 
 * to the left equals the sum of elements to the right. This
 * 
 * @note This function returns the first equilibrium index found from left 
 * to right. If multiple indices exist, only the first one is returned.
 * 
 * @param array Input integer array.
 * @param array_length Length of the array.
 * @return int The index of the equilibrium element, or -1 if none found.
 */
int find_equilibrium_index(int array[], int array_length) {
    // Total sum of elements to the right (initially all elements)
    int sum_right = 0;
    // Total sum of elements to the left (initially empty)
    int sum_left = 0;

    // Calculate the total sum of all elements stored in sum_right initially
    for (int i = 0; i < array_length; ++i) {
        sum_right += array[i];
    }

    // Iterate through each element, updating sums and checking for equilibrium
    for (int i = 0; i < array_length; ++i) {
        // Exclude the current element from the right sum
        sum_right -= array[i];

        // Include the element to the left of the current element in the 
        // left sum, except for the first element.
        if (i)  // Avoid accessing array[-1] for the first element
            sum_left += array[i - 1];

        // If left and right sums are equal, we've found an equilibrium index
        if (sum_left == sum_right) {
            return i;
        }
    }

    // If no equilibrium index is found
    return -1;
}

int main() {
    // Input array
    int arr[] = {-7, 1, 5, 2, -4, 3, 0};

    // Calculate array length
    int len = sizeof(arr) / sizeof(int);

    // Find and print the equilibrium index
    printf("Result: %d\n", find_equilibrium_index(arr, len));

    return 0;
}
