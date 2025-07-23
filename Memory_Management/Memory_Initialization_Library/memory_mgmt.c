#include "memory_mgmt.h"

void * memory_initialize(void * ptr, int value, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        *((unsigned char * )ptr + i) = (unsigned char )value;
    }

    return ptr;
}
