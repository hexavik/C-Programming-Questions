/**
 * @file count_number_of_flips_to_convert_a_to_b.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-08
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>

int get_flip_bits(int big, int small) {
    int flip_count = 0;
    while (big > 0) {
        if ((big & 1) ^ (small & 1)) {
            flip_count++;
        }

        big >>= 1;
        small >>= 1;
    }

    return flip_count;
}

int main() {
    // Input
    int a = 0b11101;
    int b = 0b01111;

    int flip_count = 0;

    if (a > b) {
        printf("Result: %d\n", get_flip_bits(a, b));
    } else {
        printf("Result: %d\n", get_flip_bits(b, a));
    }

    return 0;
}
