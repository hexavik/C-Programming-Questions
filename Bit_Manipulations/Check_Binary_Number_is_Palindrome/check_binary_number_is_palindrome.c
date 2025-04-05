/**
 * @file check_binary_number_is_palindrome.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-05
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>

/**
 * @brief Check if a binary number is a palindrome.
 *
 * @param num The number to check.
 */
void check_binary_palindrome(int num) {
    // Get the significant bit count
    int bit_count = 0;
    int k = num;
    while (k != 0) {
        bit_count++;
        k >>= 1;
    }

    int lsb = 0;
    int msb = 0;
    int i = 0;
    while (i < bit_count / 2) {
        lsb = (num >> i) & 1;
        msb = (num >> (bit_count - 1 - i)) & 1;
        if (lsb == msb) {
            i++;
            continue;
        } else {
            printf("False (for %d)\n", num);
            return;
        }
    }

    printf("True (for %d)\n", num);
}

int main() {
    // Input number
    int num = 21;
    check_binary_palindrome(num);

    num = 15;
    check_binary_palindrome(num);

    num = 10;
    check_binary_palindrome(num);
}
