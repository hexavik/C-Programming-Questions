# Concatenate Two Strings Using Pointers Only

## Problem Statement

Design a function to concatenate two null-terminated strings using only pointers and without using standard library functions.

## Requirements

- Use pointer arithmetic to append the second string to the first.
- Avoid any standard functions like `strcat()` or `strlen()`.

## Input

```bash
char str1[50] = "Good ";
char *str2 = "Morning";
```

## Output

```bash
"Good Morning"
```

## Constraints

- The first string must have enough space to hold the result.
- Null terminator must be handled properly.

> [!NOTE]
>
> - Move the pointer of the first string to its null terminator.
> - Copy each character from the second string to this position.
> - Ensure the result is null-terminated.
