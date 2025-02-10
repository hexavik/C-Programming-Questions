/**
 * @file cpu_scheduling_algorithm.c
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @date 2025-02-09
 * 
 * @copyright Copyright (c) 2025
 * 
 * Compile command:
 * $ gcc cpu_scheduling_algorithm.c ../../Components/queue/queue.c -o cpu_scheduling_algorithm
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../Components/queue/queue.h"

/**
 * @brief Calculate the Turn Around Time (TAT) for a process in 
 * scheduling. 
 * It is calculated by Completion Time (CT) - Arrival Time (AT).
 * 
 * @return int 
 */
int get_turnaround_time(int completion_time, int arrival_time) {
    return completion_time - arrival_time;
}

/**
 * @brief Calculate the waiting time (WT) for a process in scheduling. 
 * It is calculated by Turn Around Time (TAT) - Burst Time (BT).
 * 
 * @return int 
 */
int get_waiting_time(int turnaround_time, int burst_time) {
    return (turnaround_time - burst_time);
}

/**
 * @brief Schedule the input processes using the Round Robin 
 * algorithm. This algorithm picks up the process and executes it 
 * either for it's burst time or provided time slice whichever is 
 * smaller. This allows to schedule processes fairly.
 * 
 * @param processes Array of Prcoess IDs
 * @param num_processes Total number of processes
 * @param burst_time Array of Burst Times in accordance to processes
 * @param time_quantum Input time slice value
 * @param arrival Array of Arrival Times in accordance to processes
 */
void round_robin(int * processes, int num_processes, int * burst_time, 
                int time_quantum, int * arrival) {
    // Initialize ready queue
    queue readyq;
    initialize_queue(&readyq);
    
    // Initialize Gantt Queue
    queue gantt;
    initialize_queue(&gantt);

    // Create an array for Turn Around Times
    int * turnaround = (int * )malloc(num_processes * sizeof(int));
    if (!turnaround) {
        printf("ERROR: Memory allocation failed for turn around times.\n");
        return;
    }

    // Create an array for Waiting Times
    int * waiting_time = (int * )malloc(num_processes * sizeof(int));
    if (!waiting_time) {
        free(turnaround);
        turnaround = NULL;
        printf("ERROR: Memory allocation failed for waiting times.\n");
        return;
    }

    // Create another array for storing remaining time for all 
    // processes. Also, initialize them with the burst time.
    int * remaining_time = (int * )malloc(num_processes * sizeof(int));
    if (!remaining_time) {
        free(turnaround);
        turnaround = NULL;
        free(waiting_time);
        waiting_time = NULL;
        printf("ERROR: Memory allocation failed for reamining times.\n");
        return;
    }
    for (int i = 0; i < num_processes; ++i) {
        remaining_time[i] = burst_time[i];
    }

    // Push all the processes into the ready queue
    for (int i = 0; i < num_processes; ++i) {
        if (arrival[i] == 0) {
            enqueue(&readyq, processes[i]);
        }
    }

    if (is_empty(&readyq)) {
        printf("ERROR: Ready queue is empty.\n");
        exit(1);
    }

    int current_process = 0;
    // Initialize the total time sum for getting the completion time
    int current_time = 0;

    // Pick up the process from the ready queue and push it to the
    // gantt queue.
    while (!is_empty(&readyq)) {
        current_process = peek(&readyq);
        dequeue(&readyq);
        enqueue(&gantt, current_process);

        //
        // Check if the remaining time is less than the Time Quantum 
        // or not so that the time slice will be upadted accordingly
        // and add it to the current time.
        //
        if (remaining_time[current_process - 1] > 0) {
            int time_slice = 
                (remaining_time[current_process - 1] <= time_quantum) ?
                remaining_time[current_process - 1] : time_quantum;

            current_time += time_slice;
            remaining_time[current_process - 1] -= time_slice;

            // Calculate the turnaround time and the waiting time for
            // the process if it is completed.
            if (remaining_time[current_process - 1] == 0) {
                turnaround[current_process - 1] = 
                    get_turnaround_time(
                        current_time, 
                        arrival[current_process - 1]);
                waiting_time[current_process - 1] = 
                    get_waiting_time(
                        turnaround[current_process - 1], 
                        burst_time[current_process - 1]);
            } else {
                // Push the prcoess back again into the ready queue
                enqueue(&readyq, current_process);
            }
        }

        // Add processses that arrive during this time slice
        for (int i = 0; i < num_processes; ++i) {
            if (arrival[i] != 0 && arrival[i] <= current_time && (remaining_time[i] == burst_time[i])) {
                enqueue(&readyq, processes[i]);
            }
        }
    }

    float average_turnaround = 0.0f;
    float average_waiting = 0.0f;
    printf("Process Execution Order: ");
    for (int i = gantt.front + 1; i < gantt.rear; ++i) {
        printf("P%d -> ", gantt.items[i]);
    }
    printf("\nTurn Around Times: [");
    for (int i = 0; i < num_processes; ++i) {
        printf("%d, ", turnaround[i]);
        average_turnaround += turnaround[i];
    }
    printf("]\nWaiitng Times: [");
    for (int i = 0; i < num_processes; ++i) {
        printf("%d, ", waiting_time[i]);
        average_waiting += waiting_time[i];
    }
    printf("]\n");
    printf("Avergae Turn Around Time: %f\n", 
        average_turnaround / (float)num_processes);
    printf("Avergae Waiting Time: %f\n", 
        average_waiting / (float)num_processes);

    // Release all dynamic memory
    free(remaining_time);
    remaining_time = NULL;
    free(turnaround);
    turnaround = NULL;
    free(waiting_time);
    waiting_time = NULL;
}

int main() {
    // Prcoess IDs
    int processes[] = {1, 2, 3};
    // Calcalate total count of processes
    int pcount = sizeof(processes) / sizeof(processes[0]);

    // Burst time of all process
    int burst_time[] = {10, 5, 8};

    // Consider the default arrival time for all processes is the same
    int arrival[] = {0, 0, 0};

    // Input Time Quantum
    int quantum = 2;
    if (quantum < 1) {
        printf("ERROR: Invalid Time Quantum value.\n");
        exit(1);
    }

    round_robin(processes, pcount, burst_time, 
        quantum, arrival);

    return 0;
}
