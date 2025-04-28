# User-Space File Reader

## Problem Statement

Create a user-space program that reads a file using system calls (`open()` and `read()`) and displays its contents.

## Requirements

- Use the `open()` system call to open the file.
- Use the `read()` system call to read the contents of the file.
- Display the file contents to the standard output (typically the terminal).

## Input

The file name to be read.

```bash
Enter file name: example.txt
```

## Output

Displays the contents of the file to the terminal.

```bash
File contents:
Hello, world!
This is a simple file.
```

## Constraints

- Ensure proper error handling for cases such as file not found or permission denied.
- The file reading should stop when the **end of the file (EOF)** is reached.
- Handle large files by reading in chunks instead of the entire file at once.

> [!NOTE]
>
> - The `open()` system call is used to open the file, and `read()` is used to read it into memory.
> - It's important to close the file using `close()` to release file descriptors when done.
