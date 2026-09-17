/**
 * @file 32bit_value_access.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-09-17
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdint.h>
#include <stdio.h>

typedef union {
    uint32_t val32;    // Full 32-bit value
    uint16_t val16[2]; // Two 16-bit values
    uint8_t  val8[2];  // Four 8-bit values
} Register32;

int main() {
    Register32 reg;
    // Input value
    reg.val32 = 0xABCD1234;

    printf("Input Value: 0x%08X\n\n", reg.val32);

    //
    // Determine endianness at runtime to print in the requested physical order
    //
    volatile uint32_t i = 0x01234567;
    int is_little_endian = (*((uint8_t*)(&i)) == 0x67);

    if (is_little_endian) {
        //
        // On Little-Endian, the elements are stored reversed in memory:
        // val8[0] = 0x34, val8[1] = 0x12, val8[2] = 0xCD, val8[3] = 0xAB
        // val16[0] = 0x1234, val16[1] = 0xABCD
        //
        printf("--- Intepreted Layout (Big-Endian Order Representation) ---\n");
        printf("16-bits: 0x%04X, 0x%04X\n", reg.val16[0], reg.val16[1]);
        printf("8-bits: 0x%02X, 0x%02X, 0x%02X, 0x%02X\n",
            reg.val8[0], reg.val8[1], reg.val8[2], reg.val8[3]);
    } else {
        //
        // On Big-Endian, elements naturally map in order:
        //
        printf("--- Interpreted Layout (Big-Endian Natural Order) ---\n");
        printf("16-bits: 0x%04X, 0x%04X\n", reg.val16[0], reg.val16[1]);
        printf("8-bits: 0x%02X, 0x%02X, 0x%02X, 0x%02X\n",
            reg.val8[0], reg.val8[1], reg.val8[2], reg.val8[3]);
    }

    return 0;
}
