/**
 * @file queue.h
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @date 2025-02-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} queue;

/**
 * @brief Initializes the queue with front at -1 and rear at 0.
 * 
 */
void initialize_queue(queue * );

/**
 * @brief Checks if the queue is empty or not
 * 
 * @return true 
 * @return false 
 */
bool is_empty(queue * );

/**
 * @brief Checks if the queue is full or not
 * 
 * @return true 
 * @return false 
 */
bool is_full(queue * );

/**
 * @brief Gets the current value at the front
 * 
 * @return int 
 */
int peek(queue * );

/**
 * @brief Inserts an item inside the queue at the rear
 * 
 * @param item integer to be inserted
 */
void enqueue(queue * , int item);

/**
 * @brief Removes an item from the queue at the front
 * 
 */
void dequeue(queue * );

#endif /* QUEUE_H */
