/**
 * @file student_average_marks.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-07-31
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

//
// Prefer enum over #define (macro) for type safety
//
enum {
    SUBJECT_COUNT = 5
};

typedef struct Student {
    uint8_t roll_number;
    // Marks are of uint8_t as their value won't be going beyond 100
    uint8_t marks[SUBJECT_COUNT];
    char* name;
} Student;

uint8_t compute_average_marks(Student* student) {
    if (!student) { return 0; }

    //
    // average is 16-bit integer as max total of the marks would be 500
    // If the subject count is more then change the type
    //
    uint16_t average = 0;
    for (size_t i = 0; i < SUBJECT_COUNT; ++i) {
        average += student->marks[i];
    }
    return (average /= SUBJECT_COUNT);
}

void average_display(Student* student) {
    if (!student) { return; }

    printf("Name: %s | Roll No.: %d | Average: %d\n",
        student->name, student->roll_number, compute_average_marks(student));
}

int main() {
    Student s1 = {
        .name = "abc",
        .roll_number = 1,
        .marks = { 83, 75, 63, 67, 99 }
    };

    Student s2 = {
        .name = "def",
        .roll_number = 2,
        .marks = { 78, 78, 76, 70, 54 }
    };

    Student s3 = {
        .name = "",
        .roll_number = -2,
        .marks = { 0, 0, 0, 0, 0 }
    };

    average_display(&s1);
    average_display(&s2);
    average_display(&s3);

    return 0;
}
