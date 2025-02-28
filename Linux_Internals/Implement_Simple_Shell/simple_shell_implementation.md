# Simple Shell Implementation

**Problem Statement:**

Design and implement a minimal shell in C that can execute basic Linux commands. The shell should support user input, parse commands, and use system calls like `fork()` and `exec()` to create child processes and run commands.

**Requirements:**

- Continuously read user input to accept shell commands.
- Parse the input to separate the **command** and its **arguments**.
- Use `fork()` to create a child process.
- Use `execvp()` to execute the command in the child process.
- Wait for the child process to finish using `waitpid()`.
- Implement a basic `cd` command to change the current working directory using `chdir()`.
- Support `exit` to terminate the shell.

**Input:**

A single line containing a shell command (with optional arguments).

```bash
ls -l
pwd
cd /home
exit
```

**Output:**

The output of the executed command, or an error message if the command is invalid.

```bash
$ ls -l
total 4
-rw-r--r-- 1 user user 1024 Oct 10 12:00 file.txt
```

```bash
$ pwd
/home/user
```

**Constraints:**

- Implement using **POSIX system calls**.
- Limit input to **1024 charcaters per line**.
- Support only simple commands (no pipes or redirections).
- The shell should handle up to **100 commands per session**.
- Must work on **Linux-based systems**.

> [!NOTE]
>
> - Use `getline()` or `fgets()` to safely read user input.
> - Use `strtok()` to split the input into command and arguments for **command parsing**.
> - Process management:
>   - `fork()` to create a child process.
>   - `execvp()` to execute the given command.
>   - `waitpid()` to wait for the child to finish.
> - Built-in commands:
>   - `cd` should update the shell's current directory.
>   - `exit` should terminate the shell loop.
> - Edge cases to consider:
>   - Handling empty input (pressing Enter without a command).
>   - Executing invalid commands.
>   - Changing to a non-existing directory with `cd`.
>   - Ensuring zombie processes are handled correctly with `waitpid()`.

> [!TIP]
> I have included a sample program for `fork()` and `waitpid()` to understand their role in this program.
