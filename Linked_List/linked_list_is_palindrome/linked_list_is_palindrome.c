/**
 * @file linked_list_is_palindrome.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-08-09
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
void list_front_insert(LinkedList* list, int value) {
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

Node* list_reverse(Node* head) {
    if (!head) { return nullptr; }

    Node* prev = nullptr;
    Node* current = head;
    Node* next = current->next;

    while (current && current->next) {
        current->next = prev;
        prev = current;
        current = next;
        next = current->next;
    }

    current->next = prev;
    head = current;

    return head;
}

bool list_is_palindrome(LinkedList* list) {
    if (!list || !list->head) { return false; }

    //
    // Traverse the list using slow and fast pointers and then find the half
    // of the list and reverse it.
    //

    Node* slow = list->head;
    Node* fast = list->head;
    Node* prev = nullptr;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (list->size & 1) {
        prev = slow;
        slow = slow->next;
    }
    prev->next = list_reverse(slow);

    //
    // Check if the list is palindrome
    //
    Node* pt1 = list->head;
    Node* pt2 = prev->next;
    while (pt1 && pt2) {
        if (pt1->data != pt2->data) {
            return false;
        }
        pt1 = pt1->next;
        pt2 = pt2->next;
    }

    return true;
}

int main() {
    LinkedList ls;
    list_initialize(&ls);

    list_front_insert(&ls, 1);
    list_front_insert(&ls, 2);
    list_front_insert(&ls, 3);
    list_front_insert(&ls, 2);
    list_front_insert(&ls, 1);

    list_display(&ls);

    list_is_palindrome(&ls) ? printf("True\n") : printf("False\n");

    list_destroy(&ls);

    return 0;
}
