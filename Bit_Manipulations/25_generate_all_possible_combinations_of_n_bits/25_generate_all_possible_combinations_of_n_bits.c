/**
 * @file generate_all_possible_combinations_of_n_bits.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-10
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>

void generate_all_bytes_of_length(int length) {
    if (length < 1) {
        printf("Invalid Input\n");
        return;
    }

    int limit = (1 << length);
    unsigned int byte = 0;
    for (int i = 0; i < limit; ++i) {
        for (int j = length - 1; j >= 0; --j) {
            printf("%d", (byte >> j) & 1);
        }
        printf("\n");
        byte++;
    }
}

int main() {
    // Input
    int bit_count = 3;

    generate_all_bytes_of_length(bit_count);

    return 0;
}
