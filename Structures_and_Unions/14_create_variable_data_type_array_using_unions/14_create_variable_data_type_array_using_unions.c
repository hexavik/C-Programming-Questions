/**
 * @file variable_datatype_array.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-08-30
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>

typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_CHAR
} DataType;

typedef union {
    int* int_arr;
    float* float_arr;
    char* char_arr;
} DataUnion;

typedef struct {
    DataType type;
    ssize_t size;
    DataUnion data;
} GenericArray;

void printArray(GenericArray arr) {
    switch (arr.type) {
        case TYPE_INT:
            printf("Array of Integers: [");
            for (int i = 0; i < arr.size; ++i) {
                printf("%d%s",
                    arr.data.int_arr[i], (i < arr.size - 1) ? ", " : "");
            }
            printf("]\n");
            break;

        case TYPE_FLOAT:
            printf("Array of Floats: [");
            for (int i = 0; i < arr.size; ++i) {
                printf("%f%s",
                    arr.data.float_arr[i], (i < arr.size - 1) ? ", " : "");
            }
            printf("]\n");
            break;

        case TYPE_CHAR:
            printf("Array of Char: [");
            for (int i = 0; i < arr.size; ++i) {
                printf("%c%s",
                    arr.data.char_arr[i], (i < arr.size - 1) ? ", " : "");
            }
            printf("]\n");
            break;

        default:
            printf("Unknown Data Type.\n");
    }
}

int main() {
    //
    // Example with Integer Array
    //
    int int_values[] = { 1, 2, 3, 4, 5 };
    GenericArray int_struct;
    int_struct.type = TYPE_INT;
    int_struct.size = 5;
    int_struct.data.int_arr = int_values;

    //
    // Example with Float Array
    //
    float float_values[] = { 1.1f, 2.2f, 3.3f };
    GenericArray float_struct;
    float_struct.type = TYPE_FLOAT;
    float_struct.size = 3;
    float_struct.data.float_arr = float_values;

    //
    // Example with Integer Array
    //
    char char_values[] = { 'A', 'B', 'C', 'D' };
    GenericArray char_struct;
    char_struct.type = TYPE_CHAR;
    char_struct.size = 4;
    char_struct.data.char_arr = char_values;

    printArray(int_struct);
    printArray(float_struct);
    printArray(char_struct);

    return 0;
}
