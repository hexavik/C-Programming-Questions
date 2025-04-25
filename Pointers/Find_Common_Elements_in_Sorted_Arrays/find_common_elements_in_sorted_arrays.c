/**
 * @file find_common_elements_in_sorted_arrays.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-25
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

size_t get_min(size_t a, size_t b, size_t c) {
    if (a < b && a < c) {
        return a;
    } else if (b < c) {
        return b;
    }
    return c;
}

int * find_commons(int * xarr, size_t xlen,
                   int * yarr, size_t ylen,
                   int * zarr, size_t zlen,
                   size_t * common_count) {
    int * result = (int * )malloc(sizeof(int) * get_min(xlen, ylen, zlen));
    int result_counter = 0;

    int * endx = xarr + xlen;
    int * endy = yarr + ylen;
    int * endz = zarr + zlen;

    while (xarr < endx && yarr < endy && zarr < endz) {
        if (*xarr < *yarr && *xarr < *zarr) {
            xarr++;
        } else if (*yarr < *xarr && *yarr < *zarr) {
            yarr++;
        } else if (*zarr < *xarr && *zarr < *yarr) {
            zarr++;
        } else if (*xarr == *yarr && *yarr == *zarr) {
            if (result_counter == 0 || *(result + result_counter - 1) != *xarr) {
                *(result + result_counter) = *xarr;
                result_counter++;
            }
            xarr++;
            yarr++;
            zarr++;
        }
    }

    *common_count = result_counter;
    return result;
}

int main() {
    // Input arrays
    int xarr[] = {1, 5, 10, 20, 40, 80};
    int yarr[] = {6, 7, 20, 80, 100};
    int zarr[] = {3, 4, 15, 20, 30, 70, 80, 120};

    // Get the size of input arrays
    size_t xsize = sizeof(xarr) / sizeof(xarr[0]);
    size_t ysize = sizeof(yarr) / sizeof(yarr[0]);
    size_t zsize = sizeof(zarr) / sizeof(zarr[0]);

    size_t common_count = 0;

    int * result = find_commons(xarr, xsize, yarr, ysize, zarr, zsize, &common_count);

    printf("{");
    for (size_t i = 0; i < common_count; ++i) {
        printf("%d", *(result + i));
        if (i != common_count - 1) {
            printf(", ");
        }
    }
    printf("}\n");

    free(result);

    return 0;
}
