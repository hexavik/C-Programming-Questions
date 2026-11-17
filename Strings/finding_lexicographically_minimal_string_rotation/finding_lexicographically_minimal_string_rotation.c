/**
 * @file finding_lexicographically_minimal_string_rotation.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-09-21
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t booth_minimal_rotation(const char* str) {
    size_t len = strlen(str);
    int *f = (int * )malloc(2 * len * sizeof(int));
    for (int i = 0; i < 2 * len; ++i) { f[i] = -1; } // Fill -1 in f

    int k = 0; // Least rotation index found so far
    for (int j = 1; j < 2 * len; ++j) {
        char sj = str[j % len];
        int i = f[j - k - 1];

        while (i != -1 && sj != str[(k + i + 1) % len]) {
            if (sj < str[(k + i + 1) % len]) {
                k = j - i - 1;
            }
            i = f[i];
        }

        if (sj != str[(k + i + 1) % len]) {
            if (sj < str[k % len]) { k = j; }
            f[j - k] = -1;
        } else {
            f[j - k] = i + 1;
        }
    }

    free(f);
    return k % len;
}

void print_min_rotation(const char *str) {
    size_t len = strlen(str);
    int start = booth_minimal_rotation(str);

    printf("Minimal rotation: ");
    for (int i = 0; i < len; ++i) {
        printf("%c", str[(start + i) % len]);
    }
    printf("\n");
}

int main() {
    const char *str = "BCABDADAB";
    print_min_rotation(str);

    return 0;
}
