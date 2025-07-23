#include "memory_mgmt.h"

int main() {
    unsigned char arr[10] = {0};

    printf("Before init: ");
    for (int i = 0; i < 10; ++i) {
        printf("0x%02x, ", arr[i]);
    }
    printf("\n");

    memory_initialize(arr + 3, 0xAA, 4);

    printf("After init: ");
    for (int i = 0; i < 10; ++i) {
        printf("0x%02x, ", arr[i]);
    }
    printf("\n");

    return 0;
}
