# Swap Two Strings Using Pointers to Pointers

## Problem Statement

Implement a program that swaps two string pointers using pointer-to-pointer technique.

## Requirements

- Use pointer-to-pointer manipulation to swap the addresses of two string pointers.
- The strings themselves remain in memory; only the pointers are exchanged.

## Input

```bash
char *str1 = "hello";
char *str2 = "world";
```

## Output

```bash
str1 = "world";
str2 = "hello";
```

## Constraints

- Strings must be stored in modifiable pointers (not string literals if mutation is needed).
- Only pointer swapping is required; no need to copy string contents.

> [!NOTE]
>
> - Use a temporary pointer for swapping the addresses via `char**`.
> - This technique is useful in functions where the caller's pointers need to be updated.
