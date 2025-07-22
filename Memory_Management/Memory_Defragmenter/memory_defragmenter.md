# Memory Defragmenter

## Problem Statement

Simulate a memory manager that supports allocation, deallocation, and defragmentation of a memory pool. The defragmentation function should consolidate adjacent free blocks into larger contiguous blocks to optimize memory usage.

## Requirements

- Use an array to simulate a memory pool.
- Track both allocated and free blocks using appropriate data structures.
- Implement `allocate()`, `free()`, and `defragment()` functions.
- The `defragment()` function should merge adjacent free blocks.
- After defragmentation, all free space should be consolidated.

## Input

Sequence of memory operations — allocation, freeing, and defragmentation.

```bash
Allocate 10 bytes
Free 5 bytes
Defragment
```

## Output

Status of memory after each operation, especially after defragmentation.

```bash
[INFO] Allocated 10 bytes
[INFO] Freed 5 bytes
[INFO] Memory defragmented — free blocks consolidated
```

## Constraints

- Memory pool size is fixed (e.g., 100 bytes).
- Allocation and deallocation must respect memory boundaries.
- Defragmentation must preserve data in allocated blocks while consolidating free space.
- You must update metadata (e.g., block list or descriptors) after each operation.

> [!NOTE]
>
> - This simulates a real-world heap manager behavior.
> - The algorithm should scan the memory pool, compact allocated blocks to the front, and merge free space toward the end.
> - Optional: Visualize memory before and after defragmentation using ASCII blocks or address mapping.

> [!WARNING]
>
> Understand that the solution is based on a simple defragmenter implementation. I am not following any standardized logic followed by `free()` (where it deallocates memory using addresses). I am deallocating memory using bytes only, which will also split between the allocated blocks, since we are not adding any data. This is logic that must not be followed in the real-time programs; this will be just a simple experiment to understand the defgamenter most simply.
