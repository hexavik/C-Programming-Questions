# Implement Custom `strtok()` Using Pointers

## Problem Statement

Design a function that mimics the behavior of the standard `strtok()` function using pointers. The function should split a given string based on a specified delimiter character and return each token one at a time.

## Requirements

- Use static variables to maintain context between calls.
- Traverse the string using pointers.
- Replace each delimiter with `'\0'` to terminate tokens.
- Return a pointer to the start of each token on successive calls.

## Input

```bash
char str[] = "embedded,systems,linux";
char delimiter = ',';
```

## Output

```bash
"embedded"
"systems"
"linux"
```

## Constraints

- The original string is modified (delimiter replaced with `'\0'`).
- Only a single character can be used as delimiter.
- Multiple delimiters in a row should be skipped (optional enhancement).

> [!NOTE]
>
> - Maintain a static pointer for next call tracking.
> - On first call, initialize the static pointer with the input string.
> - On subsequent calls, continue from the last position.
> - Terminate and return `NULL` when the end of the string is reached.
