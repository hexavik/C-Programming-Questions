/**
 * @file string_to_integer_conversion_without_built_in_functions.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-09-20
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stddef.h>
#include <stdio.h>

long long string_to_integer(const char* str, bool* success) {
    if (!str || *str == '\0') {
        if (success) { *success = false; }
        return 0;
    }

    long long result = 0;
    int sign = 1;
    size_t i = 0;

    //
    // Handle optional leading negative or positive sign
    //
    if (str[0] == '-') {
        sign = -1;
        i++;
    } else if (str[0] == '+') {
        i++;
    }

    //
    // A string containing only "-" or "+" is invalid
    //
    if (str[i] == '\0') {
        if (success) { *success = false; }
        return 0;
    }

    //
    // Process each character
    //
    while (str[i] != '\0') {
        //
        // If a non-digit character is found, conversion fails
        //
        if (str[i] < '0' || str[i] > '9') {
            if (success) { *success = false; }
            return 0;
        }

        //
        // Shift existing digits left (multiply by 10) and add the new digit
        //
        result = (result * 10) + (str[i] - '0');
        i++;
    }

    if (success) { *success = true; }
    return result * sign;
}

int main() {
    bool success;

    long long res1 = string_to_integer("1234", &success);
    printf("Input: \"1234\" → Output: %lld (Success: %s)\n",
        res1, success ? "True" : "False");

    long long res2 = string_to_integer("-567", &success);
    printf("Input: \"-567\" → Output: %lld (Success: %s)\n",
        res2, success ? "True" : "False");

    long long res3 = string_to_integer("12a34", &success);
    printf("Input: \"12a34\" → Output: %lld (Success: %s)\n",
        res3, success ? "True" : "False");

    return 0;
}
