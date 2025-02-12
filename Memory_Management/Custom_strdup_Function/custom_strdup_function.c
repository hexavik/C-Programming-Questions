/**
 * @file custom_strdup_function.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-02-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief A replica of a custom strdup(), in which we are duplciating
 * the source string. This also handles the mepty strings "" since 
 * they are null-terminated.
 * 
 * @param str Input String
 * @return char* duplcated string pointer
 */
char * duplicate_str(const char * str) {
    // Calculate the length of the string
    int str_len = strlen(str);

    // Validate the null terminated string
    if (str[str_len] == '\0') {
        printf("Null Terminated String.\n");
    } else {
        printf("Invalid String.\n");
    }

    // Create a new string pointer and allocate memeory to it
    char * duplicate = (char * )malloc(str_len + 1);
    if (!duplicate) {
        printf("ERROR: Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i <= str_len; ++i) {
        *(duplicate + i) = *(str + i);
    }

    return duplicate;
}

int main() {
    // Input String
    char * source_str = "hello, world!";

    char * duplicate = duplicate_str(source_str);

    if (duplicate != NULL) {      
        printf("Duplcaited String: %s\n", duplicate);
        free(duplicate);
    }

    return 0;
}
