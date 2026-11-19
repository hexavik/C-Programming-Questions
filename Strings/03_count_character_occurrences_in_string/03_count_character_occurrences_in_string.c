/**
 * @file counting_character_occurrences_in_a_string.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-09-18
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>

int count_character_occurence(const char* str, char ch) {
    if (!str || *str == '\0') { return -1; }

    int occurrence = 0;
    while (*str) {
        if (ch == *str++) {
            occurrence += 1;
        }
    }

    return occurrence;
}

int main() {
    char* str = "sjkdfhalughfoSEFHwhecfbahisdlkfhaskdhgfwksdhflksadjflksh";
    char ch = 'h';

    printf("%c occurred: %d times\n", ch, count_character_occurence(str, ch));

    return 0;
}
