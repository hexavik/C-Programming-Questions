/**
 * @file queue.c
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @date 2025-02-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "queue.h"
#include <stdbool.h>
#include <stdio.h>

void initialize_queue(queue * q) {
    q->front = -1;
    q->rear = 0;
}

int peek(queue * q) {
    return q->items[q->front + 1];
}

bool is_empty(queue * q) {
    if (q->front == q->rear - 1) {
        return true;
    }

    return false;
}

bool is_full(queue * q) {
    if (q->rear == MAX_SIZE - 1) {
        return true;
    }

    return false;
}

void enqueue(queue * q, int item) {
    if (is_full(q)) {
        printf("Queue is full.\n");
        return;
    }

    q->items[q->rear++] = item;
}

void dequeue(queue * q) {
    if (is_empty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    q->front++;
}
