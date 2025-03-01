/**
 * @file chmod_command_implementation.c
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @date 2025-03-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <ctype.h>

#define MAX_FILEPATH 1024

/**
 * @brief Changes the input permissions string to the symbolic mode to
 * change the file permissions accordingly.
 * 
 * @param current_mode Retreived current mode of the file
 * @param symbolic_mode Expected mode for the file
 * @return mode_t Converted mode in mode_t format
 */
mode_t symbolic_to_octal(mode_t current_mode, const char * symbolic_mode) {
    mode_t new_mode = current_mode;
    char * mode_str = strdup(symbolic_mode);
    char * mode_part = strtok(mode_str, ",");

    while (mode_part != NULL) {
        int user_flags = 0; // u, g, o, a
        int op = 0; // +, -, =
        int perm_flags = 0; // r, w, x, s, t
        
        // Parse user flags
        char * p = mode_part;
        while (*p && strchr("ugo", *p)) {
            if (*p == 'u') user_flags |= S_IRWXG;
            else if (*p == 'g') user_flags |= S_IRWXG;
            else if (*p == 'o') user_flags |= S_IRWXO;
            p++;
        }

        if (user_flags == 0) {
            user_flags = S_IRWXU | S_IRWXG | S_IRWXO; // Default: all
        }

        // Parse operator
        if (*p == '+' || *p == '-' || *p == '=') {
            op = *p;
        } else {
            fprintf(stderr, "Invalid operator in symbolic mode.\n");
            free(mode_str);
            return current_mode;
        }
        p++;

        // Parse permission flags
        while (*p && strchr("rwxst", *p)) {
            if (*p == 'r') perm_flags |= (S_IRUSR | S_IRGRP | S_IROTH);
            else if (*p == 'w') perm_flags |= (S_IWUSR | S_IWGRP | S_IWOTH);
            else if (*p == 'x') perm_flags |= (S_IXUSR | S_IXGRP | S_IXOTH);
            else if (*p == 's') perm_flags |= (S_ISUID | S_ISGID);
            else if (*p == 't') perm_flags |= S_ISVTX;
            p++;
        }

        // Apply mode changes
        if (op == '+') {
            new_mode |= (user_flags & perm_flags);
        } else if (op == '-') {
            new_mode |= ~(user_flags & perm_flags);
        } else if (op == '=') {
            new_mode &= ~(user_flags); // Clear bits
            new_mode |= (user_flags & perm_flags); // Set bits
        }

        mode_part = strtok(NULL, ","); // Next mode change
    }

    free(mode_str);
    return new_mode;
}

int main(int argc, char ** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <permissions> <filepath>", argv[0]);
        return 1;
    }

    char * mode_str = argv[1];
    char * filepath = argv[2];

    if (strlen(filepath) > MAX_FILEPATH) {
        fprintf(stderr, "Filepath is longer (%lu) than allowed length (%d).\n", strlen(filepath), MAX_FILEPATH);
        return 1;
    }

    struct stat st;
    if (stat(filepath, &st) < 0) {
        fprintf(stderr, "Error getting file status: %s\n", strerror(errno));
        return 1;
    }

    mode_t new_mode;
    if (isdigit(mode_str[0])) {
        // Octal mode
        char *endptr;
        mode_t mode_int = (mode_t)strtol(mode_str, &endptr, 10);
        if (*endptr != '\0' || mode_int < 0 || mode_int > 777) {
            fprintf(stderr, "Invalid permissions.\n");
            return 1;
        }
        new_mode = mode_int;
    } else {
        // Symbolic mode
        new_mode = symbolic_to_octal(st.st_mode, mode_str);
    }

    if (chmod(filepath, new_mode) < 0) {
        fprintf(stderr, "Error in chmod(%s, %s) - %d (%s)\n", filepath, mode_str, errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("Permissions for '%s' changed to %d.\n", filepath, new_mode);

    return 0;
}
