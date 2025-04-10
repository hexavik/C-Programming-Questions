/**
 * @file mask_certain_bits.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-10
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>

void mask_n_bits(int num, int n) {
    int bit_count = 0;
    int k = num;
    while (k > 0) {
        bit_count++;
        k >>= 1;
    }

    int result = num & ((1 << n) - 1);

    printf("0b");
    for (int i = bit_count - 1; i >= 0; --i) {
        printf("%d", (result >> i) & 1);
    }
    printf("\n");
}

int main() {
    // Input
    int num = 0b10101111;
    int n = 4;

    mask_n_bits(num, n);

    return 0;
}
