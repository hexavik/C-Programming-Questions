/**
 * @file check_if_number_is_multiple_of_3.c
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @date 2025-04-06
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Checks if a number is a multiple of 3 using bit manipulation.
 *
 * @param num The number to check.
 * @return true If the number is a multiple of 3.
 * @return false If the number is not a multiple of 3.
 */
bool check_multiple_of_3(int num) {
    if (num == 0) {
        return true;
    }

    if (num < 0) {
        num *= -1;
    }
    int odd_sum = 0;
    int even_sum = 0;

    char toggle = 1;

    while (num > 0) {
        if (toggle == 2) {
            toggle >>= 1;
            even_sum += num & 1;
        } else {
            toggle <<= 1;
            odd_sum += num & 1;
        }
        num >>= 1;
    }

    int diff = odd_sum - even_sum;
    if (diff == 0 || diff == 3 || diff == 6 || diff == -3 || diff == -6) {
        return true;
    } else {
        return false;
    }
}

int main() {
    // Input
    int num = 9;
    check_multiple_of_3(num) ?
        printf("True (for %d)\n", num) :
        printf("False (for %d)\n", num);

    num = 12;
    check_multiple_of_3(num) ?
        printf("True (for %d)\n", num) :
        printf("False (for %d)\n", num);

    num = 7;
    check_multiple_of_3(num) ?
        printf("True (for %d)\n", num) :
        printf("False (for %d)\n", num);

    num = -18;
    check_multiple_of_3(num) ?
        printf("True (for %d)\n", num) :
        printf("False (for %d)\n", num);

    num = -22;
    check_multiple_of_3(num) ?
        printf("True (for %d)\n", num) :
        printf("False (for %d)\n", num);
}
