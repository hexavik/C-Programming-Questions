# User-Space to Kernel-Space Communication using procfs

## Problem Statement

Implement a user-space to kernel-space communication system using procfs. The user-space program writes a string to a proc file, and the kernel module echoes the message back to the user-space.

## Requirements

- Create a kernel module that implements a proc file.
- User-space program writes a string message to this proc file.
- The kernel module reads the message from the proc file and returns it (echoes back).
- Ensure proper synchronization and error handling in both kernel and user-space.

## Input

A string message written by the user-space program to the proc file.

```bash
User sends message: "Hello, Kernel!"
```

## Output

The kernel module echoes the message back to the user-space program.

```bash
Kernel responds: "Hello, Kernel!"
```

## Constraints

- The user-space program should handle the case when the proc file does not exist.
- The message written to the proc file must be properly handled in the kernel, ensuring it does not overflow the buffer.
- Ensure proper memory handling and synchronization.

> [!NOTE]
>
> - The procfs (Process File System) allows user-space applications to interact with the kernel through special files in `/proc`. These files can be read from or written to, enabling communication.
> - In the kernel module, you'll use `proc_create()` to create the proc file and implement file operations like `read` and `write`.
> - The user-space program will use `fopen()`, `fprintf()`, and `fscanf()` to interact with the proc file.
