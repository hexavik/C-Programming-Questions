/**
 * @file identifying_duplicate_characters_in_a_string.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-09-20
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stddef.h>
#include <stdio.h>

void duplicates(const char* str) {
    if (!str || *str == '\0') { return; }

    unsigned char chars[256] = { 0 };

    while (*str) {
        chars[(unsigned char)*str] += 1;
        str++;
    }

    printf("Duplicate Chars:\n");
    for (size_t i = 0; i < 256; ++i) {
        if (chars[i] > 1) {
            printf("%c occurred for %d\n", (unsigned char)i, chars[i]);
        }
    }
}

int main() {
    char* str = "sjkhfgaksjghabksdhfvaohyfcaosygiuryfahsegbuarhkglhabdsfg";

    duplicates(str);

    return 0;
}
