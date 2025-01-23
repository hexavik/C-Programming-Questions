# Positive Negative Rearranger

**Problem Statement:**

Rearrange the elements of an array such that positive numbers and negative numbers alternate in sequence. The relative order of the positive and negative numbers in their respective groups should be preserved.

If it is not possible to alternate (due to an unequal number of positive and negative elements), append the remaining elements of the majority group to the end.

**Requirements:**

Write a function or program to rearrange the array as described. The relative order of positive and negative elements must be maintained.

**Input:**

An integer array `arr` containing both positive and negative integers.

```bash
arr = [-1, 2, -3, 4, 5, 6, -7, 8, 9]
```

**Output:**

An array where positive and negative integers are rearranged alternately, maintaining their relative order in the input.

```bash
result = [2, -1, 4, -3, 5, -7, 6, 8, 9]
```

**Constraints:**

- The array can contain both positive and negative integers.
- There will be at least one positive and one negative number.
- If the number of positive and negative integers are not equal:
  - Excess positive integers should appear at the end.
  - Excess negative integers should appear at the end.
- Zero is neither positive nor negative but can be treated as a positive number if included.

**Notes:**

- **Approach 1:** Use two separate arrays to store positive and negative numbers, then merge them alternately.
- **Approach 2 (In-place):** Rearrange the elements directly within the original array using pointer manipulation.
