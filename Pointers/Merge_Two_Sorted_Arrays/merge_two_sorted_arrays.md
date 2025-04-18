# Merge Two Sorted Arrays Using Pointers

## Problem Statement

Design a function that merges two sorted arrays into a single sorted array using pointer-based traversal.

## Requirements

- Utilize **three pointers**: two for the input arrays and one for the result array.
- Compare current elements from both arrays and insert the smaller one into the result array.
- Copy the remaining elements when one array is exhausted.

## Input

```bash
int arr1[] = {1, 3, 5};  
int arr2[] = {2, 4, 6};  
```

## Output

```bash
int merged[] = {1, 2, 3, 4, 5, 6};  
```

## Constraints

- Both input arrays are sorted in ascending order.
- Result array must also be sorted.
- No use of standard sort or merge functions.

> [!NOTE]
>
> - Ensure that array bounds are not violated while traversing.
> - Can be extended to dynamically allocated result arrays if size isn't known.
