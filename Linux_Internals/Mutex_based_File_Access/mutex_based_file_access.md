# Mutex-based File Access

## Problem Statement

Create a multi-threaded program where multiple threads attempt to write to a common file. Use mutexes to prevent race conditions and ensure thread-safe file writing.

## Requirements

- Use `pthread` library for threading.
- Use a `pthread_mutex_t` to protect file writing.
- Each thread should lock the mutex before writing and unlock it after writing.

## Input

Number of threads to create.

```bash
Thread Count: 5
```

## Output

A file containing properly written data from each thread without corruption.

```bash
Output (file content):
Thread 1 wrote this line.
Thread 2 wrote this line.
Thread 3 wrote this line.
Thread 4 wrote this line.
Thread 5 wrote this line.
```

## Constraints

- The file must not have mixed or partial writes from different threads.
- Properly initialize and destroy the mutex.
- Handle file I/O errors and thread joining properly.

> [!NOTE]
>
> - Always lock before writing and unlock *immediately after* writing to minimize the critical section.
> - Using `fprintf` inside the locked section is sufficient if you ensure no other thread writes concurrently.
