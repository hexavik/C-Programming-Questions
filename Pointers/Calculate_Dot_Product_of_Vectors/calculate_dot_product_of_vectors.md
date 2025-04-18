# Dot Product of Two Vectors Using Pointers

## Problem Statement

Write a function to calculate the dot product of two integer vectors by traversing them using pointer arithmetic.

## Requirements

- Use only pointer-based access to elements (no array indexing).
- Traverse both vectors simultaneously.
- Multiply corresponding elements and accumulate the sum.

## Input

```bash
int vec1[] = {1, 2, 3};
int vec2[] = {4, 5, 6};
int n = 3;
```

## Output

```bash
32
```

## Constraints

- `1 <= n <= 10^5`
- Vectors must be of equal length
- Elements can be any integers (positive, negative, or zero)

> [!NOTE]
>
> - Use expressions like `*(vec1 + i)` or increment pointers directly using `*p1++`
> - Dot product = sum of element-wise products:
> `vec1[0]*vec2[0] + vec1[1]*vec2[1] + ... + vec1[n-1]*vec2[n-1]`
