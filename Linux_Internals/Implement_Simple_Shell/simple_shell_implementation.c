/**
 * @file simple_shell_implementation.c
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @date 2025-02-27
 * 
 * @copyright Copyright (c) 2025
 * 
 * Compile command:
 * gcc simple_shell_implementation.c -o simple_shell_implementation -fsanitize=address -static-libasan
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

enum limits {
    MAX_COMMAND_LEN = 1024,
    MAX_TOKEN_LEN = 32,
};

// Delimiter to distinguish between command provided through user input
const char delim[] = " \t";

/**
 * @brief Initialize the interaction with user name and hostname. 
 * Must be called everytime "cd" command is executed to update the 
 * username and the hostname.
 * 
 */
void vsh_init_intercation() {
    char cwd[MAX_COMMAND_LEN];
    getcwd(cwd, sizeof(cwd));
    
    char * username = getlogin();
    if (!username) {
        perror("getlogin failed");
        username = "unknown";
    }
    
    char hostname[MAX_COMMAND_LEN];
    gethostname(hostname, sizeof(hostname));
    printf("%s@%s:%s$ ", username, hostname, cwd);
}

/**
 * @brief Reads input from a user enrolled trough shell terminal.
 * 
 * @return char* Output string enrolled as an input by a user
 */
char * vsh_read_input(void) {
    char * command_buff = (char * )malloc(sizeof(char) * MAX_COMMAND_LEN);
    if (!command_buff) {
        perror("malloc failed at read input");
        exit(EXIT_FAILURE);
    }
    
    if (fgets(command_buff, MAX_COMMAND_LEN, stdin) == NULL) {
        perror("fgets failed");
        exit(EXIT_FAILURE);
    }

    // Remove trailing newline
    size_t len = strlen(command_buff);
    if (len > 0 && command_buff[len - 1] == '\n') {
        command_buff[len - 1] = '\0';
    }

    return command_buff;
}

/**
 * @brief Retrieve the command line from `vsh_read_input()` and split
 * it into the valid tokens based on the delimiter. All the tokens 
 * recorded in the array allocated dynamically.
 * 
 * @param command Retrieved command line from the user.
 * @param token_counter Total number of tokens
 * @return char** All recorded individual tokens
 */
char ** vsh_split_command(char * command, int * token_counter) {
    int position = 0;
    char ** tokens = (char ** )calloc(MAX_TOKEN_LEN, sizeof(char * ));
    if (!tokens) {
        perror("malloc error at split command");
        exit(EXIT_FAILURE);
    }
    // Get the first token
    char * token = strtok(command, delim);
    while (token) {
        tokens[position] = strdup(token);
        if (!tokens[position]) {
            perror("strdup failed");
            exit(EXIT_FAILURE);
        }
        ++position;
        // Go through other tokens by using strtok
        token = strtok(NULL, delim);
    }
    tokens[position] = NULL;
    *token_counter = position;

    return tokens;
}

/**
 * @brief Launch the shell by creating a child process so that current
 * process would not be distrubed.
 * 
 * @param command Command string which are in PATH variable
 * @param command_args Arguments provided along with the commands
 */
void vsh_launch(char * command, char ** command_args) {
    pid_t pid;
    pid_t wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Newly spawned child process
        status = execvp(command, command_args);
        if (status == -1) {
            perror("execvp failed");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        // Error in forking
        perror("vsh fork failed");
    } else {
        // Parent process
        do {
            if (waitpid(pid, &status, WUNTRACED) == -1) {
                perror("waitpid failed");
                break;
            }
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

/**
 * @brief Execution of the shell which will replicate the behavior of
 * a shell in the current terminal session.
 * 
 * @param tokens Dynamic array of all recorded tokens retrieved from
 * a command line
 * @param get_command Dynmaic array of the retrieved user input
 * @param token_count Total number of tokens recorded from the command
 * line
 */
void vsh_execute(char ** tokens, char * get_command, int token_count) {
    if (tokens[0] == NULL) {
        return; // Empty command
    }

    //
    // cd command
    //
    if (strcmp(tokens[0], "cd") == 0) {
        if (tokens[1] == NULL) {
            fprintf(stderr, "vsh: expected argument to \"cd\"\n");        
        } else if (chdir(tokens[1]) != 0) {
            perror("vsh");
        }
        return;
    }

    //
    // exit command
    //
    if (strcmp(tokens[0], "exit") == 0) {
        // Release memory before exiting
        free(get_command);
        for (int i = 0; i < token_count; ++i) {
            free(tokens[i]);
        }
        free(tokens);
        exit(EXIT_SUCCESS);
    }

    //
    // Other external commands
    //
    vsh_launch(tokens[0], tokens);
}

int main(int argc, char ** argv) {
    while (1) {
        vsh_init_intercation();
        
        // Read input from user
        char * get_command = vsh_read_input();
        
        // Split the user input
        int token_count = 0;
        char ** get_tokens = vsh_split_command(get_command, &token_count);
        
        vsh_execute(get_tokens, get_command, token_count);
        
        // Release memory if 'exit' wasn't called
        free(get_command);
        for (int i = 0; i < token_count; ++i) {
            free(get_tokens[i]);
        }
        free(get_tokens);
    }

    return 0;
}
