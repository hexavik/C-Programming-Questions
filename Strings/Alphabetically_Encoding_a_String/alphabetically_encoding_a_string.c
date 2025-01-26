/**
 * @file alphabetically_encoding_a_string.c
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum count of A-Z alphabets
#define ALPHABETS_COUNT 26

void encode_string(char * input_string, char * output_string, int char_place) {
    if (input_string == NULL) {
        printf("Error: Input string is NULL.\n");
        return;
    }

    for (int i = 0; i < strlen(input_string); ++i) {
        char get_char = input_string[i];
        if (get_char >= 'a' && get_char <= 'z') {
            output_string[i] = ((get_char - 'a' + char_place) % ALPHABETS_COUNT) + 'a';
        } else if (get_char >= 'A' && get_char <= 'Z') {
            output_string[i] = ((get_char - 'A' + char_place) % ALPHABETS_COUNT) + 'A';
        } else {
            output_string[i] = get_char;
        }
    }
}

int main() {
    // Input String
    char * input_string = "Hello World!";
    // Encoding offset
    int offset = 3;

    char * output_string = (char *)malloc((strlen(input_string) + 1) * sizeof(char));
    if (!output_string) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }

    encode_string(input_string, output_string, offset);

    // Display output string
    printf("Result: %s\n", output_string);

    free(output_string);
    output_string = NULL;

    return 0;
}
