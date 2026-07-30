/**
 * @file move_last_element_to_front.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-08-02
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

//
// A basic block of a Linked List
//
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//
// Management for LinkedList for easy insertion and deletion
//
typedef struct {
    Node* head;
    size_t size;
} LinkedList;

/**
 * @brief Initialize the empty list with default values
 *
 * @param list Input linked list created using LinkedList type
 */
void list_initialize(LinkedList* list) {
    if (!list) { return; }

    list->head = nullptr;
    list->size = 0;
}

/**
 * @brief Insert a node at the front of the list
 *
 * @param list Existing list which must not be null
 * @param value Input value for a node
 */
void list_insert_front(LinkedList* list, int value) {
    if (!list) { return; }

    Node* new_node = malloc(sizeof(*new_node));
    if (!new_node) { return; }
    new_node->data = value;
    new_node->next = list->head;
    list->head = new_node;
    list->size += 1;
}

/**
 * @brief Destroy all existing nodes inside the list,
 * must be called at the end of the program to avoid memory leak.
 *
 * @param list Existing linked list
 */
void list_destroy(LinkedList* list) {
    if (!list || !list->head) { return; }

    Node* current = list->head;
    while (current) {
        list->head = list->head->next;
        free(current);
        current = list->head;
    }

    list->head = nullptr;
    list->size = 0;
}

void list_display(LinkedList* list) {
    if (!list) { return; }

    printf("List: ");
    Node* current = list->head;
    while (current) {
        printf("%d → ", current->data);
        current = current->next;
    }
    printf("Null\n");
}

/**
 * @brief Traverse to the last element and then move it to the front of the
 * linked list. Use a previous pointer to record
 *
 * @param list Existing linked list
 */
void move_last_element_to_front(LinkedList* list) {
    if (!list || !list->head) { return; }

    Node* prev = nullptr;
    Node* current = list->head;
    while (current->next) {
        prev = current;
        current = current->next;
    }
    prev->next = nullptr;
    current->next = list->head;
    list->head = current;
}

int main() {
    LinkedList ls;
    list_initialize(&ls);

    list_insert_front(&ls, 4);
    list_insert_front(&ls, 3);
    list_insert_front(&ls, 2);
    list_insert_front(&ls, 1);

    list_display(&ls);

    move_last_element_to_front(&ls);
    list_display(&ls);

    list_destroy(&ls);

    return 0;
}
