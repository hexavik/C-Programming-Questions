# Thread Creation and Synchronization

## Problem Statement

Create a program that spawns multiple threads and synchronizes their access to a shared resource using mutexes to avoid race conditions.

## Requirements

- Use `pthread_create()` to create multiple threads.
- Use `pthread_mutex_lock()` and `pthread_mutex_unlock()` to synchronize access to critical sections.
- Ensure threads execute safely without data corruption.

## Input

Number of threads to create.

```bash
Input Example:
Enter number of threads: 3
```

## Output

Threads printing their IDs or messages in a synchronized (non-interleaved) manner.

```bash
Output Example:
Thread 1 executing
Thread 2 executing
Thread 3 executing
```

## Constraints

- Ensure proper thread joining using `pthread_join()`.
- Mutex must protect all shared data access.
- Threads must not interleave their critical section outputs.

> [!NOTE]
>
> - Without mutexes, outputs from threads may overlap, leading to inconsistent results.
> - Proper mutex usage enforces serialized access to shared resources.
