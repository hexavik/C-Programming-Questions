# Implement a Custom `tail` Command

## Problem Statement

Create a function that mimics the behavior of the Linux `tail` command: display the last `n` lines of a file.

## Requirements

- Use file I/O operations.
- Read the file in reverse to efficiently fetch the last `n` lines without loading the entire file if possible.
- Default to the last 10 lines if `n` is not specified.

## Input

Path to the file and optionally the number of lines to display.

```bash
File path: "/path/to/file.txt"
Number of lines: 10  // Optional, default is 10
```

## Output

The last `n` lines of the provided file.

```bash
[Contents of the last 10 lines of the file]
```

## Constraints

- Efficiently handle very large files without reading the entire file into memory.
- File should be text-based.
- If the file has fewer than `n` lines, print all available lines.

> [!NOTE]
>
> - Use `fseek()` to move the file pointer from the end towards the beginning.
> - Count newline characters while moving backwards to find the starting point for printing.
