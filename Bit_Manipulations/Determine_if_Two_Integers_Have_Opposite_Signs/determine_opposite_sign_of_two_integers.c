/**
 * @file determine_opposite_sign_of_two_integers.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-08
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>

int main() {
    // Input
    int a = -4;
    int b = 6;

    if ((a ^ b) < 0) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
