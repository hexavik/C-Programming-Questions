/**
 * @file calculate_dot_product_of_vectors.c
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @date 2025-04-18
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>

int calculate_dot_product(int * vec1, int * vec2, size_t vec_len) {
    int sum = 0;

    for (size_t i = 0; i < vec_len; ++i) {
        sum += (*(vec1 + i)) * (*(vec2 + i));
    }

    return sum;
}

int main() {
    // Input vectors
    int vec1[] = {1, 2, 3};
    int vec2[] = {4, 5, 6};

    // Calculate the size of arrays
    size_t vec1_len = sizeof(vec1) / sizeof(vec1[0]);
    size_t vec2_len = sizeof(vec2) / sizeof(vec2[0]);

    if (vec2_len != vec1_len) {
        fprintf(stderr, "Both vectors are not of equal length.");
        return 1;
    }

    printf("Dot product: %d\n", calculate_dot_product(vec1, vec2, vec1_len));

    return 0;
}
