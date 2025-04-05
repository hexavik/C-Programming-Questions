# File Copy Program

## Problem Statement

Write a C program to copy the contents of one file to another using low-level file operations. Use system calls like `open()`, `read()`, and `write()` to perform the file copy operation. The program should handle errors and provide appropriate status messages.

## Requirements

- Use the `open()`, `read()`, `write()`, and `close()` system calls for file operations.
- Copy the entire content from the **source file** to the **destination file**.
- Handle errors such as file not found, permission denied, or insufficient space.
- Ensure that the program closes all file descriptors properly.

## Input

- Source file path (file to copy from).
- Destination file path (file to copy to).

## Output

Status messages indicating the success or failure of the file copy operation.

```bash
File copied successfully from input.txt to output.txt
```

In case of an error:

```bash
Error: Source file not found
```

## Constraints

- The program should handle files up to **1 GB** in size.
- Use a buffer for efficient copying (e.g., **4096 bytes per read/write** operation).
- The program must run on a Linux system.
- Return appropriate exit codes (**0** for success, **non-zero** for errors).

> [!NOTE]
>
> - Use `O_RDONLY` for opening the source file and `O_WRONLY | O_CREAT | O_TRUNC` for the destination file.
> - Handle **file permissions** using `chmod()` or appropriate flags during `open()` (e.g., `0666` for read-write permissions).
> - Edge cases to consider:
>   - **Destination file** already exists (prompt or overwrite).
>   - **Source file** is empty (create an empty destination file).
>   - **Interrupted read/write** operations (e.g., due to signals).
> - Properly flush and close all file descriptors using `close()` to prevent memory leaks.
