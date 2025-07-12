# Write-Once Memory Simulator

## Problem Statement

Simulate a write-once memory block where each byte can be written only once. Any subsequent writes to the same address must fail.

## Requirements

- Use an array to represent the memory block.
- Use a boolean array of the same size to track write status of each byte.
- Implement a write function that:
  - Checks if the target address has already been written to.
  - If not written, perform the write and mark it as written.
  - If already written, output "Write Failed".

## Input

Sequence of write operations specifying byte value and address.

```bash
Write 0xAA to address 5
Write 0xAA to address 5
```

## Output

Report success or failure of each write operation.

```bash
Write Successful
Write Failed
```

## Constraints

- Address values must be within the memory block size.
- Memory block size is fixed.
- Each byte can be written exactly once.

> [!NOTE]
>
> - Use an array `memory[]` for storing byte values.
> - Use a boolean array `written[]` initialized to false to track if each byte has been written.
> - On write attempt to `address`:
>   - If `written[address] == false`, write byte, set `written[address] = true`.
>   - Else, reject the write and print "Write Failed".
> - This ensures immutability after the first write, simulating write-once memory behavior.
