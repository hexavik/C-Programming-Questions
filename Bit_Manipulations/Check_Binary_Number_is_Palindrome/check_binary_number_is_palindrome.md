# Check if Binary Representation of a Number is Palindrome

## Problem Statement

Given an integer `n`, check whether its **binary representation** is a palindrome—i.e., it reads the same **forwards and backwards**.

## Requirements

- Use bitwise operations to extract and compare bits.
- **Avoid string or array conversion** for checking the palindrome property.
- The function should return **true** if the binary representation is a palindrome and **false** otherwise.

## Input

An integer `n`:

```bash
Input: 9   (0b1001)  
Input: 15  (0b1111)  
Input: 10  (0b1010)  
```

## Output

Boolean value:

```bash
Output: True  (for 9)  
Output: True  (for 15)  
Output: False (for 10)  
```

## Constraints

- `0 ≤ n ≤ 2^31 - 1` (Handles up to 32-bit integers)
- **Efficient bitwise-only approach**

> [!NOTE]
>
> **Bitwise Approach**
>
> - **Extract bits from both ends and compare**
>   - Find **leftmost** and **rightmost** bits using shifting and masking.
>   - Compare bits one by one moving inward.
>   - If all corresponding bits match, the number is a palindrome.
> - Find the number of significant bits (`k`)
>   - The highest set bit gives the number of meaningful bits.
>   - Example: `9 (0b1001)` → **4 bits used**.
> - Compare bits using `(n >> i) & 1` and `(n >> (k-i-1)) & 1`
>   - If they mismatch at any position, return `false`.
>
> **Edge Cases**
>
> - **Single-bit numbers** (`n = 0, 1`) → Always **true**
> - **Powers of two** (`n = 8 (0b1000)`) → Always **false**
> - **Large numbers** (`n = 2^31 - 1`) → Should be handled efficiently
