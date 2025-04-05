# Single Number in Array

## Problem Statement

You are given an array where every element appears twice except for **one unique element** that appears only once. Use bitwise operations to find that unique element. Your solution should use **constant space**.

## Requirements

- Use only bitwise operations.
- Do not use extra space like hash tables.
- Linear time solution is expected.

## Input

```bash
arr[4, 1, 2, 1, 2]
```

## Output

The unique element that appears only once

```bash
Output: 4

```

## Constraints

- Only one element appears once; all others appear exactly twice
- Time complexity: **O(n)** and Space complexity: **O(1)**

> [!NOTE]
>
> - Think about how XOR behaves: `a ^ a = 0` and `a ^ 0 = a`.
> - XORing all elements cancels out duplicates, leaving the unique number.
