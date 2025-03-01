/**
 * @file heap_metadata_inspector.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-03-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <stdbool.h>

enum limits {
    MAX_HEAP_BLOCK = 100,
    MAX_HEAP_BLOCK_SIZE = 1024,
    INITIAL_ADDRESS = 1
};

typedef struct {
    size_t size;
    bool isFree;
    int address;
} HeapBlock;

HeapBlock gHeapBlock[MAX_HEAP_BLOCK] = {0};
int index_counter = 0;

/**
 * @brief Display the simple memory information in following format:
 * Block <number>: address: <address>, <Used or Free>, size: <size in bytes>
 * 
 */
void inspect() {
    printf("Memory State:\n");
    for (int i = 0; i < index_counter; ++i) {
        printf("Block %d: address: %d, %s, size: %zu\n", 
               i + 1, 
               gHeapBlock[i].address, 
               gHeapBlock[i].isFree ? "Free" : "Used", 
               gHeapBlock[i].size);
    }
    printf("\n");
}

/**
 * @brief Allocates the block of memory into an array representing
 * heap memory blocks.
 * 
 * @param size desired size of the block
 */
void allocate(size_t size) {
    if (index_counter == MAX_HEAP_BLOCK) {
        fprintf(stderr, "Maximum limit of allocation is reached.\n");
        return;
    }

    // check for a free block that cxan fit the size
    for (int i = 0; i < index_counter; ++i) {
        if (gHeapBlock[i].isFree && gHeapBlock[i].size >= size) {
            // Split the block if larger than required
            if (gHeapBlock[i].size > size) {
                for (int j = index_counter; j > i; --j) {
                    gHeapBlock[j] = gHeapBlock[j - 1];
                    gHeapBlock[j].address++;
                }
                gHeapBlock[i + 1].size = gHeapBlock[i].size - size;
                gHeapBlock[i + 1].address = gHeapBlock[i].address + 1;
                gHeapBlock[i + 1].isFree = true;
                index_counter++;
            }

            gHeapBlock[i].size = size;
            gHeapBlock[i].isFree = false;
            inspect();
            return;
        }
    }

    // Allocate a new block at the end of the current index
    gHeapBlock[index_counter].size = size;
    gHeapBlock[index_counter].isFree = false;
    gHeapBlock[index_counter].address = INITIAL_ADDRESS + index_counter;
    index_counter++;

    inspect();
}

/**
 * @brief Releases the block of memory from an array and coalesces 
 * with the adjacent memory blocks if they are free.
 * 
 * @param address 
 */
void freeblock(int address) {
    for (int i = 0; i < index_counter; ++i) {
        if (gHeapBlock[i].address == address) {
            if (gHeapBlock[i].isFree == true) {
                fprintf(stderr, "Block is already free.\n");
                return;
            }
            gHeapBlock[i].isFree = true;

            // Merge previous block if it is free
            if (i > 0 && gHeapBlock[i - 1].isFree == true) {
                gHeapBlock[i - 1].size += gHeapBlock[i].size;
                // Shift all further blocks to left
                for (int j = i; j < index_counter; ++j) {
                    gHeapBlock[j] = gHeapBlock[j + 1];
                    gHeapBlock[j].address -= 1;
                }
                index_counter--;
            }

            // Merge next block if it is free
            if (i < index_counter - 1 && gHeapBlock[i + 1].isFree == true) {
                gHeapBlock[i + 1].size += gHeapBlock[i].size;
                // Shift all further blocks to left
                for (int j = i; j < index_counter; ++j) {
                    gHeapBlock[j] = gHeapBlock[j + 1];
                    gHeapBlock[j].address -= 1;
                }
                index_counter--;
            }

            inspect();
            return;
        }
    }

    fprintf(stderr, "Block at address %d not found.\n", address);
}

int main() {
    allocate(10);
    allocate(20);
    freeblock(1);
    allocate(5);
    allocate(30);
    freeblock(3);

    return 0;
}
