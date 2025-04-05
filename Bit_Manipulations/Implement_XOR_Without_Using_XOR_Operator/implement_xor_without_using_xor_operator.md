# Implement XOR Without Using XOR Operator

## Problem Statement

Given two integers, compute their bitwise XOR without using the built-in `^` (XOR) operator.

## Requirements

- Implement XOR using other bitwise operations like AND, OR, and NOT.

## Input

Two integers `a` and `b`

```bash
Input: a = 5, b = 3
```

## Output

Result of `a XOR b`

```bash
Output: 6
```

## Constraints

- `0 ≤ a, b < 2³²`

> [!NOTE]
>
> - XOR logic can be derived from: `a XOR b = (a OR b) AND NOT (a AND b)`
>
> - Bitwise truth table:
> | In | In | XOR Out |
> |-|-|-|
> | 0 | 0 | 0 |
> | 1 | 0 | 1 |
> | 0 | 1 | 1 |
> | 1 | 1 | 0 |
