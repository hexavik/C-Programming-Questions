# Sorted Array Merger

**Problem Statement:**

Merge two sorted arrays into a single sorted array. The resulting array must maintain the order of sorting.

**Requirements:**

Write a program or function to combine two sorted arrays into a single array, ensuring the elements are in ascending order.

**Input:**

Two sorted integer arrays:

- `arr1`: First sorted array of size `n`.
- `arr2`: Second sorted array of size `m`.

```bash
arr1 = [1, 3, 5]
arr2 = [2, 4, 6]
```

**Output:**

A single sorted array that merges all elements of `arr1` and `arr2.

```bash
result = [1, 2, 3, 4, 5, 6]
```

**Constraints:**

- The input arrays `arr1` and `arr2` are sorted in non-decreasing order.
- The resulting merged array must also be sorted in non-decreasing order.
- The function should handle empty arrays gracefully (e.g., merging `[]` and `[1,2,3]`).

**Notes:**

- **Merge Logic:**
  - Use two pointers, one for each array, to compare elements.
  - Append the smaller element to the result and move the pointer forward in the respective array.
  - If elements remain in one array after the other is exhausted, append the remaining elements to the result.
