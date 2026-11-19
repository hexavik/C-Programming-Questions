# Segregate Even and Odd Values in an Integer Array Using Pointers

## Problem Statement

Design a function that rearranges an integer array so that all even numbers appear before all odd numbers. Use two-pointer technique to perform the operation in-place.

## Requirements

- Use pointers to traverse from both ends.
- Swap values if left points to an odd and right points to an even number.
- Continue until the two pointers meet.

## Input

```bash
int arr[] = {12, 34, 9, 8, 45, 90}
```

## Output

```bash
Rearranged Array: {12, 34, 8, 90, 9, 45}
```

## Constraints

- Array must be non-empty.
- All elements are integers.

> [!NOTE]
>
> - Maintain stability only if needed; else, swap without preserving order.
> - Time complexity: **O(n)**, Space complexity: **O(1)**.
