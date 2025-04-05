# Rotate Bits Left

## Problem Statement

Given an integer and a rotation count `k`, rotate the bits of the integer to the **left** by `k` positions using bitwise operations.

## Requirements

- Perform a left rotation of the binary representation.
- Use only bitwise operations.
- Bit-width should be assumed to be **8 bits** unless otherwise specified.

## Input

- An integer `num` (e.g., `0b10110011`)
- An integer `k` representing number of left rotations (e.g., `3`)

```bash
Input: num = 0b10110011, k = 3
```

## Output

The resulting 8-bit number after rotating left by `k` positions

```bash
Output: 0b10011101
```

## Constraints

- `0 ≤ num ≤ 255` (8-bit integer)
- `0 ≤ k ≤ 7`

> [!NOTE]
>
> - Use shifting and masking to wrap the overflowed bits from left to right.
> - Rotation should preserve the total number of bits.
