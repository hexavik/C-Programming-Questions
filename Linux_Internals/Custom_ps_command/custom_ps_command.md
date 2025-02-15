# Custom `ps` Command

**Problem Statement:**

Implement a simplified version of the `ps` command in C to display a list of currently running processes on a Linux system. The program should read process information from the `/proc` filesystem and display key details such as **PID**, **command name**, and **state**.

**Requirements:**

- Traverse the `/proc` directory to identify all running processes.
- Extract and display process details from files like `/proc/[pid]/stat`.
- Display the **PID**, **command name**, and **state** of each running process in a formatted table.

**Input:**

No user input required since the program will automatically read form the `/proc` filesystem.

**Output:**

A formatted table displaying currently running processes.

```bash
PID       STATE COMMAND
1         S     systemd
1345      S     bash
2789      R     firefox
3201      R     custom_ps
```

**Constraints:**

- Handle up to 10,000 processes efficiently.
- Ensure proper error handling when accessing `/proc` files.

> [!NOTE]
>
> - Use `opendir()`, `readdir()`, and `closedir()` from `dirent.h` to iterate thorugh `/proc`.
> - Parse the `/proc/[pid]/stat` file to extract the **PID**, **process state** and **Command Name**, ensuring to handle cases where Command Name might be empty.
> - Edge cases to consider:
>   - Processes with very long command names.
>   - System processes with restricted access.
>   - Handling processes that terminate while being read.
