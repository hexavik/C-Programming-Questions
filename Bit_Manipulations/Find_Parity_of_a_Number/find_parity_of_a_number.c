/**
 * @file find_parity_of_a_number.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-08
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>

void check_parity(int num) {
    // Count the set bits
    num = num - ((num >> 1) & 0x55555555);
    num = (num & 0x33333333) + ((num >> 2) & 0x33333333);
    num = num + (num >> 4);
    num &= 0xF0F0F0F;
    num = (num * 0x01010101) >> 24;

    if (num & 1) {
        printf("Odd\n");
    } else {
        printf("Even\n");
    }
}

int main() {
    // Input
    int num = 67;
    check_parity(num);

    return 0;
}
