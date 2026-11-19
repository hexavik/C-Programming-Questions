/**
 * @file calculate_a_power_b.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-02-19
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>

/**
 * @brief Adds two integers using bitwise operations.
 *
 * @param x The first integer.
 * @param y The second integer.
 * @return The sum of x and y.
 */
int bitwise_add(int x, int y) {
    while (y != 0) {
        unsigned int carry = x & y;
        x ^= y;
        y = carry << 1;
    }

    return x;
}

/**
 * @brief Multiplies two integers using bitwise operations.
 *
 * @param x The first integer.
 * @param y The second integer.
 * @return The product of x and y.
 */
int bitwise_multiply(int x, int y) {
    unsigned int result = 0;
    while (y > 0) {
        if (y & 1) {
            result = bitwise_add(result, x);
        }
        x <<= 1;
        y >>= 1;
    }

    return result;
}

/**
 * @brief Raises an integer to a power using bitwise operations.
 *
 * @param x The base integer.
 * @param y The exponent.
 * @return The result of x raised to the power of y.
 */
int bitwise_power(int x, int y) {
    unsigned int result = 1;
    int base = x;
    int exponent = y;

    while (exponent != 0) {
        if (exponent & 1) {
            result = bitwise_multiply(result, base);
        }
        base = bitwise_multiply(base, base);
        exponent >>= 1;
    }

    return result;
}

int main() {
    // Inputs
    int a = 4;
    int b = 5;

    printf("%d power %d: %d\n", a, b, bitwise_power(a, b));

    return 0;
}
