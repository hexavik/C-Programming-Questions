/**
 * @file concatenate_strings_without_lib.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-21
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>

void my_concatenate(char * dest_str, char * src_str) {
    // Move dest_str pointer to the end of the current string
    while (*dest_str) {
        dest_str++;
    }

    // Copy characters from src_str to dest_str
    while (*src_str) {
        *dest_str = *src_str;
        dest_str++;
        src_str++;
    }

    *dest_str = '\0'; // null-terminate
}

int main() {
    // Input strings
    char str1[50] = "Good ";
    char * str2 = "Morning";

    my_concatenate(str1, str2);
    printf("Result: %s\n", str1);

    return 0;
}
