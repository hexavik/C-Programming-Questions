#include <stdio.h>
#include <stddef.h>

#define PRINT_STRUCT_OFFSET(struct, member) \
    printf("Offset of '%s' in '%s': %ld bytes\n", \
        #member, #struct, offsetof(struct, member))

struct address {
    char name[50];
    float house_no;
    int phone;
};

int main() {
    PRINT_STRUCT_OFFSET(struct address, phone);
    PRINT_STRUCT_OFFSET(struct address, name);
    PRINT_STRUCT_OFFSET(struct address, house_no);

    return 0;
}
