/**
 * @file majority_element_identifier.c
 * 
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * 
 * @date 2024-05-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Calculate the presence of majority element, only if the number of
 * its occurrence is greater than the half lenght of the input array. We 
 * use hash map to caluclate the frequency of an array elements and at the 
 * same time we shall keep a track on maximum frequency element.
 * 
 * @param arr input array
 * @param length size of the input array
 * @return int majority element if found else -1 as an error.
 */
int hash_repeat_calculator(int arr[], int length) {
    // Create a hash table assuming array element values are within 0-1000 range
    int frequency[1001] = {0};

    int max_frequency = 0;
    int majority_element = 0;

    for (int i = 0; i < length; ++i) {
        frequency[arr[i]]++;
        if (max_frequency < frequency[arr[i]]) {
            max_frequency = frequency[arr[i]];
            majority_element = arr[i];
        }
    }

    if (max_frequency > length / 2)
        return majority_element;
    else
        return -1;
}

int main(void) {
    // The input array
    int arr[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};

    // The length of the array
    int len = sizeof(arr) / sizeof(int);

    if (len <= 2) {
        printf("Array length is not enough for this problem, terminating the program.\n");
        return 0;
    }

    int result = hash_repeat_calculator(arr, len);
    result != -1 ? 
        printf("Majority Element: %d\n", result) : 
        printf("Majority Element not found\n");

    return 0;
}
