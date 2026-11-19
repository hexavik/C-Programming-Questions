/**
 * @file split_string_into_halves.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-26
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * split_string(char ** str) {
    size_t mid = strlen(*str) / 2;
    char * first_half = (char * )malloc(mid + 1);
    char * first_end = *str + mid;
    size_t index_counter = 0;

    while (*str < first_end) {
        *(first_half + index_counter) = **str;
        index_counter++;
        (*str)++;
    }
    *(first_half + index_counter) = '\0';

    return first_half;
}

int main() {
    // Input string
    char str[] = "HelloWorld";
    char * ptr = str;

    char * first_half = split_string(&ptr);
    printf("First Half: %s\n", first_half);
    printf("Second Half: %s\n", ptr);

    free(first_half);

    return 0;
}
