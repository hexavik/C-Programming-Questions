#include "memory_leak_detector.h"

MemoryBlock * head = NULL;

void * memtrack_malloc_internal(size_t bytes, const char * file, int line, const char * func) {
    void * address = malloc(bytes);
    if (!address) {
        printf("[FAIL] malloc failed at %s:%d (%s)\n", file, line, func);
        return NULL;
    }

    if (head == NULL) {
        head = (MemoryBlock * )malloc(sizeof(MemoryBlock));
        head->address = address;
        head->size = bytes;
        head->file = file;
        head->line = line;
        head->func = func;
        head->next = NULL;

        return address;
    }

    MemoryBlock * new_node = (MemoryBlock * )malloc(sizeof(MemoryBlock));
    if (!new_node) {
        fprintf(stderr, "malloc failed for new block\n");
        return NULL;
    }

    new_node->address = address;
    new_node->size = bytes;
    new_node->file = file;
    new_node->line = line;
    new_node->func = func;
    new_node->next = NULL;

    MemoryBlock * curr = head;
    while (curr->next) {
        curr = curr->next;
    }
    curr->next = new_node;

    return address;
}

void memtrack_free(void * address) {
    MemoryBlock * prev = NULL;
    MemoryBlock * curr = head;
    while (curr) {
        if (curr->address == address) {
            if (prev) {
                prev->next = curr->next;
            } else {
                head = curr->next;
            }
            free(address);
            free(curr);
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    fprintf(stderr, "Unable to find block to free\n");
}

void detect_memory_leak() {
    if (head == NULL) {
        printf("No memory leak found\n");
        return;
    }

    MemoryBlock * curr = head;
    while (curr) {
        fprintf(stderr, "Memory Leak detected at address: %p, from %s() in %s at line %d\n", curr->address, curr->func, curr->file, curr->line);
        curr = curr->next;
    }
}

__attribute__((constructor))
void register_leak_detector() {
    atexit(detect_memory_leak);
}
