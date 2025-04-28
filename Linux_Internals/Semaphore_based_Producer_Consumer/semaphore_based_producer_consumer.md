# Semaphore-based Producer-Consumer

## Problem Statement

Implement the classic Producer-Consumer problem using POSIX semaphores and threads, where multiple producer threads produce items and multiple consumer threads consume them in a synchronized manner without conflicts.

## Requirements

- Use POSIX semaphores (`sem_t`).
- Use pthreads (`pthread_create`, `pthread_join`).
- Ensure correct synchronization between producers and consumers.

## Input

Number of items to produce and consume.

```bash
Input Example:
Items to produce: 5
Items to consume: 5
```

## Output

Order of item production and consumption with proper synchronization.

```bash
Output Example:
Produced: Item 1
Produced: Item 2
Consumed: Item 1
Produced: Item 3
Consumed: Item 2
Consumed: Item 3
...
```

## Constraints

- The buffer (shared queue) has a limited fixed size.
- Producers must wait if the buffer is full.
- Consumers must wait if the buffer is empty.
- No deadlocks or race conditions allowed.

> [!NOTE]
>
> - Use one semaphore to count empty slots and one to count filled slots.
> - Use a mutex to protect critical sections (like buffer access).
> - This is a standard concurrency control problem — mastering it builds a strong foundation in multithreaded programming.
