# Set First `n` Bits Without Arithmetic Operations

## Problem Statement

Given an integer `n`, set the first `n` bits (from the most significant bit) of an 8-bit number to 1 using **only bitwise operations**. The remaining bits should be 0.

## Requirements

- Do not use arithmetic operations like `+`, `-`, `*`, or `/`.
- Use only bitwise operations to construct the result.
- Output should be an 8-bit number with the first `n` bits as `1`.

## Input

```bash
Input: n = 4
```

## Output

An 8-bit number with `n` leading 1s and the rest 0s

```bash
Output: 0b11110000
```

## Constraints

- `0 ≤ n ≤ 8`

> [!NOTE]
>
> - Think in terms of masks and how left shifts or bitwise NOTs can help.
> - Remember that in an 8-bit representation, the most significant bit is at position 7.
