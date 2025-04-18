# Flatten a 2D Array into a 1D Array Using Pointers

## Problem Statement

Create a program that takes a 2D array and flattens it into a 1D array using pointer arithmetic. The elements should be stored row by row in the resulting 1D array.

## Requirements

- Use nested pointer traversal to access and copy each element.
- Output a single 1D array containing all elements in row-major order.

## Input

```c
int arr[2][2] = {{1, 2}, {3, 4}};
```

## Output

```bash
Flattened array: {1, 2, 3, 4}
```

## Constraints

- The 2D array must be of fixed dimensions (e.g., `arr[M][N]`).
- The result array must have size `M * N`.

> [!NOTE]
>
> - Treat the 2D array as a contiguous block of memory.
> - Use a single loop and pointer arithmetic: access element at `*(arr + i * N + j)` or equivalent with `(int *)arr`.
