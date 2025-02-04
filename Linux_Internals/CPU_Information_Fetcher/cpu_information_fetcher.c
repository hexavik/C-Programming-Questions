/**
 * @file cpu_information_fetcher.c
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @date 2025-01-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define _GNU_SOURCE

int main() {
    FILE *cpuinfo = fopen("/proc/cpuinfo", "rb");
    if (cpuinfo == NULL) {
        fprintf(stderr, "Error opening /proc/cpuinfo: %s\n", strerror(errno));
        return 1;
    }

    char * line = 0;
    size_t len = 0;
    while (getdelim(&line, &len, 0, cpuinfo) != -1) {
        fputs(line, stdout);
    }

    free(line);
    line = NULL;
    fclose(cpuinfo);

    return 0;
}
