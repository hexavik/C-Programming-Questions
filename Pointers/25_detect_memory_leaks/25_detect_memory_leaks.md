# Custom Memory Allocator and Leak Detector Using Pointers

## Problem Statement

Implement custom `allocate()` and `deallocate()` functions that internally track all dynamic memory allocations. At the end of the program, report memory leaks (i.e., memory that was allocated but not freed).

## Requirements

- Maintain a linked list or array to track each allocated block.
- When `deallocate()` is called, remove the pointer from the tracking list.
- On program completion, print the list of unfreed allocations.

## Input

```c
allocate(5); // called 5 times  
deallocate(ptr1);  
deallocate(ptr2);  
deallocate(ptr3);  
deallocate(ptr4);  
```

## Output

```bash
Memory Leak Detected: 1 block(s) not deallocated.
```

## Constraints

- Use `malloc()` and `free()` internally.
- Do not use standard memory leak detection tools (like *Valgrind*).
- Pointer tracking must be done manually using a structure like a linked list.

> [!NOTE]
>
> - Use a struct to store pointer information (e.g., address, size).
> - At the end, traverse the list to check for any non-deallocated blocks and print them.
