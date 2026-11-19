/**
 * @file count_array_elements_without_loop.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-21
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stddef.h>
#include <stdio.h>

int main() {
    // Input array
    int arr[] ={1, 2, 3, 4, 5, 6};

    //
    // Integer array doesn't have null-termination character at the
    // end. So to calculate the size of an array, we need is total
    // number of bytes consumed by array and size in bytes.
    //
    ptrdiff_t size = ((char *)(&arr + 1) - (char *)&arr) / ((char *)(arr + 1) - (char *)arr);

    printf("Total elements: %ld\n", size);

    return 0;
}
