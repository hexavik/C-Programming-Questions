# Zero-Copy Data Transfer Using Shared Memory

## Problem Statement

Implement a mechanism to transfer data between two processes using shared memory without copying data between the processes. Utilize `mmap()` to map a region of memory that both processes can access, allowing them to transfer data directly.

## Requirements

- Use `mmap()` to create a shared memory region that is accessible by both processes.
- **Process A** *writes data* into the shared memory.
- **Process B** *reads the data* from the shared memory.
- Ensure proper synchronization to prevent race conditions.
- Handle memory cleanup and synchronization between the processes.

## Input

Data to transfer from one process to another using shared memory.

```bash
Process A sends data: "Hello, Process B!"
```

## Output

Process B receives the data from the shared memory and displays it.

```bash
Process B receives data: "Hello, Process B!"
```

## Constraints

- The shared memory should be large enough to hold the data being transferred.
- The processes should synchronize access to the shared memory to avoid race conditions.
- After use, the shared memory region must be properly cleaned up.
- Handle errors like failure to map memory or memory access violations.

> [!NOTE]
>
> - Zero-copy mechanisms avoid unnecessary data copying between user-space and kernel-space by mapping the memory directly between processes.
> - Using `mmap()` allows both processes to access the same physical memory without copying data, making it faster and more efficient.
> - Synchronization can be done using semaphores or mutexes to ensure that both processes access the shared memory in a controlled manner.

---

Here's an outline of how you could implement this in code:

1. **Process A (Writer):**
   - Create a shared memory region using `mmap()`.
   - Write data into the shared memory region.
   - Signal that data is ready for Process B to read.

2. **Process B (Reader):**
   - Attach to the shared memory region using `mmap()`.
   - Read the data from the shared memory.
   - Signal that data has been read and release the shared memory.
