/**
 * @file discovering_the_longest_palindromeic_substring.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-09-24
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>
#include <string.h>

/**
 * @brief Expands outward while characters match and returns the 
 * palindrome length
 * 
 * @param str Input constant string
 * @param len length of the input string
 * @param left Index from the left
 * @param right Index from the right
 * @return int 
 */
int expand_around_corner(const char *str, int len, int left, int right) {
    while (left >= 0 && right < len && str[left] == str[right]) {
        left--;
        right++;
    }

    //
    // Length is (right - 1) - (left + 1) + 1
    //
    return right - left - 1;
}

void longest_palindrome(const char *str, char *result) {
    int len = strlen(str);
    if (len == 0) {
        result[0] = '\0';
        return;
    }

    int start = 0;
    int max_len = 1;

    for (int i = 0; i < len; ++i) {
        // Odd-length center
        int len1 = expand_around_corner(str, len, i, i);
        // Even-length center
        int len2 = expand_around_corner(str, len, i, i + 1);
        int len = (len1 > len2) ? len1 : len2;

        if (len > max_len) {
            max_len = len;
            start = i - (len - 1) / 2;
        }
    }

    strncpy(result, str + start, max_len);
    result[max_len] = '\0';
}

int main() {
    const char *str = "babad";
    char result[100];

    longest_palindrome(str, result);
    printf("I/P: \"%s\"\n", str);
    printf("O/P: \"%s\"\n", result);

    return 0;
}
