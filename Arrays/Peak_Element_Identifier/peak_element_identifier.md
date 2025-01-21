# Peak Element Identifier

**Problem Statement:**

Given an integer array, find a peak element. A peak element is one that is greater than or equal to its neighbors.

**Requirements:**

Write a function or program that identifies a peak element in the array. If multiple peak elements exist, returning any one of them is acceptable.

**Input:**

An integer array `arr` of size `n`, where `n≥1`.

```bash
arr = [1, 3, 20, 4, 1, 0]
```

**Output:**

An integer representing any peak element in the array.

```bash
result  = 20
```

**Constraints:**

- For an element to be a peak:
  - If it is not at the ends of the array, it must be greater than or equal to both its left and right neighbors.
  - If it is the first or last element, it only needs to be greater than or equal to its single neighbor.
- The array may contain duplicates.
- If the array contains only one element, that element is the peak.

**Notes:**

- Aim for an efficient solution using a **binary search** technique, which achieves **O(log n)** time complexity.
- A straightforward solution involves linear traversal with **O(n)** time complexity.
- If implementing a binary search, focus on dividing the array into halves and checking the middle element's neighbors.
- Using straight `for` loop is also efficient enough.
