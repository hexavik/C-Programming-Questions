/**
 * @file garbage_collector_simulation.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-02-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BLOCKS 100
#define MAX_BLOCK_SIZE 1024
#define DEFAULT_ADDRESS 1001

typedef struct MemoryBlock {
    int address;
    size_t size;
    bool marked;
    struct MemoryBlock * next;
} MemoryBlock;

// Global link list for storing allocated blocks
MemoryBlock * head = NULL;
// Counts the number of blocks created
int block_count = 0;

/**
 * @brief Create a new block in a linked list and allocate the memory 
 * to it, along with updating the size within the structure.
 * 
 * @param size Input size in bytes
 */
void allocate(size_t size) {
    if (size > MAX_BLOCK_SIZE) {
        fprintf(stderr, "ERROR: Input size exceeds maximum allowed block size %d.\n", MAX_BLOCK_SIZE);
        return;
    }

    if (block_count >= MAX_BLOCKS) {
        fprintf(stderr, "ERROR: Maximum block count reached.\n");
        return;
    }

    MemoryBlock * current = head;

    // Allocate the memory to the first block (head)
    if (head == NULL) {
        head = (MemoryBlock * )malloc(sizeof(MemoryBlock));
        if (!head) {
            perror("malloc failed");
            exit(EXIT_FAILURE);
        }
        head->address = DEFAULT_ADDRESS;
        head->size = size;
        head->marked = false;
        head->next = NULL;
        ++block_count;
        printf("Allocated %zu bytes at address %d\n", size, head->address);
        return;
    }

    // Traverse to the end of the list
    while (current->next) {
        current = current->next;
    }

    // Allocate new block
    MemoryBlock * new_block = (MemoryBlock * )malloc(sizeof(MemoryBlock));
    if (!new_block) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    new_block->address = current->address + 1;
    new_block->size = size;
    new_block->marked = false;
    new_block->next = NULL;
    ++block_count;
    current->next = new_block;
    printf("Allocated %zu bytes at address %d\n", size, new_block->address);
}

/**
 * @brief Marks a block by providing the corresponding address of it.
 * 
 * @param address 
 */
void mark(int address) {
    MemoryBlock * current = head;

    while (current) {
        printf("Current Address: %d | address: %d\n", current->address, address);
        if (current->address == address) {
            current->marked = true;
            printf("Marked a block at address %d\n", current->address);
            return;
        }

        current = current->next;
    }

    printf("Address %d not found to mark.\n", address);
}

/**
 * @brief Collects the memory blocks from the unmarked blocks. This 
 * function also resets the current mark status for the next cycle.
 * 
 */
void sweep() {
    if (block_count == 0) {
        fprintf(stderr, "ERROR: No blocks available to sweep.\n");
        return;
    }

    MemoryBlock * current = head;
    MemoryBlock * prev = NULL;

    while (current) {
        if (!current->marked) {
            printf("Collected %zu bytes at address %d\n", current->size, current->address);
            if (prev) {
                // Unlink the block
                prev->next = current->next;
            } else {
                // Updatye head if first block is collected
                head = current->next;
            }
            MemoryBlock * temp = current;
            current = current->next;
            free(temp);
            --block_count;
        } else {
            // Reset mark status for next cycle
            current->marked = false;
            prev = current;
            current = current->next;
        }
    }
}

int main() {
    allocate(5);
    allocate(7);
    mark(1001);
    sweep();

    return 0;
}
