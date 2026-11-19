# Detect If Pointer Is Out of Bounds of an Array

## Problem Statement

Design a function that checks whether a given pointer is out of bounds for a specified array. This is useful for ensuring memory safety when navigating arrays using pointer arithmetic.

## Requirements

- Use pointer comparison.
- Compare the given pointer against the starting and past-the-end positions of the array.

## Input

```bash
int arr[] = {1, 2, 3, 4, 5};
int *ptr = &arr[5]; // pointer just past the last element
```

## Output

```bash
"Out of bounds"
```

## Constraints

- Pointer must be compared using:
  - `ptr < arr` (before start)
  - `ptr >= arr + size` (after end)
- Assumes contiguous memory layout.

> [!NOTE]
>
> - This technique ensures the pointer remains within valid array limits.
> - Useful in custom memory-safe routines and low-level operations.
