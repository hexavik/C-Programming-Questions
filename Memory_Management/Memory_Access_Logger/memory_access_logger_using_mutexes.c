#include <stdint.h>
#include <stdio.h>
#include <pthread.h>

enum {
    SIZE = 100,
    MAX_LOGS = 50,
};

typedef enum {
    WRITE,
    READ,
} AccessType;

int8_t memory[SIZE] = {0};
uint16_t log_index = 0;
pthread_mutex_t lock;

typedef struct {
    uint16_t address;
    AccessType access;
} LogEntry;

void log_memory_access(LogEntry *mLog, uint16_t address, AccessType access) {
    if (log_index == MAX_LOGS) {
        fprintf(stderr, "Maximum entries limit reached.\n");
        return;
    }

    mLog[log_index].address = address;
    mLog[log_index].access = access;
    log_index += 1;
}

int8_t write_to_address(LogEntry *mLog, uint16_t address, int8_t data) {
    pthread_mutex_lock(&lock);
    if (address >= SIZE) {
        fprintf(stderr, "Invalid Address.\n");
        pthread_mutex_unlock(&lock);
        return -1;
    }

    *(memory + address) = data;

    log_memory_access(mLog, address, WRITE);
    pthread_mutex_unlock(&lock);
    return 0;
}

int8_t read_from_address(LogEntry *mLog, uint16_t address) {
    pthread_mutex_lock(&lock);
    if (address >= SIZE) {
        fprintf(stderr, "Invalid Address.\n");
        pthread_mutex_unlock(&lock);
        return -1;
    }

    log_memory_access(mLog, address, READ);
    pthread_mutex_unlock(&lock);
    return *(memory + address);
}

void display_memory_log(LogEntry *mLog) {
    printf("Log Start:\n");
    for (int i = 0; i < log_index; ++i) {
        printf("[LOG] ");
        mLog[i].access ? printf("Read from ") : printf("Write to ");
        printf("address %d", mLog[i].address);
        mLog[i].access ? printf("\n") : printf(": %d\n", memory[mLog[i].address]);
    }
    printf("\n");
}

int main() {
    // Create an array of memory logger for maximum 50 entries
    LogEntry mlog[MAX_LOGS];
    pthread_mutex_init(&lock, NULL);

    display_memory_log(mlog);

    write_to_address(mlog, 5, 42);
    read_from_address(mlog, 5);
    write_to_address(mlog, 10, 99);

    display_memory_log(mlog);

    return 0;
}
