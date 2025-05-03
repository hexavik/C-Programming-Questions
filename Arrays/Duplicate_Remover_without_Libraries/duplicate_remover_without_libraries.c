/**
 * @file duplicate_remover_without_libraries.c
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @date 2023-12-24
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Removes duplicates from an array in-place.
 *
 * @param arr
 * @param len
 */
void remove_duplicates(int array[], size_t array_length) {
    // Index to track the position of the next unique element
    int unique_element_index = 0;

    // Frequency array to store element counts (assuming values within 0-1000)
    int element_frequencies[1001] = {0};

    // Iterate through the array
    for (int i = 0; i < array_length; ++i) {
        // Increment the frequency of the current element
        element_frequencies[array[i]]++;

        // If this is the first occurrence of the element, add it to the unique section
        if (element_frequencies[array[i]] == 1) {
            // Swap with current position
            int temp = array[unique_element_index];
            array[unique_element_index] = array[i];
            array[i] = temp;
            unique_element_index++;
        }
    }

    // Display the modified array with duplicates removed
    printf("Result: [");
    for (int i = 0; i < unique_element_index; ++i) {
        printf("%d", array[i]);
        if (i < unique_element_index - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    // Input array
    int arr[] = {1, 1, 2, 2, 3, 4, 4};

    // Calculate the length of array
    size_t len = sizeof(arr) / sizeof(int);

    remove_duplicates(arr, len);

    return 0;
}
