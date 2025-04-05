# Power Calculation Using Bit Manippulation

## Problem Statement

Write a function to compute a<sup>b</sup> (where `a` is the base and `b` is the exponent) using **bitwise operations** only. Avoid using the built-in power operator (`**`, `pow()`) or any direct multiplication operations.

## Requirements

- Use **bitwise shifts**, **AND** (`&`), and **XOR** (`^`) operations for calculation.
- Implement the solution using an **iterative approach** (using bit manipulation and exponentiation by squaring).
- Return the result as an integer.

## Input

Two integers as base (`a`) and exponent (`b`).

```bash
a = 2, b = 3
```

## Output

Result of a to the power b.

```bash
Result: 8
```

## Constraints

- 1 ≤ a ≤ 10<sup>5</sup>
- 0 ≤ b ≤ 31 (since the result fits within a 32-bit integer)

> [!NOTE]
>
> - Use the exponentiation by squaring technique:
>   - Left shift (`<<`) for multiplication by 2.
>   - Right shift (`>>`) for dividing the exponent by 2.
>   - Bitwise AND (`&`) to check if the current bit of the exponent is set.
> - Edge cases to consider:
>   - When b = 0, return 1 (anything raised to the power 0 is 1).
>   - When a = 0 and b > 0, return 0.
> - Avoid any loops or operations that directly compute multiplication without bitwise operations.
