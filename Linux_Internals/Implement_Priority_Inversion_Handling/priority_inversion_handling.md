# Priority Inversion Handling Simulation

**Problem Statement:**

Simulate **Priority Inversion**, a situation where a higher-priority thread is blocked by a lower-priority thread holding a shared resource. Implement a solution using techniques such as **Priority Inheritance** to resolve the inversion. The program should use **threads**, **mutexes**, and **synchronization primitives** to demonstrate and fix the issue.

**Requirements:**

- Create three threads with different priorities: **High**, **Medium**, and **Low**.
- Use a **mutex** to simulate a shared resource.
- Demonstrate **priority inversion**, where the **High-priority** thread waits because the **Low-priority** thread holds the resource, and the **Medium-priority** thread preempts the system.
- Implement a solution to resolve the inversion using techniques such as **Priority Inheritance Protocol**.

**Input:**

No user input required; the program will simulate the priority inversion scenario.

**Output:**

Display logs showing the execution order of threads and the impact of priority inversion. Show the corrected behavior after applying the solution.

```bash
[Low] Acquired resource
[High] Waiting for resource
[Medium] Running (preempts Low)
[Low] Released resource (after priority inheritance)
[High] Acquired resource
[High] Completed
```

**Constraints:**

- The solution should be implemented using **POSIX threads (pthreads)**.
- Use **mutexes** and **condition variables** for synchronization.
- Simulate **delays** using `sleep()` to clearly demonstrate the priority inversion.

> [!NOTE]
>
> - Priority Inversion: A scenario where a low-priority thread holds a resource needed by a high-priority thread, while a medium-priority thread blocks the low-priority thread from completing.
> - Priority Inheritance: Temporarily raising the priority of the low-priority thread holding the resource to prevent blocking the high-priority thread.
> - Edge cases to consider:
>   - High-priority thread requests the resource immediately after the low-priority thread.
>   - Multiple threads requesting the same resource.
>   - Sudden termination of a thread during execution.

> [!IMPORTANT]
> I have invested multiple hours to make this work, but I did not get the results I was expecting. I researched for hours and days to understand what I was doing wrong, but I have had no success. I shall work on this again later to verify and understand the correct measures to make this work reliably. I have even attached an analysis document to this folder.
