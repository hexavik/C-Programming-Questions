/**
 * @file custom_memcpy_function.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-21
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>

int main() {
    // Input
    char src[] = "hello";
    char dest[6];
    int length = sizeof(src) / sizeof(src[0]);

    char * src_ptr = src;
    char * dest_ptr = dest;

    for (int i = 0; i < length; ++i) {
        *dest_ptr++ = *src_ptr++;
    }

    printf("dest: %s\n", dest);

    return 0;
}
