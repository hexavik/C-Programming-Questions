# Memory Initialization Library

## Problem Statement

Design a function to initialize a block of memory with a specific byte value. This utility mimics `memset()` behavior and is useful for manual memory management, especially in low-level systems programming.

## Requirements

- Accept two inputs: block size and byte value.
- Allocate or reference a memory block.
- Fill the entire block with the given value.
- Output the final state of memory (for verification).

## Input

A block size (number of bytes) and a hexadecimal value to initialize.

```bash
Block size = 5
Value = 0xAA
```

## Output

The memory block after initialization.

```bash
Memory: 0xAA 0xAA 0xAA 0xAA 0xAA
```

## Constraints

- Value must fit in one byte (0x00 to 0xFF).
- The block size should be positive and reasonably bounded (e.g., ≤ 1024 bytes for simulation).
- Alignment isn't critical but should be mentioned for embedded use-cases.

> [!NOTE]
>
> - This kind of initialization is useful before deallocation, debugging uninitialized memory, or preparing buffers for communication.
> - You can extend this library with functions like `memzero()`, `memfill16()`, or `secure_memset()` to overwrite memory securely.
