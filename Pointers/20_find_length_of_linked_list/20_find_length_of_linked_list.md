# Find Length of Linked List Using Double Pointers

## Problem Statement

Design a program that determines the length of a singly linked list using a double pointer (or two-pointer) approach. One pointer moves twice as fast as the other. When the faster pointer reaches the end, the slower one helps track progress or midpoint for optimization.

## Requirements

- Use two pointers: a slow pointer and a fast pointer.
- Count the number of steps while traversing to determine total length.
- The fast pointer helps skip unnecessary comparisons in some cases.

## Input

```bash
Linked List: 1 -> 2 -> 3 -> 4 -> 5
```

## Output

```bash
Length: 5
```

## Constraints

- Linked list can have zero or more nodes.
- Use only pointer-based traversal (no array or indexing).
- Nodes contain integer data.

> [!NOTE]
>
> - Initialize both pointers at the head.
> - Fast moves 2 steps at a time; slow moves 1.
> - Each iteration may increment a counter accordingly.
> - Handle odd and even length cases appropriately.
