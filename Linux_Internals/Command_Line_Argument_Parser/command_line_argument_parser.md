# Command-line argument Parser

## Problem Statement

Write a C program that takes various command-line options and arguments and prints them. The program should use the `getopt()` function to parse command-line options and their corresponding arguments.

## Requirements

- Use the `getopt()` function to handle command-line options.
- Support both short (`-a`, `-b`) and long (`--option`) arguments.
- Display parsed options and their values in a structured format.
- Handle cases where an option requires an argument.
- Provide a help message (`-h` or `--help`) displaying available options.

## Input

Command-line options and arguments passed during program execution.

```bash
./parser -a -b value --name=John --age 25
```

## Output

Parsed options and their values.

```bash
Option -a (Flag detected)
Option -b, Argument: value
Option --name, Argument: John
Option --age, Argument: 25
```

## Constraints

- The program should handle invalid or missing arguments gracefully.
- Options may have required or optional arguments
- Support for a help message to guide users.

> [!NOTE]
>
> - **Approach:**
>   - Use `getopt()` for parsing short options (`-a`, `-b`).
>   - Use `getopt_long()` for parsing long options (`--name`, `--age`).
>   - Implement a loop to extract and process each option.
> - **Edge Cases:**
>   - Handling unknown options.
>   - Detecting missing arguments for options that require them.
>   - Providing a meaningful help message.
> - **Alternative Methods:**
>   - Manually parsing `argv[]`, though `getopt()` is the preferred method.
>   - Using third-party libraries for more advanced parsing.
