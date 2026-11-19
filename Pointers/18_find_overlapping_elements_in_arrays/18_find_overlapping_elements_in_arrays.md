# Find Overlapping Elements in Two Arrays Using Pointers

## Problem Statement

Design a program that identifies the overlapping elements (common suffix) of two arrays using pointer-based traversal. The goal is to find the sequence where both arrays start matching till the end.

## Requirements

- Use two pointers to traverse both arrays.
- Start comparison from the end of both arrays to find overlapping parts.
- Return the common suffix sequence if it exists.

## Input

```bash
arr1[] = {1, 2, 3, 4, 5, 6}  
arr2[] = {5, 6, 7, 8}

```

## Output

```bash
Overlapping elements: {5, 6}
```

## Constraints

- Arrays can have different lengths.
- Overlap (common elements) must occur in the same order from the end.
- Elements are assumed to be comparable with `==`.

> [!NOTE]
>
> - Start both pointers from the end of the arrays.
> - Traverse backwards, storing common values until elements differ.
> - Reverse the collected result to maintain input order if needed.
