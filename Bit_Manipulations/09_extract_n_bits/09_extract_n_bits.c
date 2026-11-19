/**
 * @file extract_n_bits.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-08
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>

int bit_extractor(int num, int extract_count, int offset) {
    // Shift the number to the right till offset
    num = num >> (offset + 1);

    // Mask the bits from LSB to the extract count
    num = num & ((1 << extract_count) - 1);

    return num;
}

int main() {
    // Input
    int byte = 0b10101100;
    int extract_bit_count = 3;
    int offset = 2;

    printf("Result: %d\n", bit_extractor(byte, extract_bit_count, offset));

    return 0;
}
