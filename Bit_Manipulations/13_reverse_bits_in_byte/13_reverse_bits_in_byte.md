# Reverse Bits in a Byte

## Problem Statement

Given an 8-bit byte, reverse the order of its bits using bitwise operations. The most significant bit becomes the least significant bit and vice versa.

## Requirements

- Use only bitwise operations.
- Operate strictly on **8-bit data**.

## Input

An integer `byte` representing an 8-bit value

```bash
Input: 0b11001001
```

## Output

An integer representing the byte with its bits reversed

```bash
Output: 0b10010011
```

## Constraints

- `0 ≤ byte ≤ 255` (i.e., fits in 8 bits)

> [!NOTE]
>
> - You may use shifting and masking to swap bits at mirrored positions.
> - Bit positions (0 to 7) can be reversed by swapping bits (0↔7), (1↔6), (2↔5), (3↔4).
