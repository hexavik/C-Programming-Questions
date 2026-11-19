/**
 * @file identifying_the_longest_substring_without_repeats.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-09-21
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

size_t length_of_longest_substring(const char *str) {
    //
    // Stores the last seen index of every ASCII character
    //
    int last_index[256];
    for (int i = 0; i < 256; ++i) {
        last_index[i] = -1;
    }

    int max_length = 0;
    int left = 0; // Start index of the current valid windows

    for (int right = 0; str[right] != '\0'; ++right) {
        unsigned char current = (unsigned char)str[right];

        //
        // If current character is already inside the active window,
        // shrink from the left
        //
        if (last_index[current] >= left) {
            left = last_index[current] + 1;
        }

        //
        // Record the latest position of the current character
        //
        last_index[current] = right;

        //
        // Update maximum length found so far
        //
        int window_length = right - left + 1;
        if (window_length > max_length) { max_length = window_length; }
    }

    return max_length;
}

int main() {
    const char *str = "pwwkew";
    printf("I/P: \"%s\"\n", str);
    printf("O/P: %zu\n", length_of_longest_substring(str));

    return 0;
}
