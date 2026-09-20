/**
 * @file recursive_string_reversal.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-09-18
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>
#include <string.h>

void reverse_recursive(char* str, int left, int right) {
    if (left >= right) { return; }

    //
    // Swap the characters at left and right positions
    //
    char temp = str[left];
    str[left] = str[right];
    str[right] = temp;

    //
    // Recursive call: move pointers inward
    //
    reverse_recursive(str, left + 1, right - 1);
}

void reverse_string(char* str) {
    if (!str || *str == '\0') { return; }

    int length = strlen(str);
    reverse_recursive(str, 0, length - 1);
}

int main() {
    char str[] = "hello";

    printf("Original: %s\n", str);
    reverse_string(str);
    printf("Reversed: %s\n", str);

    return 0;
}
