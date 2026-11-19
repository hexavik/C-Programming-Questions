/**
 * @file structure_memory_optimization.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-09-17
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stddef.h>
#include <stdio.h>

//
// Unoptimized Structure (Causes Memory Wastage)
//
struct Unoptimized {
    char data1;  // 1 byte
                 // 3 bytes padding inserted here to align next member
    int data2;   // 4 bytes
    short data3; // 2 bytes
                 // 2 bytes padding added at the end for structure alignment
};

//
// Optimized Structure (Members reordered Largest to Smallest)
//
struct Optimized {
    int data2;   // 4 bytes
    short data3; // 2 bytes
    char data1;  // 1 bytes
                 // Only 1 byte of padding added at the end to make it a
                 // multiple of 4
} ;

//
// Removing All Padding using Compiler Directives
//

//
// Option A: GCC/Clang attribute syntax
//
struct __attribute__((packed)) PackedClang {
    int data1;   // 4 bytes
    char data2;  // 1 byte
    short data3; // 2 bytes
};

//
// Option B: Cross-compiler MSVC/GCC pragma syntax
//
#pragma pack(push, 1) // Set alignment boundary to 1 byte
struct PackedPragma {
    int data1;   // 4 bytes
    char data2;  // 1 byte
    short data3; // 2 bytes
};
#pragma pack(pop) // Restore original alignment rules

int main() {
    //
    // Note: Standard C compilers round up structures to multiples of their
    // largest member. An unoptimized layout of (char, int, short) takes 12
    // bytes on standard 32/64-bit systems. By reordering it we reduce it down
    // to 8 bytes.
    //
    printf("Original Structure Size : %zu bytes\n", sizeof(struct Unoptimized));
    printf("Optimized Structure Size: %zu bytes\n", sizeof(struct Optimized));

    // Savings Calculation
    size_t wasted_bytes = sizeof(struct Unoptimized) - sizeof(struct Optimized);
    printf("Memory saved by reordering: %zu bytes\n", wasted_bytes);

    printf("Attributed Structure Size: %zu bytes\n",
        sizeof(struct PackedClang));
    printf("Pragma Structure Size    : %zu bytes\n",
        sizeof(struct PackedPragma));

    return 0;
}
