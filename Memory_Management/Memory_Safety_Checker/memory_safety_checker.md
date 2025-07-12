# Memory Safety Checker

## Problem Statement

Implement a safety-checking function that verifies memory access boundaries. It should detect buffer overflows and underflows during read/write operations to a memory block.

## Requirements

- Track each allocated buffer’s size and boundaries.
- Implement safety checks before read/write access.
- Detect and report overflows (write/read beyond allocated size) and underflows (accessing before the buffer start).
- Return meaningful diagnostics when violations are detected.

## Input

Memory access request with size and offset.

```bash
Buffer Size: 10 bytes
Write Request: 12 bytes
```

## Output

Status of the memory operation, such as success or a buffer violation warning.

```bash
Buffer overflow detected
```

## Constraints

- Only access memory within allocated boundaries.
- Overlapping writes beyond boundaries should raise errors.
- No use of unsafe operations like unchecked pointer arithmetic.

> [!NOTE]
>
> - Maintain metadata (start address, size) for each memory block.
> - Optional: Implement sentinels or guard bytes before and after the buffer to catch boundary violations.
> - Extendable to monitor stack safety or user-space buffers in embedded systems.
