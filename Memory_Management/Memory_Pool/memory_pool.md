# Memory Pool

## Problem Statement

Design a memory allocation system with multiple fixed-size memory pools. Each pool must manage its own allocations and deallocations independently. This allows for more deterministic memory usage, commonly used in embedded or real-time systems.

## Requirements

- Implement multiple memory pools using arrays.
- Each pool maintains a separate buffer and free list.
- Implement `allocate(pool_id, size)` and `free(pool_id, address)` functions.
- Ensure that memory from one pool cannot be allocated or freed by another.

## Input

Commands to allocate or free memory from a specified pool.

```bash
Allocate 5 bytes from Pool A
Allocate 7 bytes from Pool B
```

## Output

Addresses (offsets or pointers) indicating successful allocation from the respective pool.

```bash
Pool A -> Allocated 5 bytes at address 0x1000
Pool B -> Allocated 7 bytes at address 0x2000
```

## Constraints

- Pools must be preallocated with fixed sizes.
- Allocation requests must not exceed the remaining pool capacity.
- Pools operate independently — no memory sharing between them.
- Proper bookkeeping of allocated and free blocks is required.

> [!NOTE]
>
> - Use a free list or block bitmap for each pool to track allocations.
> - Extendable to support fixed block sizes per pool for faster allocation.
> - This is a good model for deterministic memory allocation in embedded firmware or RTOS environments.
