#include "circular_buffer.h"
#include <stdint.h>
#include <stdio.h>

int main() {
    CircularBuffer buff;
    init_circular_buffer(&buff);

    display_buffer(&buff);

    uint8_t rSz1 = 4;
    uint8_t rData1[4] = {0};
    if (read_data(&buff, rData1, rSz1) != CB_OK) {
        // Handle error here, else leave it blank
    }

    uint8_t data1[3] = {3, 2, 9};
    uint8_t sz1 = sizeof(data1) / sizeof(data1[0]);
    if (write_data(&buff, data1, sz1) != CB_OK) {
        // Handle error here, else leave it blank
    }

    uint8_t data2[5] = {6, 1, 9, 4, 5};
    uint8_t sz2 = sizeof(data2) / sizeof(data2[0]);
    if (write_data(&buff, data2, sz2) != CB_OK) {
        // Handle error here, else leave it blank
    }

    uint8_t rSz2 = 4;
    uint8_t rData2[4] = {0};
    if (read_data(&buff, rData2, rSz2) != CB_OK) {
        // Handle error here, else leave it blank
    }

    uint8_t data3[4] = {8, 8, 8, 8};
    uint8_t sz3 = sizeof(data3) / sizeof(data3[0]);
    if (write_data(&buff, data3, sz3) != CB_OK) {
        // Handle error here, else leave it blank
    }

    return 0;
}
