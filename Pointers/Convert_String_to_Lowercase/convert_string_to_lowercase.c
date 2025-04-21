/**
 * @file convert_string_to_lowercase.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-21
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>

void to_lowercase(char * str) {
    // ASCII Values difference: 32
    // A 65 : Z 90
    // a 97 : z 122
    while (*str) {
        if (*str > 64 && *str < 91) {
            *str += 32;
            str++;
        }
    }
}

int main() {
    // Input string
    char str[] = "HELLO";

    to_lowercase(str);
    printf("Result: %s\n", str);

    return 0;
}
