/**
 * @file check_pointers_point_to_same_array.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>

bool check_pointers(int * arr, size_t arr_size, int * ptr1, int * ptr2) {
    if (arr_size < 1) {
        fprintf(stderr, "Invalid Array Size\n");
        return false;
    }

    if (ptr1 < arr || ptr2 < arr) {
        return false;
    }

    return ((ptr1 - arr) < arr_size) && ((ptr2 - arr) < arr_size);
}

int main() {
    // Input array
    int arr[] = {1, 2, 3, 4};

    // Pointers pointing to the array
    int * ptr1 = &arr[1];
    int * ptr2 = &arr[3];

    // Calculate the size of the array
    size_t arr_len = sizeof(arr) / sizeof(arr[0]);

    check_pointers(arr, arr_len, ptr1, ptr2) ? 
        printf("True\n") :
        printf("False\n");

    return 0;
}
