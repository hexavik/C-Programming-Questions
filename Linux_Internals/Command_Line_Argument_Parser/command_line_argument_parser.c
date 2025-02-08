/**
 * @file command_line_argument_parser.c
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @date 2025-02-05
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>

/**
 * @brief Display the help message for all possible commandl-line 
 * arguments.
 * 
 * @param program_name provided input character to verify it doesn't
 * belong to available options
 */
void print_usage(char * program_name) {
    fprintf(stderr, "Usage: %s [options]\n", program_name);
    fprintf(stderr, "Options:\n");
    fprintf(stderr, "  -a, --a           : Enable feature A\n");
    fprintf(stderr, "  -b, --b <arg>     : Enable feature B with argument\n");
    fprintf(stderr, "  -n, --name <name> : Specify the name\n");
    fprintf(stderr, "  -y, --age <age>   : Specify the age\n");
    fprintf(stderr, "  -h, --help        : Display this help message\n");
}

int main(int argc, char **argv) {
    int aflag = 0;      // Boolean flag to track the presence of -a option
    int bflag = 0;      // Boolean flag to track the presence of -b option
    int bvalue = -1;     // Store the value for -b option
    char * name = NULL;
    int age = -1;
    int opt;

    static struct option long_options[] = {
        {"name", required_argument, NULL, 'n'},
        {"age", required_argument, NULL, 'y'},
        {0, 0, 0, 0}
    };

    // Disables the default error message handling of getopt()
    // and allows you to customize the error message.
    opterr = 0;

    int option_index = 0;

    while ((opt = getopt_long(argc, argv, "ahb:n:y:", long_options, &option_index)) != -1) {
        switch (opt) {
            case 0:
                // If this option set a flag, do nothing else now
                if (long_options[option_index].flag != 0) {
                    break;
                }
                printf("Option %s", long_options[option_index].name);
                if (optarg) {
                    printf(" with arg %s", optarg);
                }
                printf("\n");
                break;

            case 'a':
                printf("a flag detected\n");
                aflag = 1;
                break;

            case 'b':
                bflag = 1;
                bvalue = atoi(optarg);
                break;

            case 'n':
                name = optarg;
                break;

            case 'y':
                age = atoi(optarg);
                break;

            case 'h':
                print_usage(argv[0]);
                return 0;

            case '?':
                // getopt_long already printed an error message.
                fprintf(stderr, "Unknown Option: '%c'\n", optopt);
                print_usage(argv[0]);
                return 1;

            default:
                return 1;
        }
    }

    // Display the output
    aflag ? printf("Option -a (Flag detected)\n") : printf("Option -a (Flag not detected)\n");
    printf("Option -b, Argument: %d\n", bvalue);
    printf("Option --name, Argument: %s\n", name);
    printf("Option --age, Argument: %d\n", age);

    // Handle non-option arguments (if provided)
    for (int i = optind; i < argc; ++i) {
        printf("Non-option argument %s\n", argv[i]);
    }

    return 0;
}
