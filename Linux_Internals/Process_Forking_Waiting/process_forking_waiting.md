# Process Forking and Waiting

## Problem Statement

Create a program that spawns multiple child processes using `fork()` and then waits for each child to complete using `wait()` or `waitpid()`. After each child exits, capture and print its exit status.

## Requirements

- Use `fork()` to create child processes.
- Use `wait()` or `waitpid()` to wait for specific or any child to terminate.
- Capture and report each child's exit status.

## Input

Number of child processes to be created.

```bash
Input Example:
Number of child processes: 3
```

## Output

Display the Process ID (PID) of each child and their exit status after they terminate.

```bash
Output Example:
Child with PID 12345 exited with status 0
Child with PID 12346 exited with status 0
Child with PID 12347 exited with status 0
```

## Constraints

- Properly handle `fork()` failure cases.
- Ensure that the parent waits for all child processes.
- Exit codes should be captured accurately.

> [!NOTE]
>
> - This demonstrates basic process control and synchronization between parent and child processes.
> - Each child can perform a simple task or just exit immediately for simplicity.
