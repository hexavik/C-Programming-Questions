/**
 * @file array_leaders_finder.c
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @date 2023-12-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[] = {16, 17, 4, 3, 5, 2};

    // Calculate the length of array
    size_t len = sizeof(arr) / sizeof(int);

    // Declare and allocate memory to a result
    int * leaders = (int * )malloc(sizeof(int) * len);

    //
    // We shall go in a reverse way since we need to find the leader
    // We need to pick each element and check whether it is greater
    // than or equal to all the elements towards right side of it.
    // We shall take one more variable to hold the max value.
    //
    int max = 0;
    int resultLen = 0;
    for (int i = len - 1; i >= 0; --i) {
        if (arr[i] > max) {
            // Update the max only if element is a leader
            leaders[resultLen++] = max = arr[i];
        }
    }

    // Display the result
    printf("leaders: ");
    for (int i = resultLen - 1; i >= 0; --i) {
        printf("%d, ", leaders[i]);
    }
    printf("\n");

    free(leaders);

    return 0;
}
