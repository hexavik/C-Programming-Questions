# Determine if Two Pointers Belong to the Same Array

## Problem Statement

Design a function that checks whether two given pointers point to elements within the same array.

## Requirements

- Use only pointer arithmetic and dereferencing.
- No additional data structures or libraries.
- Avoid using array indexing.

## Input

```bash
int arr[] = {1, 2, 3, 4};
int *ptr1 = &arr[1];
int *ptr2 = &arr[3];
```

## Output

```bash
True
```

## Constraints

- The pointers must point to valid memory locations.
- The arrays are assumed to be null-terminated or have known bounds via context.
- Input array is in contiguous memory.

> [!NOTE]
>
> - Use forward and backward traversal from each pointer to detect if a common boundary or overlap is found.
> - Be cautious of undefined behavior when moving beyond array bounds.
> - In controlled environments, this can be simplified if array boundaries are accessible or passed in.
