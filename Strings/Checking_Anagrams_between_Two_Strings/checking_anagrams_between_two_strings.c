/**
 * @file checking_anagrams_between_two_strings.c
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @date 2025-01-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABETS_COUNT 26

bool check_anagram(char * str1, char * str2) {
    // Check the empty string
    if (str1 == NULL || str2 == NULL) {
        printf("Error: Input string is empty\n");
        return false;
    }

    // Create a hashmap for chatracters from string1
    int hashmap[ALPHABETS_COUNT] = {0};
    for (int i = 0; i < strlen(str1); ++i) {
        hashmap[str1[i] - 'a']++;
    }

    // Now traverse through the second string and check if all the
    // charcaters are anagram to the first string
    for (int i = 0; i < strlen(str2); ++i) {
        if (hashmap[str2[i] - 'a'] == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    // Input strings
    char * str1 = "listen";
    char * str2 = "silent";

    check_anagram(str1, str2) ?
    printf("result: true\n") : 
    printf("result: false\n");

    return 0;
}
