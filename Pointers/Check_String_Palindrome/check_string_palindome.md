# Check if a String is a Palindrome Using Pointers

## Problem Statement

Create a function to determine if a given string is a palindrome. Use two pointers — one starting at the beginning and the other at the end — and compare characters while traversing inward.

## Requirements

- Use only pointer arithmetic for character access.
- Avoid using array indexing.
- Do not use string library functions like strlen.

## Input

```bash
char str[] = "radar";
```

## Output

```bash
True
```

## Constraints

- String must be null-terminated.
- Case-sensitive comparison.
- Ignore spaces or special characters only if explicitly handled.

> [!NOTE]
>
> - Use one pointer to move forward and another backward until they meet or cross.
> - Stop early if a mismatch is found.
> - Can be extended for case-insensitive or alphanumeric-only comparison if needed.
