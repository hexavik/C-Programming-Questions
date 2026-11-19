/**
 * @file isolate_the_rightmost_set_bit.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-10
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>

void display_rightmost_set_bit(int num) {
    int bit_count = 0;
    int k = num;
    while (k > 0) {
        bit_count++;
        k >>= 1;
    }

    num &= -num;

    printf("0b");
    for (int i = bit_count - 1; i >= 0; --i) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main() {
    // Input
    int num = 0b10100000;

    display_rightmost_set_bit(num);

    return 0;
}
