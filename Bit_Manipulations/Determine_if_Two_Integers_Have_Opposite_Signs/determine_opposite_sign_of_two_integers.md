# Determine if Two Integers Have Opposite Signs

## Problem Statement

Write a function to check whether two given integers have **opposite signs** using bitwise operations only.

## Requirements

- Use **bit manipulation** to detect sign difference.
- Avoid using conditional operators or multiplication/division.

## Input

Two integers:

```bash
Input: -4, 5
```

## Output

A boolean indicating whether the numbers have opposite signs:

```bash
Output: True
```

## Constraints

- `-2^31 ≤ a, b ≤ 2^31 - 1`

> [!NOTE]
>
> - The **sign bit** is the most significant bit in a signed integer.
> - If `a ^ b` results in a number with the sign bit set, it indicates the signs are different.
> - So, check if `(a ^ b) < 0` to confirm opposite signs.
