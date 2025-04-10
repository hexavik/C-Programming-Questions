/**
 * @file swap_odd_and_even_bits.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>

void swap_odd_and_even_bits(unsigned int num) {
    int bit_count = 0;
    int k = num;
    while (k > 0) {
        bit_count++;
        k >>= 1;
    }

    unsigned int odd = num & 0xAAAAAAAA;
    unsigned int even = num & 0x55555555;
    unsigned int result = (odd >> 1) | (even << 1);

    printf("0b");
    for (int i = bit_count - 1; i >= 0; --i) {
        printf("%d", (result >> i) & 1);
    }
    printf("\n");
}

int main() {
    // Input
    unsigned int num = 0b10101010;

    swap_odd_and_even_bits(num);

    return 0;
}
