# Custom `malloc()` and `free()`

## Problem Statement

Implement your own versions of the standard C library functions `malloc()` and `free()`. Use low-level system calls such as `sbrk()` to dynamically allocate and manage memory in a user-defined memory allocator.

## Requirements

- Implement `malloc()` to allocate a specified number of bytes from the heap.
- Implement `free()` to deallocate previously allocated memory, making it available for future allocations.
- Use `sbrk()` system call to increase or decrease the program’s data segment (heap space).
- Include mechanisms to manage memory blocks efficiently, such as maintaining a **linked list** of free and allocated blocks.

## Input

Size of memory to be allocated in bytes for each call to `malloc()`.

```bash
malloc(32);   // Allocate 32 bytes
malloc(64);   // Allocate 64 bytes
free(ptr);    // Free previously allocated memory
```

## Output

Memory allocation address for each call to `malloc()`. Confirmation of successful memory deallocation by `free()`.

```bash
Allocated 32 bytes at 0x55b3b2c4f000
Allocated 64 bytes at 0x55b3b2c4f020
Memory at 0x55b3b2c4f000 freed
```

## Constraints

- The program should handle allocations of up to 10<sup>6</sup> bytes in total.
- Implement memory management with minimal fragmentation.
- Ensure that no memory leaks occur, and all allocated memory is properly freed.
- Avoid using the built-in `malloc()` and `free()` functions from `stdlib.h`.

> [!NOTE]
>
> - Use a **header structure** in each allocated memory block to store metadata like block size and allocation status.
> - Implement techniques such as **first-fit**, **best-fit**, or **worst-fit** for block allocation.
> - Edge cases to consider:
>   - Allocating zero bytes.
>   - Freeing a NULL pointer.
>   - Requesting memory larger than available heap space.
> - `sbrk()` returns `(void *) -1` on failure; handle such cases appropriately.
