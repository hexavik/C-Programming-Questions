# Extract `n` Bits from a Byte

## Problem Statement

Design a function to extract `n` **bits** from a given **byte**, starting from a specific bit position `p`, using bitwise operations.

## Requirements

- Use only bit manipulation to extract the desired bits.
- Return the extracted bits as an integer.

## Input

- A byte (8-bit value)
- Integer `n` – number of bits to extract
- Integer `p` – starting position (0-indexed from LSB)

```bash
Input: Byte = 0b10101100, n = 3, p = 2
```

## Output

Integer value representing the extracted bits

```bash
Output: 0b101  // or 5 in decimal
```

## Constraints

- `0 ≤ p ≤ 7`
- `1 ≤ n ≤ (8 - p)`

> [!NOTE]
>
> - Shift the byte right by `p` bits so the target bits align with the LSB.
> - Mask out all but the lowest `n` bits using `(1 << n) - 1`.
> - Final result is `(byte >> p) & ((1 << n) - 1)`.
