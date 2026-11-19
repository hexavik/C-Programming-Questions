/**
 * @file error_code_representation.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-08-01
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <stdio.h>

//
// Define error categories
//
typedef enum {
    ERR_NONE = 0,
    ERR_POSIX,
    ERR_CUSTOM,
    ERR_TIMEOUT
} ErrorType;

//
// Define the error payload using a union
//
typedef union {
    int posix_code;    // For standard errno values
    int custom_code;   // For application-specific codes
    float timeout_sec; // For duration-based timeouts
} ErrorData;

//
// Combine tag and union into a single structure
//
typedef struct {
    ErrorType type;
    ErrorData data;
} ResultError;

void print_error(ResultError err) {
    switch (err.type) {
        case ERR_NONE:
            printf("No error.\n");
            break;
        case ERR_POSIX:
            printf("POSIX Error: %d\n", err.data.posix_code);
            break;
        case ERR_CUSTOM:
            printf("Custom App Error: %d\n", err.data.custom_code);
            break;
        case ERR_TIMEOUT:
            printf("Timeout after: %.2f seconds\n", err.data.timeout_sec);
            break;
    }
}

int main() {
    ResultError err1 = { .type = ERR_POSIX, .data.posix_code = 9 };
    ResultError err2 = { .type = ERR_TIMEOUT, .data.timeout_sec = 2.5f };

    print_error(err1);
    print_error(err2);

    return 0;
}
