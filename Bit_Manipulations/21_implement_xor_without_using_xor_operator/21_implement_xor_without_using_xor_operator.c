/**
 * @file implement_xor_without_using_xor_operator.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-10
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>

unsigned int custom_xor(unsigned int a, unsigned int b) {
    unsigned int result = (~(a & b)) & (a | b);

    return result;
}

int main() {
    // Input
    unsigned int a = 56;
    unsigned int b = 84;

    printf("%d\n", custom_xor(a, b));

    return 0;
}
