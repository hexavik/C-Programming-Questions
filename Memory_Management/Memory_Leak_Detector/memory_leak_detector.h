#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define \
    memtrack_malloc(size) \
    memtrack_malloc_internal(size, __FILE__, __LINE__, __func__)

/**
 * @brief Structure for a linked list node which stores the memory
 * block members. Each time user allocates memory using malloc will
 * be recorded as node, and will be removed from the list at the time
 * of free() call.
 *
 */
typedef struct MemoryBlock {
    void * address;  // Pointer at which malloc allocated memory block
    size_t size;  // Total number of bytes allocated
    const char * file;  // Filename for the debugging purpose
    int line;  // Line number for the debugging purpose
    const char * func;  // Function name for the debugging purpose
    struct MemoryBlock * next;  // Pointer to the next node
} MemoryBlock;

/**
 * @brief A wrapper for standard malloc() which will create a node
 * of a memory block and add it in the linked list at the end of it.
 * User must call `memtarck_malloc()` which is declared at the top
 * for the retrieving the filename, line number, and the function name
 * from which this function would be called (for easy denbugging
 * purpose).
 *
 * @param size Number of bytes to be allocated
 * @param file Filename in which this functin has called
 * @param line Line number at which this function has called
 * @param func Function from which this function has called
 * @return void* Pointer or address to the offset the memory allocated
 */
void * memtrack_malloc_internal(size_t size, const char * file, int line, const char * func);

/**
 * @brief A wrapper for standard free() which will remove the node
 * from the linked list based on the address at which memory has been
 * deallocated. It will throw a warning if called more than once for a
 * deallocated memory block.
 *
 * @param address Pointer to the memory block
 */
void memtrack_free(void * address);

/**
 * @brief At the end of the program this function called to verify
 * whether all the memory blocks are deallocated or not. This is done
 * by chekcing if there any nodes available in the linked list.
 *
 */
void detect_memory_leak();

/**
 * @brief At normal end of the main(), leak detection is executed
 * automatically by calliong detect_memory_leak(). This won't call
 * at the time of `exit()` occurs.
 *
 */
__attribute__((constructor))
void register_leak_detector();
