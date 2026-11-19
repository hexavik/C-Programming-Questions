# Implement Bitwise Right Shift Without '>>' Operator

## Problem Statement

Given an integer and a shift count, implement the **bitwise right shift operation** without using the built-in `>>` operator.

## Requirements

- Simulate a right shift using bitwise operations only.
- Preserve behavior for unsigned shift (i.e., logical shift).

## Input

An integer `num` and an integer `shift` representing number of positions to shift

```bash
Input: num = 0b1101, shift = 2
```

## Output

An integer after shifting `num` to the right by `shift` positions

```bash
Output: 0b0011
```

## Constraints

- `0 ≤ num < 2³²`
- `0 ≤ shift < 32`

> [!NOTE]
>
> - Use division and masking to simulate right shift.
> - Logical right shift: fills with `0` from the left regardless of sign.
> - This approach is ideal for unsigned integers.
