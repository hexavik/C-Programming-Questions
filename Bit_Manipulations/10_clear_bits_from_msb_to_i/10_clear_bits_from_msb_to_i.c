/**
 * @file clear_bits_from_msb_to_i.c
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @date 2025-04-07
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>

void display_binary(int num) {
    int k = num;
    int bit_count = 0;
    while (k > 0) {
        bit_count++;
        k >>= 1;
    }
    printf("0b");
    for (int i = bit_count - 1; i >= 0; --i) {
        printf("%d", (num >> i) & 1);
    }
}

void clear_bits_msb_to_index(int num, int index) {
    int temp = num & ((1 << index) - 1);

    display_binary(temp);
    printf(" (for ");
    display_binary(num);
    printf(", i = %d)\n", index);
}

int main() {
    // Input
    int num = 0b11111111;
    int index = 3;
    clear_bits_msb_to_index(num, index);

    num = 0b10110110;
    index = 4;
    clear_bits_msb_to_index(num, index);

    num = 0b11101111;
    index = 5;
    clear_bits_msb_to_index(num, index);


    return 0;
}
