/**
 * @file check_for_alternate_bits.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-05
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>

void check_alternate_bits(int num) {
    int i = 0;
    int current_bit;
    int next_bit;
    while (num > 0) {
        current_bit = num & 1;
        next_bit = (num >> 1) & 1;
        if (current_bit ^ next_bit) {
            num >>= 1;
            continue;
        } else {
            printf("False\n");
            return;
        }
    }

    printf("True\n");
}

int main() {
    // Input
    int num = 170;
    check_alternate_bits(num);

    num = 5;
    check_alternate_bits(num);

    num = 7;
    check_alternate_bits(num);

    return 0;
}
