/**
 * @file custom_signal_handling.c
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @date 2025-02-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * @brief Handles the SIGINT (Ctrl+C) signal
 * 
 * @param sig 
 */
void handle_sigint(int sig) {
    char * buffer = "\nReceived SIGINT. Exiting...\n";
    if (write(1, buffer, strlen(buffer)) == -1) {
        // Use _exit() in signal handlers
        _exit(1);
    }

    _exit(0);
}

/**
 * @brief Handles the SIGTERM (kill -TERM <pid>) command signal
 * 
 * @param sig 
 */
void handle_sigterm(int sig) {
    char * buffer = "\nReceied SIGTERM. Performing cleanup and exiting...\n";
    if (write(1, buffer, strlen(buffer)) == -1) {
        // Use _exit() in signal handlers
        _exit(1);
    }

    _exit(0);
}

int main() {
    struct sigaction sa;

    // Handle SIGINT
    sa.sa_handler = handle_sigint;
    sigemptyset(&sa.sa_mask);  // Block no other signals during handler execution
    sa.sa_flags = 0;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    // Handle SIGTERM
    sa.sa_handler = handle_sigterm;
    if (sigaction(SIGTERM, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    printf("Waiting for SIGINT (Ctrl+C) or SIGTERM (kill -TERM <pid>)...\n");
    while (1) {
        sleep(1);
    }

    return 0;
}
