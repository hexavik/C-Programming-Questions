# Check for Alternate Bits

## Problem Statement

Design a function to check whether the **binary representation** of a given integer follows an **alternate bit pattern** (i.e., `101010...` or `010101...`).

## Requirements

- Use **bitwise operations** to efficiently verify the alternate pattern.
- The function should return **true** if the bits alternate and **false** otherwise.

## Input

An interger `n`

```bash
Input: 170 (0b10101010)
Input: 5 (0b101)
Input: 7 (0b111)
```

## Output

Boolean value

```bash
Output: True  (for 170)
Output: True  (for 5)
Output: False (for 7)
```

## Constraints

- `0 ≤ n ≤ 2^31 - 1` (Supports 32-bit signed integers)
- **Bitwise operations only** (No string/array conversion of binary representation)

> [!NOTE]
>
> **Efficient Bitwise Approach can be achieved using:**
>
> 1. Right-shift (`n >> 1`) and XOR (`^`)
>    - If `n` has alternating bits, `n ^ (n >> 1)` should result in **all 1s** (e.g., **1111...**).
>    - Example for `n = 0b101010`
>
>    ```bash
>    n      = 101010
>    n>>1   =  10101
>    XOR    = 111111  (which is 2^k - 1)
>    ```
>
> 2. Check if result is all 1s (`x & (x + 1) == 0`)
>    - A number with all bits set (e.g. `0b1111`) has the property: `x & (x + 1) == 0`
>
> **Implmentation Hint:**
>
> ```c
> bool has_alternate_bits(int n) {
>     int x = n ^ (n >> 1);
>     return (x & (x + 1)) == 0;
> }
> ```
>
> **Edge Cases:**
>
> - **Single-bit numbers** (`n = 0` or `n = 1`) → **True**
> - **Large numbers** (`n = 2^31 - 1`) → Should be handled efficiently
