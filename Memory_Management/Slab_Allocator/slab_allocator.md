# Slab Allocator

## Problem Statement

Implement a simple slab allocator that manages a memory pool divided into fixed-size blocks (slabs). The allocator should efficiently allocate and free fixed-size memory chunks.

## Requirements

- Initialize a memory pool divided into fixed-size slabs (e.g., 32 bytes each).
- Implement an `allocate` function that returns the address of a free slab.
- Implement a `deallocate` function that marks the slab as free.
- Keep track of free and used slabs efficiently (e.g., using a linked list or bitmap).
- Optionally, support merging free slabs for larger allocations (not mandatory).

## Input

Request to allocate or free memory of fixed slab size.

```bash
Allocate object of 32 bytes
Free slab at address 0x1000
```

## Output

Return the address of the allocated slab or confirm deallocation.

```bash
Allocated slab at address 0x1000
Slab at address 0x1000 freed
```

## Constraints

- All slabs have the same fixed size.
- Memory allocation must only return slab-aligned addresses.
- Deallocation must only be done on addresses previously allocated.
- Memory pool size limits the total number of slabs.

> [!NOTE]
>
> - The slab allocator divides a large memory pool into equal-sized chunks called slabs.
> - Use a free list (linked list of free slabs) to quickly find available slabs.
> - Allocation: remove a slab from the free list and return its address.
> - Deallocation: add the slab back to the free list.
> - This approach reduces fragmentation and improves allocation speed for objects of uniform size.
