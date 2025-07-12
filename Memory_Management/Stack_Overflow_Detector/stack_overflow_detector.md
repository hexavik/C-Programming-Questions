# Stack Overflow Detector

## Problem Statement

Implement a stack data structure with overflow detection. When pushing elements, detect if the stack exceeds its maximum size and report "Stack Overflow".

## Requirements

- Define a stack with a fixed maximum size.
- Implement `push` and `pop` functions.
- On each `push`, check if the stack is full. If full, output "Stack Overflow".
- Maintain a count of the current number of elements.

## Input

Sequence of push operations exceeding the stack's capacity.

```bash
Stack size = 9
Push 10 items
```

## Output

Output message on overflow during push operation.

```bash
Stack Overflow
```

## Constraints

- Stack maximum size is fixed and known.
- Overflow detection must happen before adding a new element.
- No dynamic resizing allowed.

> [!NOTE]
>
> - Keep an integer variable (e.g., `top` or `count`) to track the number of elements.
> - If `top` equals or exceeds max size, reject push with overflow message.
> - Pop operations reduce the count and allow further pushes.
