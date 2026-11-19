/**
 * @file 4_byte_value_conversion.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-09-17
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdint.h>
#include <stdio.h>

// 
// Union to hold the 4-Bytes data
//
typedef union {
    uint8_t bytes[4]; // Raw 4-byte array
    uint32_t integer; // 32-bit unsigned integer intepretation
    float floating;   // 32-bit float interpretation
} ByteInterpreter;

int main() {
    ByteInterpreter bi;

    //
    // Check system endiannes to handle the byte array order correctly
    //
    volatile uint32_t test = 0x01234567;
    int is_little_endian = (*((uint8_t*)(&test)) == 0x67);

    //
    // Input configuration
    // Note: 0x43480000 in IEEE 754 format translates to exactly 200.0
    // If the target expected value for these bytes is 134.0, the hex bytes
    // are [0x43, 0x06, 0x00, 0x00]
    //
    if (is_little_endian) {
        //
        // Little-endian systems store the least significant byte first
        //
        bi.bytes[0] = 0x00;
        bi.bytes[1] = 0x00;
        bi.bytes[2] = 0x48;
        bi.bytes[3] = 0x43;
    } else {
        //
        // Big-endian systems store the most significant byte first
        //
        bi.bytes[0] = 0x43;
        bi.bytes[1] = 0x48;
        bi.bytes[2] = 0x00;
        bi.bytes[3] = 0x00;
    }

    //
    // Output interpretations
    //
    printf("Raw Integer Hex: 0x%08X\n", bi.integer);
    printf("As Intrger:      %u\n", bi.integer);
    printf("As Float:        %.1f\n", bi.floating);

    return 0;
}
