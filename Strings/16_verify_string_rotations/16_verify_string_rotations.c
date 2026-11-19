/**
 * @file verifying_string_rotations.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-09-21
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

bool check_rotation(const char* s1, const char* s2) {
    if (!s1 || !s2) { return false; }

    //
    // Calculate lengths manually
    //
    size_t len1 = 0, len2 = 0;
    while (s1[len1] != '\0') { len1++; }
    while (s2[len2] != '\0') { len2++; }

    //
    // Base condition: If lengths don't match, they cannot be rotations
    //
    if (len1 != len2 || len1 == 0) { return false; }

    //
    // Crate the concatenated string (s1 + s1)
    //
    char doubled[len1 * 2 + 1];
    for (size_t i = 0; i < len1; ++i) {
        doubled[i] = s1[i];
        doubled[i + len1] = s1[i];
    }
    doubled[len1 * 2] = '\0'; // Null-terminate

    //
    // Search for s2 inside the doubled string (Manual substring match)
    //
    int match_index = -1;
    for (size_t i = 0; i <= len1; ++i) {
        size_t j = 0;
        while (s2[j] != '\0' && doubled[i + j] == s2[j]) { j++; }
        if (j == len1) {
            match_index = (int)i;
            break;
        }
    }

    //
    // If a match is found, compute the rotation metrics
    //
    if (match_index != -1) {
        //
        // match_index directly indicates how many characters shifted Left
        //
        int left_shift = match_index;

        //
        // If left_shift is 0, they are identical strings
        //
        if (left_shift == 0) {
            printf("Rotation: 0 (String are identical)\n");
        } else {
            printf("Rotation: %dL\n", left_shift);
        }
    } else { return false; }

    return true;
}

int main() {
    char* str1 = "aabbccaa";
    char* str2 = "aaaabbcc";

    printf("%s\n", check_rotation(str1, str2) ? "True" : "False");

    return 0;
}
