# `chmod` Command Implementation

## Problem Statement

Design and implement a program in C that mimics the basic functionality of the `chmod` Linux command. The program should allow users to change file permissions using both octal and symbolic modes, leveraging the `chmod()` system call.

## Requirements

- Support changing file permissions using:
  - **Octal mode** (e.g., `chamod 755 file.txt`).
  - **Symbolic mode** (optional extension: `chmod u+r file.txt`)
- Use the `chmod()` system call to modify file permissions.
- Accept file paths and permission codes as input arguments.
- Handle invalid file paths, incorrect permission codes, and insufficient permissions.

## Input

The program should accept two arguments:

```bash
./chmod_sim <permissions> <file_path>
./chmod_sim 755 file.txt
./chmod_sim 644 /home/user/file.txt
```

## Output

On success, print a confirmation message; whereas, on failed, display relevant errors.

```bash
on success:
Permissions for `file.txt` changed to 755.

on failed:
Error: Invalid file path or insufficient permissions.
```

## Constraints

- Ensure the program accepts **3-digit octal numbers** only (000 to 777).
- Ensure to use valid file paths.
- Runs on Linux systems as it is using POSIX system calls.
- Limit file paths to **1024 characters**.

> [!NOTE]
>
> - **File permissions breakdown:**
>   - **Owner (User):** Read (4), Write (2), Execute (1)
>   - **Group:** Read (4), Write (2), Execute (1)
>   - **Others:** Read (4), Write (2), Execute (1)
> - **Octal to mode_t conversion:** Use `strtol()` to convert the octal string to an integer:
>
> ```c
> mode_t mode = strtol(octal_string, NULL, 8);
> ```
>
> - Change permissions using system call:
>
> ```c
> chmod(file_path, mode);
> ```
>
> - **Edge cases:**
>   - Handling non-existent files.
>   - Invalid permission formats (e.g., `999`).
>   - Files with restricted permissions (testing with `root`-owned files).
