/**
 * @file detecting_power_of_two.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-08
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdbool.h>

bool is_power_of_two(unsigned int num) {
    if (num < 1) {
        return false;
    }

    if ((num & (num - 1)) == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    // Input
    unsigned int num = 32;

    is_power_of_two(num) ? printf("True\n") : printf("False\n");

    return 0;
}
