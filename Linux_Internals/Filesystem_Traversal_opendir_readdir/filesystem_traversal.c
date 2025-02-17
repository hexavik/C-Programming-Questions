/**
 * @file filesystem_traversal.c
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @date 2025-02-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PATH_LENGTH 4096

/**
 * @brief File types for the comparison against the lstat() output. 
 * Currently we have used only the necessary members for this program.
 */
typedef enum {
    DIRECTORY,
    SYMLINK,
    REGULARFILE,
    UNKNOWN
} FILETYPE;

/**
 * @brief Retrieve the type of the file using lstat().
 * 
 * @param filepath Input path of the file or directory
 * @return FILETYPE enumeration member
 */
FILETYPE get_filetype(const char * filepath) {
    struct stat st;

    if (lstat(filepath, &st) != 0) {
        perror("lstat");
        return UNKNOWN;
    }

    switch (st.st_mode & S_IFMT) {
    case S_IFDIR:
        return DIRECTORY;
    case S_IFLNK:
        return SYMLINK;
    case S_IFREG:
        return REGULARFILE;
    default:
        return UNKNOWN;
    }
}

/**
 * @brief Opens the directory and reads the content of it. Runs 
 * recursively if the direcotry contains another directory inside it.
 * If file type is a regular file then it only displays the filename.
 * In case of symlinks, or '.', or '..' directories it does nothing.
 * 
 * @param dirpath Input valid directory path
 */
void traverse_directory(const char * dirpath) {
    DIR * pDir;
    struct dirent * entry;
    char fullpath[MAX_PATH_LENGTH];

    pDir = opendir(dirpath);
    if (pDir == NULL) {
        fprintf(stderr, "Cannot open directory: %s: %s\n", dirpath, strerror(errno));
        return;
    }

    while ((entry = readdir(pDir)) != NULL) {
        // Skip '.' (current) and '..' (parent) directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Append the directory or filename with the filepath
        snprintf(fullpath, sizeof(fullpath), "%s/%s", dirpath, entry->d_name);
        printf("%s\n", fullpath);

        FILETYPE ft = get_filetype(fullpath);
        if (ft == UNKNOWN) {
            fprintf(stderr, "Unknown or invalid file type.\n");
            continue;
        }
        if (ft == DIRECTORY) {
            traverse_directory(fullpath);
        }
    }

    closedir(pDir);
}

int main(int argc, char ** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    // Check if the argument is directory or not
    FILETYPE root_dir_type = get_filetype(argv[1]);
    if (root_dir_type != DIRECTORY) {
        fprintf(stderr, "Not a valid directory: %s\n", argv[1]);
        return 1;
    }

    traverse_directory(argv[1]);

    return 0;
}
