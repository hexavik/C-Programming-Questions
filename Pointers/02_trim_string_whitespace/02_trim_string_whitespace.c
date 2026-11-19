/**
 * @file trim_string_whitespace.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-26
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <string.h>

void trim_whitespaces(char ** str) {
    size_t len = strlen(*str);
    char * beg = *str;
    char * end = *str + len - 1;

    // Trim leading whitespaces
    while (*beg == ' ' && *beg != '\0') {
        beg++;
    }

    // Trim trailing whitespaces
    while (end >= beg && *end == ' ') {
        *end = '\0';
        end--;
    }
    *str = beg; // Update the pointer to new beginning
}

int main() {
    // Input string
    char str[] = "   Hello World   ";
    char * ptr = str;

    trim_whitespaces(&ptr);
    printf("Result: %s\n", ptr);

    return 0;
}
