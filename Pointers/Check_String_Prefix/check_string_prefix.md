# Check if One String is a Prefix of Another Using Pointers

## Problem Statement

Design a function that checks whether one string is a prefix of another using pointer arithmetic.

## Requirements

- Use only pointers to traverse and compare characters.
- Avoid using array indexing or string library functions.

## Input

```bash
char *str1 = "Hello";
char *str2 = "Hel";
```

## Output

```bash
True
```

## Constraints

- Both strings must be null-terminated.
- Case-sensitive comparison.
- The second string should not be longer than the first.

> [!NOTE]
>
> - Traverse both strings simultaneously.
> - Return `False` immediately if any mismatch is found.
> - If `str2` ends and all previous characters matched, it is a prefix.
