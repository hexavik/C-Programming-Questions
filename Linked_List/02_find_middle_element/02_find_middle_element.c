/**
 * @file find_middle_element.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-08-01
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

/**
 * @brief Find the middle node of the list and return it. For odd numbers of
 * nodes it returns exact middle node, whereas for even numbers of nodes it
 * returns the ndoe that is next to the half of the length.
 *
 * @param list Existing list
 * @return Node* The pointer to the middle node
 */
Node* list_find_middle(LinkedList* list) {
    if (!list || !list->head) { return nullptr; }

    //
    // Use Hare and Tortoise method, which is also called two pointers method,
    // where one pointer moves one place called a slow pointer, and second
    // pointer moves by two places called a fast pointer.
    //
    Node* slow = list->head;
    Node* fast = list->head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
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

    printf("Middle element of the list: %d\n",
        list_find_middle(&ls)->data);

    list_destroy(&ls);

    return 0;
}
