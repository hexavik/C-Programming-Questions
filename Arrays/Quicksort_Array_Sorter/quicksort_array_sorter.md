# Quicksort Array Sorter

**Problem Statement:**

Sort a given array of integers in ascending order using the quicksort algorithm.

**Requirements:**

Write a program or function that applies the quicksort sorting technique to the input array and returns the array sorted in ascending order.

**Input:**

An unsorted integer array `arr` of size `n`, where `n≥1`.

```bash
arr = [64, 34, 25, 12, 22, 11, 90]
```

**Output:**
****
The sorted version of the input array `arr`, arranged in ascending order.

```bash
result = [11, 12, 22, 25, 34, 64, 90]
```

**Constraints:**

- The input array may contain positive, negative, or zero values.
- The algorithm should be implemented recursively using the divide-and-conquer approach.

> [!NOTE]
>
> - Quicksort Algorithm Overview:
>   - Choose a "pivot" element from the array.
>   - Partition the array such that all elements less than the pivot are placed to its left, and all elements greater than the pivot are placed to its right.
>   - Recursively apply the same logic to the subarrays on either side of the pivot.
>   - Combine the results to form the final sorted array.
> - Ensure your implementation efficiently handles arrays with duplicate elements and varying lengths.
