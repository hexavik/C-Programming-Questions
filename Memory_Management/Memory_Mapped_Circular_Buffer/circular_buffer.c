#include "circular_buffer.h"
#include <stdint.h>
#include <stdio.h>
#include <pthread.h>

void init_circular_buffer(CircularBuffer *buff) {
    buff->head = 0;
    buff->tail = 0;
    for (int i = 0; i < BUFFER_SIZE; ++i) {
        *(buff->buffer + i) = 0;
    }
    pthread_mutex_init(&buff->lock, NULL);
}

uint8_t read_data(CircularBuffer *buff, uint8_t *data_buff, uint8_t bytes) {
    pthread_mutex_lock(&buff->lock);

    uint8_t available = buff->head >= buff->tail ?
                      buff->head - buff->tail :
                      BUFFER_SIZE - (buff->tail - buff->head);

    if (available < bytes) {
        fprintf(stderr, "Error: Insufficient data to read.\n");
        pthread_mutex_unlock(&buff->lock);
        return CB_EMPTY;
    }

    for (uint8_t i = 0; i < bytes; ++i) {
        *(data_buff + i) = buff->buffer[buff->tail];
        buff->tail = (buff->tail + 1) % BUFFER_SIZE;
    }
    printf("\n");

    display_buffer(buff);
    pthread_mutex_unlock(&buff->lock);

    return CB_OK;
}

uint8_t write_data(CircularBuffer *buff, uint8_t *data, uint8_t bytes) {
    pthread_mutex_lock(&buff->lock);

    uint8_t free = buff->head >= buff->tail ?
                      BUFFER_SIZE - (buff->head - buff->tail) :
                      buff->tail - buff->head;

    if (free < bytes) {
        fprintf(stderr, "Error: Insufficient space to write.\n");
        pthread_mutex_unlock(&buff->lock);
        return CB_FULL;
    }

    for (uint8_t i = 0; i < bytes; ++i) {
        buff->buffer[buff->head] = *(data + i);
        buff->head = (buff->head + 1) % BUFFER_SIZE;
    }

    display_buffer(buff);
    pthread_mutex_unlock(&buff->lock);

    return CB_OK;
}

void display_buffer(CircularBuffer * buff) {
    printf("Buffer: ");
    for (int i = 0; i < BUFFER_SIZE; ++i) {
        printf("%d, ", *(buff->buffer + i));
    }
    printf(" | head: %d | tail: %d\n", buff->head, buff->tail);
}
