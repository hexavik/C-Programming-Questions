/**
 * @file color_rgb_cmyk.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-08-01
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <stdint.h>
#include <stdio.h>

typedef enum {
    RGB = 0,
    CMYK = 1,
} ColorType;

typedef union ColorFormat {
    //
    // Value ranges from 0 to 255
    //
    struct RGB {
        uint8_t red;
        uint8_t green;
        uint8_t blue;
    } rgb;

    //
    // Value ranges from 0 to 100 in percentage
    //
    struct CMYK {
        uint8_t cyan;
        uint8_t magenta;
        uint8_t yellow;
        uint8_t key; // Black
    } cmyk;
} ColorFormat;

void color_format_display(ColorFormat format, ColorType type) {
    if (type == RGB) {
        printf("RGB Color: [%d %d %d]\n",
            format.rgb.red, format.rgb.green, format.rgb.blue);
    } else if (type == CMYK) {
        printf("CMYK Color: [%d%% %d%% %d%% %d%%]\n",
            format.cmyk.cyan, format.cmyk.magenta,
            format.cmyk.yellow, format.cmyk.key);
    }
}

int main() {
    ColorFormat rgb1 =
        { .rgb = { .red = 255, .green = 0, .blue = 128 } };
    ColorFormat cmyk1 =
        { .cmyk = { .cyan = 34, .magenta = 78, .yellow = 12, .key = 50 } };

    color_format_display(rgb1, RGB);
    color_format_display(cmyk1, CMYK);

    return 0;
}
