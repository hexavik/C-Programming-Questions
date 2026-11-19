# Count Number of Elements in an Array Using Pointer Arithmetic

## Problem Statement

Write a function that calculates the number of elements in an array using pointer arithmetic, without using any loop constructs.

## Requirements

- Use pointer subtraction to determine the count of elements.
- Do not use any loop constructs (for, while, etc.).

## Input

```bash
int arr[] = {1, 2, 3, 4, 5};
```

## Output

```bash
5
```

## Constraints

- The input array must be contiguous in memory.
- The array size must be known at compile time or passed along as part of the input in some form.

> [!NOTE]
>
> - Let `ptr_start = &arr[0]` and `ptr_end = &arr[5]`.
> - Then, the number of elements = `ptr_end - ptr_start`.
