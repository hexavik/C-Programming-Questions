/**
 * @file endianness_conversion.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-09-17
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <stdint.h>
#include <stdio.h>

//
// Union to map a 32-bit integer over a 4-byte array
//
typedef union {
    uint32_t value;   // Full 32-bit integer
    uint8_t bytes[4]; // Individual byte elements (indices 0 to 3)
} EndianConverter;

uint32_t toggle_endianness(uint32_t input_value) {
    EndianConverter src;
    EndianConverter dest;

    src.value = input_value;

    //
    // Reverse the byte array sequence using the shared union layout
    //
    dest.bytes[0] = src.bytes[3];
    dest.bytes[1] = src.bytes[2];
    dest.bytes[2] = src.bytes[1];
    dest.bytes[3] = src.bytes[0];

    return dest.value;
}

int main() {
    uint32_t original_int = 0xAABBCCDD;
    printf("Int:       0x%08X\n", original_int);

    uint32_t converted_int = toggle_endianness(original_int);
    printf("Converted: 0x%08X\n", converted_int);

    return 0;
}
