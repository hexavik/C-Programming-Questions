/**
 * @file palindrome_validation_for_strings.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-09-17
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <ctype.h>
#include <stddef.h>
#include <stdio.h>

bool check_palindrome(const char* str) {
    if (!str || *str == '\0') { return false; }

    char* left = (char *)str;
    char* right = (char *)str;

    //
    // Move the right pointer to the last character
    //
    while (*right) { right++; }
    right--; // Step back from the null terminator

    while (left < right) {
        if (tolower((unsigned char)*left) != tolower((unsigned char)*right)) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main() {
    const char* str = "radar";

    printf("Is '%s' palindrome: ", str);
    check_palindrome(str) ? printf("true\n") : printf("false\n");

    return 0;
}
