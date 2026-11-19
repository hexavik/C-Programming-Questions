/**
 * @file count_set_bits.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-08
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>

unsigned int count_set_bits(unsigned int x) {
    // Count bits of each 2-bit chunk
    x = x - ((x >> 1) & 0x55555555);
    // Count bits of each 4-bit chunk
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    // Count bits of each 8-bit chunk
    x = x + (x >> 4);
    // Mask out junk
    x &= 0xF0F0F0F;
    // Add all four 8-bit chunks
    return  (x * 0x01010101) >> 24;
}

int main() {
    // Input
    int num = 0b11010110;
    printf("Set bit: %d\n", count_set_bits(num));
    return 0;
}
