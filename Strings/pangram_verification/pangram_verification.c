/**
 * @file pangram_verification.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-09-18
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <ctype.h>
#include <stddef.h>
#include <stdio.h>

bool is_pangram(const char* str) {
    if (!str || *str == '\0') { return false; }

    unsigned int char_pool[26] = { 0 };

    while (*str) {
        char ch = tolower((unsigned char)*str);
        char_pool[ch - 'a'] += 1;
        str++;
    }

    for (size_t i = 0; i < 26; ++i) {
        if (char_pool[i] < 1) {
            return false;
        }
    }

    return true;
}

int main() {
    //char* str = "Jinxed wizards pluck ivy from the big quilt";
    char* str = "Quick brown fox jumps over the lazy dog";

    is_pangram(str) ? printf("True\n") : printf("False\n");

    return 0;
}
