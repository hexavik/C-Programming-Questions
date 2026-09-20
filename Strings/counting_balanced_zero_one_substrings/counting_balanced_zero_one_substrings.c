/**
 * @file counting_balanced_zero_one_substrings.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-09-20
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stddef.h>
#include <stdio.h>

size_t count_binary_substrings(const char* str) {
    if (!str || *str == '\0') { return 0; }

    size_t total_count = 0;
    size_t prev_group_len = 0; // Length of the previous consecutive block
    size_t curr_group_len = 1; // Length of the current consecutive block

    size_t i = 1;
    while (str[i] != '\0') {
        if (str[i] == str[i - 1]) {
            //
            // If the character matches the previous one, extend the current
            // group
            //
            curr_group_len++;
        } else {
            //
            // Character changed (e.g., `0` to `1` or `1` to `0`)
            // The number of valid substrings formed between these two adjacent
            // groups is the minimum of their lengths
            //
            total_count += (prev_group_len < curr_group_len) ?
                            prev_group_len : curr_group_len;

            //
            // Move current group length to previous, reset current group to 1
            //
            prev_group_len = curr_group_len;
            curr_group_len = 1;
        }
        i++;
    }

    //
    // Don't forget to count the transition for the very last group block
    //
    total_count += (prev_group_len < curr_group_len) ?
                    prev_group_len : curr_group_len;

    return total_count;
}

int main() {
    const char* test1 = "0101";
    const char* test2 = "0011";

    printf("Input: \"%s\" → Output: %zu\n",
        test1, count_binary_substrings(test1));
    printf("Input: \"%s\" → Output: %zu\n",
        test2, count_binary_substrings(test2));

    return 0;
}
