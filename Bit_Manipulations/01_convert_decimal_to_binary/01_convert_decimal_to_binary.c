/**
 * @file convert_decimal_to_binary.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-07
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dec_to_bin(int num) {
    if (num == 0) {
        printf("Binary: 0b0\n");
        return;
    }

    // Get the bit coounts
    int temp = num;
    int bit_count = 2;
    while (temp > 0) {
        bit_count++;
        temp >>= 1;
    }

    char * bin_str = (char * )malloc(sizeof(char) * bit_count);
    if (bin_str == NULL) {
        fprintf(stderr, "malloc error");
        return;
    }
    strcpy(bin_str, "0b");
    int index = 2;
    while (num > 0) {
        *(bin_str + index) = (num & 1) ? '1' : '0';
        index++;
        num >>= 1;
    }
    // Add null termination at last
    *(bin_str + index) = '\0';

    printf("Binary: %s\n", bin_str);
    free(bin_str);
}

int main() {
    // Input
    int num = 5;
    dec_to_bin(num);

    num = 13;
    dec_to_bin(num);

    num = 0;
    dec_to_bin(num);

    return 0;
}
