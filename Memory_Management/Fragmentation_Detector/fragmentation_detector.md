# Fragmentation Detector

## Problem Statement

Write a program that **simulates memory allocation and deallocation**, tracking fragmentation in a fixed-size memory pool.

## Requirements

- Use a **fixed-size memory pool** to simulate memory allocation.
- Keep track of allocated and free memory blocks efficiently.
- Compute fragmentation as: Total size of free blocks - Largest contiguous free block.
- Implement operations for allocating and freeing memory dynamically.
- Ensure efficient memory management using linked lists, sorted lists, or trees to track free blocks.
- Display the current memory state after each operation.

## Input

A series of memory operations, such as allocation and deallocation requests.

```bash
Allocate 10
Free 5
Allocate 3
```

## Output

The fragmentation amount in bytes after each operation.

```bash
Fragmentation = 2 bytes
```

## Constraints

- The memory pool size is fixed and predefined.
- Allocations and deallocations should be efficient to minimize overhead.
- Fragmentation is reported in bytes and should be updated after each operation.
- Ensure that memory is managed contiguously to avoid excessive fragmentation.

> [!NOTE]
>
> - Consider using best-fit or worst-fit allocation strategies to optimize memory usage.
> - A sorted list or tree can help efficiently find the largest free block.
> - Proper compaction techniques can be implemented to reduce fragmentation when possible.
