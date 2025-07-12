# Memory Offset Calculator

## Problem Statement

Design a function that computes the byte offset of a specific field within a structure. This is useful for understanding memory layout and for implementing low-level data serialization or reflection systems.

## Requirements

- Define a structure with multiple fields.
- Implement a function that returns the offset of a specific field.
- Use the `offsetof` macro (from `<stddef.h>`) or simulate it with manual pointer arithmetic.
- Output the offset in bytes from the beginning of the struct.

## Input

The name of a structure and a field within it.

```bash
Struct A with fields: int a; char b; float x
Requested Field: x
```

## Output

Offset in bytes of the given field from the start of the struct.

```bash
Offset of field 'x' in struct A = 8 bytes
```

## Constraints

- Field name must exist in the structure.
- Padding/alignment rules apply depending on the platform and data type sizes.
- Only plain C structs are supported (no bitfields or unions unless extended).

> [!NOTE]
>
> - `offsetof(struct_type, field)` is the safest and most portable way to retrieve the offset.
> - Manual pointer arithmetic involves casting a null pointer of struct type and computing address difference.
> - Useful for debugging compilers, serialization frameworks, or understanding ABI-level layouts.
