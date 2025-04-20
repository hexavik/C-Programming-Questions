/**
 * @file check_string_palindome.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-20
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdbool.h>

bool check_string_palindrome(char * str) {
    int str_len = 0;
    while (*(str + str_len) != 0) {
        str_len++;
    }

    char * i = str;
    char * j = str + (str_len - 1);
    while (i < j) {
        if (*i++ != *j--) {
            return false;
        }
    }

    return true;
}

int main() {
    // Input string
    char str[] = "radar";

    check_string_palindrome(str) ?
        printf("True\n") : printf("False\n");

    return 0;
}
