/**
 * @file partition_linked_list_around_value.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-08-11
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
    Node* tail;
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
    list->tail = nullptr;
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
    if (!list->tail) {
        list->tail = new_node;
    }
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
    list->tail = nullptr;
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

void list_parition_around_value(LinkedList* list, int partition) {
    if (!list || !list->head) { return; }

    LinkedList smaller;
    LinkedList larger;
    list_initialize(&smaller);
    list_initialize(&larger);

    Node* current = list->head;
    while (current) {
        current->data < partition
            ? list_insert_front(&smaller, current->data)
            : list_insert_front(&larger, current->data);

        current = current->next;
    }

    smaller.tail->next = larger.head;
    smaller.tail = larger.tail;

    list_display(&smaller);

    list_destroy(&smaller);
}

int main() {
    LinkedList ls;
    list_initialize(&ls);

    list_insert_front(&ls, 2);
    list_insert_front(&ls, 5);
    list_insert_front(&ls, 2);
    list_insert_front(&ls, 3);
    list_insert_front(&ls, 4);
    list_insert_front(&ls, 1);

    list_display(&ls);

    list_parition_around_value(&ls, 3);

    list_destroy(&ls);

    return 0;
}
