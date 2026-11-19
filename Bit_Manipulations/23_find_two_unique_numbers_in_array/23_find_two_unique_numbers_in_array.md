# Find Two Unique Numbers in an Array

## Problem Statement

Given an array where every element appears **exactly twice**, except for **two unique numbers**, use bitwise operations to identify and return those two numbers.

## Requirements

- Use bit manipulation to solve the problem efficiently.
- Avoid using extra space like hash maps or sets.

## Input

An array of integers

```bash
Input: [4, 1, 2, 1, 2, 5]
```

## Output

Two integers that appear only once in the array

```bash
Output: 4, 5
```

## Constraints

- All elements appear exactly twice, except for two unique values.
- `1 ≤ array.length ≤ 10^5`
- All numbers are 32-bit signed integers.

> [!NOTE]
>
> - XOR of all elements gives `x ^ y` where `x` and `y` are the two unique numbers.
> - Find any set bit in `x ^ y` (e.g., rightmost set bit) to separate the array into two groups.
> - XOR-ing elements within each group will isolate `x` and `y`.
