# Memory Access Logger

## Problem Statement

Design and implement a simulation of memory access logging. Every read or write operation to a simulated memory block should be logged with details including the address and the type of operation.

## Requirements

- Simulate memory using an array (e.g., `int memory[SIZE]`).
- Implement read and write operations that log each access.
- Use a list, array, or struct to record logs with:
  - Memory address
  - Operation type (`read` or `write`)
- Output the full log after a series of operations.

## Input

A sequence of read and write operations to simulated memory.

```bash
Write to address 5: 42
Read from address 5
Write to address 10: 99
```

## Output

Logs of each memory access operation with address and type.

```bash
[LOG] Write at address 5
[LOG] Read at address 5
[LOG] Write at address 10
```

## Constraints

- Ensure memory bounds are respected (access within allowed array size).
- Avoid duplicate logging if the same action is repeated rapidly unless intended.
- The logger should maintain operation order accurately.

> [!NOTE]
>
> - This simulates hardware-level memory access tracking often done in debuggers or memory protection systems.
> - For advanced simulation, timestamps and data values could also be logged.
> - Can be extended to simulate cache access patterns or page faults later.
