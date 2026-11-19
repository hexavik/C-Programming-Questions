/**
 * @file find_first_non_repeated_character.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-26
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stddef.h>
#include <stdio.h>

// Size set to 256 cause we are onyl reading characters from ASCII
#define MAX_CHARS 256

char find_first_non_repeated_char(char * str) {
    char hashmap[MAX_CHARS];
    for (int i = 0; i < MAX_CHARS; ++i) {
       *(hashmap + i) = 0;
    }

    size_t counter = 0;
    while (*(str + counter)) {
        hashmap[*(str + counter)]++;
        counter++;
    }

    while (*str) {
        if (hashmap[*str] == 1) {
            return *str;
        }
        str++;
    }

    return 0;
}

int main() {
    // Input string
    char str[] = "swiss";

    printf("First non-repeated character: ");
    char c = find_first_non_repeated_char(str);
    c ? printf("%c\n", c) : printf("NULL\n");

    return 0;
}
