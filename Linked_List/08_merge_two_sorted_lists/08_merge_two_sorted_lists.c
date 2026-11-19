/**
 * @file merge_two_sorted_lists.c
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

Node* lists_merge(LinkedList* list1, LinkedList* list2) {
    if (!list1 || !list1->head) { return (list2) ? list2->head : nullptr; }
    if (!list2 || !list2->head) { return list1->head; }

    Node dummy;
    Node* dummy_curr = &dummy;
    Node* h1 = list1->head;
    Node* h2 = list2->head;
    while (h1 && h2) {
        if (h1->data < h2->data) {
            dummy_curr->next = h1;
            h1 = h1->next;
        } else {
            dummy_curr->next = h2;
            h2 = h2->next;
        }

        dummy_curr = dummy_curr->next;
    }

   if (h1) { dummy_curr->next = h1; }
   else { dummy_curr->next = h2; }

   list1->head = nullptr;
   list2->head = nullptr;
   list1->size += list2->size;
   list2->size = list1->size;

   return dummy.next;
}

int main() {
    LinkedList ls1;
    LinkedList ls2;
    list_initialize(&ls1);
    list_initialize(&ls2);

    list_insert_front(&ls1, 5);
    list_insert_front(&ls1, 3);
    list_insert_front(&ls1, 1);

    list_insert_front(&ls2, 6);
    list_insert_front(&ls2, 4);
    list_insert_front(&ls2, 2);

    list_display(&ls1);
    list_display(&ls2);

    ls1.head = lists_merge(&ls1, &ls2);
    list_display(&ls1);
    printf("Merged Size: %zu\n", ls1.size);

    list_destroy(&ls1);

    return 0;
}
