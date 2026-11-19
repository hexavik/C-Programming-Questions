/**
 * @file command_parsing.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-08-30
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
    MAX_ARG_LEN = 64, // Maximum length of command string
};

typedef struct Command {
    char* command_name;
    char** arguments;
    int argument_count;
} Command;

/**
 * @brief Take the input string and parse it to understand the command
 * and the argument parameters
 * 
 * @param input_str Command string
 * @return Command* Output command string after parsing
 */
Command* command_parse(const char* input_str) {
    if (!input_str) { return nullptr; }

    //
    // Duplicate input string to aovid modifying the original literal
    //
    char* str_copy = strdup(input_str);
    if (str_copy == nullptr) { return nullptr; }

    //
    // Allocate memory for the Command structure
    //
    Command* cmd = malloc(sizeof(*cmd));
    if (cmd == nullptr) {
        free(str_copy);
        return nullptr;
    }

    cmd->command_name = nullptr;
    cmd->arguments = nullptr;
    cmd->argument_count = 0;

    //
    // Tokenize the string by spaces
    //
    char* token = strtok(str_copy, " ");
    while (token != nullptr) {
        if (cmd->command_name == nullptr) {
            //
            // First token is always the command name
            //
            cmd->command_name = strdup(token);
        } else {
            //
            // Subsequent tokens are parameters
            //
            cmd->argument_count += 1;
            cmd->arguments = (char **)realloc(cmd->arguments,
                cmd->argument_count * sizeof(char *));
            cmd->arguments[cmd->argument_count - 1] = strdup(token);
        }
        token = strtok(nullptr, " ");
    }

    free(str_copy);
    return cmd;
}

/**
 * @brief De-allocate the memory assigned to the command string
 * 
 * @param cmd Input command string
 */
void command_free(Command* cmd) {
    if (cmd == nullptr) { return; }

    if (cmd->command_name) { free(cmd->command_name); }

    if (cmd->arguments) {
        for (int i = 0; i < cmd->argument_count; ++i) {
            free(cmd->arguments[i]);
        }
        free(cmd->arguments);
    }

    free(cmd);
}

int main() {
    const char* raw_input = "connect --port 8080 --host 127.0.0.1 -v";

    printf("Parsing input: \"%s\"\n\n", raw_input);
    Command* my_cmd = command_parse(raw_input);

    if (my_cmd && my_cmd->command_name) {
        printf("Structure Details:\n");
        printf("→ Base Command: %s\n", my_cmd->command_name);
        printf("→ Total Params: %d\n", my_cmd->argument_count);

        for (int i = 0; i < my_cmd->argument_count; ++i) {
            printf("   ↳ Param [%d]: %s\n", i, my_cmd->arguments[i]);
        }
    } else {
        printf("Failed to parse command.\n");
    }

    command_free(my_cmd);

    return 0;
}
