/**
 * @file counting_vowels_and_consonants_in_a_string.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-09-18
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stddef.h>
#include <stdio.h>

void count_vowels_and_consonants(
const char* str, size_t* vowels, size_t* consonants) {
    if (!str || *str == '\0') { return; }

    while (*str) {
        if (*str == 'a' ||
            *str == 'e' ||
            *str == 'i' ||
            *str == 'o' ||
            *str == 'u') {
            *vowels += 1;
        } else {
            *consonants += 1;
        }
        str++;
    }
}

int main() {
    char* str = "apple";

    size_t vowels = 0;
    size_t consonants = 0;

    count_vowels_and_consonants(str, &vowels, &consonants);
    printf("Vowels: %zu | Consonants: %zu\n", vowels, consonants);

    return 0;
}
