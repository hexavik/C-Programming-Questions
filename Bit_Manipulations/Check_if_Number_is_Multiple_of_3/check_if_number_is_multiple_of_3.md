# Check if a Number is a Multiple of 3 Using Bit Manipulation

## Problem Statement

Given an integer `n`, determine whether it is a **multiple of 3** using only bitwise operations (i.e., without using `/`, `%`, or `*`).

## Requirements

- Use bitwise operations only (no division/modulo).
- Implement an efficient algorithm.
- Function should return true if `n` is a multiple of 3, otherwise false.

## Input

An interger `n`

```bash
Input: 9  
Input: 12  
Input: 7  
```

## Output

```bash
Output: True  (for 9)  
Output: True  (for 12)  
Output: False (for 7)  
```

## Constraints

- `-2^31 ≤ n ≤ 2^31 - 1` (Handles signed 32-bit integers).
- **O(log N) time complexity** using bitwise operations.

> [!NOTE]
>
> **Bitwise Approach:**
>
> - Sum of Odd and Even Positioned Bits
>   - Convert `n` to binary.
>   - Compute separate sums of bits at odd and even positions.
>   - If the difference of these sums is a multiple of 3, then `n` is a multiple of 3.
> - Recursive Reduction
>   - Keep reducing |odd_sum - even_sum| until it's 0, 3, or 6.
>   - Example for n = 9 (1001):
>  
>   ```bash
>   Odd-positioned bits: 1 (LSB), 0 (3rd bit) → Sum = 1
>   Even-positioned bits: 0 (2nd bit), 1 (4th bit) → Sum = 1
>   Difference = |1 - 1| = 0  → Multiple of 3
>   ```
>
> **Edge Cases:**
>
> - `n = 0` or `n = 3` → Always true
> - Negative numbers (`n = -9`) → Should be handled correctly
> - Large numbers (`n = 2^31 - 1`) → Should work efficiently
