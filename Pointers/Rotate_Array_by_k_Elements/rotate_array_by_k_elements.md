# Rotate Array to the Right by `k` Elements Using Pointers

## Problem Statement

Create a function that rotates an array to the right by `k` positions using pointer manipulation. Use the reverse technique:

1. Reverse the entire array.
2. Reverse the first `k` elements.
3. Reverse the remaining `n - k` elements.

## Requirements

- Use pointer arithmetic to perform in-place reversal.
- Optimize for **O(n)** time and **O(1)** space.

## Input

```bash
Array: {1, 2, 3, 4, 5}  
k: 2
```

## Output

```bash
Rotated Array: {4, 5, 1, 2, 3}
```

## Constraints

- `0 ≤ k < n`
- Array must be non-empty.
- Array elements are integers.

> [!NOTE]
>
> - Reversal using pointers involves swapping elements from both ends moving inward.
> - Normalize `k` if it's greater than `n`.
