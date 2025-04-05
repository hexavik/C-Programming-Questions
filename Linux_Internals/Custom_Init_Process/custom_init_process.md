# Custom Init Process

## Problem Statement

Write a custom init process to replace the default init for embedded Linux. Research how init works and write a C program that performs the necessary initialization steps.

## Requirements

- The init process must be implemented in C.
- It should handle basic system initialization tasks.
- Must replace the default init process in an embedded Linux system.
- Should correctly spawn and manage child processes.
- Implement basic signal handling for process termination.
- Ensure minimal resource usage, suitable for embedded environments.
- Must be able to execute essential startup scripts or commands.
- Proper logging of initialization steps.

## Input

None

## Output

```bash
System booted with custom init
```

## Constraints

- Must run as PID 1 (first process after the kernel).
- Limited to standard C libraries available in embedded Linux environments.
- Should avoid resource-heavy operations due to constrained hardware.
- Ensure stability—any failure in init leads to a non-functional system.

> [!NOTE]
>
> - **Understanding Init:** Init is the first process started by the kernel and remains running until the system shuts down.
> - **Key Tasks:** Mount filesystems, set up network interfaces, start essential services, and manage child processes.
> - **Signal Handling:** Ensure the init process can handle `SIGCHLD` for cleaning up zombie processes.
> - **Testing:** Run the custom init in a QEMU virtual machine or a test embedded board to ensure proper functionality.

> [!WARNING]
> This program has not tested on a QEMU virtual machine or any other real-time embedded Linux. This warning will be removed when the testing is done and procedure of testing will be added.
