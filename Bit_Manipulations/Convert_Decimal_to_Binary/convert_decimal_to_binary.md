# Decimal to Bianry Conversion using Bit Manipulation

## Problem Statement

Write a function that takes a **decimal integer** as input and returns its **binary representation** as a string, prefixed with `0b`. Use **bitwise operations only** for the conversion.

## Requirements

- Use bit manipulation to construct the binary representation.
- Return the result as a **binary string prefixed with** `0b`.
- Avoid using standard library functions like `itoa`, `sprintf`, or built-in binary formatters.

## Input

A single non-negative integer:

```bash
Input: 5
Input: 13
Input: 0
```

## Output

A string representing the binary value of the number prefixed with `0b`.

```bash
Output: 0b101   (for 5)
Output: 0b1101  (for 13)
Output: 0b0     (for 0)
```

## Constraints

- `0 ≤ n ≤ 2^31 - 1`
- Return value must be a null-terminated string in C.

> [!NOTE]
>
> **Bitwise Approach:**
>
> - Iterate from the **most significant bit (MSB)** down to the **least significant bit (LSB)**.
> - Use the bitmask `(1 << i)` to check each bit.
> - Append '1' or '0' to the result based on whether the bit is set.
> - Skip leading zeroes until the first '1' is encountered.
>
> **Edge Cases:**
>
> - `n = 0` → Output should be `"0b0"`
> - Very large numbers (e.g., `2^31 - 1`) should be handled properly.
