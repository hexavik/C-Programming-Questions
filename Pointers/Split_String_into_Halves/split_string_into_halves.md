# Split a String into Two Halves Using Pointers

## Problem Statement

Implement a function that takes a string and splits it into two halves. Return pointers to the beginning of each half using pointer arithmetic.

## Requirements

- Use pointers to locate the middle of the string.
- Split by modifying the original string (e.g., inserting `'\0'` at midpoint).
- Return two pointers: one to the start and one to the second half.

## Input

```bash
char str[] = "HelloWorld"
```

## Output

```bash
First Half: "Hello"  
Second Half: "World"
```

## Constraints

- String length must be even or handle odd by floor division (e.g., 9 → 4+5).
- Original string must be modifiable (i.e., not a string literal).

> [!NOTE]
>
> - Use `strlen()` to calculate midpoint if allowed, else manually traverse.
> - Ensure null-termination for the first half when splitting.
