# Filesystem Traversal Using `opendir()` and `readdir()`

**Problem Statement:**

Write a C program to recursively traverse a directory and list all files and subdirectories. Use low-level directory handling system calls like `opendir()`, `readdir()`, and `closedir()` to read directory contents.

**Requirements:**

- Use `opendir()`, `readdir()`, and `closedir()` from *dirent.h* to access directory entries.
- Recursively explore subdirectories to list all files and folders.
- Display full paths for each file and directory.
- Handle symbolic links appropriately.

**Input:**

Path to the root directory to start traversal.

```bash
Root directory: /home/user/Documents
```

**Output:**

A list of all files and directories, including their paths.

```bash
/home/user/Documents/file1.txt
/home/user/Documents/folder1
/home/user/Documents/folder1/file2.c
/home/user/Documents/folder2
```

**Constraints:**

- The program should support directory structures up to **100 levels deep**.
- Maximum path length should be **4096 characters** (as per POSIX).
- Handle directories containing up to **100,000 files**.
- Must work on a Linux system.
- Avoid infinite loops when encountering **symbolic links**.

> [!NOTE]
>
> - Use `stat()` to distinguish between `files`, `directories`, and `symbolic links`.
> - Skip `.` **(current directory)** and `..` **(parent directory)** entries during traversal.
> - Edge cases to consider:
>   - Directory does not exist (print an error).
>   - Insufficient permissions (print a warning and continue).
>   - Symbolic links pointing to directories (prevent infinite recursion).
> - Implement proper error handling for `opendir()` and `readdir()` failures.
> - Close directories using `closedir()` to avoid memory leaks.
