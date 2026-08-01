/**
 * @file time_operations.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-07-31
 *
 * @copyright Copyright (c) 2026
 *
 */
#include <stdint.h>
#include <stdio.h>

typedef struct Time {
    uint8_t h;
    uint8_t m;
    uint8_t s;
} Time;

//
// One can also use the structure to return the values
// I have preferred pointers, since they are much more easiers
//
// typedef struct Duration {
//     Time sum;
//     uint64_t seconds;
// } Duration;

void time_duration(Time* t1, Time* t2, Time* sum, uint64_t* seconds) {
    if (!t1 || !t2) { return; }

    uint8_t carry = 0; // Use to carry extra second or minute from the sum

    //
    // Calculate the sum of seconds
    //
    sum->s = t1->s + t2->s;
    if (sum->s > 60) { sum->s -= 60; carry = 1; }

    //
    // Calculate the sum of minutes
    //
    sum->m = t1->m + t2->m + carry;
    carry = 0;
    if (sum->m > 60) { sum->m -= 60; carry = 1; }

    //
    // Calculate the sum of hours
    //
    sum->h = t1->h + t2->h + carry;

    //
    // Calculate total duration in seconds
    //
    *seconds = (sum->h * 3600) + (sum->m * 60) + sum->s;
}

int main() {
    Time t1 = { .h = 1, .m = 20, .s = 30 };
    Time t2 = { .h = 0, .m = 50, .s = 31 };

    Time sum;
    uint64_t duration_seconds;

    time_duration(&t1, &t2, &sum, &duration_seconds);
    printf("Sum: %dh %dm %ds\nDuration Seconds: %lld\n",
        sum.h, sum.m, sum.s, duration_seconds);

    return 0;
}
