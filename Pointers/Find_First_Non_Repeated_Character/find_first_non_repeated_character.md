# Find First Non-Repeated Character Using Pointers

## Problem Statement

Implement a program that identifies the first non-repeated character in a string using pointers. Count character frequencies first, then scan to find the first character with a count of one.

## Requirements

- Use pointer-based traversal of the string.
- Use a fixed-size array (e.g., size 256) to store character counts.
- Avoid using string library functions except for pointer operations.

## Input

```bash
String: "swiss"
```

## Output

```bash
First non-repeated character: 'w'
```

## Constraints

- Input string may contain both uppercase and lowercase characters.
- Assume ASCII character set (0-255).

> [!NOTE]
>
> - **First pass:** increment count for each character using its ASCII value as index.
> - **Second pass:** return the first character whose count is 1.
> - If no non-repeated character is found, return a null character or suitable message.
