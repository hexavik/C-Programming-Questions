# Move a 2D Point Using Pointer Arithmetic

## Problem Statement

Create a structure to represent a 2D point. Implement a function that updates the point's position using pointer arithmetic, based on given x and y deltas.

## Requirements

- Define a struct with `x` and `y` fields.
- Use pointers to access and modify these fields.
- Apply the movement values to the point.

## Input

```bash
Point: (2, 3)  
Move: (1, -1)
```

## Output

```bash
New Point: (3, 2)
```

## Constraints

- Only pointer arithmetic should be used to modify values.
- Assume movement values are integers.
- The struct should be passed by pointer to the function.

> [!NOTE]
>
> - Avoid direct dot (`.`) or arrow (`->`) access in the movement function if you want to strictly follow pointer arithmetic.
> - Ensure memory safety when using pointers.
