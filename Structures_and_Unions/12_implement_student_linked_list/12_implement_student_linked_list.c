/**
 * @file student_linked_list.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-08-30
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[50];
    int roll;
    struct Student* next; // Pointer to the next node
} Student;

typedef struct {
    Student* head;
    size_t count;
} StudentList;

/**
 * @brief Initialize the linked list
 * 
 * @param list Input existing StudentList object
 */
void list_initialize(StudentList* list) {
    if (!list) { return; }
    list->head = nullptr;
    list->count = 0;
}

/**
 * @brief Insert a node as a student entry inside the StudentList
 * 
 * @param list Input existing StudentList object
 * @param name New student name
 * @param roll New student roll number
 */
void list_insert_student(StudentList* list, const char* name, int roll) {
    if (!list) { return; }

    Student* new_student = malloc(sizeof(*new_student));
    if (!new_student) { return; }
    strcpy(new_student->name, name);
    new_student->roll = roll;
    new_student->next = list->head;
    list->head = new_student;
    list->count += 1;
}

/**
 * @brief Destroy the all existing nodes inside the list to de-allocate
 * memory
 * 
 * @param list Input existing StudentList struct
 */
void list_destroy(StudentList* list) {
    if (!list || !list->head) { return; }

    Student* curr = list->head;
    while (curr) {
        list->head = list->head->next;
        free(curr);
        curr = list->head;
    }
}

void list_display(StudentList* list) {
    if (!list) { return; }

    printf("Student List: ");
    Student* curr = list->head;
    while (curr) {
        printf("[ %s | %d ] → ", curr->name, curr->roll);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    StudentList sl;
    list_initialize(&sl);

    list_insert_student(&sl, "Chandler", 108);
    list_insert_student(&sl, "Monica", 109);

    list_display(&sl);
    list_destroy(&sl);

    return 0;
}
