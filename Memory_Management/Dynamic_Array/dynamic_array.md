# Dynamic Array

## Problem Statement

Implement a **dynamic array** that can automatically **resize itself** as elements are added or removed.

## Requirements

- Start with an initial fixed size for the array.
- When adding an element:
  - If the array is **full**, allocate a **larger memory block** and copy the existing elements.
- When removing an element:
  - If the array is **less than half full**, shrink its size to optimize memory usage.
- Use **malloc** and **free** (or a custom allocator) for dynamic memory management.
- Support basic operations like **insertion**, **deletion**, and **accessing elements**.
- Ensure efficient **resizing strategy** (e.g., doubling size on expansion, halving on shrink).

## Input

A series of operations such as inserting or removing elements.

```bash
Add: 5, 10, 15, 20
Remove: 10
```

## Output

The updated state of the dynamic array after operations.

```bash
Dynamic array: [5, 15, 20]
```

## Constraints

- The array should handle **dynamic resizing efficiently** to balance performance and memory usage.
- Ensure **O(1) average time complexity** for adding/removing elements.
- Avoid unnecessary memory allocations and deallocations.

> [!NOTE]
>
> - Consider implementing a **growth factor (e.g., 2x size expansion)** to reduce frequent reallocations.
> - Ensure **memory safety** by handling allocation failures gracefully.
> - Support **random access** to elements like a standard array.
