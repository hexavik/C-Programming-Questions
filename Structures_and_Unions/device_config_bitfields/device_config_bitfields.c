/**
 * @file device_config_bitfields.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-09-17
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>

//
// Structure with bit fields to tightly pack binary configuration states
//
typedef struct {
    unsigned int setting1 : 1; // 1 bit: can be 0 (OFF) or 1 (ON)
    unsigned int setting2 : 1; // 1 bit
    unsigned int setting3 : 1; // 1 bit
    unsigned int setting4 : 1; // 1 bit
    // Remaining bits in the integer padding are automatically
    // managed by the compiler
} DeviceConfig;

void display_settings(DeviceConfig config) {
    printf("O/P: ");

    int active_count = 0;

    //
    // Check individual bit field variables directly
    //
    if (config.setting1) {
        printf("Setting 1");
        active_count += 1;
    }
    if (config.setting2) {
        printf("%sSetting 2", active_count > 0 ? " & " : "");
        active_count += 1;
    }
    if (config.setting3) {
        printf("%sSetting 3", active_count > 0 ? " & " : "");
        active_count += 1;
    }
    if (config.setting4) {
        printf("%sSetting 4", active_count > 0 ? " & " : "");
        active_count += 1;
    }

    if (active_count == 0) { printf("All Settings: OFF"); }
    else { printf(": ON\n"); }
}

int main() {
    DeviceConfig dev;

    //
    // Setting binary sequence 1001
    // (reading right-to-left or mapping explicitly)
    //
    dev.setting1 = 1; // ON
    dev.setting2 = 0; // OFF
    dev.setting3 = 0; // OFF
    dev.setting4 = 1; // ON

    printf("Input Config: 1001 (Setting 1: ON, 2: OFF, 3: OFF, 4: ON)\n");

    //
    // Evaluate and output status
    //
    display_settings(dev);

    //
    // Verify the compact footprint size
    //
    printf("Size of compact structure: %zu byte(s)\n", sizeof(dev));

    return 0;
}
