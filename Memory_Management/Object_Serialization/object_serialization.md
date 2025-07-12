# Object Serialization and Deserialization

## Problem Statement

Implement functions to serialize an object into a byte array and deserialize the byte array back into the original object representation.

## Requirements

- Convert each field of the object into its byte representation.
- Concatenate the byte representations of all fields to form the serialized byte array.
- Parse the byte array during deserialization to reconstruct the object fields correctly.

## Input

An object with multiple fields (e.g., integers, floats, or other primitive types).

```bash
Object {a: 1, b: 2}
```

## Output

A byte array representing the serialized object or an object reconstructed from the byte array.

```bash
Output Example (Serialization):
[00 00 00 01 00 00 00 02]  // Byte array representing fields a=1, b=2

Output Example (Deserialization):
Object {a: 1, b: 2}
```

## Constraints

- The serialization format should preserve field order and type information implicitly or explicitly.
- Assume fixed-size primitive fields for simplicity (e.g., 4 bytes for int).
- Handle endianness consistently across serialization and deserialization.

> [!NOTE]
>
> - Serialization can be done by casting fields to byte pointers or using bit shifts.
> - Deserialization involves reading fixed-size chunks and converting back to original data types.
> - For more complex objects, consider adding field length headers or type metadata.
> - This problem mimics concepts behind formats like JSON, Protocol Buffers, or FlatBuffers but in a simplified binary form.
