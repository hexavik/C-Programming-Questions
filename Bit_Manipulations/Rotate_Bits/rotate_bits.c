/**
 * @file rotate_bits.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdint.h>
#include <stdio.h>

void display_byte(uint8_t num) {
    printf("0b");
    for (int i = 7; i >= 0; --i) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

void rotate_bits(uint8_t num, uint8_t rotate) {
    // Retrieve the MSB bits equal to the rotate count
    uint8_t bits = (num >> (8 - rotate)) & ((1 << rotate) - 1);
    num <<= rotate;
    num |= bits;

    display_byte(num);
}

int main() {
    // Input
    uint8_t num = 0b10110011;
    uint8_t rotate = 3;

    rotate_bits(num, rotate);

    return 0;
}
