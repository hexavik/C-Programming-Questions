/**
 * @file verifying_numeric_only_characters_in_a_string.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-09-20
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <ctype.h>
#include <stddef.h>
#include <stdio.h>

bool contains_only_digits(const char* str) {
    if (!str || *str == '\0') { return false; }

    //
    // Check each character one by one
    //
    for (size_t i = 0; str[i] != '\0'; ++i) {
        //
        // Cast to unsigned char for safety with <ctype.h> functions
        //
        if (!isdigit((unsigned char)str[i])) {
            return false; // Found a non-digit character, exit early
        }
    }

    return true; // All characters were digits
}

int main() {
    const char* str1 = "12345";
    const char* str2 = "12345a";
    const char* str3 = "";
    const char* str4 = "12 34"; // Contains a space

    printf("Input: \"%s\" → Output: %s\n", str1,
        contains_only_digits(str1) ? "True" : "False");
    printf("Input: \"%s\" → Output: %s\n", str2,
        contains_only_digits(str2) ? "True" : "False");
    printf("Input: \"%s\" → Output: %s\n", str3,
        contains_only_digits(str3) ? "True" : "False");
    printf("Input: \"%s\" → Output: %s\n", str4,
        contains_only_digits(str4) ? "True" : "False");

    return 0;
}
