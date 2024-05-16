/**
 * @file max_min_finder_in_an_unsorted_array.c
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

int main(void) {
    // Input array
    int arr[] = {34, 15, 88, 2};

    // Calculate the size of the array
    int len = sizeof(arr) / sizeof(int);

    int max = 0;
    int min = 1000;

    for (int i = 0; i < len; ++i) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    printf("Max: %d, Min: %d\n", max, min);

    return 0;
}
