/**
 * @file pairwise_swap_elements.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-08-03
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
 * @brief Swap nodes pairwise, where a left node swapped by a right node.
 * Use a dummy node to start so that the swapped pair can be assigned to it.
 *
 * @param list Existing list which must not be null
 */
void node_swap_pairwise(LinkedList* list) {
    if (!list || !list->head || !list->head->next) { return; }

    Node dummy = *(list->head);
    Node* offset = &dummy;
    Node* temp = list->head;
    list->head = dummy.next;

    while (temp && temp->next) {
        offset->next = temp->next;
        temp->next = offset->next->next;
        offset->next->next = temp;

        offset = temp;
        temp = temp->next;
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

    list_display(&ls);

    node_swap_pairwise(&ls);
    list_display(&ls);

    list_destroy(&ls);

    return 0;
}
