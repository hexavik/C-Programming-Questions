# Find Parity of a Number

## Problem Statement

Implement a function to determine the **parity** of a given integer — whether the number of `1`s in its **binary representation** is **even or odd** — using bitwise operations only.

## Requirements

- Use bitwise operations to count the number of `1`s.
- Return whether the count is **Even** or **Odd**.

## Input

A single integer `n`:

```bash
Input: 7  // Binary: 0b0111
```

## Output

A string: `"Even"` or `"Odd"`

```bash
Output: Odd
```

## Constraints

- `0 ≤ n ≤ 2^31 - 1`

> [!NOTE]
>
> - Parity can be determined by XOR-ing all bits of the number together.
> - Efficient techniques exist using successive XOR shifts to reduce all bits to one parity bit.
> - Even parity: total 1s is even; Odd parity: total 1s is odd.
