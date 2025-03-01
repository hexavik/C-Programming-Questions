# Heap Metadata Inspector

**Problem Statement:**

Design and implement a **Heap Metadata Inspector** in C that simulates heap memory allocation. The program should maintain metadata for each block—tracking size, usage status, and addresses—and provide a function to inspect and print the current state of the heap.

**Requirements:**

- Use an **array** to simulate the heap.
- Metadata structure should have the following fields:
  - Block size (in bytes)
  - Is free (boolean indicating whether the block is allocated or free)
  - Address (unique identifier or index representing the start of the block)
- Functions:
  - Allocate (size): Adds a new block with the specified size of the heap.
  - Free (address): Marks the block at the given address as free.
  - Inspect: Iterrates through the heap and prints the status of all blocks.

**Input:**

A series of commands to allocate, free, and inspect memory.

```bash
Allocate 5
Allocate 2
Free 2
Inspect
```

**Output:**

The **Inspect** command should output each block;s status like this:

```bash
Block 1: Used, size: 5
Block 2: Free, size: 2
```

**Constraints:**

- Maximum of **100 blocks** in the simulated heap.
- Block sizes range from **1 to 1024 bytes**.
- Address is represented by the order of allocation (incremental, starting from 1).
- Freeing a non-existent or already free block should print a warning.

```bash
Error: Invalid free operation at address <address>
```

> [!NOTE]
>
> - Use a simple struct for heap blocks:
>
> ```bash
> typedef struct {
>     int size;       // size of the block
>     bool isFree;    // False - used, true - free
>     int address;    // unique block ID
> } HeapBlocks;
> ```
>
> - **Algorithm:**
>   - **Allocate:** Find the next free slot in the array, set size and address, and mark as used.
>   - **Free:** Locate the block by address and mark it as free.
>   - **Inspect:** Iterate through all blocks and print their metadata.
> - **Edge cases:**
>   - Allocating more blocks than the maximum limit.
>   - Freeing a block that was never allocated.
>   - Running **Inspect** when the heap is empty.
> - **Optimization:** Consider adding **coalescing** to merge adjacent free blocks, simulating real-world heap optimizations.

> [!IMPORTANT]
>
> The addresses used in this program are just for simple understanding. They are not representing any addressing technique used in real-time.
