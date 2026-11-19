# Count Number of Flips to Convert A to B

## Problem Statement

Given two integers `A` and `B`, determine how many `bit flips` are required to convert `A` into `B`. Only bitwise operations should be used to perform the check.

## Requirements

- Use bit manipulation to compare the binary representations of `A` and `B`.
- Count and return the **number of differing bits**.
- No built-in population count or bit-counting functions allowed.

## Input

Two integers:

```bash
A = 29  // (0b11101)
B = 15  // (0b01111)
```

## Output

Integer representing the number of bits that differ between `A` and `B`:

```bash
Output: 2
```

## Constraints

- `0 ≤ A, B ≤ 2^31 - 1`
- Time complexity should be **O(number of bits)** in the integers (typically 32).

> [!NOTE]
>
> - Perform a **bitwise XOR** of `A` and `B`. The result will have `1`s in positions where the bits differ.
> - Count the number of `1`s in the XOR result using bitwise shifting and masking.
> - This count gives the **minimum number of bit flips** needed to convert A to B.
