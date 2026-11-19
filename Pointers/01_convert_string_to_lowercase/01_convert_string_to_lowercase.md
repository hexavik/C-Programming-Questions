# Convert String to Lowercase Using Pointers

## Problem Statement

Write a function that converts all uppercase letters in a string to lowercase using pointer arithmetic.

## Requirements

- Traverse the string using pointers.
- Convert each uppercase character to lowercase by adding 32 to its ASCII value.

## Input

```bash
char str[] = "HELLO";
```

## Output

```bash
"hello"
```

## Constraints

- Only uppercase alphabetic characters ('A' to 'Z') are to be converted.
- Assume ASCII encoding.
- The string must be null-terminated.

> [!NOTE]
>
> - For each character `*ptr`, check if it falls in the range `'A'` to `'Z'`.
> - If true, modify it in-place: `*ptr += 32`.
> - Continue until the null terminator is reached.
