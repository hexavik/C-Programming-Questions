# Zero Sum Subarray Detector

**Problem Statement:**

Determine whether a given array contains any subarray (subset of consecutive elements) whose sum equals zero.

**Requirements:**

Write a program or function to check for the existence of a zero-sum subarray in the given array.

**Input:**

An array `arr` of integers of size `n`, which can contain both positive and negative numbers.

```bash
arr =[4, 2, -3, 1, 6]
```

**Output:**

If there exists a subarray with a sum of zero, return `true`, else `false`.

```bash
result = true
```

**Constraints:**

- The array can contain both positive and negative integers.
- The function should aim for optimal performance with minimal computational overhead.
- An empty subarray is not considered valid.

> [!NOTE]
>
> - **Approach:**
>   - Use a **prefix sum** method:
>     - Compute the cumulative sum of the array while iterating through it.
>     - If the cumulative sum at any point is zero or if it has been seen before, a zero-sum subarray exists.
>   - This is based on the idea that if two prefix sums are the same, the elements between them sum to zero.
> - **Optimal Solution:**
>   - Utilize a hash set to track cumulative sums encountered so far, ensuring an efficient check for duplicates.
> - **Edge Cases:**
>   - The array starts with a zero-sum subarray, e.g., `[0, 1, 2]`.
>   - The array contains all positive or all negative numbers, e.g., `[1, 2, 3]`.
>   - Large arrays with repeated values.
