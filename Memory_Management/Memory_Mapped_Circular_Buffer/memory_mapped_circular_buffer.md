# Memory-Mapped Circular Buffer

## Problem Statement

Simulate a memory-mapped I/O device using a circular buffer. The buffer should support efficient read and write operations while preventing data overflows and handling wrap-around.

## Requirements

- Create a fixed-size circular buffer in memory.
- Implement `write()` to add data and `read()` to retrieve data from the buffer.
- Use `head` and `tail` pointers to track buffer positions.
- Support wrap-around logic for both read and write operations.
- Ensure no overwrite occurs on unread data (buffer overflow protection).

## Input

A sequence of write and read operations.

```bash
Write: 5
Write: 7
Write: 9
Read: 2 times
Write: 12
```

## Output

Data read and internal state changes (like pointer wrap-around).

```bash
Read: 5
Read: 7
Write: 12 (wrapped to start of buffer)

```

## Constraints

- Buffer size must be fixed (e.g., 4 or 8 elements).
- Cannot overwrite unread data.
- Handle simultaneous read/write conditions safely in future multi-threaded extensions.
- Properly initialize and update head/tail indices during operations.

> [!NOTE]
>
> - This simulates how device drivers use memory-mapped I/O buffers to communicate with hardware.
> - Wrap-around is key: when `head` or `tail` reaches the end of the buffer, it should reset to 0.
> - Circular buffers are commonly used in producer-consumer problems, device drivers, and real-time systems.
