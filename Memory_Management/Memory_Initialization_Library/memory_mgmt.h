#include <stdio.h>
#include <stddef.h>

/**
 * @brief Initialize a block of memory with the input value.
 *
 * @param ptr Address of the memory offset
 * @param value Integer value, must be within 0x00 - 0xFF
 * @param size Number of bytes to be written with the specified value
 * @return void* Address of the pointer offset
 */
void * memory_initialize(void * ptr, int value, size_t size);
