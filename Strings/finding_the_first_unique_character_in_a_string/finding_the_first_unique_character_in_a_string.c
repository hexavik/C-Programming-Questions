/**
 * @file finding_the_first_unique_character_in_a_string.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-09-20
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stddef.h>
#include <stdio.h>

unsigned char first_unique_char(const char* str) {
    if (!str || *str == '\0') { return '\0'; }

    int count[256] = { 0 };

    for (size_t i = 0; str[i] != '\0'; ++i) {
        //
        // Cast to unsigned char to prevent negative indexing with extended
        // ASCII
        //
        unsigned char index = (unsigned char)str[i];
        count[index] += 1;
    }

    for (size_t i = 0; str[i] != '\0'; ++i) {
        unsigned char index = (unsigned char)str[i];
        if (count[index] == 1) {
            return index;
        }
    }

    return '\0';
}

int main() {
    char* str1 = "swiss";
    char* str2 = "racecar";
    char* str3 = "aabbcc";

    printf("The first non-repeated character is: '%c'\n",
        first_unique_char(str1));

    printf("The first non-repeated character is: '%c'\n",
        first_unique_char(str2));

    printf("The first non-repeated character is: '%c'\n",
        first_unique_char(str3));

    return 0;
}
