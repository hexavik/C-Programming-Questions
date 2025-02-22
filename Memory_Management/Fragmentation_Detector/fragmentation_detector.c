/**
 * @file fragmentation_dectector.c
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @date 2025-02-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024  // Fixed size buffer

/**
 * @brief Linked List for storing memory blocks created.
 * 
 */
typedef struct MemoryBlock {
    void * address;
    size_t size;
    int is_allocated;
    struct MemoryBlock * next;
} MemoryBlock;

static char memory_pool[POOL_SIZE];
static MemoryBlock * head = NULL;

/**
 * @brief Initialize with assigning the first block of memory in a
 * linked list. This also assigns the fixed size to the memory
 * pool, it is considered as the free available memory.
 * 
 */
void initialize_memory_pool() {
    head = (MemoryBlock * )malloc(sizeof(MemoryBlock));
    if (!head) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    head->address = memory_pool;
    head->size = POOL_SIZE;
    head->is_allocated = 0;
    head->next = NULL;
}

/**
 * @brief Calculates the total fragmentation in a fixed memory pool.
 * It is calculated by using Total Free Space - Largest Free Block.
 * 
 * @return size_t 
 */
size_t calculate_fragmentation() {
    size_t total_free_space = 0;
    size_t largest_free_block = 0;
    MemoryBlock * current = head;

    while (current) {
        if (!current->is_allocated) {
            total_free_space += current->size;
            if (current->size > largest_free_block) {
                largest_free_block = current->size;
            }
        }
        current = current->next;
    }

    return total_free_space - largest_free_block;
}

/**
 * @brief Display the current memory state or memory map of the total
 * available fixed size memory pool.
 * 
 */
void display_memory() {
    MemoryBlock * current = head;

    printf("Memory State:\n");
    while (current) {
        printf("Address: %p, Size: %zu, %s\n", 
               current->address, current->size, 
               current->is_allocated ? "Allocated" : "Free");
        current = current->next;
    }
    printf("Fragmentation: %zu\n\n", calculate_fragmentation());
}

/**
 * @brief Custom function for allocating a block of memory to a linked
 * list node.
 * 
 * @param size size of the memory block to be allocated
 * @return void* Pointer to the memory assigned by malloc
 */
void * allocate_memory(size_t size) {
    MemoryBlock * current = head;
    MemoryBlock * prev = NULL;

    while (current) {
        if (!current->is_allocated && current->size >= size) {
            if (current->size > size) {
                MemoryBlock * new_block = (MemoryBlock * )malloc(sizeof(MemoryBlock));
                if (!new_block) {
                    perror("malloc failed");
                    exit(EXIT_FAILURE);
                }
                new_block->address = current->address + size;
                new_block->size = current->size - size;
                new_block->is_allocated = 0;
                new_block->next = current->next;

                current->size = size;
                current->next = new_block;
            }
            current->is_allocated = 1;
            display_memory();
            return  current->address;
        }

        current = current->next;
    }

    printf("Memory allocation failed\n");
    return NULL;
}

/**
 * @brief Custom function for releasing a block of memory from the 
 * available allocated linked list nodes.
 * 
 * @param address Valid address of the linked list node
 */
void free_memory(void * address) {
    MemoryBlock * current = head;
    MemoryBlock * prev = NULL;

    while (current) {
        if (current->address == address && current->is_allocated) {
            current->is_allocated = 0;

            // Coalesce with next block if it's free
            if (current->next && !current->next->is_allocated) {
                MemoryBlock * next = current->next;
                current->size += next->size;
                current->next = next->next;
                free(next);
            }
            // Coalesce with previous block if it's free
            if (prev && !prev->is_allocated) {
                prev->size += current->size;
                prev->next = current->next;
                free(current);
                current = prev;
            }
            display_memory();
            return;
        }

        prev = current;
        current = current->next;
    }

    fprintf(stderr, "Invalid free request\n");
    display_memory();
}

int main() {
    initialize_memory_pool();
    display_memory();

    void * b1 = allocate_memory(100);
    void * b2 = allocate_memory(100);
    free_memory(b1);
    void * b3 = allocate_memory(50);

    free_memory(b2);
    free_memory(b3);

    return 0;
}
