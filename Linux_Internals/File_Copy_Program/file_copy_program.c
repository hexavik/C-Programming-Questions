/**
 * @file file_copy_program.c
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @date 2025-02-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 4096

int main() {
    char * src_file = "./input.txt";
    char * dest_file = "./output.txt";

    // Create a fixed size buffer, as we are going to copy file data
    // chunk by chunk.
    char buffer[BUFFER_SIZE];

    // The source file must exist
    int src_fd = open(src_file, O_RDONLY, 0);
    if (src_fd < 0) {
        fprintf(stderr, "Cannot open the file: %s\n", src_file);
        exit(1);
    }

    // Open or crate the destination file
    int dest_fd = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (dest_fd < 0) {
        fprintf(stderr, "Cannot open the file: %s\n", dest_file);
        close(src_fd);
        exit(1);
    }

    int bytes_read;
    int bytes_written;
    
    // read and write data in chunks
    while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            fprintf(stderr, "Error writing to destination file: %s: %s\n", dest_file, strerror(errno));
            close(dest_fd);
            close(src_fd);
            exit(1);
        }
    }

    // Handle read errors
    if (bytes_read == -1) {
        fprintf(stderr, "Error reading from source file: %s: %s\n", src_file, strerror(errno));
        close(dest_fd);
        close(src_fd);
        exit(1);
    }

    // Close files
    close(dest_fd);
    close(src_fd);

    printf("File copied successfully.\n");

    return 0;
}
