/**
 * @file evaluating_repeated_substring_patterns.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-09-21
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool repeated_substring_pattern(const char *str) {
    size_t len = strlen(str);
    if (len <= 1) { return false; }

    //
    // Allocate space for s + s + null terminator
    //
    char *doubled = (char * )malloc((2 * len + 1) * sizeof(char));
    strcpy(doubled, str);
    strcat(doubled, str);

    //
    // Remove the last character so we don't match the second full copy
    //
    doubled[2 * len - 1] = '\0';

    //
    // Search starting from index 1 (skipping the first character)
    //
    bool found = (strstr(doubled + 1, str) != nullptr);

    free(doubled);
    return found;
}

int main() {
    const char *str = "abab";
    printf("I/P: \"%s\"\n", str);
    printf("O/P: %s\n", repeated_substring_pattern(str) ? "True" : "False");

    return 0;
}
