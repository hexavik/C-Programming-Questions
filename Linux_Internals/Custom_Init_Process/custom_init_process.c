/**
 * @file custom_init_process.c
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @date 2025-02-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mount.h>
#include <signal.h>
#include <errno.h>

/**
 * @brief Handles the specified signals
 * 
 * @param sig e.g. SIGCHLD
 */
void handle_signal(int sig) {
    int status;
    pid_t child_pid;

    switch (sig) {
        case SIGCHLD:
            // Reap any terminated child processes to prevent zombies
            while ((child_pid = waitpid(-1, &status, WNOHANG)) > 0) {
                if (WIFEXITED(status)) {
                    fprintf(stderr, "Child process %d exited with status %d.\n", child_pid, WEXITSTATUS(status));
                } else if (WIFSIGNALED(status)) {
                    fprintf(stderr, "Child process %d terminated by signal %d.\n", child_pid, WTERMSIG(status));
                }
            }
            break;
        
        // Add other signal handlers as needed (e.g., for graceful shutdown)

        default:
            fprintf(stderr, "Unhandled Signal: %d\n", sig);
            break;
    }
}

int main(int argc, char **argv) {
    pid_t pid;

    //
    // 1. Set up signal handlers (important for robustness)
    //
    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART | SA_NOCLDSTOP;  // Important flags
    if (sigaction(SIGCHLD, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }
    // Others signals handlers can be added in accordance to the requirement.

    //
    // 2. Mount essential filesystems (critical)
    //
    if (mount("/", "/", NULL, MS_RDONLY, NULL) == -1) {
        // Remount root read-only
        perror("mount /");
        return 1;
    }

    if (mount("proc", "/proc", "proc", 0, NULL) == -1) {
        perror("mount /proc");
        return 1;
    }

    if (mount("sys", "/sys", "sysfs", 0, NULL) == -1) {
        perror("mount /sys");
        return 1;
    }

    if (mount("devtmpfs", "/dev", "devtmpfs", 0, "size=65536k") == -1) {
        perror("mount /dev");
        return 1;
    }

    //
    // Create necessary device nodes (if needed, using mknod ot udev)
    // Example (if you don't have udev):
    // mknod("/dev/console", S_IFCHR | 0600, makedev(5, 1)); // Example
    //

    //
    // 3. Remount root read-write (after basic setup)
    //
    if (mount("/", "/", NULL, MS_REMOUNT, NULL) == -1) {
        perror("remount / rw");
        return 1;
    }

    //
    // 4. Start essential servivces or daemons
    //
    pid = fork();
    if (pid == 0) { // Child process
        // Execute your first program (e.g. a shell or a system initialization script)
        execl("/bin/sh", "/bin/sh", NULL);
        perror("execl");
        _exit(1);
    } else if (pid < 0) {
        perror("fork");
        return 1;
    }

    //
    // 5. The init process's main loop (handling children, etc.)
    //
    while (1) {
        // Wait for signals (children to die, etc.)
        pause();
    }

    return 0;
}
