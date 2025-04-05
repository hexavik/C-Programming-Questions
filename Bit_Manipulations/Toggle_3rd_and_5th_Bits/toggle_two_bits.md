# Toggle 3rd and 5th Bits of an 8-bit Number

## Problem Statement

Given an 8-bit number, toggle (i.e., flip) the **3rd and 5th bits**, counting from the least significant bit (rightmost is position 0).

## Input

```bash
0b10100101
```

## Output

```bash
0b10000101
```

## Constraints

- Use XOR (`^`) with a mask that has `1` at positions 3 and 5.
- Bit mask:
  - Bit 3 → `1 << 3 = 0b00001000`
  - Bit 5 → `1 << 5 = 0b00100000`
  - Combined mask: `0b00101000`

## Bonus Challenge

- Generalize to toggle any arbitrary set of bits.
- Try writing a reusable function: `toggle_bits(num, positions)`.

> [!NOTE]
>
> - Toggling a bit means flipping 1 → 0 and 0 → 1.
> - XOR with `1` does exactly that for each bit.
