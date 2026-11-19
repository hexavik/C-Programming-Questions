/**
 * @file toggle_two_bits.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdint.h>
#include <stdio.h>

void display_byte(uint8_t byte) {
    printf("0b");
    for (int i = 7; i >= 0; --i) {
        printf("%d", (byte >> i) & 1);
    }
    printf("\n");
}

uint8_t toggle(uint8_t byte, uint8_t position) {
    return (1 << position) ^ byte;
}

int main() {
    // Input
    uint8_t byte = 0b10100101;
    byte = toggle(byte, 3);
    byte = toggle(byte, 5);
    display_byte(byte);

    return 0;
}
