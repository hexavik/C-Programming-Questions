# Find Size of Data Type Using Pointer Arithmetic (Without `sizeof`)

## Problem Statement

Write a program to determine the size of a given data type without using the `sizeof` operator by leveraging pointer arithmetic.

## Requirements

- Use two pointers of the same type.
- Increment one pointer and subtract the other.
- The difference gives the size of that data type in bytes.

## Input

```bash
Data type: int
```

## Output

```bash
4  // Output will depend on the platform (commonly 4 bytes for int)
```

## Constraints

- You are not allowed to use the `sizeof` operator.
- Only pointer arithmetic is allowed.

> [!NOTE]
>
> - Pointer arithmetic moves in steps of the size of the type.
> - Subtracting `ptr + 1 - ptr` gives the size in terms of elements; cast difference to `char*` to get byte size.
