# Mask Certain Bits

## Problem Statement

Given an integer, **mask (set to zero)** all bits except for the **least significant `n` bits**. Return the resulting masked value using bitwise operations.

## Requirements

- Use only bitwise operations.
- Preserve only the **lowest** `n` bits of the integer.

## Input

An integer `num` and an integer `n` representing how many LSBs (least significant bits) to keep.

```bash
Input: num = 0b10101111, n = 4
```

## Output

Result after masking all but the first `n` bits

```bash
Output: 0b00001111
```

## Constraints

- `0 ≤ num < 2³²`
- `0 ≤ n ≤ 32`

> [!NOTE]
>
> Use the expression: `num & ((1 << n) - 1)`  
> This creates a mask with `n` 1's in the LSBs and zeroes elsewhere.
