/**
 * @file counting_substring_occurrences_in_a_string.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-09-20
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stddef.h>
#include <stdio.h>

size_t substring_count_occurrence(const char* str, const char* substr) {
    if (!str || !substr || *str == '\0' || *substr == '\0') { return 0; }

    size_t count = 0;
    size_t i = 0;

    //
    // Calculate the lenght of the substring manually
    //
    size_t sub_len = 0;
    while (substr[sub_len] != '\0') {
        sub_len++;
    }

    //
    // Traverse the main string
    //
    while (str[i] != '\0') {
        size_t j = 0;

        //
        // Check if substr matches str starting at index i
        //
        while (substr[j] != '\0' && str[i + j] == substr[j]) { j++; }

        //
        // If j reached the end of substr, we found a complete match
        //
        if (j == sub_len) {
            count++;
            i += sub_len; // Move past the matched substring (non-overlapping)
        } else {
            i++; // No match, just move to the next character
        }
    }

    return count;
}

int main() {
    char* str1 = "banana";
    char* sub1 = "ana";
    printf("Main: \"%s\", Sub: \"%s\" → Output: %zu\n",
        str1, sub1, substring_count_occurrence(str1, sub1));

    char* str2 = "zzzzzz";
    char* sub2 = "zz";
    printf("Main: \"%s\", Sub: \"%s\" → Output: %zu\n",
        str2, sub2, substring_count_occurrence(str2, sub2));

    return 0;
}
