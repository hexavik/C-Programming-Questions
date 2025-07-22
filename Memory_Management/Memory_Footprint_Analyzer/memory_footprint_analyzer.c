#include <stddef.h>
#include <stdio.h>
#include <stdalign.h>

#define PRINT_TYPE_SIZE(type) \
    printf("Size of %-20s : %zu bytes\n", #type, sizeof(type))

#define PRINT_TYPE_ALIGN(type) \
    printf("Alignment of %-15s : %zu bytes\n", #type, alignof(type))

#define PRINT_STRUCT_PADDING(struct_type, ...) \
    do { \
        size_t raw_size = 0; \
        size_t member_sizes[] = { __VA_ARGS__ }; \
        for (size_t i = 0; i < sizeof(member_sizes) / sizeof(member_sizes[0]); i++) { \
            raw_size += member_sizes[i]; \
        } \
        size_t padded_size = sizeof(struct_type); \
        printf("Padding in %-17s : %zu bytes (raw: %zu)\n", \
            #struct_type, padded_size - raw_size, raw_size, padded_size); \
    } while (0)

struct Point { int x; int y; int z;};
struct Info { int id; char c; float amount; };
union Data { int i; float f; char c; };

int main() {
    // Primitive types
    PRINT_TYPE_SIZE(int);
    PRINT_TYPE_SIZE(char);
    PRINT_TYPE_SIZE(float);
    PRINT_TYPE_SIZE(long);
    PRINT_TYPE_SIZE(double);

    // Custom types
    PRINT_TYPE_SIZE(struct Point);
    PRINT_TYPE_SIZE(struct Info);
    PRINT_TYPE_SIZE(union Data);

    // Padding Comparison
    PRINT_STRUCT_PADDING(struct Point, sizeof(int), sizeof(int), sizeof(int));
    PRINT_STRUCT_PADDING(struct Info, sizeof(int), sizeof(char), sizeof(float));

    // Alignment info
    PRINT_TYPE_ALIGN(struct Point);
    PRINT_TYPE_ALIGN(struct Info);
    PRINT_TYPE_ALIGN(union Data);

    return 0;
}
