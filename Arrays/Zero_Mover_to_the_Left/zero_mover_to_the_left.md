# Zero Mover to the Left

**Problem Statement:**

Rearrange a given array such that all zero values are moved to the leftmost positions while maintaining the relative order of the non-zero elements.

**Requirements:**

Write a program or function that modifies the input array to meet the specified conditions in-place without using additional storage for a new array.

**Input:**

An array `arr` of integers of size `n`, containing both zero and non-zero values.

```bash
arr = [1, 2, 0, 4, 3, 0, 5, 0]
```

**Output:**

The modified array with all zeros moved to the left while preserving the order of non-zero numbers.

```bash
result = [0, 0, 0, 1, 2, 4, 3, 5]
```

**Constraints:**

- The input array can contain any integer values (positive, negative, or zero)
- The array should be modified in-place, with minimal extra space usage.
- Maintain the relative order of non-zero numbers.

> [!NOTE]
>
> - Approach:
>   - Traverse the array from right to left, ensuring zero values are shifted towards the beginning
>   - Use a pointer or index to track the position for inserting zeros and rearranging non-zero values.
> - Avoid unnecessary swaps or auxiliary data structures, aiming for optimal efficiency.
> - Edge Cases:
>   - The array contains no zeros, e.g., `[1, 2, 3]`.
>   - The array contains only zeros, e.g., `[0, 0, 0]`.
>   - Large arrays with interspersed zeros and non-zero numbers.
