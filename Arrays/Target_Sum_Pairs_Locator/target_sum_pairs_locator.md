# Target Sum Pairs Locator

**Problem Statement:**

Identify all pairs of integers in a given array such that the sum of the pair equals a specified target value.

**Requirements:**

Write a program or function that identifies all pairs `(a, b)` in the array such that: `a+b=targt`.

**Input:**

1. An array of integers `arr`, which may contain duplicates and negative values.
2. An integer `target` specifying the desired sum of the pairs.

```bash
arr = [2, 4, 3, 5, 6, -2, 4, 6, 8, 9]
target = 7
```

**Output:**

- A list of pairs `(a, b)` where `a+b=target`.
- Each pair must appear only once, regardless of their order.

```bash
result = [(2, 5), (4, 3), (-2, 9)]
```

**Constraints:**

- The array `arr` may contain duplicate values.
- Ensure no duplicate pairs are included in the output.
- Handle negative numbers and zeros appropriately.

**Notes:**

- **Transformation Logic:**
  - Iterate through the array and use a hash map (dictionary) to store the complements of the numbers seen so far.
  - For each number, check if its complement (i.e., target - number) exists in the hash map.
  - If the complement exists, add the pair to the result.
- **Output Format:**
  - The order of pairs does not matter.
  - Avoid duplicate entries by ensuring each pair is only added once
- **Edge Cases:**
  - Input array is empty: [].
  - No pairs match the target sum.
  - Input contains multiple duplicates of the same number.
