# Generate All Possible Combinations of `n` Bits

## Problem Statement

Design a program that generates all possible binary combinations of length `n`. Use bitwise operations to produce each sequence.

## Requirements

- For a given integer `n`, generate all binary numbers from `0` to `2ⁿ - 1`.
- Display each number in **n-bit binary format**.

## Input

An integer `n`

```bash
Input: 3
```

## Output

A list of `2ⁿ` binary strings, each `n` bits long

```bash
Output: 000, 001, 010, 011, 100, 101, 110, 111
```

## Constraints

- `1 ≤ n ≤ 20`

> [!NOTE]
>
> - Loop through all integers from `0` to `(1 << n) - 1`.
> - Use bitwise left-shift to generate the upper bound.
> - Format each number into binary with padding to `n` bits.
