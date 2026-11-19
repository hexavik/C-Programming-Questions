# Implement Custom `memcpy()` Using Pointers

## Problem Statement

Design a function that mimics the behavior of the standard `memcpy()` function. Use pointer arithmetic to copy memory from a source location to a destination location.

## Requirements

- Traverse both source and destination using pointers.
- Copy each byte individually using dereferencing.
- Avoid using standard library memory functions.

## Input

```bash
char src[] = "hello";
char dest[6];
int length = 5;
```

## Output

```bash
dest = "hello"
```

## Constraints

- Source and destination must not overlap.
- Ensure the destination has enough allocated memory.
- Only byte-wise copying is allowed using pointers.

> [!NOTE]
>
> - Set two pointers: `src_ptr` and `dest_ptr`.
> - For each byte up to `length`, perform: `*dest_ptr++ = *src_ptr++`.
