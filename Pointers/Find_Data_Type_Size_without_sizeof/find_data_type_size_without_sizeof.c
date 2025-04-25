/**
 * @file find_data_type_size_without_sizeof.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-26
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>

// The macro uses a GNU C extension "({...})" block, which works in
// GCC/Clang, but not strictly in standard C.
#define GET_SIZE(var) ({ \
    typeof(var) temp[2]; \
    (char *)&temp[1] - (char *)&temp[0]; \
})

// This implementation is only for datatypes
#define GET_TYPE_SIZE(type) ((char *)(((type * )0) + 1) - (char *)((type * )0))

int main() {
    int x = 5;
    char c = 'A';
    float f = 3.14f;
    double d = 9.81;

    printf("Size of int: %zu\n", GET_SIZE(x));
    printf("Size of char: %zu\n", GET_SIZE(c));
    printf("Size of float: %zu\n", GET_SIZE(f));
    printf("Size of double: %zu\n", GET_SIZE(d));

    printf("Size of int: %zu\n", GET_TYPE_SIZE(int));
    printf("Size of char: %zu\n", GET_TYPE_SIZE(char));
    printf("Size of float: %zu\n", GET_TYPE_SIZE(float));
    printf("Size of double: %zu\n", GET_TYPE_SIZE(double));

    return 0;
}
