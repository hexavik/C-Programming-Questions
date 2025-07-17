#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <pthread.h>

enum {
    BUFFER_SIZE = 10,
    CB_FULL = -1,
    CB_EMPTY = -1,
    CB_OK = 0,
};

typedef struct {
    uint8_t buffer[BUFFER_SIZE];
    volatile uint8_t head; // Write increment pointer
    volatile uint8_t tail; // Read increment pointer
    pthread_mutex_t lock;
} CircularBuffer;

/**
 * @brief Initialize the circular buffer struct object with setting up
 * initial values to head and tail, along with resetting the buffer
 * by clearing it ot zero.
 *
 * @param cBuff Circular Buffer Object
 */
void init_circular_buffer(CircularBuffer * cBuff);

/**
 * @brief Read data from the circular buffer to the data array.
 * 
 * @param cBuff Circular buffer object
 * @param data_buffer Array of data to store read output
 * @param bytes Number of bytes to be read
 * @return uint8_t return error if no enough data available to read,
 * else return success
 */
uint8_t read_data(CircularBuffer * cBuff, uint8_t * data_buffer, uint8_t bytes);

/**
 * @brief Write data from the data array to the circular buffer
 * 
 * @param cBuff Circular buffer object
 * @param data Array of data to retrieve write input
 * @param bytes Number of bytes to be written
 * @return uint8_t return error if no enough free space is available
 * to write, else return success
 */
uint8_t write_data(CircularBuffer * cBuff, uint8_t * data, uint8_t bytes);

/**
 * @brief Display the Cicular buffer content for verification and 
 * debugging
 *
 * @param cBuff Circular buffer object
 */
void display_buffer(CircularBuffer * cBuff);
