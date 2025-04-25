/**
 * @file custom_strtok_function.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-22
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <string.h>

char * custom_strtok(char * str, const char delimiter) {
    static char * input_str;
    char * token_start;
    char * token_end;

    if (str != NULL) {
        input_str = str;
    }

    if (input_str == NULL || *input_str == '\0') {
        return NULL;
    }

    // Find the start of the next token (skip leading delimiters)
    while (*input_str == delimiter) {
        input_str++;
        if (*input_str == '\0') {
            return NULL;
        }
    }
    token_start = input_str;

    // Find end of the current token (the next delimiter or end of string)
    while (*input_str != delimiter && *input_str != '\0') {
        input_str++;
    }
    token_end = input_str;

    // If we found a delimiter, replace it with a null-terminator to
    // mark the end of the token string
    if (*input_str == delimiter) {
        *input_str++ = '\0';
    }

    // Return the pointer to the start of the token
    return token_start;
}

int main() {
    // Input string
    char str[] = "embedded,systems,linux";
    char delimiter = ',';

    // Since strtok() is a stateful and non-reentrant function
    // wee need to call it repeatedly to retrieve all tokens one by one
    char * token = custom_strtok(str, ',');

    while (token != NULL) {
        printf("%s\n", token);
        token = custom_strtok(NULL, ',');
    }

    return 0;
}
