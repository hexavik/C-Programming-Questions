# CPU Scheduling Algorithm

**Problem Statement:**

Implement a basic CPU scheduling algorithm like **Round Robin**. The program should use a queue to manage processes and simulate the CPU scheduler, computing turnaround and waiting times for each process.

**Requirements:**

- Implement Round Robin scheduling with a fixed **time quantum**.
- Use a queue to manage the execution order of processes.
- Calculate **Turnaround Time (TAT)** and **Waiting Time (WT)** for each process.
- Display a **Gantt Chart** or a summary of process execution order
- Handle cases where a process requires multiple CPU bursts due to the time quantum limitation

**Input:**

- A list of processes, each with a **process ID**, **burst time**, and optionally an **arrival time**.
- A **time quantum** value.

```bash
Processes: P1, P2, P3
Burst Times: [10, 5, 8]
Time Quantum: 2
```

**Output:**

- **Turnaround Time (TAT)** for each process.
- **Waiting Time (WT)** for each process.
- **Average Turnaround Time** and **Average Waiting Time**.
- Execution order of processes in a **Gantt Chart** format.

```bash
Process Execution Order: P1 -> P2 -> P3 -> P1 -> P3 -> P1
Turnaround Times: [14, 10, 13]
Waiting Times: [4, 3, 5]
Avergae Turnaround Time: 12.33
Avergae Waiting Time: 4.00
```

**Constraints:**

- The time quantum should be greater than zero.
- Processes should be executed in a circular fashion until they complete.
- The program should handle different burst times efficiently.
- Assume all processes arrive at time 0 (for simplicity), but the implementation can be extended for varying arrival times.

> [!NOTE]
>
> - **Approach:**
>   - Use a queue to manage processes.
>   - Process execution happens in time slices defined by the quantum.
>   - If a process’s remaining burst time is greater than the quantum, it is **preempted** and added back to the queue.
>   - When a process finishes execution, calculate **Turnaround Time (TAT)** and **Waiting Time (WT)**.
> - **Edge Cases:**
>   - When all processes have the same burst time.
>   - When the time quantum is larger than the largest burst time.
>   - When only one process is in the queue.
> - **Alternative Scheduling Algorithms:**
>   - FCFS (First Come First Serve)
>   - SJF (Shortest Job First)
>   - Priority Scheduling
>   - Multilevel Queue Scheduling
