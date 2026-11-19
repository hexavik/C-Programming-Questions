/**
 * @file file_attributes.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-08-01
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

typedef struct Date {
    uint8_t day;
    uint8_t month;
    uint16_t year;
} Date;

typedef enum FileType {
    DOCUMENT,
    IMAGE,
    VIDEO,
    AUDIO,
    OTHER
} FileType;

const char* get_file_type_name(FileType type) {
    switch (type) {
        case DOCUMENT: return "Documet";
        case IMAGE:    return "Image";
        case VIDEO:    return "Video";
        case AUDIO:    return "Audio";
        default:       return "Other";
    }
}

typedef struct FileAttributes {
    char* name;
    FileType type;
    size_t size;
    Date creation_date;
} FileAttributes;

int main() {
    FileAttributes file = {
        "document.txt",
        DOCUMENT,
        1024,
        { 29, 8, 2023 }
    };

    printf(
        "File: \"%s\", Type: %s, Size: %lu bytes, \
        Created on: %04d-%02d-%02d\n",
        file.name, get_file_type_name(file.type),
        file.size,
        file.creation_date.year,
        file.creation_date.month,
        file.creation_date.day);

    return 0;
}
