# Segmented Memory Allocator

## Problem Statement

Implement a segmented memory allocator where multiple fixed-size memory buffers (segments) act as independent allocation regions. Allocation and deallocation happen within specific segments, maintaining separate stack tops for each.

## Requirements

- Define multiple memory segments as fixed-size buffers.
- Each segment tracks its current allocation position (stack top).
- Implement `allocate` and `free` functions that specify which segment to operate on.
- Allocation increments the segment’s stack top; deallocation decrements it.
- Return addresses within the corresponding segment’s buffer.

## Input

Commands to allocate or free memory from specified segments with given sizes.

```bash
Allocate 10 bytes in Segment A
Allocate 20 bytes in Segment B
```

## Output

Memory addresses allocated within the requested segments.

```bash
Segment A allocated at address 0x1000
Segment B allocated at address 0x2000
```

## Constraints

- Fixed-size buffers per segment limit total allocatable memory.
- Allocations cannot exceed the buffer size in each segment.
- Deallocation is stack-like (last allocated freed first) per segment.
- Memory management is local to each segment; no cross-segment allocations.

> [!NOTE]
>
> - Use an array of structures where each structure holds a segment buffer pointer and a stack top index.
> - `allocate` increases the stack top by requested size if enough space is available.
> - `free` reduces the stack top by the size of the last allocation.
> - This simulates segmented memory regions common in embedded systems or OS memory models.
> - To avoid fragmentation, allocations and deallocations happen in LIFO order within each segment.
