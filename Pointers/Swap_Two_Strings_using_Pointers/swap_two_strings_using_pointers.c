/**
 * @file swap_two_strings_using_pointers.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-26
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>

int main() {
    // Input strings
    char * str1 = "hello";
    char * str2 = "world";

    char * temp = str1;
    str1 = str2;
    str2 = temp;

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    return 0;
}
