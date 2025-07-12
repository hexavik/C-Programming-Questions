# Memory Leak Detector

## Problem Statement

Implement a custom memory leak detector that wraps around dynamic memory allocation functions like `malloc()` and `free()`. It should track memory allocations and deallocations to identify memory leaks at the end of program execution.

## Requirements

- Intercept or wrap calls to `malloc()` and `free()`.
- Track every allocated memory block (size and address).
- On `free()`, remove the corresponding entry.
- After execution, report any remaining (unfreed) allocations.
- Use a linked list to maintain allocation records.

## Input

Sequence of dynamic memory operations.

```bash
Allocate 5 bytes
Allocate 7 bytes
Free 5-byte allocation
```

## Output

Report status of memory blocks — whether successfully freed or leaked.

```bash
[INFO] Allocated 5 bytes at 0x1A2B3C
[INFO] Allocated 7 bytes at 0x1A2B50
[INFO] Freed 5 bytes at 0x1A2B3C
[LEAK] Memory leak detected: 7 bytes at 0x1A2B50
```

## Constraints

- Use a dynamic data structure (e.g., singly linked list) to record allocations.
- Only `malloc()` and `free()` are monitored — `calloc()` or `realloc()` can be added as extensions.
- Address uniqueness must be ensured for detection logic.
- Freeing a non-allocated or already-freed pointer should also raise a warning (optional).

> [!NOTE]
>
> - This detector is especially useful during debugging and development in C/C++ projects.
> - Can be extended to include memory timestamps, stack traces, or source line info (via macros).
> - Consider using function-like macros or inline functions to simplify the wrapping of `malloc()` and `free()`.
