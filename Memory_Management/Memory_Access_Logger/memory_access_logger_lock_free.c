#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdatomic.h>

enum {
    SIZE = 100,
    MAX_LOGS = 50,
};

int8_t memory[SIZE] = {0};

typedef struct {
    uint16_t address;
    char access; // 'R' or 'W'
    atomic_bool valid; // true once fully written
} LogEntry;

static LogEntry mLog[MAX_LOGS];
static atomic_uint log_index = 0;

void log_memory_access(uint16_t address, char access) {
    int idx = atomic_fetch_add(&log_index, 1) % MAX_LOGS;

    // Invalidate this slot before writing
    // We could use simple atomic_store() here but since we are
    // executing two more sentences after this, so to avoid the race
    // conditions due to compiler or CPU might reorder writes, we are
    // using memory_oder_relaxed and memory_order_release
    atomic_store_explicit(&mLog[idx].valid, false, memory_order_relaxed);

    mLog[idx].address = address;
    mLog[idx].access = access;

    // Atomically mark as valid
    atomic_store_explicit(&mLog[idx].valid, true, memory_order_release);
}

int8_t write_to_address(uint16_t address, int8_t data) {
    if (address >= SIZE) {
        fprintf(stderr, "Invalid Address.\n");
        return -1;
    }

    *(memory + address) = data;

    log_memory_access(address, 'W');
    return 0;
}

int8_t read_from_address(uint16_t address) {
    if (address >= SIZE) {
        fprintf(stderr, "Invalid Address.\n");
        return -1;
    }

    log_memory_access(address, 'R');
    return *(memory + address);
}

void display_memory_log() {
    printf("Log Start:\n");
    for (int i = 0; i < MAX_LOGS; ++i) {
        if (atomic_load_explicit(&mLog[i].valid, memory_order_acquire)) {
            printf("[LOG] ");
            mLog[i].access == 'R' ? printf("Read from ") : printf("Write to ");
            printf("address %d", mLog[i].address);
            mLog[i].access == 'R' ? printf("\n") : printf(": %d\n", memory[mLog[i].address]);
        }
    }
    printf("\n");
}

int main() {
    display_memory_log();

    write_to_address(5, 42);
    read_from_address(5);
    write_to_address(10, 99);

    display_memory_log();

    return 0;
}
