/**
 * @file memory_bound_priority_queue.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-20
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdint.h>
#include <stdio.h>

enum {
    FIXED_SIZE = 50,
};

int top = 0;

/**
 * @brief Display priority queue, where the left most element is at
 * 0th index.
 *
 * @param queue Integer Queue in array format
 */
void display_queue(int * queue) {
    printf("[");
    for (int i = 0; i < top; ++i) {
        printf("%d", queue[i]);
        if (i < top - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void swap(int * a, int * b) {
    //printf("swapping: %d %d\n", *a, *b);
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Compares the recently inserted element inside the queue
 * and swaps it with it's parent node in case parent node has smaller
 * value.
 *
 * @param queue Integer Queue in array format
 */
void heapify_up(int * queue, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (queue[parent] < queue[index]) {
            swap(&queue[parent], &queue[index]);
            index = parent;
        } else {
            break;
        }
    }
}

/**
 * @brief Builds Max-Heap Binary Tree after removal of the largest 
 * element.
 * 
 * @param queue 
 */
void heapify_down(int * queue) {
    int node = 0;
    while (1) {
        int left = 2 * node + 1;
        int right = 2 * node + 2;
        int largest = node;

        if (left < top && queue[left] > queue[largest]) {
            largest = left;
        }
        if (right < top && queue[right] > queue[largest]) {
            largest = right;
        }
        if (largest != node) {
            swap(&queue[node], &queue[largest]);
            node = largest;
        } else {
            break;
        }
    }
}

/**
 * @brief Insert the data (as a priority) into the priority queue.
 *
 * @param queue Integer Queue in array format
 * @param data
 */
void prio_enqueue(int * queue, int data) {
    if (top == FIXED_SIZE) {
        fprintf(stderr, "Error: Queue is full.\n");
        return;
    }

    if (top == 0) {
        *(queue) = data;
        top++;
        return;
    }

    // Insert an element at the end of the queue
    // Swap upwards until heap priority is maintined.
    *(queue + top) = data;
    top++;

    heapify_up(queue, top - 1);
}

/**
 * @brief Removes the data with high value (considered as priority)
 * and sorts the queue in binary max-heap algorithm again.
 *
 * @param queue Integer Qeueue in array format
 */
void prio_dequeue(int * queue) {
    if (top == 0) {
        fprintf(stderr, "Error: Queue is empty.\n");
        return;
    }

    if (top == 1) {
        queue[0] = 0;
        top--;
        return;
    }

    // Swap root with last element
    // Reduce size and restore heap by bubbling down
    swap(&queue[0], &queue[top - 1]);
    top--;
    printf("Removed: %d | ", queue[top]);
    queue[top] = 0;

    heapify_down(queue);
}

int main() {
    // Create an array of fixed size
    int queue[FIXED_SIZE];

    prio_enqueue(queue, 5);
    prio_enqueue(queue, 9);
    prio_enqueue(queue, 2);

    display_queue(queue);

    prio_dequeue(queue);

    display_queue(queue);

    return 0;
}
