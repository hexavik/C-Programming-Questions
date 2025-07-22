#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

enum {
    POOL_SIZE = 100,
};

typedef enum {
    FREE = 0,
    ALLOCATED = 1,
} BlockStatus;

// Since we need to distribute the memory pool into allocated and
// unallocated (or freed) blocks, we need to utilize the proper data
// structure to make it possible. A Linked List will help us to keep
// a list of nodes of these memory blocks, either allocated or
// unallocated. Imagine the whole memory pool is like a single node
// that is non-allocated. When we allocate memory to it, it will split
// into two parts, one is allocated and another is unallocated, which
// gives us two nodes in the same linked list.
typedef struct MemoryBlock {
    void * address;
    size_t size;
    BlockStatus status;
    struct MemoryBlock * next;
} MemoryBlock;

static uint8_t MemoryPool[POOL_SIZE] = {0};
static MemoryBlock * head = NULL;

void initilize_memory_pool() {
    head = (MemoryBlock * )malloc(sizeof(MemoryBlock));
    if (!head) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    head->address = MemoryPool;
    head->size = POOL_SIZE;
    head->status = FREE;
    head->next = NULL;
}

void allocate_memory(size_t bytes) {
    if (bytes > POOL_SIZE) {
        fprintf(stderr, "Invalid allocation size\n");
        return;
    }

    MemoryBlock * curr = head;
    while (curr) {
        if (curr->size < bytes) {
            curr = curr->next;
            continue;
        }

        if (curr->size == bytes && curr->status == FREE) {
            curr->status = ALLOCATED;
            return;
        }

        MemoryBlock * new_block = (MemoryBlock * )malloc(sizeof(MemoryBlock));
        if (!new_block) {
            fprintf(stderr, "malloc failed in allocate_memory()\n");
            return;
        }

        if (curr->status == FREE) {
            new_block->address = curr->address + bytes;
            new_block->size = curr->size - bytes;
            new_block->status = FREE;
            new_block->next = curr->next;
            curr->size = bytes;
            curr->status = ALLOCATED;
            curr->next = new_block;
            return;
        }

        free(new_block);
        curr = curr->next;
    }

    fprintf(stderr, "Allocation Failed\n");
}

void free_memory(size_t bytes) {
    if (bytes > POOL_SIZE) {
        fprintf(stderr, "Invalid allocation size\n");
        return;
    }

    if (head->size == POOL_SIZE && head->status == FREE) {
        fprintf(stderr, "No memory block to be freed\n");
        return;
    }

    MemoryBlock * curr = head;
    while (curr) {
        if (curr->status == FREE || curr->size < bytes) {
            curr = curr->next;
            continue;
        }

        if (curr->status == ALLOCATED && curr->size == bytes) {
            curr->status = FREE;
            return;
        }

        if (curr->size > bytes && curr->status == ALLOCATED) {
            MemoryBlock * new_block = (MemoryBlock * )malloc(sizeof(MemoryBlock));
            if (!new_block) {
                fprintf(stderr, "malloc failed in allocate_memory()\n");
                return;
            }

            new_block->address = curr->address + bytes;
            new_block->size = curr->size - bytes;
            new_block->status = ALLOCATED;
            new_block->next = curr->next;
            curr->size = bytes;
            curr->status = FREE;
            curr->next = new_block;
            return;
        }
    }

    fprintf(stderr, "Memory free failed\n");
}

void defragment() {
    MemoryBlock * curr = head;
    while (curr) {
        if (curr->status == FREE && curr->next != NULL) {
            MemoryBlock * temp = curr->next;
            if (temp->status == FREE) {
                curr->size += temp->size;
                curr->next = temp->next;
                free(temp);
                printf("Memory defragmented - free blocks consolidated\n");
            } else {
                curr = curr->next;
            }
        } else {
            curr = curr->next;
        }
    }

}

void display_memory() {
    MemoryBlock * curr = head;

    while (curr) {
        printf("[ %p %zu %c ] -> ", curr->address, curr->size, curr->status ? 'A' : 'F');
        curr = curr->next;
    }
    printf("[ NULL ]\n");
}

int main() {
    initilize_memory_pool();
    display_memory();

    allocate_memory(20);
    display_memory();

    allocate_memory(30);
    display_memory();

    free_memory(5);
    display_memory();

    free_memory(20);
    display_memory();

    allocate_memory(10);
    display_memory();

    free_memory(10);
    display_memory();

    free_memory(5);
    display_memory();

    // allocate_memory(5);
    // display_memory();

    defragment();
    display_memory();

    // Free all memory at the end
    while (head) {
        MemoryBlock * temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
