# Count Set Bits Without Looping

## Problem Statement

Design a function to **count the number of set bits (1s)** in the binary representation of a given integer, using **no loops**.

## Requirements

- Avoid all forms of loops (`for`, `while`, recursion, etc.).
- Use only bitwise operations and arithmetic.
- Prefer a **constant-time approach** for fixed-width integers (e.g., 32-bit).

## Input

A single integer `n`.

```bash
Input: 0b11010110
```

## Output

An integer indicating how many bits are set to 1.

```bash
Output: 5
```

## Constraints

- `0 ≤ n ≤ 2^31 - 1`
- Function must work for 32-bit integers.

> [!NOTE]
>
> - Use a **bit-parallel counting algorithm** (e.g., Hamming Weight using masks and shifts).
> - These techniques repeatedly collapse groups of bits to sum up the count of set bits.
> - Commonly used constants:
>   - `0x55555555` (0101...)
>   - `0x33333333` (0011...)
>   - `0x0F0F0F0F` (00001111...)
>   - etc., to aggregate counts from 1-bit to 32-bit chunks efficiently.
