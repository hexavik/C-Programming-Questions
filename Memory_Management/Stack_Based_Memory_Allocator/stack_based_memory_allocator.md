# Stack-based Memory Allocator

## Problem Statement

Design a memory allocator that allocates memory blocks in a Last-In-First-Out (LIFO) manner from a fixed-size buffer. The allocator should provide `allocate` and `free` functions that manage memory like a stack.

## Requirements

- Maintain a fixed-size memory pool as an array.
- Track the "top" pointer of the stack to mark the current allocation boundary.
- On allocation, move the stack top forward by the requested size and return the starting address.
- On free, ensure the block being freed is the most recently allocated block, then move the stack top backward accordingly.
- Reject freeing blocks that are not the most recent allocation.

## Input

Requests to allocate or free specified bytes in the stack-based memory pool.

```bash
Allocate 10 bytes
Allocate 20 bytes
Allocate 15 bytes
Free 15 bytes
```

## Output

Addresses returned for allocated blocks and updated stack top after freeing.

```bash
Allocated at address 0x1000
Allocated at address 0x100A
Allocated at address 0x101E
Freed 15 bytes, next available address 0x100A
```

## Constraints

- Memory pool size is fixed; allocations cannot exceed available space.
- Free operations must only free the most recent allocation (LIFO order).
- Allocation requests exceeding remaining memory should fail.

> [!NOTE]
>
> - Use a stack pointer (`top`) to track the current position in the memory pool.
> - Keep a record of allocation sizes (e.g., stack or array) to validate correct free calls.
> - On allocation, return the current top and increment by requested size.
> - On free, check if the size matches the last allocation and decrement top accordingly.
> - This model is efficient and simple but limited to LIFO freeing pattern.
