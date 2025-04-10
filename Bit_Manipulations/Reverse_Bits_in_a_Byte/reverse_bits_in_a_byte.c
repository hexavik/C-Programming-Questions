/**
 * @file reverse_bits_in_a_byte.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-10
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

void reverse_bits(uint8_t byte) {
    uint8_t result = 0;
    uint8_t msb;
    uint8_t lsb;

    for (int i = 0; i < 4; ++i) {
        // Retrieve the msb
        msb = (byte >> (7 - (i * 2))) & (1 << i);
        // Retrieve the lsb
        lsb = (byte << (7 - (i * 2))) & (1 << (7 - i));
        result |= msb | lsb;
    }

    display_byte(result);
}

int main() {
    // Input
    uint8_t byte = 0b11001001;

    reverse_bits(byte);

    return 0;
}
