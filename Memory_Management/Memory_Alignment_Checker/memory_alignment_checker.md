# Memory Alignment Checker

## Problem Statement

Write a function to check if a given memory address is aligned to a specified number of bytes. Use bitwise operations to determine alignment efficiency.

## Requirements

- Take a memory address (as an integer or pointer) and an alignment value.
- Use bitwise operations to determine if the address is aligned.
- Return or log whether the address is aligned or not.

## Input

A memory address and an alignment value in bytes.

```bash
Address = 0x1004
Alignment = 4
```

## Output

Prints whether the address is aligned based on the alignment value.

```bash
Address 0x1004 is Aligned to 4 bytes
```

## Constraints

- Alignment must be a power of two (2, 4, 8, 16...).
- Address should be passed in integer form or cast from pointer type if needed.
- Must not perform division or modulo operations — only bitwise.

> [!NOTE]
>
> - Memory alignment is important for performance and hardware safety, especially on embedded systems and DMA.
> - The check relies on the fact that aligned addresses result in zero when masked with `alignment - 1`.
