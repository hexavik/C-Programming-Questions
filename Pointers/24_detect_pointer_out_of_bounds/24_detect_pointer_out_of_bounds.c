/**
 * @file detect_pointer_out_of_bounds.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-24
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stddef.h>
#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int * ptr = &arr[5];

    // Size of an array
    size_t arr_len = (&arr)[1] - arr;

    if (ptr < arr || ptr > arr + arr_len - 1) {
        printf("Pointer is out of bounds.");
    } else {
        printf("Pointer belongs to the array.");
    }

    return 0;
}
