/**
 * @file delete_alternate_nodes.c
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
    size_t size; // Keeps the track of count of nodes automatically
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
 * @param data Input value
 */
void list_insert_front(LinkedList* list, int data) {
    if (!list) { return; }

    Node* new_node = malloc(sizeof(*new_node));
    if (!new_node) { return; }
    new_node->data = data;
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
        Node* next = current->next;
        free(current);
        current = next;
    }

    list->head = nullptr;
    list->size = 0;
}

void list_display(LinkedList* list) {
    if (!list || !list->head) { return; }

    printf("List: ");
    Node* current = list->head;
    while (current) {
        printf("%d -> ", current->data); // Don't forget to change the type
        current = current->next;
    }
    printf("Null\n");
}

/**
 * @brief Delete the alternate node from the list, starting from head node
 * till the end of the list.
 *
 * @param list Existing list which must not be null
 */
void list_delete_alternate(LinkedList* list) {
    if (!list || !list->head) { return; }

    Node* current = list->head;
    while (current && current->next) {
        Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
        current = current->next;
    }
}

int main() {
    LinkedList ls;
    list_initialize(&ls);

    list_insert_front(&ls, 1);
    list_insert_front(&ls, 2);
    list_insert_front(&ls, 3);
    list_insert_front(&ls, 4);
    list_insert_front(&ls, 5);
    list_insert_front(&ls, 6);
    list_insert_front(&ls, 7);
    list_insert_front(&ls, 8);
    list_insert_front(&ls, 9);
    // list_insert_front(&ls, 10);

    list_display(&ls);

    list_delete_alternate(&ls);
    list_display(&ls);

    list_destroy(&ls);
    return 0;
}
