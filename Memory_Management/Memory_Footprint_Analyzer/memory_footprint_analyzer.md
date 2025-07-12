# Memory Footprint Analyzer

## Problem Statement

Develop a program that calculates and reports the memory footprint (in bytes) of various data types — including primitive types (like `int`, `float`, `double`) and user-defined types (like `struct` or `union`). This helps understand how much memory is consumed by different constructs.

## Requirements

- Use the `sizeof` operator to determine the size of any type.
- Support standard primitive types and custom user-defined types (structs/unions).
- Display the memory footprint in bytes.
- Should be easily extendable to add new data types.

## Input

A list of data types to analyze (primitive and user-defined).

```bash
int
float
double
struct Point { int x; int y; }
union Data { int i; float f; char c; }
```

## Output

Memory size (in bytes) of each type provided.

```bash
int: 4 bytes
float: 4 bytes
double: 8 bytes
struct Point: 8 bytes
union Data: 4 bytes

```

## Constraints

- Platform-dependent: Sizes may vary across architectures.
- For user-defined types, the structure must be defined before analysis.
- Padding and alignment may affect the final reported size.

> [!NOTE]
>
> - This tool is useful for understanding memory layout, optimizing embedded systems, and debugging alignment issues.
> - Optionally, display field-wise breakdown of struct size and padding (advanced).
> - Can be extended to work with dynamic types via macros or generic functions.
