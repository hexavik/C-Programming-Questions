# Find a Unique Number in an Array (All Others Appear Thrice)

## Problem Statement

Given an array where every number appears **exactly three times** except for **one unique number** that appears **only once**, use bitwise operations to find that number.

## Requirements

- Avoid using extra memory like hash maps or frequency tables.
- Solve using bit manipulation.

## Input

An array of integers

```bash
Input: [6, 1, 3, 3, 3, 6, 6]
```

## Output

The integer that appears only once

```bash
Output: 1
```

## Constraints

- All elements except one appear exactly three times.
- Array `length ≤ 10^5`
- All numbers are 32-bit signed integers.

> [!NOTE]
>
> - Count the number of set bits at each position across all elements.
> - If a bit appears not in a multiple of 3, it's set in the unique number.
> - Construct the result bit by bit using this observation.
