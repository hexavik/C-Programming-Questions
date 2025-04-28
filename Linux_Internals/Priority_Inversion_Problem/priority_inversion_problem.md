# Priority Inversion Problem with Priority Inheritance

## Problem Statement

Simulate a scenario where a low-priority thread holds a mutex needed by a high-priority thread, causing *priority inversion*. Then, implement *priority inheritance* to solve it, allowing the low-priority thread to inherit higher priority temporarily.

## Requirements

- Use `pthread` library for threading.
- Assign different priorities to threads using `pthread_setschedparam`.
- Use mutex attributes to enable priority inheritance (`PTHREAD_PRIO_INHERIT`).

## Input

Priorities assigned to three threads:

- High-priority thread (wants the mutex)
- Low-priority thread (holds the mutex)
- Medium-priority thread (competes for CPU)

```bash
High Priority: 80
Medium Priority: 50
Low Priority: 20
```

## Output

The execution sequence showing priority inversion and its resolution through priority inheritance.

```bash
Output (example flow):
Low-priority thread acquires mutex.
High-priority thread waiting on mutex.
Medium-priority thread preempted.
Low-priority thread inherits high-priority.
Low-priority thread releases mutex.
High-priority thread acquires mutex.
```

## Constraints

- The operating system must support real-time scheduling (`SCHED_FIFO` or `SCHED_RR`).
- Priority inheritance must be enabled on mutexes explicitly.
- Threads must properly handle mutex locking and unlocking.

> [!NOTE]
>
> - Without priority inheritance, the medium-priority thread would keep running, delaying the high-priority thread (*classic inversion*).
> - With priority inheritance, the low-priority thread is boosted, quickly finishing its task and releasing the mutex.
