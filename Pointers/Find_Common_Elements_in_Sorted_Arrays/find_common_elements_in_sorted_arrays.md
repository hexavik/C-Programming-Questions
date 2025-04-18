# Find Common Elements in Three Sorted Arrays Using Pointers

## Problem Statement

Implement a function that finds all common elements in three sorted arrays using pointers.

## Requirements

- Traverse all three arrays using three pointers.
- At each step, compare the elements the pointers refer to.
- If all are equal, store the value and advance all pointers.
- Otherwise, increment the pointer pointing to the smallest value.

## Input

```c
int arr1[] = {1, 5, 10, 20, 40, 80};
int arr2[] = {6, 7, 20, 80, 100};
int arr3[] = {3, 4, 15, 20, 30, 70, 80, 120};
```

## Output

```bash
{20, 80}
```

## Constraints

- Arrays are **sorted in ascending order**.
- Time complexity must be **O(n1 + n2 + n3)**, where n1, n2, and n3 are lengths of the arrays.
- Do not use extra space for unsorted hash-based techniques.

> [!NOTE]
>
> - Efficient pointer control ensures optimal time.
> - Handle edge cases where arrays may have different lengths or no common elements.
