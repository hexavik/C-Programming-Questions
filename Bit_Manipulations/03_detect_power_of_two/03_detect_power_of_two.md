# Detecting Power of Two

## Problem Statement

Write a function to determine whether a given integer is a **power of two** using **bitwise operations only**.

## Requirements

- Use **bitwise logic** to validate the power-of-two condition.

Avoid using division, multiplication, logarithms, or any standard math library functions.

## Input

A single positive integer `n`.

```bash
Input: 32
```

## Output

A boolean indicating whether the number is a power of two.

```bash
Output: True
```

## Constraints

- `1 ≤ n ≤ 2^31 - 1`
- Return `False` if `n` is zero or negative.

> [!NOTE]
>
> - A number `n` is a power of two **if and only if** it has exactly one bit set in its binary representation.
> - The condition **n & (n - 1) == 0** helps detect this because powers of two have only a single `1` followed by `0`s.
