# Find Intersection of Two Arrays Using Pointers

## Problem Statement

Design a function that identifies common elements (intersection) between two arrays using pointers. The approach varies depending on whether the arrays are sorted.

## Requirements

- If arrays are **sorted**, use two-pointer technique.
- If **unsorted**, use a hash table for one and pointer traversal for the other.

## Input

```bash
int arr1[] = {1, 2, 3, 4};
int arr2[] = {3, 4, 5, 6};
```

## Output

```bash
{3, 4}
```

## Constraints

- Time complexity should be **O(n + m)** for unsorted arrays using hashing.
- For sorted arrays, aim for **O(n + m)** with two pointers.
- No standard library intersection functions allowed.

> [!NOTE]
>
> - Make sure to avoid duplicate entries in the output.
> - If arrays are large, use pointers to reduce space overhead.
