# Implement a Custom `watch` Command

## Problem Statement

Create a program that mimics the Linux `watch` command: repeatedly runs a given command at fixed time intervals.

## Requirements

- Use `system()`, or `fork()` with `exec()` to execute the command.
- Sleep for the specified interval between each execution.
- Continuously refresh the command output until the program is terminated manually.

## Input

Command to execute and the time interval (in seconds).

```bash
Command: "date"
Interval: 2  // seconds
```

## Output

Repeatedly prints the output of the given command at the specified interval.

```bash
Output (every 2 seconds):
Mon Apr 28 12:00:01 2025
Mon Apr 28 12:00:03 2025
Mon Apr 28 12:00:05 2025
...
```

## Constraints

- Command must be valid and executable on the system.
- Interval must be a positive integer.
- The program should handle `Ctrl+C` gracefully to exit.

> [!NOTE]
>
> - Use `sleep(interval)` to wait between runs.
> - Optionally, clear the screen (using `system("clear")`) before each execution for a cleaner output, similar to real `watch`.
