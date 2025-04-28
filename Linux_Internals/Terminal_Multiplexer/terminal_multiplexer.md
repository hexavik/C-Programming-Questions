# Terminal Multiplexer

## Problem Statement

Create a basic terminal multiplexer that allows a user to switch between multiple running shell instances. Each shell instance runs independently, and the user can toggle between them using specific key commands.

## Requirements

- Use `fork()` and `exec()` to create multiple shell instances.
- Capture user key commands to switch between shells.
- Manage terminal I/O properly to detach/attach sessions.

## Input

Key commands from the user to switch between shell instances.

```bash
Input Example:
Key '1' → Switch to shell instance 1
Key '2' → Switch to shell instance 2
...
```

## Output

Display the active shell corresponding to the user's command.

```bash
Output Example:
Switched to Shell 1
[user@terminal1]$ 
Switched to Shell 2
[user@terminal2]$ 
...
```

## Constraints

- Limited number of shell instances (e.g., 2–5).
- Proper handling of child processes to avoid zombies.
- Maintain the terminal state (input/output redirection) correctly.

> [!NOTE]
>
> - You will need to use `tcsetpgrp()` and `tcgetpgrp()` for terminal control.
> - Advanced versions would handle resizing, detaching, and background sessions — but here, focus on basic switching and management.
> - This is a simplified foundation for something like `tmux` or `screen`.
