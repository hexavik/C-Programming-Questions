# Clear Bits from MSB to i (Inclusive) Using Bitwise Operations

## Problem Statement

Given an integer `n` and an index `i`, clear all bits **from the most significant bit (MSB) to bit** `i` **(inclusive)**. The function should **return the modified integer** with the required bits set to `0`.

## Requirements

- Use bitwise operations only.
- The least significant bits (LSBs) from `i-1` to 0 remain unchanged.
- Function should return the updated integer.

## Input

An integer `n` and an index `i` (0-based index)

```bash
Input: 0b11111111, i = 3  
Input: 0b10110110, i = 4  
Input: 0b11101111, i = 5  
```

## Output

Modified integer with cleared MSB to `i`

```bash
Output: 0b00001111 (for 0b11111111, i = 3)  
Output: 0b00001110 (for 0b10110110, i = 4)  
Output: 0b00000111 (for 0b11101111, i = 5)  

```

## Constraints

- `0 ≤ i ≤ 31` (Valid for 32-bit integers).
- **O(1) time complexity** (constant time).

> [!NOTE]
>
**Bitwise Approach:**

- Construct a Mask
  - To clear bits from `MSB` to `i`, we need a mask where:
    - Bits from `i` upwards are 0.
    - Bits from `i-1` downwards remain unchanged.
  - This can be achieved using: `mask = (1 << i) − 1`
  - Example for `i = 3`: `(1 << 3) - 1 = 0b00001000 - 1 = 0b00000111`
- Apply Mask using Bitwise AND
  - Use `n & mask` to retain lower bits and clear upper bits.

**Edge Cases:**

- `i = 0` (Clears all bits) → Output: `0b00000000`
- `i = 31` (Only the sign bit is cleared in a 32-bit integer)
- Large numbers (`n = 0xFFFFFFFF`) → Should work efficiently
