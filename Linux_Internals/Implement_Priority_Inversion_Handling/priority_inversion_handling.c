/**
 * @file priority_inversion_handling.c
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @date 2025-02-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <pthread.h>
#include <sched.h>
#include <unistd.h>
#include <sys/time.h>

#define HIGH_PRIO 99
#define MED_PRIO 50
#define LOW_PRIO 1

pthread_mutex_t shared_mutex;

/**
 * @brief Gets time in miliseconds, working as a timing mechanism.
 * 
 * @return long long 
 */
long long get_time_ms() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

/* Error-checking wrapper */
/**
 * @brief Set the thread priority and Error-checking wrapper.
 * 
 * @param thread Input thread
 * @param policy Predefined input policy
 * @param priority
 */
void set_thread_priority(pthread_t thread, int policy, int priority) {
    struct sched_param param = {.sched_priority = priority};
    if (pthread_setschedparam(thread, policy, &param)) {
        perror("pthread_setschedparam");
    }
}

/**
 * @brief High priority job
 * 
 * @param arg 
 * @return void* 
 */
void * high_prio_thread(void * arg) {
    long long start = get_time_ms();
    printf("[HIGH] Trying to acquire mutex at %lldms\n", get_time_ms() - start);
    
    pthread_mutex_lock(&shared_mutex);
    printf("[HIGH] Acquired mutex at %lldms\n", get_time_ms() - start);
    
    // Simulate critical section work
    for(int i = 0; i < 200000000; ++i) {
        ; // Busy wait
    }
    
    pthread_mutex_unlock(&shared_mutex);
    printf("[HIGH] Released mutex at %lldms\n", get_time_ms() - start);

    return NULL;
}

/**
 * @brief Medium priority job
 * 
 * @param arg 
 * @return void* 
 */
void * med_prio_thread(void * arg) {
    long long start = get_time_ms();
    printf("[MED] Started at %lldms\n", get_time_ms() - start);
    
    // Simulate medium-priority work
    for (int i = 0; i < 400000000; ++i) {
        ; // Longer busy wait
    }
    
    printf("[MED] Finished at %lldms\n", get_time_ms() - start);

    return NULL;
}

/**
 * @brief Low priority job
 * 
 * @param arg 
 * @return void* 
 */
void * low_prio_thread(void * arg) {
    long long start = get_time_ms();
    printf("[LOW] Acquiring mutex at %lldms\n", get_time_ms() - start);
    
    pthread_mutex_lock(&shared_mutex);
    printf("[LOW] Entered critical section at %lldms\n", get_time_ms() - start);
    
    // Simulate long critical section
    for (int i = 0; i < 300000000; ++i) {
        ; // Busy wait
    }
    
    pthread_mutex_unlock(&shared_mutex);
    printf("[LOW] Released mutex at %lldms\n", get_time_ms() - start);

    return NULL;
}

int main() {
    pthread_t high, med, low;
    pthread_attr_t attr;
    struct sched_param param;
    
    // Initialize mutex with priority inheritance protocol
    pthread_mutexattr_t mutexattr;
    pthread_mutexattr_init(&mutexattr);
    pthread_mutexattr_setprotocol(&mutexattr, PTHREAD_PRIO_INHERIT);
    pthread_mutex_init(&shared_mutex, &mutexattr);

    // Create threads with explicit scheduling attributes
    pthread_attr_init(&attr);
    pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&attr, SCHED_FIFO);

    // Create low-priority thread first
    param.sched_priority = LOW_PRIO;
    pthread_attr_setschedparam(&attr, &param);
    pthread_create(&low, &attr, low_prio_thread, NULL);

    // Allow low-priority thread to acquire mutex first
    usleep(100000); // 100ms delay

    // Create medium-priority thread
    param.sched_priority = MED_PRIO;
    pthread_attr_setschedparam(&attr, &param);
    pthread_create(&med, &attr, med_prio_thread, NULL);

    // Create high-priority thread
    param.sched_priority = HIGH_PRIO;
    pthread_attr_setschedparam(&attr, &param);
    pthread_create(&high, &attr, high_prio_thread, NULL);

    // Wait for threads to complete
    pthread_join(high, NULL);
    pthread_join(med, NULL);
    pthread_join(low, NULL);

    // Cleanup
    pthread_mutex_destroy(&shared_mutex);
    pthread_mutexattr_destroy(&mutexattr);

    return 0;
}
