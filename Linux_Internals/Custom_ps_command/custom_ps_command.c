/**
 * @file custom_ps_command.c
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @date 2025-02-15
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 256

/**
 * @brief Removes parentheses from the string by removing first and 
 * last characters.
 * 
 * @param str Input string with parentheses at first and last characters
 * @return char* Modified string
 */
char * remove_brackets(char * str) {
    char * ostr = str + 1;
    ostr[strlen(ostr) - 1] = '\0';
    return ostr;
}

/**
 * @brief Prints the process info of input PID string in the following
 * format
 * PID       STATE COMMAND
 * 1         S     systemd
 * 1345      S     bash
 * 
 * @param pid_str Input PID string retrieved from /proc directory
 */
void display_process_info(const char * pid_str) {
    char stat_path[MAX_BUFFER];
    char stat_buffer[MAX_BUFFER];
    int pid;
    char state;
    char command[MAX_BUFFER];

    // Construct paths to /proc/[pid]/stat and /proc/[pid]/cmdline
    snprintf(stat_path, sizeof(stat_path), "/proc/%s/stat", pid_str);

    // Read stat file
    FILE *stat_file = fopen(stat_path, "r");
    if (stat_file == NULL) {
        fprintf(stderr, "Error opening stat file: %s\n", stat_path);
        return;
    }
    if (fgets(stat_buffer, sizeof(stat_buffer), stat_file) == NULL) {
        fprintf(stderr, "Error reading stat file: %s\n", stat_path);
        fclose(stat_file);
        return;
    }
    fclose(stat_file);

    // Parse /proc/[pid]/stat
    if (sscanf(stat_buffer, "%d %s %c", &pid, command, &state) != 3) {
        fprintf(stderr, "Error parsing stat file for PID %s\n", pid_str);
        return;
    } 

    // Print the information
    printf("%5d\t  %c\t%s\n", pid, state, remove_brackets(command));
}

int main() {
    DIR * pDir;
    struct dirent * entry;
    char * proc_dir = "/proc";

    pDir = opendir(proc_dir);
    if (pDir == NULL) {
        printf("Cannot open directory: %s\n", proc_dir);
        return 1;
    }

    printf("PID\tSTATE\tCOMMAND\n");
    while ((entry = readdir(pDir)) != NULL) {
        // Parse only PID based directories
        if (atoi(entry->d_name) > 0) {
            display_process_info(entry->d_name);
        }
    }

    closedir(pDir);
    return 0;
}
