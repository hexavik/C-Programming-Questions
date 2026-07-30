/**
 * @file remove_nodes_of_specific_value.c
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
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void list_delete_by_value(LinkedList* list, int target_value) {
    if (!list || !list->head) { return; }

    // Start with the address of the head pointer
    Node** indirect = &list->head;

    // Traverse the list until the pointer points to null, and delete the node
    // if it has the target value
    while (*indirect) {
        if ((*indirect)->data == target_value) {
            // Save the node to free it later
            Node* temp = *indirect;
            // Splice out the node by updating the pointer
            *indirect = (*indirect)->next;
            free(temp);
            list->size -= 1;
            continue;
        }

        // Advance to the address of the 'next' pointer inside the current node
        indirect = &((*indirect)->next);
    }
}

int main() {
    LinkedList ls;
    list_initialize(&ls);

    list_insert_front(&ls, 1);
    list_insert_front(&ls, 1);
    list_insert_front(&ls, 2);
    list_insert_front(&ls, 3);
    list_insert_front(&ls, 4);
    list_insert_front(&ls, 5);

    list_display(&ls);

    list_delete_by_value(&ls, 1);

    list_insert_front(&ls, 6);

    list_display(&ls);

    list_destroy(&ls);

    return 0;
}
