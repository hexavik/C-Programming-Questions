/**
 * @file set_bits_without_using_arithmatic_operations.c
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

void set_n_msb_bits(uint8_t n) {
    uint8_t result = (0xFF << (8 - n));
    display_byte(result);
}

int main() {
    // Input
    uint8_t n = 5;

    set_n_msb_bits(n);

    return 0;
}
