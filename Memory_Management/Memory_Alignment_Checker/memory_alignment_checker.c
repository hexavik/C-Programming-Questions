#include <stdint.h>
#include <stdio.h>

void alignment_check(uint16_t address, uint16_t alignment) {
    // Validate if the alignment is the power of 2 or not
    if ((alignment & (alignment - 1)) != 0) {
        fprintf(stderr, "Alignment is not in power of 2.\n");
        return;
    }

    printf("Address 0x%x is ", address);
    if ((address & (alignment - 1)) != 0) {
        printf("not ");
    }
    printf("aligned to %d bytes\n", alignment);
}

int main() {
    alignment_check(0x1004, 8);
    alignment_check(2032, 8);
    alignment_check(0x15, 8);
    alignment_check(100, 5);

    return 0;
}
