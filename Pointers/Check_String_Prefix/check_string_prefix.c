/**
 * @file check_string_prefix.c
 * @author Vikrant (vikrant_ap@hotmail.com)\
 * @date 2025-04-21
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdint.h>

void check_string_prefix(char * srcstr, char * substr) {
    uint16_t srcstr_len = 0;
    uint16_t substr_len = 0;

    while (*(srcstr + srcstr_len) != '\0') {
        srcstr_len++;
    }
    while (*(substr + substr_len) != '\0') {
        substr_len++;
    }

    if (substr_len > srcstr_len) {
        fprintf(stderr, "Sub-string has larger length than the source string.\n");
        return;
    }

    while (*substr) {
        if (*substr++ != *srcstr++) {
            printf("False\n");
            return;
        }
    }

    printf("True\n");
}

int main() {
    // Input strings
    char * str1 = "Helllo";
    char * str2 = "Hel";

    check_string_prefix(str1, str2);

    return 0;
}
