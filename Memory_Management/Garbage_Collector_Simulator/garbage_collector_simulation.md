# Garbage Collector Simulator

**Problem Statement:**

Implement a simple **Mark-and-Sweep Garbage Collector** in C. The simulator should allow dynamic memory allocation, marking of live objects, and garbage collection by sweeping unmarked blocks.

**Requirements:**

- Use **linked list** or **array** to keep track of all allocated mmemory blocks for **memory representation**.
- **Block Structure**: Each block should have
  - Size (bytes)
  - Marked (boolean flag indicating if the block is still in use)
  - Pointer to next block (if using a linked list)
- **Functions**:
  - Allocate (size): Add a new memory block to the list.
  - Mark (address): Mark a block as "in use" by setting its flag.
  - Sweep: Free all unmarked blocks and unmark the rest.
- Display which block were collected or preserved during the sweep as an output.

**Input:**

A series of commands, one per line:

- **Allocate** `<size>`: Requests memory allocation.
- **Mark** `<address>`: Marks the memory block at the given address.
- **Sweep**: Runs garbage collection.

```bash
Allocate 5
Allocate 7
Mark 5
Sweep
```

**Output:**

After each command, print the corresponding result:

- Allocate: "Allocated <size> bytes at address <address>"
- Mark: "Marked block at address <address>"
- Sweep: "Collected <size> bytes at address <address>" for each freed block.

```bash
Allocated 5 bytes at address 1001
Allocated 7 bytes at address 1002
Marked block at adress 1001
Collected 7 bytes at adress 1002
```

**Constraints:**

- Maximum of **100 allocated blocks** at a time.
- Block size range from **1 to 1024 bytes**.
- Addresses can be represented using incremental integers starting from **1000**.
- The program should handle invalid commands gracefully.

> [!NOTE]
>
> - Use a simple **linked list** for dynamic allocation tracking.
> - **Algorithm:**
>   - **Mark**: Iterate through the list and set the marked flag for the specified block.
>   - **Sweep**: Iterate through the list, free unmarked blocks, and reset the marked flag for all remaining blocks.
> - **Edge cases:**
>   - Sweeping when no blocks are allocated.
>   - Attempting to mark a non-existent address.
>   - Repeated sweeps with no new allocations.
> - Optimization:
>   - Consider adding a **root set** or **stack simulation** to track which objects should automatically be marked (for more complex GC systems).
