/**
 * @file generating_all_string_permutations.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-09-22
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Checks if s[curr] already appeared in s[start ... curr - 1]
 * 
 * @param str Input constant string
 * @param start Starting index
 * @param curr current index
 * @return true 
 * @return false 
 */
bool should_swap(const char *str, int start, int curr) {
    for (int i = start; i < curr; ++i) {
        if (str[i] == str[curr]) { return false; }
    }
    return true;
}

void generate_permutations(char *str, int start, int end) {
    if (start == end) {
        printf("\"%s\"\n", str);
        return;
    }

    for (int i = start; i <= end; ++i) {
        //
        // Skip duplicate characters at the same recursion level
        //
        if (should_swap(str, start, i)) {
            swap(&str[start], &str[i]);
            generate_permutations(str, start + 1, end);
            // Backtrack to restore original string
            swap(&str[start], &str[i]);
        }
    }
}

int main() {
    //
    // Must be a mutable char array, not a read-only string literal
    //
    char str[] = "abc";
    int len = strlen(str);

    printf("I/P: \"%s\"\n", str);
    printf("Permutations:\n");
    generate_permutations(str, 0, len - 1);

    return 0;
}
