/**
 * @file implement_bitwise_right_shift.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-10
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>

void display_bin(unsigned int num, int bit_len) {
    printf("0b");
    for (int i = bit_len - 1; i >= 0; --i) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

unsigned int bitwise_right_shift(int num, int shift) {
    int bit_count = 0;
    int k = num;
    while (k > 0) {
        k >>= 1;
        bit_count++;
    }

    unsigned int result = 0;
    for (int i = 0; i < 32 - shift; ++i) {
        if (num & (1U << (i + shift))) {
            result |= (1U << i);
        }
    }

    display_bin(result, bit_count);

    return result;
}



int main() {
    // Input
    int num = 0b1101U;
    int shift = 2;

    bitwise_right_shift(num, shift);

    return 0;
}
