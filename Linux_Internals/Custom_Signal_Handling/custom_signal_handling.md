# Custom Signal Handling

## Problem Statement

Write a program that **custom handles signals** as `SIGINT` and `SIGTERM`. The program should catch these signals using `signal()` or `sigaction()` and execute a **custom action** when the signal is received.

## Requirements

- Use `signal()` or `sigaction()` to register custom signal handlers.
- Print a custom message or execute a specific action upon receiving a signal.
- Handle at least **SIGINT (Ctrl+C) and SIGTERM (kill command)**.
- Allow cleanup operations before exiting when a termination signal is received.
- The program should continue running until a termination signal is received.

## Input

A **signal type** sent via keyboard (`Ctrl+C`) or system commands (`kill -TERM <pid>`).

```bash
User presses Ctrl+C (SIGINT)
```

## Output

A **custom message or action** executed upon receiving the signal.

```bash
Received SIGINT! Cleaning up resources...
```

## Constraints

- The program should not exit immediately on receiving `SIGINT`, unless specified.
- **Multiple signals should be handled correctly** without undefined behavior.
- The solutiuon should work on Linux-based systems where `signal()` and `sigaction()` are available.

> [!NOTE]
>
> - The program can be extended to handle additional signals like `SIGUSR1`, `SGHUP`, etc.
> - Avoid using `non-reentrant functions` like `printf()` inside signal handlers. Use `write()` instead for safe logging.
> - Implement cleanup actions before exiting to release resources.
