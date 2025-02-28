#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int pid;
    int status;

    printf("Parent: %d\n", getpid());

    pid = fork();
    if (pid == 0) { 
        printf("Child: %d\n", getpid());
        sleep(2);
        exit(EXIT_SUCCESS);
    }

    // Parent waits process pid (child)
    waitpid(pid, &status, 0);

    if (WIFSIGNALED(status)) {
        printf("Error\n");
    } else if (WEXITSTATUS(status)) {
        printf("Exited Normally\n");
    }

    printf("Parent: %d\n", getpid());

    return 0;
}
