# Isolate the Rightmost Set Bit

## Problem Statement

Given an integer, isolate its **rightmost set bit** (i.e., the least significant bit that is 1). All other bits in the result should be set to 0.

## Requirements

- Use bitwise operations only.
- Return an integer with only the rightmost 1-bit preserved.

## Input

An integer `num`

```bash
Input: num = 0b10100000
```

## Output

An integer with only the rightmost set bit of `num`

```bash
Output: 0b00100000
```

## Constraints

- `0 ≤ num < 2³²`
- Input is non-zero

> [!NOTE]
>
> Use the expression: `num & -num`  
> This isolates the rightmost bit set to 1 using two's complement arithmetic.
