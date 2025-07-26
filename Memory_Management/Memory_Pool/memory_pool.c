#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define \
    pool_allocate(pool_id, size) \
    pool_allocate_internal(pool_id, size, __FILE__, __LINE__, __func__)

#define \
    pool_free(pool_id, address) \
    pool_free_internal(pool_id, address, __FILE__, __LINE__, __func__)

enum {
    MEMORY_SIZE = 1024,
    POOL_COUNT = 3,
};

typedef enum {
    FREE = 0,
    ALLOCATED = 1,
} Access;

typedef struct MemoryBlock {
    void * address;
    size_t size;
    Access access;
    struct MemoryBlock * next;
} MemoryBlock;

typedef struct MemoryPool {
    unsigned char memory[MEMORY_SIZE];
    size_t free_memory;
    MemoryBlock * head;
} MemoryPool;

// Create the multiple memory pools using an array
MemoryPool mem_id[POOL_COUNT];

void update_node(MemoryBlock * node, void * address, size_t size, Access access, MemoryBlock * next) {
    *node = (MemoryBlock){ .address = address, .size = size, .access = access, .next = next };
}

void initialize_pool() {
    for (int i = 0; i < POOL_COUNT; ++i) {
        memset(mem_id[i].memory, 0, MEMORY_SIZE);
        mem_id[i].free_memory = MEMORY_SIZE;
        mem_id[i].head = (MemoryBlock * )malloc(sizeof(MemoryBlock));
        update_node(mem_id[i].head, mem_id[i].memory, MEMORY_SIZE, FREE, NULL);
    }
}

void * pool_allocate_internal(int pool_id, size_t size, const char * file, int line, const char * func) {
    MemoryPool * mempool = &mem_id[pool_id];

    if (size > mempool->free_memory) {
        printf("Insufficient Memory for allocation in %s at %d from %s()\n", file, line, func);
        return NULL;
    }

    MemoryBlock * new_node = (MemoryBlock * )malloc(sizeof(MemoryBlock));
    if (!new_node) {
        printf("malloc failed for new_node in %s at %d from %s()\n", file, line, func);
        return NULL;
    }

    if (mempool->head->size == MEMORY_SIZE) {
        mempool->free_memory = MEMORY_SIZE - size;
        update_node(new_node, (unsigned char * )mempool->memory + size, MEMORY_SIZE - size, FREE, NULL);
        update_node(mempool->head, mempool->memory, size, ALLOCATED, new_node);
        printf("Pool ID %d -> Allocated %zu bytes at address 0x%p\n", pool_id, size, mempool->head->address);
        return mempool->head->address;
    }

    MemoryBlock * curr = mempool->head;
    while (curr) {
        if (curr->size == size && curr->access == FREE) {
            curr->access = ALLOCATED;
            free(new_node);
            printf("Pool ID %d -> Allocated %zu bytes at address 0x%p\n", pool_id, size, curr->address);
            return curr->address;
        }

        if (curr->size > size && curr->access == FREE) {
            update_node(new_node, curr->address + size, curr->size - size, FREE, curr->next);
            update_node(curr, curr->address, size, ALLOCATED, new_node);
            mempool->free_memory -= size;
            printf("Pool ID %d -> Allocated %zu bytes at address 0x%p\n", pool_id, size, curr->address);
            return curr->address;
        }

        curr = curr->next;
    }

    return NULL;
}

void pool_free_internal(int pool_id, void * address, const char * file, int line, const char * func) {
    MemoryPool * pool = &mem_id[pool_id];

    if (address == NULL) {
        printf("Invalid address specified in %s at %d from %s()\n", file, line, func);
        return;
    }

    MemoryBlock * prev = NULL;
    MemoryBlock * curr = pool->head;
    while (curr) {
        if (curr->address == address && curr->access == ALLOCATED) {
            curr->access = FREE;
            pool->free_memory += curr->size;
            if (curr->next != NULL && curr->next->access == FREE) {
                MemoryBlock * temp = curr->next;
                curr->size += curr->next->size;
                curr->next = curr->next->next;
                free(temp);
            }
            if (prev != NULL && prev->access == FREE) {
                MemoryBlock * temp = curr;
                prev->size += curr->size;
                prev->next = curr->next;
                free(temp);
            }
            return;
        }

        if (curr->address == address && curr->access == FREE) {
            printf("Double call of free(), memory block is already free in %s at %d from %s()\n", file, line, func);
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    printf("Address not found to free in %s at %d from %s()\n", file, line, func);
}

void print_pools() {
    for (int i = 0; i < POOL_COUNT; ++i) {
        printf("Pool stats: ID %d | Free size: %zu\n", i, mem_id[i].free_memory);
        MemoryBlock * curr = mem_id[i].head;
        while (curr) {
            printf("0x%p [", curr->address);
            curr->access ? printf("A") : printf("F");
            printf("] (%zu) -> ", curr->size);

            curr = curr->next;
        }
        printf("NULL\n");
    }
    printf("\n");
}

int main() {
    initialize_pool();

    pool_free(1, NULL);

    pool_allocate(1, 500);
    pool_allocate(2, 800);

    print_pools();

    pool_allocate(0, 2000);
    pool_allocate(0, 100);
    pool_allocate(1, 100);

    print_pools();

    return 0;
}
