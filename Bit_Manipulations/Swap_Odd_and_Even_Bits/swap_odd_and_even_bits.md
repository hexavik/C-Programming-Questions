# Swap Odd and Even Bits

## Problem Statement

Given an integer, swap its odd and even bits.  
That is:

- Bit 0 ↔ Bit 1
- Bit 2 ↔ Bit 3
- Bit 4 ↔ Bit 5
- Bit 6 ↔ Bit 7

...and so on.  
Use bitwise operations only to perform this operation.

## Requirements

- Use masks and bit shifts to swap bits in place.
- Avoid loops if possible (for fixed-size integers).

## Input

```bash
Input: 0b10101010
```

## Output

Integer with swapped odd and even bits

```bash
Output: 0b01010101
```

## Constraints

- You can assume a 32-bit integer if needed
- Bit positions are 0-indexed from the right

## Bonus Challenges

- Can you make it work for both 8-bit and 32-bit inputs?
- Extend it to swap bits in blocks of 2, 4, or 8 instead of just odd/even.

> [!NOTE]
>
> - Use the masks:
>   - `0xAAAAAAAA` (binary: 10101010...) to extract even bits
>   - `0x55555555` (binary: 01010101...) to extract odd bits
> - Shift even bits right, odd bits left, then OR the result.
